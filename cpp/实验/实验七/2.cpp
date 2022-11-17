#include  <vector>
#include  <iostream>
using  namespace  std;
char  szHW[20]  =  "Hello  World";
int main()  
{
        vector <char>  vec;
        vector <char>::iterator  vi;
        char*  cptr  =  szHW;
        while(*cptr != '\0')  {
                vec.push_back(*cptr);
                cptr++;
        }
        for  (vi=vec.begin();  vi!=vec.end();  vi++)
        {
                cout << *vi;

        }
        cout  <<  endl;
        return  0;
}