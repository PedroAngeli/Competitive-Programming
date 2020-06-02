#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

const int nax = 1e2 + 5;
int total;
int n;
int vet[nax];
int dp[105][50005];

int solve(int i, int cur){

  if(i == n){
    int a = cur;
    int b = total-cur;
    
    return abs(a-b);
  }

  if(dp[i][cur] != -1){
   return dp[i][cur];
  }

  int l = solve(i+1,cur);
  int r = solve(i+1,cur+vet[i]);

  return dp[i][cur] = min(l,r);
}

int main(){
  
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  while(t--){
    cin >> n;
    total = 0;
  
    for(int i=0;i<n;i++)
      cin >> vet[i],total+=vet[i];

    memset(dp,-1,sizeof dp);

    int ans = solve(0,0);

    cout << ans << endl;
  }
  return 0;
}