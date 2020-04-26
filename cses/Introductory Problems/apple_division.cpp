#include <bits/stdc++.h>

using namespace std;

const int nax = 20;

long long vet[nax];
int n;

long long solve(int i,int *dp){

  if(i == n){
    long long sum1 = 0, sum2 = 0;

    for(int i=0;i<n;i++){
      if(dp[i] == 1){
        sum1+=vet[i];
      }else{
        sum2+=vet[i];
      }
    }

    return abs(sum1 - sum2);
  }

  dp[i] = 1;
  long long a = solve(i+1,dp);
  dp[i] = 2;
  long long b = solve(i+1,dp);

  return min(a,b);
}

int main(){

  cin >> n;

  for(int i=0;i<n;i++)
    cin >> vet[i];

  int dp[n] = {0};

  cout << solve(0,dp) << endl;
  return 0;
}