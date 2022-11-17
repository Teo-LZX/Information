from sklearn.linear_model import LinearRegression
from sklearn.model_selection import cross_val_score
from sklearn.metrics import mean_absolute_error
from sklearn.metrics import mean_squared_error 
from sklearn.metrics import r2_score # R square
import matplotlib.pyplot as plt
import pandas as pd
import numpy as np

data风化后=pd.read_excel('./风化前和风化后化学成分对比.xlsx', usecols=['二氧化硅风化后(SiO2)','氧化钠风化后(Na2O)','氧化钾风化后(K2O)', '氧化钙风化后(CaO)', '氧化镁风化后(MgO)', '氧化铝风化后(Al2O3)', '氧化铁风化后(Fe2O3)', '氧化铜风化后(CuO)', '氧化铅风化后(PbO)','氧化钡风化后(BaO)','五氧化二磷风化后(P2O5)','氧化锶风化后(SrO)','氧化锡风化后(SnO2)','二氧化硫风化后(SO2)'])
data风化前=pd.read_excel('./风化前和风化后化学成分对比.xlsx', usecols=['二氧化硅(SiO2)','氧化钠(Na2O)','氧化钾(K2O)', '氧化钙(CaO)', '氧化镁(MgO)', '氧化铝(Al2O3)', '氧化铁(Fe2O3)', '氧化铜(CuO)', '氧化铅(PbO)','氧化钡(BaO)','五氧化二磷(P2O5)','氧化锶(SrO)','氧化锡(SnO2)','二氧化硫(SO2)'])


Train_X=np.array(data风化后)
Train_Y=np.array(data风化前)

l=LinearRegression(n_jobs=-1).fit(Train_X,Train_Y)
P=l.predict(Train_X)
print('MAE', mean_absolute_error(P,Train_Y))
print('R2', r2_score(P, Train_Y))
print('MSE', mean_squared_error(P, Train_Y))

for i in range(len(P)):
    for j in range(len(P[i])):
        P[i][j] = round(P[i][j], 3)
df = pd.DataFrame(P, columns=['二氧化硅(SiO2)','氧化钠(Na2O)','氧化钾(K2O)', '氧化钙(CaO)', '氧化镁(MgO)', '氧化铝(Al2O3)', '氧化铁(Fe2O3)', '氧化铜(CuO)', '氧化铅(PbO)','氧化钡(BaO)','五氧化二磷(P2O5)','氧化锶(SrO)','氧化锡(SnO2)','二氧化硫(SO2)'])
df.to_csv('./问题一预测结果.csv', index=False,encoding='gb2312')
plt.xlabel('')
plt.title('模型拟合效果')
plt.show()