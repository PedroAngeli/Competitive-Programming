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
  vi st;
  vi original_a;
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
  void build(int n,vi& a){
    original_a = a;
    sz = n;
    st.assign(4*sz,0);
    build(0,n-1,0);
  }

  int query(int l,int r,int pos,int k){
    if(l == r)
      return l;

    int left = st[left_child(pos)];
    int right = st[right_child(pos)];

    int m = (l+r)/2;

    if(k < left)
      return query(l,m,left_child(pos),k);

    return query(m+1,r,right_child(pos),k-left);
  }

  int query(int k){
    return query(0,sz-1,0,k);
  }

  void update(int l,int r,int pos,int i){
    if(i > r || i < l)
      return;

    if(l == r){
      st[pos] = 1-st[pos];
      return;
    }

    int m = (l+r)/2;

    update(l,m,left_child(pos),i);
    update(m+1,r,right_child(pos),i);
    st[pos] = st[left_child(pos)] + st[right_child(pos)];
  }

  void update(int i){
    update(0,sz-1,0,i);
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
    int op;
    cin >> op;
    if(op == 1){
      int i;
      cin >> i;
      st.update(i);
    }else{
      int k;
      cin >> k;
      cout << st.query(k) << endl;
    }
  }
  
  
  return 0;
}