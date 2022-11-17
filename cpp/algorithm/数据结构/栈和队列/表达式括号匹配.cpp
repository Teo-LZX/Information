#include<bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    int flag=1;
    stack<char> s;
    cin >> str;
    for(auto &it:str)
    {
        if(it == '(')
            s.push('(');
        else if(it == ')')
        {
            if(s.empty())
            {
                flag=0;
                break;
            }
            s.pop();
        }
    }
    if(flag && s.empty())
        cout << "YES";
    else
        cout << "NO";
}