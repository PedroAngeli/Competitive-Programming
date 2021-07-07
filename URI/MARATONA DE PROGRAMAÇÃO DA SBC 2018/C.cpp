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
  int merge(int l,int r){
    return st[l] + st[r];
  }

  void build(int l,int r,int pos){
    if(l == r){
      st[pos] = 1;
      return;
    }
    int m = (l+r)/2;
    build(l,m,2*pos+1);
    build(m+1,r,2*pos+2);
    st[pos] = merge(2*pos+1,2*pos+2);
  }
  Segtree(int n){
    st.assign(4*n,0);
    build(0,n-1,0);
  }
  
  void update(int l,int r,int pos,int i){
    if(i < l || i > r)
      return;
    if(l == r){
      st[pos] = 0;
      return;
    }
    int m = (l+r)/2;
    update(l,m,2*pos+1,i);
    update(m+1,r,2*pos+2,i);
    st[pos] = merge(2*pos+1,2*pos+2);
  }
  int query(int l,int r,int pos,int ql,int qr){
    if(ql > r || qr < l)
      return 0;
    if(ql <= l && r <= qr)
      return st[pos];

    int m = (l+r)/2;
    return query(l,m,2*pos+1,ql,qr) + query(m+1,r,2*pos+2,ql,qr);
  }
};

ll solve(int H){
  map <int,int> h1;
  map <int,int> h2;
  vi ph1,ph2;
  Segtree s1(H);
  ll inter = 0;
  for(int i=0;i<H;i++){
    int y1,y2;
    cin >> y1 >> y2;
    ph1.pb(y1);
    ph2.pb(y2);
    h1[y1] = y2;
  }
  sort(all(ph1));
  sort(all(ph2));
  for(int i=0;i<H;i++)
    h2[ph2[i]] = i;

  for(int i=0;i<H;i++){
    int y = h2[h1[ph1[i]]];
    inter += s1.query(0,H-1,0,0,y-1);
    s1.update(0,H-1,0,y);
  }
  return inter;
}

int main(){
  fastio;

  int x,y;
  cin >> x >> y;
  int H,V;
  cin >> H >> V;
  ll ans = 1LL * (H + 1) * (V + 1);
  ll inter = solve(H) + solve(V);

  cout << ans + inter << endl;
  
  return 0;
}