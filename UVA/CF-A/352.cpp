#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int n;
int mat[30][30];

bool valid(int i,int j){
  return i>=0 && i < n && j>=0 && j < n && mat[i][j] == 1;
}

int solve(int i,int j){
  mat[i][j] = 0;
  int ans = 0;

  if(valid(i+1,j))
    ans += 1 + solve(i+1,j);

  if(valid(i-1,j))
    ans += 1 + solve(i-1,j);

    if(valid(i,j+1))
    ans += 1 + solve(i,j+1);

    if(valid(i,j-1))
    ans += 1 + solve(i,j-1);

    if(valid(i-1,j-1))
    ans += 1 + solve(i-1,j-1);

    if(valid(i-1,j+1))
    ans += 1 + solve(i-1,j+1);

    if(valid(i+1,j-1))
    ans += 1 + solve(i+1,j-1);

    if(valid(i+1,j+1))
    ans += 1 + solve(i+1,j+1);

  return ans;
}

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int image = 1;

  while(cin >> n){
    char c;

    for(int i=0;i<n;i++)
      for(int j=0;j<n;j++){
        cin >> c;
        mat[i][j] = c-'0';
      }

    int ans = 0;

    for(int i=0;i<n;i++)
      for(int j=0;j<n;j++)
        if(mat[i][j] == 1)
          solve(i,j),ans++;

    cout << "Image number " << image++ << " contains " << ans << " war eagles." << endl;

  }


  return 0; 
}