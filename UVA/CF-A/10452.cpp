#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int n,m;
char mat[10][10];
int xi,yi,x2,y2;

bool valid(int i, int j){
  return (i >= 0 && i < n && j>=0 && j < m) && (mat[i][j] == 'I' 
  || mat[i][j] == 'E' || mat[i][j] == 'H' || mat[i][j] == 'O' 
  || mat[i][j] == 'V' || mat[i][j] == 'A' || mat[i][j] == '#');
}

void solve(int i,int j){
  mat[i][j] = 0;
  if(valid(i-1,j)){
    if(mat[i-1][j] == '#')
    cout << "forth" << endl;
    else
    cout << "forth ";

    solve(i-1,j);
    return;
  }

  if(valid(i,j+1)){
    if(mat[i][j+1] == '#')
    cout << "right" << endl;
    else
    cout << "right ";
    solve(i,j+1);
    return;
  }

  if(valid(i,j-1)){
    if(mat[i][j-1] == '#')
    cout << "left" << endl;
    else
    cout << "left ";
    solve(i,j-1);
  }
}

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  
  int t;

  cin >> t;

  while(t--){
    cin >> n >> m;

    for(int i=0;i<n;i++)
      for(int j=0;j<m;j++){
        cin >> mat[i][j];
        if(mat[i][j] == '@')
          xi = i,yi = j;

        if(mat[i][j] == '#')
          x2 = i,y2 = j;
      }
        
    solve(xi,yi);

  }

  return 0; 
}