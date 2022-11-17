import matplotlib.pyplot as plt
import math
from functools import reduce,  cmp_to_key
import operator

class Point():
    def __init__(self, x, y):
        self.x = x
        self.y = y

class Convex_hull():
    def __init__(self):
        self.points = []
        self.n = eval(input("请输入点的数量:"))
        self.visit = [0]*self.n
        self.res = []
        self.hull_points = []
        print("输入所有点:")
        for  i in range(self.n):
            x, y = input().split(" ")
            x = int(x)
            y = int(y)
            self.points.append(Point(x, y))
        self.points.sort(key=lambda p:(p.x, p.y)) #按x大小排序，x大小相同按y大小排序
        self.show_points()

    def show_res(self):
        print("凸包点：")
        for it in self.res:
            print(it)

    def show_points(self):
        for it in self.points:
            print('(', it.x, ',', it.y, ')')

    def judge(self, p1, p2, p3):                   #计算三角形面积，根据三角形面积来求顶点
        x1, x2, x3 = p1.x, p2.x, p3.x
        y1, y2, y3 = p1.y, p2.y, p3.y
        res = x1*y2 + x3*y1 + x2*y3 - x3*y2 - x2*y1 - x1*y3
        return res

    def hull(self, left, right):
        max = 0
        index = -1
        if left<right:
            for i in range(left+1, right):
                res = self.judge(self.points[left], self.points[i], self.points[right])
                if res == 0:
                    self.visit[i] = 1
                if res>max:
                    max = res
                    index = i
        else:
            for i in range(right, left):
                res = self.judge(self.points[left], self.points[i], self.points[right])
                if res == 0:
                    self.visit[i] = 1
                if res>max:
                    max = res
                    index = i
        
        if index != -1:
            self.visit[index] = 1
            self.hull(left, index)
            self.hull(index, right)
        
    def get_hull(self):
        self.visit[0] = 1
        self.visit[self.n-1] = 1
        self.hull(0, self.n-1)
        self.hull(self.n-1, 0)
        #为了将凸包点顺时针连接，这里需要作一下处理
        for i in range(self.n):
            if self.visit[i]==1:
                self.hull_points.append(Point(self.points[i].x, self.points[i].y))
                
        for it in self.hull_points:
            self.res.append((it.x, it.y))
        #将答案中的点按顺时针排序，方便画图的时候连线
        center = tuple(map(operator.truediv, reduce(lambda x, y: map(operator.add, x, y), self.res), [len(self.res)] * 2))
        self.res=sorted(self.res, key=lambda coord: (-135 - math.degrees(math.atan2(*tuple(map(operator.sub, coord, center))[::-1]))) % 360, reverse=False)

def draw_answer(points, res):
    x = []
    y = []
    x_res = []
    y_res = []
    for it in points:
        p = (it.x, it.y)
        if it not in res:
            x.append(it.x)
            y.append(it.y)
    for it in res:    
        x_res.append(it[0])
        y_res.append(it[1])
    x_res.append(res[0][0])
    y_res.append(res[0][1])
    print(x_res)
    print(y_res)
    plt.title('Convex Hull')
    plt.scatter(x, y)
    plt.scatter(x_res, y_res, c='#228B22')
    plt.plot(x_res, y_res)
    plt.show()

c = Convex_hull()
c.get_hull()     #求解凸包
c.show_res()
draw_answer(c.points, c.res)  #将结果以图形画出来
