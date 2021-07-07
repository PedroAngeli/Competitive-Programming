#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define debug(...) cout << " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] " << endl

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
  vi perm(n+1);
  vi used(n+1,0);

  for(int i=1;i<=n;i++)
    cin >> perm[i],used[perm[i]] = 1;

  vi not_used;
  for(int i=1;i<=n;i++)
    if(!used[i])
      not_used.pb(i);
  
  while(true){
    random_shuffle(all(not_used));
    int j = 0;
    
    for(int i=1;i<=n;i++){
    if(perm[i] != 0)
      continue;
      if(i == not_used[j])
        break;
      j++;
    }
    if(j == sz(not_used)){
      j = 0;
      for(int i=1;i<=n;i++){
      if(perm[i] != 0)
        continue;
        perm[i] = not_used[j];
        j++;
      }
      break;
    } 
  }
  

  for(int i=1;i<=n;i++)
    cout << perm[i] << " ";
  cout << endl;
  return 0;
}