#include  <iostream>
#include  <string>
using  namespace  std;
class  person
{
public:
        person()
        {
                cout<<"Input  id:";
                cin>>id;
                cout<<"Input  name:";
                cin>>name;
        }
        void  display()
        {
                cout<<"Id:"<<id<<endl;
                cout<<"Name:"<<name<<endl;
        }
private:
        string  id;
        string  name;
};
class student:public person
{
public:
    student()
    {
        cout << "Input class:";
        cin >> cla;
        cout << "Input score:";
        cin >> score;
    }
    void display()
    {
        cout << "Student's info:" << endl;
        person::display();
        cout << "Class:" << cla << endl;
        cout << "Score:" << score << endl;
    }
private:
    string cla;
    double score;
};
class teacher:public person
{
public:
    teacher()
    {
        cout << "Input title:";
        cin >> title;
        cout << "Input department:";
        cin >> department;
    }
    void display()
    {
        cout << "Teacher's info:" << endl;
        person::display();
        cout << "Title:" << title << endl;
        cout << "Department:" << department << endl;
    }
private:
    string title;
    string department;
};
int  main()
{
        student  stu;
        teacher  tea;
        stu.display();
        tea.display();
        return  0;
}