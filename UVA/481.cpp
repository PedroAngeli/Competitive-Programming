#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define f first
#define s second
#define ub  upper_bound
#define lb  lower_bound
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define fbo find_by_order 
#define ook order_of_key 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
cerr << "[" << name << " : " << arg1 << "]" << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
const char* comma = strchr(names + 1, ',');cerr << "[";
cerr.write(names, comma - names) << " : " << arg1<<"] | ";__f(comma+1, args...);
}

using ld = long double;
using ll = long long;
using pii = pair <int,int>;
using pll = pair <ll,ll>;
using vi = vector <int>;
using vll = vector <ll>;
using vpii = vector <pii>;
using vpll = vector<pll>;
using vs = vector <string>;

const int nax = 1e5 + 5;
int n;
int L[nax], L_id[nax], A[nax], parent[nax];

int main(){
  fastio;

  int x;

  while(cin >> A[n++]);

  int lis = 0, lis_end = 0;

  for(int i=0;i<n;i++){
    int pos = lb(L, L + lis, A[i]) - L;
    L[pos] = A[i];
    L_id[pos] = i;
    parent[i] = pos ? L_id[pos-1] : -1;
    if(pos + 1 >= lis){
      lis = pos + 1;
      lis_end = i;
    }
  }

  cout << lis << endl;
  cout << "-" << endl;
  
  int i = lis_end;
  stack <int> S;
  while(parent[i] >= 0){
    S.push(A[i]);
    i = parent[i];
  }

  cout << A[i] << endl;
  while(!S.empty()){
    cout << S.top() << endl;
    S.pop();
  }
  return 0;
}