import numpy as np
import pandas as pd
from scipy.stats import pearsonr
data = np.array(pd.read_csv('./data.csv'))

data高钾 = []
data铅钡 = []

for it in data:
    if it[-3] == '高钾':
        data高钾.append(it)
    elif it[-3] == '铅钡':
        data铅钡.append(it)

print(len(data高钾))
print(len(data铅钡))

df = pd.DataFrame(data高钾, columns=['二氧化硅(SiO2)','氧化钠(Na2O)','氧化钾(K2O)','氧化钙(CaO)','氧化镁(MgO)','氧化铝(Al2O3)','氧化铁(Fe2O3)','氧化铜(CuO)','氧化铅(PbO)','氧化钡(BaO)','五氧化二磷(P2O5)','氧化锶(SrO)','氧化锡(SnO2)','二氧化硫(SO2)','纹饰','类型','颜色','风化'])
df.to_csv('./data高钾.csv', index=False)
df = pd.DataFrame(data铅钡, columns=['二氧化硅(SiO2)','氧化钠(Na2O)','氧化钾(K2O)','氧化钙(CaO)','氧化镁(MgO)','氧化铝(Al2O3)','氧化铁(Fe2O3)','氧化铜(CuO)','氧化铅(PbO)','氧化钡(BaO)','五氧化二磷(P2O5)','氧化锶(SrO)','氧化锡(SnO2)','二氧化硫(SO2)','纹饰','类型','颜色','风化'])
df.to_csv('./data铅钡.csv', index=False)
高钾数据 = pd.read_excel('./高钾玻璃化学成分的相关性分析.xlsx')
铅钡数据 = pd.read_excel('./铅钡玻璃化学成分的相关性分析.xlsx')

def is_number(s):   #函数功能-判断字符串是否为数字
    try:  # 如果能运行float(s)语句，返回True（字符串s是浮点数）
        float(s)
        return True
    except ValueError:  # ValueError为Python的一种标准异常，表示"传入无效的参数"
        pass  # 如果引发了ValueError这种异常，不做任何事情（pass：不做任何事情，一般用做占位语句）
    try:
        import unicodedata  # 处理ASCii码的包
        unicodedata.numeric(s)  # 把一个表示数字的字符串转换为浮点数返回的函数
        return True
    except (TypeError, ValueError):
        pass
    return False

高钾相关性 = np.array(高钾数据)
高钾显著性检验值 = []
for it in 高钾相关性:
    temp = [it[0]]
    for it2 in it:
        左括号位置 = it2.find('(')
        右括号位置 = it2.find(')')
        #print(it2, (左括号位置, 右括号位置), end='')
        it2 = it2[左括号位置+1:右括号位置].strip('*')
        if is_number(it2):
            it2 = float(it2)
            temp.append(it2)
            #print(it2, end='')
        #print()
    高钾显著性检验值.append(temp)

#将P值符合条件的相关关系筛选出来
df = pd.DataFrame(高钾显著性检验值, columns=['名称','二氧化硅(SiO2)', '氧化钠(Na2O)', '氧化铜(CuO)', '二氧化硫(SO2)',  '氧化镁(MgO)', '氧化锡(SnO2)', '氧化锶(SrO)',	'氧化钾(K2O)', '五氧化二磷(P2O5)', '氧化钡(BaO)', '氧化钙(CaO)', '氧化铅(PbO)',	'氧化铁(Fe2O3)', '氧化铝(Al2O3)'])
df.to_csv('./高钾显著性检验值.csv', index=False)

有相关性的值 = []
index = ['名称','二氧化硅(SiO2)', '氧化钠(Na2O)', '氧化铜(CuO)', '二氧化硫(SO2)',  '氧化镁(MgO)', '氧化锡(SnO2)', '氧化锶(SrO)',	'氧化钾(K2O)', '五氧化二磷(P2O5)', '氧化钡(BaO)', '氧化钙(CaO)', '氧化铅(PbO)',	'氧化铁(Fe2O3)', '氧化铝(Al2O3)']
for i in range(len(高钾显著性检验值)):
    for j in range(1, i):
        if 高钾显著性检验值[i][j] < 0.05:
            #print(高钾显著性检验值[i][j], (i, j), end='')
            #print('对应的相关系数值=', end='')
            l = 高钾相关性[i][j].find('(')
            r = 高钾相关性[i][j].find(')')
            相关系数值 = float(高钾相关性[i][j][:l])
            #print(相关系数值, (index[i+1],index[j]))
            有相关性的值.append((相关系数值, (index[i+1],index[j])))

for i in range(len(有相关性的值)):
    for j in range(len(有相关性的值)-i-1):
        if 有相关性的值[j][0] > 有相关性的值[j+1][0]:
            temp = 有相关性的值[j]
            有相关性的值[j] = 有相关性的值[j+1]
            有相关性的值[j+1] = temp
print(有相关性的值, len(有相关性的值))

#对筛选出来的相关关系进行强度分类
#•	0.8-1.0 极强相关
#•	0.6-0.8 强相关
#•	0.4-0.6 中等程度相关
#•	0.2-0.4 弱相关
#•	0.0-0.2 极弱相关或无相关
极强相关 = []
强相关 = []
中等相关 = []
弱相关 = []

正相关 = []
负相关 = []
for it in 有相关性的值:
    if abs(it[0]) >= 0.8:
        极强相关.append(it)
    elif abs(it[0]) >= 0.6:
        强相关.append(it)
    elif abs(it[0]) >= 0.4:
        中等相关.append(it)
for it in 有相关性的值:
    if it[0] > 0 :
        正相关.append(it)
    elif it[0] < 0 : 
        负相关.append(it)
print(len(有相关性的值), len(极强相关), len(强相关), len(中等相关), len(正相关), len(负相关))

for i in 中等相关:
    print(i[1][0], '与', i[1][1], '相关系数=', i[0])
for i in 强相关:
    print(i[1][0], '与', i[1][1], '相关系数=', i[0])
for i in 极强相关:
    print(i[1][0], '与', i[1][1], '相关系数=', i[0])

#相关强度分布图
import matplotlib.pyplot as plt
plt.rcParams["font.sans-serif"]=["SimHei"] #设置字体
plt.rcParams["axes.unicode_minus"]=False #该语句解决图像中的“-”负号的乱码问题
res = [len(极强相关), len(强相关), len(中等相关)]
res2 = [len(正相关), len(负相关)]

plt.pie(res,
    labels=['极强相关(' + str(len(极强相关)) + '个)', '强相关(' + str(len(强相关)) + '个)', '中等强度相关(' + str(len(中等相关)) + '个)'],
    autopct='%.2f%%') # 格式化输出百分比
plt.title('相关强度分布图')
plt.show()

plt.pie(res2,
    labels=['正相关(' + str(len(正相关)) + '个)', '负相关(' + str(len(负相关)) + '个)'],
    autopct='%.2f%%') # 格式化输出百分比
plt.title('相关强度分布图2')
plt.show()

###################

铅钡相关性 = np.array(铅钡数据)
铅钡相关性
铅钡显著性检验值 = []
for it in 铅钡相关性:
    temp = [it[0]]
    for it2 in it:
        左括号位置 = it2.find('(')
        右括号位置 = it2.find(')')
        #print(it2, (左括号位置, 右括号位置), end='')
        it2 = it2[左括号位置+1:右括号位置].strip('*')
        if is_number(it2):
            it2 = float(it2)
            temp.append(it2)
            #print(it2, end='')
        #print()
    铅钡显著性检验值.append(temp)

df = pd.DataFrame(铅钡显著性检验值, columns=['名称','二氧化硅(SiO2)', '氧化钠(Na2O)', '氧化铜(CuO)', '二氧化硫(SO2)',  '氧化镁(MgO)', '氧化锡(SnO2)', '氧化锶(SrO)',	'氧化钾(K2O)', '五氧化二磷(P2O5)', '氧化钡(BaO)', '氧化钙(CaO)', '氧化铅(PbO)',	'氧化铁(Fe2O3)', '氧化铝(Al2O3)'])
df.to_csv('./铅钡显著性检验值.csv', index=False)

有相关性的值2 = []
index = ['名称','二氧化硅(SiO2)', '氧化钠(Na2O)', '氧化铜(CuO)', '二氧化硫(SO2)',  '氧化镁(MgO)', '氧化锡(SnO2)', '氧化锶(SrO)',	'氧化钾(K2O)', '五氧化二磷(P2O5)', '氧化钡(BaO)', '氧化钙(CaO)', '氧化铅(PbO)',	'氧化铁(Fe2O3)', '氧化铝(Al2O3)']
for i in range(len(铅钡显著性检验值)):
    for j in range(1, i):
        if 铅钡显著性检验值[i][j] < 0.05:
            #print(铅钡显著性检验值[i][j], (i, j), end='')
            #print('对应的相关系数值=', end='')
            l = 铅钡相关性[i][j].find('(')
            r = 铅钡相关性[i][j].find(')')
            相关系数值 = float(铅钡相关性[i][j][:l])
            #print(相关系数值, (index[i+1],index[j]))
            有相关性的值2.append((相关系数值, (index[i+1],index[j])))

for i in range(len(有相关性的值2)):
    for j in range(len(有相关性的值2)-i-1):
        if 有相关性的值2[j][0] > 有相关性的值2[j+1][0]:
            temp = 有相关性的值2[j]
            有相关性的值2[j] = 有相关性的值2[j+1]
            有相关性的值2[j+1] = temp
print(有相关性的值2, len(有相关性的值2))

#对筛选出来的相关关系进行强度分类
#•	0.8-1.0 极强相关
#•	0.6-0.8 强相关
#•	0.4-0.6 中等程度相关
#•	0.2-0.4 弱相关
#•	0.0-0.2 极弱相关或无相关
极强相关 = []
强相关 = []
中等相关 = []
弱相关 = []
正相关 = []
负相关 = []

for it in 有相关性的值2:
    if abs(it[0]) >= 0.8:
        极强相关.append(it)
    elif abs(it[0]) >= 0.6:
        强相关.append(it)
    elif abs(it[0]) >= 0.4:
        中等相关.append(it)
    else:
        弱相关.append(it)
for it in 有相关性的值2:
    if it[0] > 0 :
        正相关.append(it)
    elif it[0] < 0 : 
        负相关.append(it)
print(len(有相关性的值2), len(极强相关), len(强相关), len(中等相关), len(弱相关), len(正相关), len(负相关))

#相关强度分布图
plt.rcParams["font.sans-serif"]=["SimHei"] #设置字体
plt.rcParams["axes.unicode_minus"]=False #该语句解决图像中的“-”负号的乱码问题
res = [len(强相关), len(中等相关), len(弱相关)]
res2 = [len(正相关), len(负相关)]
plt.pie(res,
    labels=['强相关(' + str(len(强相关)) + '个)', '中等强度相关(' + str(len(中等相关)) + '个)', '弱相关(' + str(len(弱相关)) + '个)'],
    autopct='%.2f%%') # 格式化输出百分比
plt.title('相关强度分布图')
plt.show()

plt.pie(res2,
    labels=['正相关(' + str(len(正相关)) + '个)', '负相关(' + str(len(负相关)) + '个)'],
    autopct='%.2f%%') # 格式化输出百分比
plt.title('相关强度分布图2')
plt.show()

