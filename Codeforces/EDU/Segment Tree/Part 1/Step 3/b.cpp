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

  int kth_one(int l,int r,int pos,int k){
    if(l == r)
      return l;

    int m = (l+r)/2;

    int right = st[right_child(pos)];
    if(k < right)
      return kth_one(m+1,r,right_child(pos),k);

    int left = st[left_child(pos)];
    return kth_one(l,m,left_child(pos),k-right);
  }

  int kth_one(int k){
    return kth_one(0,sz-1,0,k);
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

  SegTree st;
  vi tmp(n+1,1);
  st.build(n+1,tmp);

  vll a(n);

  for(int i=0;i<n;i++){
    cin >> a[i];
  }

  vi ans(n);
  for(int i=n-1;i>=0;i--){
    ans[i] = st.kth_one(a[i]),st.update(ans[i],0);
  }

  for(int x:ans)
    cout << x << " ";

  cout << endl;

  return 0;
}