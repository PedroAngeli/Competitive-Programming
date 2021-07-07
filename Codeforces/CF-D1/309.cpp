#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define f first
#define s second
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using ld = long double;
using ll = long long;
using pii = pair <int,int>;
using pll = pair <ll,ll>;
using vi = vector <int>;
using vll = vector <ll>;
using vpii = vector <pii>;
using vpll = vector<pll>;
using vs = vector <string>;


int main(){
  fastio;
  
  int n,m;
  cin >> n >> m;
  vi a(n);
  for(int i=0;i<n;i++)
    cin >> a[i];
  sort(a.begin(),a.end());
  
  vi b(30,0);

  for(int i=0;i<m;i++){
    int x;
    cin >> x;
    b[x]++;
  }

  int ans = 0;

  for(int i=0;i<n && b[0];i++){
    if(a[i] % 2 == 1)
      a[i]--,b[0]--,ans++;
  }

  int i = 0, j = 0;

  while(i < n && j < 30){
    if(!b[j]){
      j++;
      continue;
    }

    if(a[i] >= (1 << j))
      a[i] -= (1 << j),b[j]--,ans++;
    else
      i++;
  }

  cout << ans << endl;
  

  return 0;
}