#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Document
{
    private:
        string name;
    public:
        Document(string name):name(name) {}
        void display()
        {
            cout << "Name:" << name << endl;
        }
};
class Book:public Document
{
    private:
        int pageCount;
    public:
        Book(string name, int pageCount):Document(name), pageCount(pageCount) {}
        void display()
        {
            Document::display();
            cout << "Page:" << pageCount << endl;
        }
};
int main()
{
    string name;
    int page;
    cout << "Input Name and Page:";
    cin>> name >> page;
    Book b(name, page);
    b.display();
}