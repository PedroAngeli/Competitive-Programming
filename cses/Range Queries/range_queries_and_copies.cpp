#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define f first
#define s second
#define ub  upper_bound
#define lb  lower_bound
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define fbo find_by_order 
#define ook order_of_key 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
cerr << "[" << name << " : " << arg1 << "]" << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
const char* comma = strchr(names + 1, ',');cerr << "[";
cerr.write(names, comma - names) << " : " << arg1<<"] | ";__f(comma+1, args...);
}

using ld = long double;
using ll = long long;
using pii = pair <int,int>;
using pll = pair <ll,ll>;
using vi = vector <int>;
using vll = vector <ll>;
using vpii = vector <pii>;
using vpll = vector<pll>;
using vs = vector <string>;

const int nax = 2e5;

int t[nax];
int n, q;

struct Node{
  Node* left, *right;
  ll val;
  Node(Node* left=NULL, Node* right=NULL,ll val=0)
  :left(left), right(right), val(val){}
};

vector <Node*> versions[nax];

void build(Node* node, int l=0, int r=n-1){
  if(l == r){
    node->val = t[l];
    return;
  }
  node->left = new Node();
  node->right = new Node();
  int m = (l+r)/2;
  build(node->left,l,m);
  build(node->right,m+1,r);
  node->val = node->left->val + node->right->val;
}

ll query(Node* node, int l,int r,int ql,int qr){
  if(ql > r or qr < l) return 0;
  if(ql <= l and r <= qr) return node->val;
  int m = (l+r)/2;
  return query(node->left, l, m, ql, qr) + query(node->right,m+1,r,ql, qr);
}

void update(Node* cur, Node* prev,int a, int x, int l=0, int r=n-1){
  if(l == r){
    cur->val = x;
    return;
  }
  int m = (l+r)/2;

  if(a <= m){
    cur->right = prev->right;
    cur->left = new Node();
    update(cur->left, prev->left, a, x, l, m);
  }else{
    cur->left = prev->left;
    cur->right = new Node();
    update(cur->right, prev->right, a, x, m+1, r);
  }
  cur->val = cur->left->val + cur->right->val;
}

int main(){
  fastio;

  cin >> n >> q;

  for(int i=0;i<n;i++) cin >> t[i];
  versions[0].pb(new Node());

  build(versions[0][0]);

  int v = 1;

  while(q--){
    int op;
    cin >> op;
    if(op == 1){
      int k, a, x;
      cin >> k >> a >> x;
      k--, a--;
      Node* cur = new Node();
      Node* prev = versions[k].back();
      update(cur, prev, a, x);
      versions[k].pb(cur);
    }else if(op == 2){
      int k, a, b;
      cin >> k >> a >> b;
      k--, a--, b--;
      cout << query(versions[k].back(),0, n-1, a, b) << endl;
    }else{
      int k;
      cin >> k;
      k--;
      Node* root = versions[k].back();
      versions[v++].pb(root);
    }
  }
  return 0;
}