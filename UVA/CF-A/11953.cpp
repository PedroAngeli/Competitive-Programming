#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int n;
char mat[105][105];

bool valid(int i,int j){
  return i>=0 && i < n && j >= 0 && j < n && (mat[i][j] == 'x' || mat[i][j] == '@');
}

void solve(int i, int j){
  mat[i][j] = 0;

  if(valid(i-1,j))
    solve(i-1,j);

  if(valid(i+1,j))
    solve(i+1,j);

  if(valid(i,j+1))
    solve(i,j+1);

  if(valid(i,j-1))
    solve(i,j-1);
}

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int t;

  cin >> t;
  int ncase = 1;
  while(t--){
    cin >> n;

    for(int i=0;i<n;i++)
      for(int j=0;j<n;j++)
        cin >> mat[i][j];

    int ans = 0;

    for(int i=0;i<n;i++)
      for(int j=0;j<n;j++)
        if(mat[i][j] == 'x')
          solve(i,j),ans++;

    cout << "Case " << ncase++ << ": " << ans << endl;
  }
  

  return 0; 
}