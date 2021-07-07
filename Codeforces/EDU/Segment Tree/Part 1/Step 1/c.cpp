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

const int INF = 1e9 + 7;

typedef struct{
  vpll st;
  vll original_a;
  int sz;
  int left_child(int pos){ return pos*2+1; }
  int right_child(int pos){ return pos*2+2; }

  void build(int l,int r,int pos){
    if(l == r){
      st[pos] = {original_a[l],1};
      return;
    }

    int m = (l+r)/2;

    build(l,m,left_child(pos));
    build(m+1,r,right_child(pos));

    pll p1 = st[left_child(pos)];
    pll p2 = st[right_child(pos)];

    if(p1.f < p2.f)
      st[pos] = p1;
    else if(p1.f > p2.f)
      st[pos] = p2;
    else
      st[pos] = {p1.f,p1.s + p2.s};
  }

  void build(int n,vll& a){
    original_a = a;
    sz = n;
    st.assign(4*sz,{INF,1});
    build(0,n-1,0);
  }

  pll query(int l,int r,int pos,int ql, int qr){
    if(l >= ql && qr >= r)
      return st[pos];

    if(l > qr || r < ql)
      return {INF,1};

    int m = (l+r)/2;

    pll left = query(l,m,left_child(pos),ql,qr);
    pll right = query(m+1,r,right_child(pos),ql,qr);

    if(left.f < right.f)
      return left;
    else if(right.f < left.f)
      return right;
    else
      return {left.f, left.s + right.s};
  }

  pll query(int ql,int qr){
    return query(0,sz-1,0,ql,qr);
  }

  void update(int l,int r,int pos,int i,int v){
    if(i > r || i < l)
      return;

    if(l == r){
      st[pos] = {v,1};
      return;
    }

    int m = (l+r)/2;

    update(l,m,left_child(pos),i,v);
    update(m+1,r,right_child(pos),i,v);

    pll p1 = st[left_child(pos)];
    pll p2 = st[right_child(pos)];

    if(p1.f < p2.f)
      st[pos] = p1;
    else if(p1.f > p2.f)
      st[pos] = p2;
    else
      st[pos] = {p1.f,p1.s + p2.s};
  }

  void update(int i,int v){
    update(0,sz-1,0,i,v);
  }

}SegTree;

int main(){
  fastio;

  int n,m;
  cin >> n >> m;

  vll a(n);

  for(int i=0;i<n;i++)
    cin >> a[i];
  
  SegTree st;
  st.build(n,a);

  while(m--){
    int op;
    cin >> op;
    if(op == 1){
      int i,v;
      cin >> i >> v;
      st.update(i,v);
    }else{
      int l,r;
      cin >> l >> r;
      r--;
      pii ans = st.query(l,r);
      cout << ans.f << " " << ans.s << endl;
    }
  }
  
  
  return 0;
}