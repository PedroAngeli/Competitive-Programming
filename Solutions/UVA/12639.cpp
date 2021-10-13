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

int pieces[7][6];
int esq[7][6]; //esq[i][j] - esq do num j na peça i
int dir[7][6]; //analogo
bool vis[7];
bool can;

//u - peça
//i - indice do num
void dfs(int u, int i,int l = -1, int r = -1){

  for(int p=0;p<7;p++){
    if(vis[p]) continue;
    int cur = pieces[u][i];
    if(i == 0){
      vis[p] = true;
      dfs(u, i+1, dir[p][cur], esq[p][cur]);
      vis[p] = false;
    }else if(dir[p][cur] == r){
      if(i == 5 and l == esq[p][cur]){
        can = true;
        break;
      }
      vis[p] = true;
      dfs(u, i+1, l, esq[p][cur]);
      vis[p] = false;
    }
  }
}

int mod(int a, int b){
  return (a + b)%b;
}

int main(){
  fastio;

  while(cin >> pieces[0][0]){
    can = false;
    for(int i=0;i<7;i++)
      for(int j=0;j<6;j++)
        if(i or j){
          cin >> pieces[i][j];
          pieces[i][j]--;
        }
    pieces[0][0]--;
    for(int i=0;i<7;i++)
      for(int j=0;j<6;j++){
        esq[i][pieces[i][j]] = pieces[i][mod(j-1, 6)];
        dir[i][pieces[i][j]] = pieces[i][mod(j+1, 6)];
      }

    for(int i=0;i<7;i++){ //escolho a peça do meio
      vis[i] = true;
      dfs(i, 0);
      vis[i] = false;
    }
    
    if(can)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  
  
  return 0;
}