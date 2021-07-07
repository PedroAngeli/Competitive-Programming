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

  int sumRange(int l,int r,int pos,int ql, int qr){
    if(ql > r || qr < l)
      return 0;
    if(l >= ql && r <= qr)
      return st[pos];

    int m = (l+r)/2;
    int left = sumRange(l,m,left_child(pos),ql,qr);
    int right = sumRange(m+1,r,right_child(pos),ql,qr);

    return left + right;
  }

  int sumRange(int ql,int qr){
    return sumRange(0,sz-1,0,ql,qr);
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

void solve(vll& a,int n,vi& ans,SegTree st){
    vi left_index(n+1,-1);
    for(int i=0;i<2*n;i++){
    int cur = a[i];

    if(left_index[cur] == -1){
      left_index[cur] = i;
      st.update(i,1);
    }else{
      ans[cur] += st.sumRange(left_index[cur]+1,i-1);
      st.update(left_index[cur],0);
    }
  }
}

int main(){
  fastio;

  int n;
  cin >> n;

  SegTree st;
  vi tmp(2*n,0);
  st.build(2*n,tmp);

  vll a(2*n);

  for(int i=0;i<2*n;i++)
    cin >> a[i];
  
  vi ans(n+1,0);

  solve(a,n,ans,st);
  reverse(a.begin(),a.end());
  solve(a,n,ans,st);

 
  for(int i=1;i<=n;i++)
    cout << ans[i] << " ";
  cout << endl;

  return 0;
}