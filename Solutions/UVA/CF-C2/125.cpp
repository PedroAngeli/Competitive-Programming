#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'

int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL); 
 
  int n;
  int test = 0;
  while(cin >> n){
    vector <vector <long long> > adj(30,vector <long long>(30,0));
    int mx = 0;
    int N = n;
    while(N--){
      int u,v;
      cin >> u >> v;
      adj[u][v] = 1;
      mx = max({mx,u,v});
    }

    mx++;

    for(int k=0;k<mx;k++)
      for(int i=0;i<mx;i++)
        for(int j=0;j<mx;j++)
          adj[i][j] += (adj[i][k] * adj[k][j]);
        
    for(int k=0;k<mx;k++){
      if(adj[k][k]){
        for(int i=0;i<mx;i++)
          for(int j=0;j<mx;j++)
            if(adj[i][k] && adj[k][j])
              adj[i][j] = -1;
      }
    }
      
    cout << "matrix for city " << test++ << endl;

    for(int i=0;i<mx;i++){
      for(int j=0;j<mx;j++){
        cout << adj[i][j];
        if(j == mx-1)
          cout << endl;
        else
          cout << " ";
      }
    }
  }

  return 0;
}