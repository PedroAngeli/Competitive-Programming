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

    st[pos] = max(st[left_child(pos)],st[right_child(pos)]);
  }
  void build(int n,vll& a){
    original_a = a;
    sz = n;
    st.assign(4*sz,0);
    build(0,n-1,0);
  }

  int first_greater(int l,int r,int pos,int x){
    if(l == r)
      return st[pos] >= x ? l : -1;

    int m = (l+r)/2;
    
    int left = st[left_child(pos)];
    if(left >= x){
      return first_greater(l,m,left_child(pos),x);
    }else{
      int right = st[right_child(pos)];

      if(right >= x)
        return first_greater(m+1,r,right_child(pos),x);
    }
    
    return -1;
  }

  int first_greater(int x){
    return first_greater(0,sz-1,0,x);
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
    st[pos] = max(st[left_child(pos)],st[right_child(pos)]);
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
      int x;
      cin >> x;
      cout << st.first_greater(x) << endl;
    }
  }
  
  
  return 0;
}