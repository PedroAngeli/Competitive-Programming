#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

const int nax = 50;
set <char> colors;
char mat[nax][nax];
bool visitado[nax][nax];
int n,m;

bool valid(int i,int j,char c){
  return i >= 0 && i < n && j >=0 && j < m && !visitado[i][j] && mat[i][j] == c;
}

bool cycle(int i,int j,char c, int x,int y){
  return i >= 0 && i < n && j >=0 && j < m && visitado[i][j] && mat[i][j] == c
  && (i*m + j != x*m + y);
}

bool solve(int i, int j, char c,int pi,int pj){
  visitado[i][j] = true;

  bool a = false,b = false, e= false, d= false;

  if(valid(i+1,j,c))
    a = solve(i+1,j,c,i,j);  
  else if(cycle(i+1,j,c,pi,pj))
    return true;

   if(valid(i-1,j,c))
    b = solve(i-1,j,c,i,j);  
  else if(cycle(i-1,j,c,pi,pj))
    return true;

     if(valid(i,j-1,c))
    e = solve(i,j-1,c,i,j);  
  else if(cycle(i,j-1,c,pi,pj))
    return true;


     if(valid(i,j+1,c))
    d = solve(i,j+1,c,i,j);  
  else if(cycle(i,j+1,c,pi,pj))
    return true;

  return a || b || e || d;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;

  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++){
      cin >> mat[i][j];
      colors.insert(mat[i][j]);
    }
  
  bool ans = false;

  for(auto it = colors.begin();it != colors.end();it++){
    for(int i=0;i<n;i++)
      for(int j=0;j<m;j++)
        if(valid(i,j,*it)){
          bool temp = solve(i,j,*it,-1,-1);
          ans = ans || temp;
        }
  }

  if(ans)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;

  return 0;
}