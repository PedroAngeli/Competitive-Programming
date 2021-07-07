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
  string a;
  cin >> a;
  int n = a.size();
  vi ans(n,0);
  
  
  int r = n-1;
  while(r>=0 && a[r] == 'b')
    r--;
  r++;
  int l = 0;
  while(l < r){
    char c = a[l];
    while(l < r && a[l] == c) l++;
    ans[l-1]=1;
  }

  for(int x:ans)
    cout << x << " ";
  cout << endl;
  return 0;
}