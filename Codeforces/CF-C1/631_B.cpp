#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int n,m,k;

  cin >> n >> m >> k;
  pair <pair <int,int>, pair <int,int> > mat[n][m];
  pair <int,int> preans[n][m];

  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
      mat[i][j] = {{0,0},{0,0}}, preans[i][j] = {0,0};

  int op = 0;

  while(k--){
    int q,i,c;
    cin >> q >> i >> c;
    i--;
    if(q == 1){
      mat[i][0].first = {c,op++};
    }else{
      mat[0][i].second = {c,op++};
    }
  }

  for(int i=0;i<n;i++){
    pair <int,int> l = mat[i][0].first;
    if(l.first){
        for(int j=0;j<m;j++){
        pair <int,int> c = mat[i][j].second;
        if(!c.first || l.second > c.second)
          preans[i][j] = l;
        else
          preans[i][j] = c;
        }
    }
  }

  for(int i=0;i<m;i++){
   pair <int,int> c = mat[0][i].second;
   if(c.first){
     for(int j=0;j<n;j++){
       pair <int,int> l = preans[j][i];
       if(!l.first || c.second > l.second)
        preans[j][i] = c;
     }
   }
  }

  for(int i=0;i<n;i++){
     for(int j=0;j<m;j++)
      cout << preans[i][j].first << " ";
    cout << endl;
  }
   

    
  return 0;
}