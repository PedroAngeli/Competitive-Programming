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

const int nax = 2e7;

struct SegTree{
  vll st;
  vi a;
  int n;
  void build(int l,int r,int pos){
    if(l == r){
      st[pos] = a[l];
      return;
    }
    int m = (l+r)/2;
    build(l, m, 2*pos+1);
    build(m+1, r, 2*pos+2);
    st[pos] = st[2*pos+1] * st[2*pos+2];
    st[pos] %= 10;
  }
  void build(vi _a){
    a = _a;
    n = sz(a);
    st.assign(4*n, 1);
    build(0, n-1, 0);
  }
  int query(int l,int r,int pos,int ql,int qr){
    if(ql > r or qr < l) return 1;
    if(ql <= l and r <= qr) return st[pos];
    int m = (l+r)/2;
    int left = query(l, m, 2*pos+1, ql, qr);
    int right = query(m+1, r, 2*pos+2, ql, qr);
    return left*right%10;
  }
  int query(int l,int r){
    return query(0, n-1, 0, l, r);
  }
};

int main(){
  fastio;

  ll n,m;
  vi prod(nax+1,1), qtd_2(nax+1,0), qtd_5(nax+1, 0), pow_2(nax+1,1), pow_5(nax+1,1);

  for(int i=1;i<=nax;i++){
    int num = i;
    while(num % 5 == 0) num /= 5, qtd_5[i]++;
    while(num % 2 == 0) num /= 2, qtd_2[i]++;
    qtd_2[i] += qtd_2[i-1];
    qtd_5[i] += qtd_5[i-1];
    prod[i] = num;
    pow_2[i] *= 2*pow_2[i-1], pow_2[i] %= 10;
    pow_5[i] *= 5*pow_5[i-1], pow_5[i] %= 10;
  }

  SegTree st;
  st.build(prod);

  while(cin >> n >> m){
    int l = n-m+1;
    int r = n;
    int q5 = qtd_5[r] - qtd_5[l-1];
    int q2 = qtd_2[r] - qtd_2[l-1];
    int p = st.query(l, r);
    int pot;
    if(q2 >= q5) pot = pow_2[q2 - q5];
    else pot = pow_5[q5 - q2];

    int ans = p*pot%10;
    cout << ans << endl;
  }
  return 0;
}