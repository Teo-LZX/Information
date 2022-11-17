#include<bits/stdc++.h>
using namespace std;

// int main()
// {
//     int n;
//     cin >> n;
//     vector<int> arr(n);
//     vector<int> big_heap;
//     vector<int> small_heap;
//     make_heap(big_heap.begin(), big_heap.end(), less<int>());  //大顶堆
//     make_heap(small_heap.begin(), small_heap.end(), greater<int>());  //小顶堆
//     int mid;
//     cin >> mid; cout << mid << endl;   //前1个的中位数就是它本身
//     for(int i=2;i<=n;i++){
//         int x; cin >> x;
//         if(x < mid){
//             big_heap.push_back(x);
//             push_heap(big_heap.begin(), big_heap.end(), less<int>());
//         }
//         else{
//             small_heap.push_back(x);
//             push_heap(small_heap.begin(), small_heap.end(), greater<int>());
//         }
        
//         if(i%2 == 1){
//             while(big_heap.size() != small_heap.size()){
//                 if(big_heap.size() > small_heap.size()){
//                     small_heap.push_back(mid);
//                     push_heap(small_heap.begin(), small_heap.end(), less<int>());
//                     mid = big_heap.front();
//                     pop_heap(big_heap.begin(), big_heap.end(), less<int>());
//                     big_heap.pop_back();
//                 }
//                 else{
//                     big_heap.push_back(mid);
//                     push_heap(big_heap.begin(), big_heap.end(), greater<int>());
//                     mid = small_heap.front();
//                     pop_heap(small_heap.begin(), small_heap.end(), greater<int>());
//                     small_heap.pop_back();
//                 }
//             }
//             cout << mid << endl;
//         }  
//     }
// }

int main()
{
    int n;
    cin >> n;
    vector<int> arr(1, 0);
    for(int i=1;i<=n;i++){
        int x; cin >> x;
        arr.insert(upper_bound(arr.begin(), arr.end(), x), x);
        if(i%2 == 1)
            cout << arr[(i+1)/2] << endl;
    }
}                               