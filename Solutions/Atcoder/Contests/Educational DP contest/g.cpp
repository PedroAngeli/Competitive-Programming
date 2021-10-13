#include <bits/stdc++.h>

using namespace std;

int N,M;
const int MAXN = 1e5 + 5;

vector <int> adj[MAXN];
bool visitado[MAXN];
int dp[MAXN];

int solve(int u){
  
  visitado[u] = true;

  int ans = 0;

  for(auto &ele: adj[u]){
    if(!visitado[ele]){
      ans = max(ans,solve(ele) + 1);
    }else{
      ans = max(ans, dp[ele] + 1);
    }
  }

  return dp[u] = ans;
}

int main(){
 cin >> N >> M;

 while(M--){
   int x,y;
   cin >> x >> y;
   adj[x].push_back(y);
 }
  
 int ans = 0;

 for(int i = 1;i<=N;i++){
   if(!visitado[i])
    ans = max(ans,solve(i));
 }

 cout << ans << endl;

}