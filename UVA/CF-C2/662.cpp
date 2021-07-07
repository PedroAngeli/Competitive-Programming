#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define f first
#define s second
 
using ld = long double;
using ll = long long;
using ii = pair <int,int>;
using pll = pair <ll,ll>;
using vi = vector <int>;
using vll = vector <ll>;
using vii = vector <ii>;
using vpll = vector<pll>;

vi d;
vector <vi> dist;
vector <vi> dp;
vector <vi> ini;
const int INF = 1e9 + 7;

void print(int n,int k){
  if(n == 0 || k == 0)
    return;
  print(ini[n][k]-1,k-1);

  cout << "Depot " << k << " at restaurant " << (ini[n][k]+n)/2 << " serves restaurant";

  if(ini[n][k] == n) 
    cout << " " << n << endl;
  else
    cout << "s " << ini[n][k] << " to " << n << endl;
}
int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  int n,k;
  
  int ncase = 1;

  while(cin >> n >> k){
    if(n == 0 && k == 0)
      break;

    d.resize(n+1);
    dist.assign(n+1,vi(n+1,0));
    dp.assign(n+1,vi(k+1,INF));
    ini.assign(n+1,vi(n+1,0));

    for(int i=1;i<=n;i++)
        cin >> d[i];
    
    for(int i=1;i<=n;i++)
      for(int j=i+1;j<=n;j++){
        int mid = (i+j)/2;
        for(int l=i;l<=j;l++)
          dist[i][j] += abs(d[l]-d[mid]);
      }


    for(int i=0;i<=k;i++)
      dp[0][i] = 0;
   
    for(int i=1;i<=n;i++){
      for(int j=1;j<=k;j++){
        for(int l=1;l<=i;l++){
          int val = dp[l-1][j-1]+dist[l][i];
          if(val < dp[i][j]){
            dp[i][j] = val;
            ini[i][j] = l;
          }
        }
      }
    }

    cout << "Chain " << ncase++ << endl;
    print(n,k);
    cout << "Total distance sum = " << dp[n][k] << endl;
    cout << endl;
  }

  return 0;
}