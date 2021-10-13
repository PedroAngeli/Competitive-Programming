#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int n,m;
  cin >> n >> m;
  vector <pair <int,int> > rel(m);

  for(int i=0;i<m;i++){
    cin >> rel[i].first >> rel[i].second;
  }

  vector <pair <int,int> > ans[n+1];

  for(int i=1;i<=n;i++)
    ans[i].push_back({i,i});
  
  int j = n+1;
  for(int i=0;i<m;i++){
    int c1 = rel[i].first;
    int c2 = rel[i].second;
    ans[c1].push_back({c1,j});
    ans[c2].push_back({c2,j});
    j++;
  }

  for(int i=1;i<=n;i++){
    int len = ans[i].size();
    cout << len << endl;
    for(int j=0;j<len;j++){
      cout << ans[i][j].first << " " << ans[i][j].second << endl;
    }
  }

  return 0;
}