#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

const int nax = 1e2;
int b[nax][nax];
int a[nax][nax];
int n,m;


void fillA(int i,int j){

  for(int k = 0;k<m;k++)
    a[i][k] = 0;
  for(int k=0;k<n;k++)
    a[k][j] = 0;
}

bool checkA(int i,int j){

  for(int k = 0;k<m;k++)
    if(a[i][k] == 1)
      return true;

  for(int k=0;k<n;k++)
    if(a[k][j] == 1)
      return true;

  return false;
}

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);


  cin >> n >> m;

  
  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
    cin >> b[i][j];

  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
      a[i][j] = 1;

  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
      if(b[i][j] == 0)
      fillA(i,j);

  bool ans = true;

   for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
      if(b[i][j] == 1)
        ans = ans && checkA(i,j);

  if(ans){
    cout << "YES" << endl;
     for(int i=0;i<n;i++){
    for(int j=0;j<m;j++)
      cout << a[i][j] << " ";
      cout << endl;
     }
  }else{
    cout << "NO" << endl;
  }

  return 0;
}