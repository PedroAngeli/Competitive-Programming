#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define f first
#define s second
#define ub  upper_bound
#define lb  lower_bound
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define debug(...) cout << " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] " << endl

using ld = long double;
using ll = long long;
using pii = pair <int,int>;
using pll = pair <ll,ll>;
using vi = vector <int>;
using vll = vector <ll>;
using vpii = vector <pii>;
using vpll = vector<pll>;
using vs = vector <string>;

vi get_adv(int i,int j){
  j = 3-j;
  vi adv;
  int lx = 1,rx = 16;
  
  while(j--){
    int m =(lx+rx)/2;
    if(i <= m)
      rx = m;
    else
      lx = m+1;      
  }

  int m = (lx + rx)/2;
  if(i <= m)
    for(int a=m+1;a<=rx;a++)
      adv.pb(a);
  else
    for(int a=lx;a<=m;a++)
      adv.pb(a);

  return adv;
}

int main(){
  fastio;
  cout << fixed << setprecision(2);
  vs teams(17);
  for(int i=1;i<=16;i++)
    cin >> teams[i];

  vector <vi> prob(17,vi(17));
  for(int i=1;i<=16;i++)
    for(int j=1;j<=16;j++)
      cin >> prob[i][j];

  vector <vector <ld> > dp(17,vector <ld>(4,0));
  
  for(int i=1;i<=16;i++)
    if(i%2)
      dp[i][0] = (ld)prob[i][i+1]/100;
    else
      dp[i][0] = (ld)prob[i][i-1]/100;

  for(int j=1;j<=3;j++)
    for(int i=1;i<=16;i++){
      vi adv = get_adv(i,j);
      for(int x:adv)
        dp[i][j] += ((ld)prob[i][x]/100)*dp[x][j-1];
      dp[i][j] *= dp[i][j-1];
    }

  for(int i=1;i<=16;i++)
    cout << left << setw(10) << teams[i] << " p=" << 100*dp[i][3] <<  "%" << endl;

  
  return 0;
}