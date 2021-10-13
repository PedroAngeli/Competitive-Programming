#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 5;

int main(){

  int N, K;

  cin >> N >> K;

  int h[N];
  vector <int> dp(N,INF); //guarda o menor custo para chegar na pedra i

  for(int i=0;i<N;i++)
    cin >> h[i];

  dp[0] = 0;

   for(int i=0;i<N;i++){
     for(int j=i+1;j<=i+K;j++){
       if(j < N){
         dp[j] = min(dp[j],dp[i] + abs(h[i]-h[j]));
       }
     }
   }

   cout << dp[N-1] << endl;

  return 0;
}