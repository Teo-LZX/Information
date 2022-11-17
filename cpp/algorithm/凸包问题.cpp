#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

class Point  //点类
{   
public:
    Point() {}
    Point(int x, int y):x(x), y(y) {}
    bool operator<(const Point& p)
    {
        if(x!=p.x)
            return x < p.x;
        else
            return y<p.y;  //x相同按y的大小排序
    }
    float x, y;
};       

class Convex_Hull   //凸包类
{
public:
    Convex_Hull()      //构造函数，初始化凸包
    {
        cout << "请输入点的数量：";
        cin >> n;
        cout << "输入所有点：\n";
        for(int i=0;i<n;i++)
        {
            int x, y;
            cin >> x >> y;
            points.push_back(Point(x, y));
        }
        sort(points.begin(), points.end());    //对所有点进行排序（按照横坐标从大到小）
    }

    int get_area(Point& p1, Point& p2, Point& p3)    //求三角形面积
    {
        int x1=p1.x, x2=p2.x, x3=p3.x;
        int y1=p1.y, y2=p2.y, y3=p3.y;
        return x1*y2+x3*y1+x2*y3-x3*y2-x2*y1-x1*y3;
    }

    void up_hull(int i, int j)  //对Pi和Pj连线构成的上包
    {
        int max=0, index=-1;
        for(int k=i+1;k<j;k++)
        {
            int res=get_area(points[i], points[j], points[k]);   //通过求三角形面积来找离直线距离最远的点Pmax
            if(res>max)
            {
                max = res;
                index = k;
            }
        }
        if(index!=-1)  //找到了距离直线Pi_Pj最远的点Pmax，把直线Pi_Pmax和直线Pj_Pmax作为的上面部分作为上包，进行递归
        { 
            hull_points.push_back(points[index]);   //将Pmax加入结果集
            up_hull(i, index);
            up_hull(index, j);
        }
    }
    void down_hull(int i, int j)
    {
        int max=0, index=-1;
        for(int k=j-1;k>i;k--)
        {
            int res=get_area(points[i], points[j], points[k]);   //通过求三角形面积来找离直线距离最远的点Pmax
            if(res>max)
            {
                max = res;
                index = k;
            }
        }
        if(index!=-1)  //找到了距离直线Pi_Pj最远的点Pmax，把直线Pi_Pmax和直线Pj_Pmax作为的上面部分作为上包，进行递归
        { 
            hull_points.push_back(points[index]);   //将Pmax加入结果集
            down_hull(i, index);
            down_hull(index, j);
        }
    }
    void get_hull()
    {
        up_hull(0, n-1);  //查找上凸包
        down_hull(0, n-1);  //查找下凸包
    }
    void show_result()
    {
        cout << "hello world\n";
        for(auto &it : hull_points)
        {
            cout << "(" << it.x << "," << it.y << ")"  << ", ";
        }
    }
private:
    int n;    //一共有n个点
    vector<Point> points;   //包含所有点的数组
    vector<Point> hull_points;  //凸包点
};

int main()
{
    int n;
    Convex_Hull c;
    c.get_hull();
    c.show_result();
}