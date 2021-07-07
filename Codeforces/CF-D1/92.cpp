#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define f first
#define s second
#define ub  upper_bound
#define lb  lower_bound
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
cerr << "[" << name << " : " << arg1 << "]" << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
const char* comma = strchr(names + 1, ',');cerr << "[";
cerr.write(names, comma - names) << " : " << arg1<<"] | ";__f(comma+1, args...);
}

using ld = long double;
using ll = long long;
using pii = pair <int,int>;
using pll = pair <ll,ll>;
using vi = vector <int>;
using vll = vector <ll>;
using vpii = vector <pii>;
using vpll = vector<pll>;
using vs = vector <string>;

struct Segtree{
  vi st;
  int len;
  void build(int n){
    len = n;
    st.assign(4*n,-1);
  }
  void update(int l,int r,int pos,int i,int v){
    if(i < l || i > r)
      return;
    if(l == r){
      st[pos] = v;
      return;
    }
    int m = (l+r)/2;
    update(l,m,2*pos+1,i,v);
    update(m+1,r,2*pos+2,i,v);
    st[pos] = max(st[2*pos+1],st[2*pos+2]);
  }
  void update(int i,int v){
    update(0,len-1,0,i,v);
  }
  int get_max(int l,int r,int pos,int ql,int qr){
    if(ql > r || qr < l)
      return -1;
    if(ql <= l && r <= qr)
      return st[pos];
    int m = (l+r)/2;
    return max(get_max(l,m,2*pos+1,ql,qr), get_max(m+1,r,2*pos+2,ql,qr));
  }

  int get_max(int ql,int qr){
    return get_max(0,len-1,0,ql,qr);
  }
};
int main(){
  fastio;

  int n;
  cin >> n;
  vpii tmp(n);
  
  for(int i=0;i<n;i++){
    cin >> tmp[i].f;
    tmp[i].s = i;
  }

  sort(all(tmp));

  Segtree st;
  st.build(n);

  vi nums(n);

  for(int i=0;i<n;i++)
    nums[tmp[i].s] = i;  
  
  vi ans(n);

  for(int i=n-1;i>=0;i--){
    int ret = st.get_max(0,nums[i]-1);
    ans[i] = max(-1,ret - i - 1);
    st.update(nums[i],i);
  }

  for(int x:ans)
    cout << x << " ";
  cout << endl;
  
  return 0;
}