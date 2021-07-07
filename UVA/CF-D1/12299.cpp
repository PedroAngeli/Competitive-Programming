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


struct Segtree{
  vi st;
  vi a;
  int len;

  void build(int l,int r,int pos){
    if(l == r){
      st[pos] = a[l];
      return;
    }

    int m = (l+r)/2;
    build(l,m,2*pos+1);
    build(m+1,r,2*pos+2);

    st[pos] = min(st[2*pos+1],st[2*pos+2]);
  }
  void build(vi& _a){
    a = _a;
    len = sz(a);
    st.assign(4*len,INT_MAX);
    build(0,len-1,0);
  }
  void update(int l,int r,int pos,int i,int v){
    if(i > r || i < l)
      return;
    if(l == r){
      st[pos] = v;
      a[l] = v;
      return;
    }
    int m = (l+r)/2;
    update(l,m,2*pos+1,i,v);
    update(m+1,r,2*pos+2,i,v);
    st[pos] = min(st[2*pos+1],st[2*pos+2]);
  }

  void update(int i, int v){
    update(0,len-1,0,i,v);
  }

  ll rmq(int l,int r,int pos,int ql,int qr){
    if(ql > r || qr < l)
      return INT_MAX;

    if(ql <= l && r <= qr)
      return st[pos];

    int m = (l+r)/2;

    return min(rmq(l,m,2*pos+1,ql,qr), rmq(m+1,r,2*pos+2,ql,qr));
  }

  ll rmq(int ql,int qr){
    return rmq(0,len-1,0,ql,qr);
  }
};

vi getIdxs(string vals){
  vi ret;
  stringstream ss(vals);
  int idx;
  char c;
  while(ss >> idx){
    idx--;
    ret.pb(idx);
    ss >> c;
  }

  return ret;
}

int main(){
  fastio;

  int n,q;
  cin >> n >> q;
  
  vi a(n);

  for(int i=0;i<n;i++)
    cin >> a[i];
  
  Segtree st;
  st.build(a);

  while(q--){
    string line;
    cin >> line;
    string op = line.substr(0,5);
    vi idxs = getIdxs(line.substr(6));
    
    if(op == "query"){
      cout << st.rmq(idxs[0],idxs[1]) << endl;
    }else{
      int pri = st.a[idxs[0]];
      for(int i=0;i<sz(idxs)-1;i++)
        st.update(idxs[i],st.a[idxs[i+1]]);
        st.update(idxs[sz(idxs)-1],pri);

      
      
    }
  }

  return 0;
}