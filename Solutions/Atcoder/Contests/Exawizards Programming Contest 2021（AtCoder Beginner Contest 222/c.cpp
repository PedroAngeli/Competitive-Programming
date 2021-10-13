#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

using ld = long double;
using ll = long long;

#define endl '\n'
#define f first
#define s second
#define ub  upper_bound
#define lb  lower_bound
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
template <class T>
	using ord_set = tree<T, null_type, less<T>, rb_tree_tag,
	tree_order_statistics_node_update>;
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
const int nax = 105;
char mat[nax][nax];
int n, m;

int result(char c1, char c2){
  for(int i=1;i<=2;i++){
    if(c1 == 'G' and c2 == 'C')
      return i;
    if(c1 == 'C' and c2 == 'P')
      return i;
    if(c1 == 'P' and c2 == 'G')
      return i;
    swap(c1, c2);
  }
  return 0;
}

int main(){
  fastio;

  cin >> n >> m;
  for(int i=1;i<=2*n;i++)
    for(int j=1;j<=m;j++)
      cin >> mat[i][j];

  vector <pair <int,int> > vet;
  for(int i=1;i<=2*n;i++)
    vet.push_back({0, i});

  for(int r=1;r<=m;r++){
    vector <pair <int,int> > new_vet;
    for(int i=0;i<sz(vet)-1;i+=2){
      auto p1 = vet[i];
      auto p2 = vet[i+1];
      int res = result(mat[p1.s][r], mat[p2.s][r]);
      if(res == 1)
        p1.f++;
      if(res == 2)
        p2.f++;
      new_vet.push_back(p1);
      new_vet.push_back(p2);
    }

    sort(all(new_vet), [&](auto p1, auto p2){
      return (p1.f > p2.f) or (p1.f == p2.f and p1.s < p2.s);
    });

    vet = new_vet;
  }

  for(auto p:vet){
    cout << p.s << endl;
  }

  return 0;
}