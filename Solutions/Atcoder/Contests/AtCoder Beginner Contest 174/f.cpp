#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define f first
#define s second
 
using ld = long double;
using ll = long long;
using ii = pair <int,int>;
using pll = pair <ll,ll>;
using vi = vector <int>;
using vll = vector <ll>;
using vii = vector <ii>;
using vpll = vector<pll>;

vector < vector <int> > seg;
vi a,b;
void build(int pos,int l, int r){
  if(l == r){
    seg[pos].push_back(b[l]);
    return;
  }
  int m = (l+r)/2;
  build(2*pos,l,m);
  build(2*pos+1,m+1,r);
  seg[pos].insert(seg[pos].end(),seg[2*pos].begin(),seg[2*pos].end());
  seg[pos].insert(seg[pos].end(),seg[2*pos+1].begin(),seg[2*pos+1].end());
  sort(seg[pos].begin(),seg[pos].end());
}

int query(int pos,int l,int r,int ql,int qr){
  if(qr < l || ql > r)
    return 0;

  if(l >= ql && r <= qr){
    int qtd = lower_bound(seg[pos].begin(),seg[pos].end(),ql) - seg[pos].begin();
    return qtd;
  }

  int m = (l+r)/2;
  int left = query(2*pos,l,m,ql,qr);
  int right = query(2*pos+1,m+1,r,ql,qr);
  
  return left + right;
}
int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  
  int n,q;
  cin >> n >> q;
  a.resize(n);
  b.resize(n);
  seg.resize(4*n);

  for(int i=0;i<n;i++)
    cin >> a[i];

  vi last(n+1,-1);

  for(int i=0;i<n;i++){
    b[i] = last[a[i]];
    last[a[i]] = i;
  }

  build(1,0,n-1);

  while(q--){
    int l,r;
    cin >> l >> r;
    l--,r--;
    cout << query(1,0,n-1,l,r) << endl;
  }

  return 0;
}