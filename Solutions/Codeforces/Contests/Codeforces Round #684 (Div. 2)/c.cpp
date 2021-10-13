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

vector <vpii> ans;
char mat[105][105];


void tres_um(int i,int j){
  vpii cur;
  for(int k=i;k<i+2;k++)
    for(int l=j;l<j+2;l++)
      if(mat[k][l] == '1'){
        mat[k][l] = '0';
        cur.pb({k,l});
      }
  ans.pb(cur); 
}

void dois_um(int i,int j){
  int q = 1;
  vpii cur;
  for(int k=i;k<i+2;k++)
    for(int l=j;l<j+2;l++){
      if(mat[k][l] == '0'){
        mat[k][l] = '1';
        cur.pb({k,l});
      }else if(q){
        q--;
        mat[k][l] = '0';
        cur.pb({k,l});
      } 
    }
    ans.pb(cur);
    tres_um(i,j);
}

void um_um(int i,int j){
  int q = 2;
  vpii cur;

  for(int k=i;k<i+2;k++)
    for(int l=j;l<j+2;l++){
      if(mat[k][l] == '0' and q){
        q--;
        mat[k][l] = '1';
        cur.pb({k,l});
      }else if(mat[k][l] == '1'){ 
        mat[k][l] = '0';
        cur.pb({k,l});
      }
    }
    ans.pb(cur);
  dois_um(i, j);
}

void quatro_um(int i,int j){
  int q = 3;
    vpii cur;

   for(int k=i;k<i+2;k++)
    for(int l=j;l<j+2;l++)
      if(mat[k][l] == '1' and q){
        q--;
        mat[k][l] = '0';
        cur.pb({k,l});
      } 
  ans.pb(cur);
  um_um(i,j);
}

void solve(int i,int j){
  int q0 = 0, q1 = 0;
  for(int k=i;k<i+2;k++)
    for(int l=j;l<j+2;l++)
      if(mat[k][l] == '1') q1++;
      else q0++;

  if(q1 == 0) return;

  if(q1 == 3) tres_um(i, j);    
  else if(q1 == 2) dois_um(i,j);
  else if(q1 == 1) um_um(i,j);
  else if(q1 == 4) quatro_um(i,j);
}

int main(){
  fastio;

  int t = 1;
  cin >> t;
  while(t--){
    int n,m;
    cin >> n >> m;
    for(int i=0;i<n;i++)
      for(int j=0;j<m;j++)
        cin >> mat[i][j];
    ans.clear();

    for(int i=0;i<n;i++)
      for(int j=0;j<m;j++){
        if(i + 2 <= n and j + 2 <= m)
          solve(i, j);
      }
      int cnt = 0;
      for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
          cnt += (mat[i][j] == '0');
      }
      assert(cnt == (n*m));

      cout << sz(ans) << endl;
      for(auto vet:ans){
        int i = 0;
        for(auto p:vet){
          if(i) cout << " ";
          cout << p.f + 1 << " " << p.s + 1;
          i++;
        }
        cout << endl;
      }
  }
  return 0;
}