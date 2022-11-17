# %%
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

# %% [markdown]
# # 数据处理

# %%
data1=pd.read_excel('./附件.xlsx',sheet_name='表单1')
data2=pd.read_excel('./附件.xlsx',sheet_name='表单2')
data3=pd.read_excel('./附件.xlsx',sheet_name='表单3')

# %% [markdown]
# 清理无效数据
# 本题中将成分比例累加和介于 85%~105%之间的数据视为有效数据

# %%
print(data2.shape)
data2Sum=np.sum(data2.drop(['文物采样点'],axis=1).fillna(0).values,axis=1)
data2=data2[data2Sum>=85]
print(data2.shape)
data2Sum=np.sum(data2.drop(['文物采样点'],axis=1).fillna(0).values,axis=1)
data2=data2[data2Sum<=105]
print(data2.shape)

# %% [markdown]
# 合并数据

# %%
data2['文物编号']=data2['文物采样点'].map(lambda x:int(x[:2]))
data2=pd.merge(data2,data1,on='文物编号')

# %% [markdown]
# 数据打标

# %%
data2['风化']=data2.apply(lambda x:'风化' if len(x['表面风化'])==2 and len(x['文物采样点'])!=6 else '未风化',axis=1)
data2.drop(['文物采样点','文物编号','表面风化'],axis=1,inplace=True)
data2.fillna(0,inplace=True)

# %%
data=pd.ExcelWriter('./data.xlsx')
data2.to_excel(data,sheet_name='data',index=False)
data2[data2['风化']=='风化'].to_excel(data,sheet_name='风化',index=False)
data2[data2['风化']=='未风化'].to_excel(data,sheet_name='未风化',index=False)
data.save()
# %%
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
plt.rcParams['axes.unicode_minus']=False
plt.rcParams['font.sans-serif'] = ['SimHei']
from sklearn.preprocessing import LabelEncoder

data=pd.read_excel('./data.xlsx',sheet_name='data')
data['风化']=data['风化'].map(lambda x:1 if len(x)==3 else 0)

TrainX=data[['风化','二氧化硅(SiO2)', '氧化钠(Na2O)', '氧化钾(K2O)', '氧化钙(CaO)', '氧化镁(MgO)',
       '氧化铝(Al2O3)', '氧化铁(Fe2O3)', '氧化铜(CuO)', '氧化铅(PbO)', '氧化钡(BaO)',
       '五氧化二磷(P2O5)', '氧化锶(SrO)', '氧化锡(SnO2)', '二氧化硫(SO2)']].values
TrainX=TrainX/100

TrainY=data['类型']
encoder=LabelEncoder().fit(TrainY)
TrainY=encoder.transform(TrainY)

TestX=pd.read_excel('./附件.xlsx',sheet_name='表单3')
TestX.drop(['文物编号'],axis=1,inplace=True)
TestX.fillna(0,inplace=True)
TestX['表面风化']=TestX['表面风化'].map(lambda x:1 if len(x)==3 else 0)
TestX=TestX.values
TestX=TestX/100

# %%
from sklearn.metrics import mean_absolute_error
class Linear:
    def __init__(self,n,lr=1,) -> None:
        self.alpha=np.ones((n+1,))
        self.y=None
        self.lr=lr
    def differential(self,x:np.array,y:np.array)->np.array:
        tmp=((self.y-y)*self.y*(1-self.y)).reshape((self.y.shape[0],1)).dot(np.ones((1,self.alpha.shape[0])))
        tmp1=self.alpha*np.eye(self.alpha.shape[0])
        tmp1=x.dot(tmp1)
        return np.sum(tmp*tmp1,axis=0)
    def predict(self,x:np.array)->np.array:
        if x.shape[1]!=self.alpha.shape[0]:
            x=np.concatenate([x,np.ones((x.shape[0],1))],axis=1)
        return 1/(1+np.exp(-x.dot(self.alpha)))
    def fit(self,x:np.array,y:np.array):
        x=np.concatenate([x,np.ones((x.shape[0],1))],axis=1)
        old=0
        new=0
        counter=1000
        while counter>0:
            self.y=self.predict(x)
            d=self.differential(x,y)
            self.alpha-=self.lr*d*self.alpha
            self.y=self.predict(x)
            new=np.mean(np.abs(self.y-y))
            if np.abs(new-old)<1e-6:
                break
            old=new
            counter-=1
        return self

# %% [markdown]
# ## 训练模型

# %%
l=Linear(TrainX.shape[1])
l.fit(TrainX,TrainY)
mean_absolute_error(l.predict(TrainX),TrainY)

# %%
l.alpha

# %%
plt.subplot(1,2,1)
plt.plot(TrainY)
# plt.ylabel('value')
plt.xlabel('Y')
plt.subplot(1,2,2)
plt.plot(l.predict(TrainX))
plt.xlabel('P')
plt.savefig('./3.表现.png')

# %%
plt.barh(
    y=pd.read_excel('./附件.xlsx',sheet_name='表单3').columns[1:],
    width=l.alpha[:-1]
    )
# plt.xlabel('化学成分在alpha中对应的权重')
plt.savefig('./3.alpha.png')

# %% [markdown]
# ## 预测结果

# %%
print(encoder.inverse_transform((l.predict(TestX)+0.5).astype(np.int8)))

# %% [markdown]
# ## 敏感性分析

# %%
S=lambda x:(1-l.predict(x).reshape((x.shape[0],1))).dot(np.ones((1,x.shape[1])))*x**2*l.alpha[:-1]

# %%
tmp=S(TestX)
# tmp

# %%
labels=pd.read_excel('./附件.xlsx',sheet_name='表单3')['文物编号']
for i in range(tmp.shape[0]):
    plt.plot(tmp[i],label=labels[i])
plt.xticks(
    range(15),
    pd.read_excel('./附件.xlsx',sheet_name='表单3').columns[1:],
    rotation=90
)
plt.legend()
plt.savefig('./3.sensitivity.png')

# %% [markdown]
# 该模型对氧化铝(Al2O3)含量较敏感，对氧化铅(PbO)含量极其敏感


