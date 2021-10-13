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
  
  vi h(10001,0);
  int l,H,r;

  while(cin >> l >> H >> r){
    for(int i=l;i<r;i++)
      h[i] = max(h[i],H);
  }
 
  vi ans;
  int pos = 0;
  int cur = 0;
  while(pos < 10001){
    while(pos < 10001 && h[pos] == cur)
      pos++;
    if(pos >= 10001)
      break;
    ans.push_back(pos);
    ans.push_back(h[pos]);
    cur = h[pos];
  }

  for(int i=0;i<ans.size();i++){
    if(i == ans.size()-1)
      cout << ans[i] << endl;
    else
      cout << ans[i] << " ";
  }
  return 0;
}