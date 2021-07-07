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
    st.assign(4*n,0);
  }
  void update(int l,int r,int pos,int i){
    if(i < l || i > r)
      return;
    if(l == r){
      st[pos] = 1;
      return;
    }
    int m = (l+r)/2;
    update(l,m,2*pos+1,i);
    update(m+1,r,2*pos+2,i);
    st[pos] = st[2*pos+1] + st[2*pos+2];
  }
  void update(int i){
    update(0,len-1,0,i);
  }
  int menor(int l,int r,int pos,int ql,int qr){
    if(qr < l || ql > r)
      return 0;
    if(ql <= l && r <= qr){
      return st[pos];
    }
    int m = (l+r)/2;
    return menor(l,m,2*pos+1,ql,qr) + menor(m+1,r,2*pos+2,ql,qr);
  }
  int menor(int ql,int qr){
    return menor(0,len-1,0,ql,qr);
  }
};

vi parent;
int find(int x){
  if(x == parent[x])
    return x;
  return parent[x] = find(parent[x]);
}

void join(int x,int y){
  x = find(x);
  y = find(y);
  if(x == y)
    return;

  parent[x] = y;
}

int main(){
  fastio;

  int n;
  cin >> n;

  vi a(n);
  parent.resize(n+1);
  iota(all(parent),0);

  for(int i=0;i<n;i++)
    cin >> a[i];

  stack <int> p;
  p.push(a[n-1]);
  Segtree st;
  st.build(n+1);
  st.update(a[n-1]);

  for(int i=n-2;i>=0;i--){
    int rem = 0;
    while(!p.empty() && p.top() < a[i]){
      join(p.top(),a[i]);
      p.pop();
      rem++;
    }
    if(!p.empty()){
      if(rem != st.menor(1,a[i]-1))
        join(p.top(),a[i]);
    }
    st.update(a[i]);
    p.push(a[i]);
  }

  set <int> S;
  for(int i=1;i<=n;i++){
    S.insert(find(i));
  }

  cout << sz(S) << endl;

  return 0;
}