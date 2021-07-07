#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'

int n,k,l;
int dp[200][300];
bool vis[300][300];
vector <int> d;
vector <int> p;

int solve(int pos,int t){
  if(vis[pos][t])
    return 0;
  vis[pos][t]= true;
  
  if(pos == n+1)
    return 1;

  int add = p[t%(p.size())];

  if(d[pos]+add > l)
    return 0;

  int ret = solve(pos+1,t+1) || solve(pos,t+1);

  return ret;  
}

int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
 
  int t = 1;
  cin >> t;

  while(t--){
    cin >> n >> k >> l;
    d.resize(n+1);
    for(int i=1;i<=n;i++)
      cin >> d[i];

    p.clear();
    for(int i=0;i<=k;i++)
      p.push_back(i);
    for(int i=k-1;i>=1;i--)
      p.push_back(i);
    
    int ans = 0;
    memset(dp,-1,sizeof dp);
    for(int i=0;i<2*k;i++){
      memset(vis,false,sizeof vis);
      ans = (ans || solve(1,i+1));
    }

    if(ans)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
    
  return 0;
}