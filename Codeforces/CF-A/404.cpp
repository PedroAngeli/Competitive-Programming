#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;

  cin >> n;
  char mat[n][n];
  bool ans = true;

  for(int i=0;i<n;i++)
  for(int j=0;j<n;j++)
    cin >> mat[i][j];

  char d = mat[0][0];
  char c = mat[0][1];

  for(int i=0;i<n;i++)
    if(mat[i][i] != d || mat[i][n-i-1] != d)
      ans = false;

  for(int i=0;i<n;i++)
  for(int j=0;j<n;j++)
    if(i != j && j != n-i-1 && (mat[i][j] != c || mat[i][j] == d)){
      ans = false;
    }
      

  if(ans)
    cout << "YES" << endl;
  else 
    cout << "NO" << endl;


  
  return 0;
}