#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
 
vector <long long> c;
vector <string> strs;
int n;
const long long INF = 1e18;
long long dp[100005][2];
 
long long solve(int i, int op, string ant){
  if(i == n-1)
    return 0;

  string next = strs[i+1];
  string cur = strs[i];
  string reversedCur = strs[i];
  reverse(reversedCur.begin(),reversedCur.end());
  string resversedNext = strs[i+1];
  reverse(resversedNext.begin(),resversedNext.end());
 
  if(dp[i][op] != -1)
    return dp[i][op];
 
  if(op == 1){
    long long a = INF, b = INF;
 
     if(reversedCur <= next && reversedCur >= ant)
      a = solve(i+1, 0,reversedCur);
     if(reversedCur <= resversedNext && reversedCur >= ant)
      b = c[i+1] + solve(i+1,1,reversedCur);
 
      return dp[i][op] = min(a,b);
  }else{
    long long a = INF, b = INF, d = INF, e = INF;
    if(cur <= next && cur >= ant)
      a = solve(i+1,0,cur);

    if(cur <= resversedNext && cur >= ant)
     b = c[i+1] + solve(i+1,1,cur);

    if(reversedCur <= next && reversedCur >= ant)
     d = c[i] + solve(i+1,0,reversedCur);

    if(reversedCur <= resversedNext && reversedCur >= ant)
     e = c[i] + c[i+1] + solve(i+1,1,reversedCur);

    return dp[i][op] = min({a,b,d,e});
  }
}
 
int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
 
  cin >> n;
  c.resize(n);
  strs.resize(n);
 
  for(int i=0;i<n;i++)
    cin >> c[i];
 
  for(int i=0;i<n;i++)
    cin >> strs[i];
 
  memset(dp,-1,sizeof dp);
 
  long long ans = solve(0,0,"");
 
  if(ans == INF)
    cout << -1 << endl;
  else
    cout << ans << endl;

  return 0;
}