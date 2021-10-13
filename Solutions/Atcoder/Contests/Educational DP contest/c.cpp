#include <bits/stdc++.h>

using namespace std;


int main(){

  int N;

  cin >> N;

  vector < vector <int> > points(N);
  vector < vector <int> > dp(N);

  for(int i=0;i<N;i++){
    points[i].resize(3);
    dp[i].resize(3);
    cin >> points[i][0] >> points[i][1] >> points[i][2];
  }

  dp[0] = points[0];

  for(int i=1;i<N;i++){
    for(int j=0;j<3;j++){
      dp[i][j] =  points[i][j] + max(dp[i-1][(j+1)%3],dp[i-1][(j+2)%3]);
    }
  }

  cout << max(dp[N-1][0],max(dp[N-1][1],dp[N-1][2])) << endl;

  return 0;
}