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

struct Node{
  int f[41];
  ll inv;
  Node(){memset(f,0,sizeof f), inv = 0;}
};

struct SegTree{
  vector <Node> st;
  vi original;
  int sz;

  Node merge(Node left, Node right){
    Node cur;
    ll inv = 0;

    for(int i=40;i>=1;i--)
      for(int j=i-1;j>=1;j--)
        inv += 1LL*left.f[i]*right.f[j];

    for(int i=1;i<=40;i++)
      cur.f[i] = left.f[i] + right.f[i];

    cur.inv = left.inv + right.inv + inv;

    return cur;
  }

  void build(int l,int r,int pos){
    if(l == r){
      st[pos] = Node();
      st[pos].f[original[l]]++;
      return;
    }

    int m = (l+r)/2;

    build(l,m,2*pos+1);
    build(m+1,r,2*pos+2);

    st[pos] = merge(st[2*pos+1],st[2*pos+2]);
  }
  void build(vi& a){
    original = a;
    sz = a.size();
    st.resize(4*sz);
    build(0,sz-1,0);
  }

  void update(int l, int r,int pos,int i,int v){
    if(i < l || i > r)
      return;
    if(l == r){
      st[pos] = Node();
      st[pos].f[v]++;
      return;
    }

    int m = (l+r)/2;

    update(l,m,2*pos+1,i,v);
    update(m+1,r,2*pos+2,i,v);

    st[pos] = merge(st[2*pos+1],st[2*pos+2]);
  }

  void update(int i,int v){
    update(0,sz-1,0,i,v);
  }

  Node count_inv(int l,int r,int pos,int ql,int qr){
    if(ql > r || qr < l)
      return Node();
    
    if(l >= ql && r <= qr)
      return st[pos];
    
    int m = (l+r)/2;

    Node left = count_inv(l,m,2*pos+1,ql,qr);
    Node right = count_inv(m+1,r,2*pos+2,ql,qr);

    return merge(left,right);
  }

  ll count_inv(int ql,int qr){
    return count_inv(0,sz-1,0,ql,qr).inv;
  }
};

int main(){
  fastio;

  int n,q;

  cin >> n >> q;
  vi a(n);

  for(int i=0;i<n;i++)
    cin >> a[i];
  
  SegTree st;
  st.build(a);

  while(q--){
    int type;
    cin >> type;
    int x,y;
    cin >> x >> y;

    if(type == 1){
      x--,y--;
      cout << st.count_inv(x,y) << endl;
    }else{
      x--;
      st.update(x,y);
    }
  }

  return 0;
}