#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int n,m,k;
  cin >> n >> m >> k;

  vector <vector <int> > grid(n,vector<int>(m));

  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
      cin >> grid[i][j];

  vector <int> line(n);
  vector <int> column(m);

  for(int i=0;i<n;i++)  
    line[i] = i;

  for(int i=0;i<m;i++)
    column[i] = i;

  while(k--){
    char c;
    int x,y;
    cin >> c >> x >> y;
    x--,y--;

    if(c == 'g')
      cout << grid[line[x]][column[y]] << endl;
    else if(c == 'r')
      swap(line[x],line[y]);
    else 
      swap(column[x],column[y]);
  }

  return 0;
}