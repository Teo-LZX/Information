#pragma warning(disable:4786)
#include<iostream>
#include<string>
#include<map>
using namespace std;

typedef  map<int, string, less<int> > INT2STRING;

int main()
{
        INT2STRING theMap;
        INT2STRING::iterator theIterator;
        string theString  =  "";
        int index;
        theMap.insert(INT2STRING::value_type(0,  "Zero"));
        theMap.insert(INT2STRING::value_type(1,  "One"));
        theMap.insert(INT2STRING::value_type(2,  "Two"));
        theMap.insert(INT2STRING::value_type(3,  "Three"));
        theMap.insert(INT2STRING::value_type(4,  "Four"));
        theMap.insert(INT2STRING::value_type(5,  "Five"));
        theMap.insert(INT2STRING::value_type(6,  "Six"));
        theMap.insert(INT2STRING::value_type(7,  "Seven"));
        theMap.insert(INT2STRING::value_type(8,  "Eight"));
        theMap.insert(INT2STRING::value_type(9,  "Nine"));
        for  (;;)
        {
                cout  <<  "Enter      \"q\"      to      quit,      or      enter      a      Number:      ";
                cin  >>  theString;
                if(theString  ==  "q")
                break;
                theIterator = theMap.begin();
                char s = '0';
                int n = *(char*)theString.c_str()-(char)s;
                for(int i=0;i<n;i++)
                    theIterator++;
                cout << theIterator->second;

            
                cout  <<  endl;
        }
        return  0;
}