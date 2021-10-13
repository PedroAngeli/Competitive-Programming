#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'

int mat[105][105];
int n,m;

bool isEqual(int row){
  for(int i=0;i<row/2;i++){
    for(int j=0;j<m;j++){
      if(mat[i][j] != mat[row-1-i][j])
        return false;
    }
  }

  return true;
}

int solve(int row){
  if(row % 2 == 1)
    return row;

  if(isEqual(row)){
    return min(row/2,solve(row/2));
  }

  return row;
}

int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
 
  cin >>  n >> m;

  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
      cin >> mat[i][j];

  cout << solve(n) << endl;
  return 0;
}