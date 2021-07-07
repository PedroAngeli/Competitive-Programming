#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int n,m,x;
vector <int> c;
vector <vector<int> > p;
int ans;

void solve(int i, int total, int level[]){
  if(i == n){
    int cnt = 0;

    for(int j=0;j<m;j++){
      if(level[j] >= x)
        cnt++; 
    }

    if(cnt == m)
      ans = min(ans,total);
    return;
  }

  solve(i+1,total,level);

  for(int j=0;j<m;j++)
    level[j]+=p[i][j];

  solve(i+1,total+c[i],level);

  for(int j=0;j<m;j++)
    level[j]-=p[i][j];
}

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  
  cin >> n >> m >> x;
  c.resize(n);
  p.assign(n,vector<int>(m));

  for(int i=0;i<n;i++){
    cin >> c[i];
    for(int j=0;j<m;j++)
      cin >> p[i][j];
  }

  int level[m] = {0};
  ans = 1e9 + 7;
  solve(0,0,level);

  if(ans == 1e9 + 7)
    cout << -1 << endl;
  else
  cout << ans << endl;

  

  return 0;
}