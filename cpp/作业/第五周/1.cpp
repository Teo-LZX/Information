#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<set>
#include<stack>
#include<map>
#include<unordered_map>
using namespace std;

// int getTotalWeight(Boat b, Car c);
class Boat;
class Car;
class Boat{
    private:
        int weight;
    public: 
        friend int getTotalWeight(Boat b);
        Boat(){
            cout << "Input boat weight:";
            cin >> weight;
        }

};
// class Car{
//     private:
//         int weight;
//     public:
//         friend int getTotalWeight(Boat b, Car c);
//         Car(){
//             cout << "Input car weight:";
//             cin >> weight;
//         }
// };
int getTotalWeight(Boat b){
    return b.weight;
}
int main()
{
    Boat b;
    //Car c;
    cout << getTotalWeight(b);
}

