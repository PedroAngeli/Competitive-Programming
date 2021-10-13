#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'

int n,h;
vector <int> t;
vector <int> f;
vector <int> d;
int dp[30][200][200];
vector <int> timeSpent;

int solve(int i,int left,int stayed){
  if(i == n)
    return 0;

  int& state = dp[i][left][stayed];
  if(state != -1)
    return state;

  int a = 0, b = 0;

  if(left > 0){
    int fish = max(0,f[i] - d[i]*stayed);
    a = solve(i,left-1,stayed+1) + fish;
  }
  if(left >= t[i]){
    b = solve(i+1,left-t[i],0);
  }

  return state= max(a,b);
}

void solve2(int i,int left, int stayed){
  if(i == n)
    return;
  int a = -1 , b = -1;

  if(left > 0){
    int fish = max(0,f[i] - d[i]*stayed);
    a = dp[i][left-1][stayed+1] + fish;
  }
  if(left >= t[i]){
    b = dp[i+1][left-t[i]][0];
  }

  int mx = dp[i][left][stayed];

  if(mx == a){
    timeSpent[i] += 5;
    solve2(i,left-1,stayed+1);
  }else if(b != -1){
    solve2(i+1,left-t[i],0);
  }
}

int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL); 
  int ncase = 0;

  while(cin >> n && n){
    if(ncase)
      cout << endl;
    ncase++;
    t.assign(n,0);
    f.assign(n,0);
    d.assign(n,0);
    timeSpent.assign(n,0);

    cin >> h;

    for(int i=0;i<n;i++)
      cin >> f[i];

    for(int i=0;i<n;i++)
      cin >> d[i];

    for(int i=0;i<n-1;i++)
      cin >> t[i];

    memset(dp,-1,sizeof dp);

    int ans = solve(0,h*12,0);
    solve2(0,h*12,0);

    for(int i=0;i<n;i++){
      if(i == n-1)
        cout << timeSpent[i] << endl;
      else
        cout << timeSpent[i] << ", ";
    }

    cout << "Number of fish expected: " << ans << endl;
  }
  return 0;
}