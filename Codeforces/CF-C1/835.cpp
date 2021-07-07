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

int mat[11][101][101];
int pref[11][101][101];

int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int n,q,c;
  cin >> n >> q >> c;

  for(int i=0;i<n;i++){
    int x,y,s;
    cin >> x >> y >> s;
    mat[s][x][y]++;
  }

  for(int k=0;k<=10;k++)
    for(int i=1;i<=100;i++){
       for(int j=1;j<=100;j++)
          pref[k][i][j] = pref[k][i][j-1] + mat[k][i][j];
       for(int j=1;j<=100;j++)  
          pref[k][i][j] += pref[k][i-1][j];
    }
   
  while(q--){
    int t,x1,y1,x2,y2;
    cin >> t >> x1 >> y1 >> x2 >> y2;
    int ans = 0;

    for(int i=0;i<=10;i++){
      int newS = (i+t)%(c+1);
      int sum = pref[i][x2][y2] - pref[i][x1-1][y2] - pref[i][x2][y1-1] + pref[i][x1-1][y1-1];
      ans += newS*sum;
    }

    cout << ans << endl;
  }     
  
  return 0;
}