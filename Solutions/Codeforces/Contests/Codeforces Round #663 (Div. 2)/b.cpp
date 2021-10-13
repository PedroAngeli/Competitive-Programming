#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define f first
#define s second
 
using ld = long double;
using ll = long long;
using ii = pair <int,int>;
using pll = pair <ll,ll>;
using vi = vector <int>;
using vll = vector <ll>;
using vii = vector <ii>;
using vpll = vector<pll>;


int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  
  int t = 1;
  cin >> t;
  while(t--){
    int n,m;
    cin >> n >> m;
    vector <string> grid(n);
    for(int i=0;i<n;i++)
      cin >> grid[i];

    int ans = 0;
    for(int i=0;i<m;i++)
      if(grid[n-1][i] == 'D')
        ans++;
    for(int i=0;i<n;i++)
      if(grid[i][m-1] == 'R')
        ans++;

    cout << ans << endl;
    
  }

  return 0;
}