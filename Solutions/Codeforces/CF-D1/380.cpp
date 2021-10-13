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

struct Node{
  int open, close;
  Node(int open = 0,int close = 0):open(open),close(close){}
};

struct Segtree{
  vector <Node> st;
  string a;
  int len;
  void build(int l,int r,int pos){
    if(l == r){
      st[pos] = (a[l] == '(') ? Node(1,0) : Node(0,1);
      return;
    }

    int m = (l+r)/2;
    build(l,m,2*pos+1);
    build(m+1,r,2*pos+2);

    Node left = st[2*pos+1];
    Node right = st[2*pos+2];

    int r1 = max(0,left.open - right.close);
    int r2 = max(0,right.close - left.open);

    st[pos] = Node(right.open + r1, left.close + r2);
  }

  void build(string _a){
    a = _a;
    len = sz(a);
    st.assign(4*len, Node());
    build(0,len-1,0);
  }
  Node max_correct(int l,int r,int pos,int ql,int qr){
    if(ql > r || qr < l)
      return 0;
    if(ql <= l && r <= qr)
      return st[pos];
    
    int m = (l+r)/2;

    Node left = max_correct(l,m,2*pos+1,ql,qr);
    Node right = max_correct(m+1,r,2*pos+2,ql,qr);

    int r1 = max(0,left.open - right.close);
    int r2 = max(0,right.close - left.open);

    return Node(right.open + r1, left.close + r2);
  }
  int max_correct(int l,int r){
    Node node = max_correct(0,len-1,0,l,r);
    return (r-l+1) - (node.open + node.close);
  }

};

int main(){
  fastio;

    string a;
    cin >> a;

    Segtree st;
    st.build(a);

    int q = 0;
    cin >> q;

    while(q--){
      int l,r;
      cin >> l >> r;
      l--,r--;
      cout << st.max_correct(l,r) << endl;
    }
  
  return 0;
}