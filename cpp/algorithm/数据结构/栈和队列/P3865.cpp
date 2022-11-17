#include <bits/stdc++.h>
using namespace std;

template <typename T>
class SparseTable {
  using func_type = function<T(const T &, const T &)>;
  vector<vector<int>> ST;

  static int my_max(const int &t1, const int &t2) { return max(t1, t2); }

  func_type op;

 public:
  SparseTable(const vector<T> &v, func_type _func = default_func) {
    op = _func;
    int len = v.size(), l1 = ceil(log2(len)) + 1;
    ST.assign(len, VT(l1, 0));
    for (int i = 0; i < len; ++i) {
      ST[i][0] = v[i];
    }
    for (int j = 1; j < l1; ++j) {
      int pj = (1 << (j - 1));
      for (int i = 0; i + pj < len; ++i) {
        ST[i][j] = op(ST[i][j - 1], ST[i + (1 << (j - 1))][j - 1]);
      }
    }
  }

  T query(int l, int r) {
    int lt = r - l + 1;
    int q = ceil(log2(lt)) - 1;
    return op(ST[l][q], ST[r - (1 << q) + 1][q]);
  }
};

vector<vector<int>> ST;
static int my_max(const int &t1, const int &t2) { return max(t1, t2); }
int query(int l, int r){
    int j = r-l+1;
    int s = ceil(log2(r-l+1));  
    return my_max(ST[l][l+pow(2, s)-1], ST[r-pow(2, s) + 1][r]);
}
int SparseTable(const vector<int> &v)
{
    ST.assign(v.size(), vector<ceil(log2(v.size()))+1, 0>);
    for(int i=0;i<v.size();i++)
        ST[i][0] = v[i];
    for(int j=1;j)
}
int main()
{
    int n,m;
    vector<int> v;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        int x; cin >> x;
        v.push_back(x);
    }
}