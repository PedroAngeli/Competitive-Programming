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

  int n;
  cin >> n;
  vi l(n);

  int ans = 0;
  for(int i=0;i<n;i++)
    cin >> l[i];
  
  sort(l.begin(),l.end());

  for(int i=0;i<n;i++)
    for(int j=i+1;j<n;j++)
      for(int k=j+1;k<n;k++){
        if(l[i]==l[j] || l[i]==l[k] || l[k]==l[j])
          continue;
        if(l[i]+l[j]>l[k])
          ans++;
      }
        

  cout << ans << endl;
  return 0;
}