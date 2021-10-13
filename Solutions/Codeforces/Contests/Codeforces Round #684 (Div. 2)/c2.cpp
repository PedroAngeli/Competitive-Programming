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

int mat[105][105];
int n,m;
struct Answer{
  int x1,y1,x2,y2,x3,y3;
  Answer(){}
  Answer(int x1, int y1, int x2, int y2, int x3, int y3):
  x1(x1),y1(y1),x2(x2),y2(y2),x3(x3),y3(y3){}
};

vector <Answer> ans;

void apply_op(int op, int& a0, int& a1, int& a2, int& a3){
  if(op & (1 << 0)) a0 ^= 1;
  if(op & (1 << 1)) a1 ^= 1;
  if(op & (1 << 2)) a2 ^= 1;
  if(op & (1 << 3)) a3 ^= 1;
}

void add_to_ans(int op,int i, int j){
  vpii tmp;

  if(op & (1 << 0)) tmp.pb({i,j});
  if(op & (1 << 1)) tmp.pb({i, j+1});
  if(op & (1 << 2)) tmp.pb({i+1, j});
  if(op & (1 << 3)) tmp.pb({i+1, j+1});

  Answer a(tmp[0].f, tmp[0].s, tmp[1].f, tmp[1].s, tmp[2].f, tmp[2].s);
  ans.pb(a);
}

void fix(int i,int j){
  vi op = {7, 11, 13, 14};

  for(int mask=0;mask<16;mask++){
    int a0 = mat[i][j];
    int a1 = mat[i][j+1];
    int a2 = mat[i+1][j];
    int a3 = mat[i+1][j+1];

    for(int k=0;k<4;k++) 
      if(mask & (1 << k)) 
        apply_op(op[k], a0, a1, a2, a3);

    int sum = (!a0 + !a1 + !a2 + !a3);
    if(sum == 4)
      for(int k=0;k<4;k++) 
          if(mask & (1 << k)) 
            add_to_ans(op[k], i, j);
  }
}

int main(){
  fastio;

  int t = 1;
  cin >> t;
  while(t--){
    cin >> n >> m;
    ans.clear();
    for(int i=0;i<n;i++){
      string a;
      cin >> a;
      for(int j=0;j<m;j++) mat[i][j] = a[j] - '0';
    }

    if(n%2){
      for(int i=0;i<m;i++)
        if(mat[n-1][i]){
          mat[n-1][i] ^= 1;
          mat[n-2][i] ^= 1;
          int ni = (i == m-1) ? (i - 1) : (i + 1);
          mat[n-2][ni] ^= 1;
          Answer a(n-1,i,n-2,i,n-2,ni);
          ans.pb(a);
        }
        n--;
    }

    if(m%2){
      for(int i=0;i<n;i++)
        if(mat[i][m-1]){
          mat[i][m-1] ^= 1;
          mat[i][m-2] ^= 1;
          int ni = (i == n-1) ? (i - 1) : (i + 1);
          mat[ni][m-2] ^= 1;
          Answer a(i,m-1,i,m-2,ni,m-2);
          ans.pb(a);
        }
        m--;
    }

    for(int i=0;i<n;i+=2)
      for(int j=0;j<m;j+=2)
        fix(i,j);
      
    cout << sz(ans) << endl;
    for(auto a:ans){
      cout << a.x1 + 1 << " " << a.y1 + 1 << " ";
      cout << a.x2 + 1<< " " << a.y2 + 1 << " ";
      cout << a.x3 + 1 << " " << a.y3 + 1 << endl;
    }
  }
  return 0;
}