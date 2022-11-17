#include<iostream>
#include<pthread.h>
#include<string>
#include<vector>
using namespace std;

void* say_hello(void* args)
{
    cout << "hello world\n";
    return 0;
}
int main()
{
    int n;
    vector<pthread_t> tids;
    cin >> n;
    tids.resize(n);
    for(int i=0;i<n;++i)
    {
        int ret = pthread_create(&tids[i], NULL, say_hello, NULL);
        if(ret != 0)
        {
            cout <<  "pthread_create error:" << ret << endl;
        }   
    }
    pthread_exit(NULL);
    system("pause");
}