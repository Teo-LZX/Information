#问题提出某公司生产贮藏用容器，订货合同要求该公司制造一种敞口的长方体容器
#容积为12立方米，该容器的底为正方形，容器总重量不超过68公斤。
#已知用作容器四壁的材料为每平方米10元，重3公斤;用作容器底的材料每平方米20元，重2公斤。
#试问制造该容器所需的最小费用是多少?
#----------------------------------
#设容器底边长为x，容器高为y
#则容器体积为vol=x*x*y   容器四壁面积area1=4*x*y  容器底面积area2=x*x

import numpy as np
from scipy.optimize import minimize 
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

def func(args):
    x, y = args
    area1 = 4*x*y
    area2 = x*x
    return area1*10 + area2*20   #总费用

args = np.array((2, 1.5))    #初始迭代参数
e = 1e-10       # 非常接近0的值
#约束条件
cons = ({'type':'eq', 'fun': lambda x: x[0]*x[0]*x[1] - 12},  #体积为12
{'type':'ineq', 'fun': lambda x: 68 - 3*4*x[0]*x[1] - 2*x[0]*x[0]},   #总重量不超过68公斤
{'type':'ineq', 'fun': lambda x:x[0] - e},
{'type':'ineq', 'fun': lambda x:x[1] - e})

# a = np.linspace(-5, 5, 200)
# b = func(a)

minval = minimize(func, args, method="SLSQP", constraints=cons)

figure = plt.figure()
ax = Axes3D(figure)
x = np.arange(-5, 5, 0.01)
y = np.arange(-5, 5, 0.1)
X, Y = np.meshgrid(x, y)

# Z轴函数
Z = 4*X*Y*10 + 20*X*X

print('最优解:') 
print('容器底长:', minval.x[0], ' 容器高:', minval.x[1])
print('最小费用：', minval.fun)
print(minval.success)

# 定义x,y 轴名称
plt.xlabel("x")
plt.ylabel("y")
# 设置间隔和颜色
ax.plot_surface(X, Y, Z, rstride=1, cstride=1, cmap="rainbow")
ax.scatter(minval.x[0], minval.x[1], minval.fun)
# 展示
plt.show()


