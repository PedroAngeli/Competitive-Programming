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

const ll INF = 1e7;

typedef struct{
  vll st;
  vi original;
  int sz;

  void build(int l,int r, int pos){
    if(l == r){
      if(original[l] == 0)
        st[pos] = -INF;
      else  
        st[pos] = (original[l] < 0);
      return;
    }

    int m = (l+r)/2;
    build(l,m,2*pos+1);
    build(m+1,r,2*pos+2);
    st[pos] = st[2*pos+1] + st[2*pos+2];
  }

  void build(vi& a){
    sz = a.size();
    original = a;
    st.assign(4*sz,0);
    build(0,sz-1,0);
  }

  void update(int l,int r,int pos,int i,int v){
    if(i < l || i > r)
      return;
    
    if(l == r){
      original[l] = v;
      if(original[l] == 0)
        st[pos] = -INF;
      else  
        st[pos] = (original[l] < 0);
      return;
    }

    int m = (l+r)/2;
    update(l,m,2*pos+1,i,v);
    update(m+1,r,2*pos+2,i,v);
    st[pos] = st[2*pos+1] + st[2*pos+2];
  }

  void update(int i,int v){
    update(0,sz-1,0,i,v);
  }

  int query(int l,int r,int pos,int ql,int qr){
    if(ql > r || qr < l)
      return 0;
    if(ql <= l && r <= qr)
      return st[pos];
    
    int m = (l+r)/2;
    int left = query(l,m,2*pos+1,ql,qr);
    int right = query(m+1,r,2*pos+2,ql,qr);

    return left + right;
  }

  int query(int ql,int qr){
    return query(0,sz-1,0,ql,qr);
  }
}SegTree;
int main(){
  fastio;

  int n,q;
  
  while(cin >> n >> q){
    vi a(n);
    for(int i=0;i<n;i++)
      cin >> a[i];
    
    SegTree st;
    st.build(a);
    string line;
    getline(cin,line);

    while(q--){
      getline(cin,line);
      istringstream str(line);
      char c;
      str >> c;
      if(c == 'C'){
        int i,v;
        str >> i >> v;
        i--;
        st.update(i,v);
      }else{
        int i,j;
        str >> i >> j;
        i--,j--;
        ll qtd = st.query(i,j);
        if(qtd < 0)
          cout << 0;
        else if(qtd % 2)
          cout << "-";
        else
          cout << "+";
      }
    }
    cout << endl;
  }
  return 0;
}