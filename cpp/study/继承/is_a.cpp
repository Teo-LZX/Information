#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<set>
#include<stack>
#include<map>
#include<unordered_map>
using namespace std;

class TableTennisPlayer
{
    private:
        string firstname;
        string lastname;
        bool hasTable;
    public:
        TableTennisPlayer(const string & fn = "none", const string & ln = "none", bool ht = false);
        ~TableTennisPlayer();
        void Name() const;
        bool HasTable() const {return hasTable;}
        void ResetTable(bool v) {hasTable = v;}
};
TableTennisPlayer::TableTennisPlayer(const string & fn, const string & ln, bool ht): firstname(fn), lastname(ln), hasTable(ht) {
    cout << "TableTennisPlayer constructor called"  << endl;
}
TableTennisPlayer::~TableTennisPlayer()
{
    cout << "TableTennisPlayer destructor called" << endl;
}
void TableTennisPlayer::Name() const
{
    cout << lastname << " " << firstname << endl;
}

class RatedPlayer: public TableTennisPlayer
{
    private:
        unsigned int rating;   //比分
    public:
        RatedPlayer(unsigned int r = 0, const string & fn = "none", const string & ln = "none",  bool ht = false);
        RatedPlayer(unsigned int r, const TableTennisPlayer & tp);
        ~RatedPlayer();
        unsigned int Rating() const { return rating;}   //检索比分
        void ResetRating(unsigned int r) {rating = r;}  //充值比分
};
RatedPlayer:: RatedPlayer(unsigned int r, const string & fn, const string & ln, bool ht) : TableTennisPlayer(fn, ln, ht) 
{
    cout << "RatedPlayer constructor called" << endl;
    rating = r;
}
RatedPlayer:: RatedPlayer(unsigned int r, const TableTennisPlayer & tp) : TableTennisPlayer(tp), rating(r) {}
RatedPlayer:: ~RatedPlayer()
{
    cout << "RatedPlayer destructor called" << endl;
}
void Show(const TableTennisPlayer& rt)
{
    cout << "Name: ";
    rt.Name();
    cout << "Table: ";
    if(rt.HasTable())
        cout << "yes\n";
    else
        cout << "no\n";
}
int main()
{
    TableTennisPlayer play1("bob", "leap", true);
    RatedPlayer rpaly1(1140, "tom", "go", false);
    // 基类指针可以指向派生类，派生类指针不可以指向基类
    TableTennisPlayer &rt = play1;   //基类引用
    TableTennisPlayer * pt = &play1;     //基类指针
    // rt.Name();
    // pt->Name();
    Show(play1);
    Show(rpaly1);
    //用派生类对象给基类对象赋值
    play1 = rpaly1;
    play1.Name();
    // rpaly1 = play1;  不能用基类对象给派生类对象赋值
    //play1.Name();
    //rpaly1.Name();
}