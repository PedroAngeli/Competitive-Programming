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

typedef struct{
  vll st;
  vll original_a;
  int sz;
  int left_child(int pos){ return pos*2+1; }
  int right_child(int pos){ return pos*2+2; }

  void build(int l,int r,int pos){
    if(l == r){
      st[pos] = original_a[l];
      return;
    }
    int m = (l+r)/2;

    build(l,m,left_child(pos));
    build(m+1,r,right_child(pos));

    st[pos] = st[left_child(pos)] + st[right_child(pos)];
  }
  void build(int n,vll& a){
    original_a = a;
    sz = n;
    st.assign(4*sz,0);
    build(0,n-1,0);
  }

  ll query(int l,int r,int pos,int ql, int qr){
    if(l >= ql && qr >= r)
      return st[pos];

    if(l > qr || r < ql)
      return 0;

    int m = (l+r)/2;
    ll left = query(l,m,left_child(pos),ql,qr);
    ll right = query(m+1,r,right_child(pos),ql,qr);

    return left + right;
  }

  ll query(int ql,int qr){
    return query(0,sz-1,0,ql,qr);
  }

  void update(int l,int r,int pos,int i,int v){
    if(i > r || i < l)
      return;

    if(l == r){
      st[pos] = v;
      return;
    }

    int m = (l+r)/2;

    update(l,m,left_child(pos),i,v);
    update(m+1,r,right_child(pos),i,v);
    st[pos] = st[left_child(pos)] + st[right_child(pos)];
  }

  void update(int i,int v){
    update(0,sz-1,0,i,v);
  }
}SegTree;

int main(){
  fastio;

  int n;
  cin >> n;

  vll a(n+1,0);
  SegTree st;
  st.build(n+1,a);

  for(int i=0;i<n;i++){
    int x;
    cin >> x;
    cout << st.query(x+1,n) << " ";
    st.update(x,1);
  }

  cout << endl;

  return 0;
}