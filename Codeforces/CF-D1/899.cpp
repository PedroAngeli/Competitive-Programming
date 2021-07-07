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

struct comp{
  bool operator() (pii p1,pii p2){
    return p1.f > p2.f || (p1.f == p2.f && p1.s < p2.s);
  }
};
int main(){
  fastio;

  int n;
  cin >> n;

  vi a(n);

  for(int i=0;i<n;i++)
    cin >> a[i];
  
  int i = 0;
  set <pii,comp> s1;
  set <pii> s2;

  while(i < n){
    int cnt = 0;
    int j = i;
    int cur = a[j];
    while(j < n && cur == a[j])
      j++,cnt++;
    
    s1.insert({j-i,i});
    s2.insert({i,j-i});

    i = j;
  }

  int ans = 0;

  while(true){
    ans++;
    
    auto it = s1.begin();
    int tam = it->f;
    int l = it->s;
    s1.erase(it);

    if(s1.size() == 0)
      break;

    auto el = s2.lower_bound({l,-1});
    auto right = s2.upper_bound({l,n+1});
    auto left = s2.lower_bound({l,-1});
    left--;

    if(right != s2.end() && el != s2.begin()){
      int l1 = left->f;
      int l2 = right->f;
      if(a[l1] == a[l2]){
        s1.erase({left->s,left->f});
        s1.erase({right->s,right->f});
        s1.insert({left->s + right->s,left->f});
        s2.insert({left->f,left->s + right->s});
        s2.erase(left);
        s2.erase(right);
      }
    }

    s2.erase(el);

  }

  cout << ans << endl;
  
  return 0;
}