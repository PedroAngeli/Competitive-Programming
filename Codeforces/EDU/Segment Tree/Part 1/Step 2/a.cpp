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

typedef struct node{
  ll seg,pref,suf,sum;
  node(ll seg=0,ll pref=0,ll suf=0, ll sum=0):seg(seg),pref(pref),suf(suf),sum(sum){}
}Node;

typedef struct{
  vector <Node> st;
  vi original_a;
  int sz;
  int left_child(int pos){ return pos*2+1; }
  int right_child(int pos){ return pos*2+2; }

  void build(int l,int r,int pos){
    if(l == r){
      int v = original_a[l];
      Node node(v,v,v,v);
      st[pos] = node;
      return;
    }
    int m = (l+r)/2;

    build(l,m,left_child(pos));
    build(m+1,r,right_child(pos));

    Node left = st[left_child(pos)];
    Node right = st[right_child(pos)];

    ll pref = max(left.pref,left.sum + right.pref);
    ll suf = max(right.suf,left.suf + right.sum);
    ll seg = max({left.seg, right.seg,left.suf + right.pref});
    ll sum = left.sum + right.sum;

    Node node(seg,pref,suf,sum);
    st[pos] = node;
  }

  void build(int n,vi& a){
    original_a = a;
    sz = n;
    Node node;
    st.assign(4*sz,node);
    build(0,n-1,0);
  }

  ll max_segment(){
    return st[0].seg;
  }

  void update(int l,int r,int pos,int i,int v){
    if(i > r || i < l)
      return;

    if(l == r){
      Node node(v,v,v,v);
      st[pos] = node;
      return;
    }

    int m = (l+r)/2;

    update(l,m,left_child(pos),i,v);
    update(m+1,r,right_child(pos),i,v);

    Node left = st[left_child(pos)];
    Node right = st[right_child(pos)];

    ll pref = max(left.pref,left.sum + right.pref);
    ll suf = max(right.suf,left.suf + right.sum);
    ll seg = max({left.seg, right.seg,left.suf + right.pref});
    ll sum = left.sum + right.sum;

    Node node(seg,pref,suf,sum);
    st[pos] = node;
  }

  void update(int i,int v){
    update(0,sz-1,0,i,v);
  }
}SegTree;

int main(){
  fastio;

  int n,m;
  cin >> n >> m;

  vi a(n);

  for(int i=0;i<n;i++)
    cin >> a[i];
  
  SegTree st;
  st.build(n,a);

  while(m--){
    int i,v;
    cin >> i >> v;
    cout << max(0LL,st.max_segment()) << endl;
    st.update(i,v);
  }
  
  cout << max(0LL,st.max_segment()) << endl;
  
  
  return 0;
}