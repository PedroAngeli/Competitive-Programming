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
  string a;
  vi st;
  int len;

  void build(int l,int r,int pos){
    if(l == r){
      st[pos] = l;
      return;
    }

    int m = (l+r)/2;

    build(l,m,2*pos+1);
    build(m+1,r,2*pos+2);

    int left = st[2*pos+1];
    int right = st[2*pos+2];

    st[pos] = (a[left] >= a[right] ? left : right);
  }

  void build(string _a){
    a = _a;
    len = sz(a);
    st.assign(4*len,0);
    build(0, len-1, 0);
  }

  int get_max(int l,int r,int pos,int ql,int qr){
    if(ql > r || qr < l)
      return -1;

    if(ql <= l && r <= qr)
      return st[pos];
    
    int m = (l + r)/2;

    int left = get_max(l,m,2*pos+1,ql,qr);
    int right = get_max(m+1,r,2*pos+2,ql,qr);
    
  
    if(left == -1){
      if(right == -1)
        return -1;
      else
        return right;
    }else{
      if(right == -1)
        return left;
      else
        return (a[left] >= a[right] ? left : right);
    } 
  }

  int get_max(int ql,int qr){
    return get_max(0,len-1,0,ql,qr);
  }
};

int main(){
  fastio;

  int n,d;
  
  while(cin >> n >> d){
    if(n == 0 && d == 0)
      break;
    string a;
    cin >> a;

    SegTree st;
    st.build(a);

    string ans = "";

    int take = n-d;

    int i = 0;
    while(i < n){
      int mxIdx = n-take;
      if(take == 0)
        break;
      int pos = st.get_max(i,mxIdx);
      if(pos == -1)
        break;
      ans += a[pos];
      take--;
      i = pos + 1;
    }

    cout << ans << endl;
  }

  return 0;
}