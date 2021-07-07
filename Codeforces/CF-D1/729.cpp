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

  ll n,a,b,k;
  cin >> n >> a >> b >> k;
  a--;

  string str;
  cin >> str;

  int i = 0;
  int ans = 0;
  vi positions;
  int left = 0;

  while(i < n){
    int j = i;
    while(j < n && str[j] == '1')
      j++;
    i = j;
    while(j < n && str[j] == '0')
      j++;
    int cnt = (j-i)/b;
    
    if(left > a){
      int pos = i;
      while(cnt--)
      ans++,pos+=b,positions.push_back(pos);
    }else{
      left += cnt;
      if(left > a){
        cnt = left-a;
        int pos = i;
        while(cnt--)
        ans++,pos+=b,positions.push_back(pos);
      }
    }
    
    i = j;
  }

  
  cout << ans << endl;
  assert(ans == positions.size());
  for(int x:positions)
    cout << x << " ";
  cout << endl;      

 
  

  return 0;
}