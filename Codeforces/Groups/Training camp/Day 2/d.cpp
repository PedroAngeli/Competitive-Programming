#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'

double dp[105][105][105];
 
int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
 
  int r,s,p;
  cin >> r >> s >> p;
  dp[r][s][p] = 1;

  for(int i=r;i>=0;i--){
    for(int j=s;j>=0;j--){
      for(int k=p;k>=0;k--){
      if(i == 0 && j == 0)
        continue;
      if(i == 0 && k == 0)
        continue;
      if(j == 0 && k == 0)
        continue;

       int rs = i*j;
       int rp = i*k;
       int sp = j*k;
       double sum = rs+rp+sp;
       double prs = rs/sum;
       double prp = rp/sum;
       double psp = sp/sum;

      if(i > 0)
        dp[i-1][j][k] += prp*dp[i][j][k];
      if(j > 0)
        dp[i][j-1][k] += prs*dp[i][j][k];
      if(k > 0)
        dp[i][j][k-1] += psp*dp[i][j][k];
      }
    }
  }

  double rock = 0,scissors = 0,paper = 0;

  for(int i=1;i<=r;i++)
    rock += dp[i][0][0];
  
  for(int i=1;i<=s;i++)
    scissors += dp[0][i][0];
  
  for(int i=1;i<=p;i++)
    paper += dp[0][0][i];

  cout << fixed << setprecision(15) << rock << " " << scissors << " " << paper << endl;
  

  return 0;
}