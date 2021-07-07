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

int mod; 

typedef struct matrix{
  ll a11,a12,a21,a22;
  matrix(ll a11=1,ll a12=0,ll a21=0,ll a22=1):a11(a11),a12(a12),a21(a21),a22(a22){}
  matrix operator*(matrix b){
    ll c11 = a11 * b.a11 + a12 * b.a21;
    ll c12 = a11 * b.a12 + a12 * b.a22;
    ll c21 = a21 * b.a11 + a22 * b.a21;
    ll c22 = a21 * b.a12 + a22 * b.a22;
    return matrix(c11%mod,c12%mod,c21%mod,c22%mod);
  }
}Matrix;

typedef struct{
  vector <Matrix> st;
  vector <Matrix> original_a;
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

    st[pos] = st[left_child(pos)] * st[right_child(pos)];
  }
  void build(int n,vector <Matrix>& a){
    original_a = a;
    sz = n;
    st.assign(4*sz,Matrix());
    build(0,n-1,0);
  }

  Matrix query(int l,int r,int pos,int ql, int qr){
    if(l >= ql && qr >= r)
      return st[pos];
      
    if(l > qr || r < ql)
      return Matrix();

    int m = (l+r)/2;
    Matrix left = query(l,m,left_child(pos),ql,qr);
    Matrix right = query(m+1,r,right_child(pos),ql,qr);

    return left * right;
  }

  Matrix query(int ql,int qr){
    return query(0,sz-1,0,ql,qr);
  }
}SegTree;

int main(){
  fastio;

  int n,m;
  cin >> mod >> n >> m;

  vector <Matrix> vet(n);

  for(int i=0;i<n;i++)
    cin >> vet[i].a11 >> vet[i].a12 >> vet[i].a21 >> vet[i].a22;

  SegTree st;
  st.build(n,vet);

  while(m--){
    int l,r;
    cin >> l >> r;
    l--;
    r--;
    Matrix ans = st.query(l,r);
    cout << ans.a11 << " " << ans.a12 << endl << ans.a21 << " " << ans.a22 << endl;
    cout << endl;
  }
  
  
  return 0;
}