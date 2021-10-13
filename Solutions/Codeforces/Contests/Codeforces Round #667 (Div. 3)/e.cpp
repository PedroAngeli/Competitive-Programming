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
 
struct SegTree{
  vi st;
  vi original;
  int n;
  void build(int l,int r,int pos){
    if(l == r){
      st[pos] = original[l];
      return;
    }
    int m = (l+r)/2;
    build(l,m,2*pos+1);
    build(m+1,r,2*pos+2);

    st[pos] = max(st[2*pos+1],st[2*pos+2]);
  }
  void build(vi& a){
    original = a;
    n = sz(a);
    st.assign(4*n,0);
    build(0,n-1,0);
  }

  int get_max(int l,int r,int pos,int ql,int qr){
    if(ql > r || qr < l)
      return 0;
    if(ql <= l && r <= qr)
      return st[pos];

    int m = (l+r)/2;

    return max(get_max(l,m,2*pos+1,ql,qr),get_max(m+1,r,2*pos+2,ql,qr));
  }
  int get_max(int l,int r){
    return get_max(0,n-1,0,l,r);
  }
};
int main(){
  fastio;
 
  int t = 1;
  cin >> t;
 
  while(t--){
    int n,k;
    cin >> n >> k;
    vi x(n),y(n);
 
    for(int i=0;i<n;i++)
      cin >> x[i];
    
    for(int i=0;i<n;i++)
      cin >> y[i];
 
    sort(all(x));

    int h1 = 0;

    vi points(n);
    vi pos(n);
    for(int i=0;i<n;i++){
      auto it = upper_bound(all(x),x[i] + k);
      it--;
      int j = it - x.begin();
      int qtd = j-i+1;
      points[i] = qtd;
      pos[i] = j;
    }
    SegTree st;
    st.build(points);

    int ans = 0;

    for(int i=0;i<n;i++){
      ans = max(ans,points[i] + st.get_max(pos[i]+1,n-1));
    }

    cout << ans << endl;
  }
 
  return 0;
}