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

const int nax = (int)2e5 + 5;
int D,U;
struct SegTree {
  vll sum, tag;
  SegTree(){
    sum.assign(4 * nax,0);
    tag.assign(4 * nax,0);
  }
  void pull(int l, int r, int o) {
    if(tag[o]) sum[o] = r - l;
    else sum[o] = (l + 1 == r ? 0 : sum[o * 2 + 1] + sum[o * 2 + 2]);
  }
  void modify(int l, int r, int ql, int qr, int v, int o=0) {
    if(ql <= l && r <= qr) {
      tag[o] += v;
    }
    else {
      int mid = (l + r) >> 1, lson = o * 2 + 1, rson = o * 2 + 2;
      if(qr <= mid) modify(l, mid, ql, qr, v, lson);
      else if(mid <= ql) modify(mid, r, ql, qr, v, rson);
      else {
        modify(l, mid, ql, mid, v, lson);
        modify(mid, r, mid, qr, v, rson);
      }
    }
    pull(l, r, o);
  }
  
  ll query() {
    return sum[0];
  }
};

struct Point{
  ll x,y;
  Point(ll x=0,ll y=0):x(x),y(y){}
};

struct Seg{
  Point p,q;
};

struct Rect{
  Point p1,p2; //left-down / right-up
  Rect(Point p1,Point p2):p1(p1),p2(p2){}
  Rect(){}
  bool intersects(Rect& other){
    Point t1(max(p1.x, other.p1.x), max(p1.y, other.p1.y));
    Point t2(min(p2.x, other.p2.x), min(p2.y, other.p2.y));

    if(t1.x >= t2.x || t1.y >= t2.y) return false;
    return true;
  }
  Rect intersection(Rect& other){
    Point t1(max(p1.x, other.p1.x), max(p1.y, other.p1.y));
    Point t2(min(p2.x, other.p2.x), min(p2.y, other.p2.y));
    Rect r(t1,t2);
    return r;
  }
};

const int EXIT = -1;
const int ENTRY = 1;
vector <Seg> segs;
vector <Rect> rects;
Rect nlogonia;
int P;
int n;

struct Event {
  ll l, r, y, v;

  bool operator<(const Event& rhs) const {
    return y < rhs.y;
  }
};

bool can(int r){
  vector <Event> events;
  rects.clear();

  for(int i=0;i<n;i++){
    Point p = segs[i].p;
    Point q = segs[i].q;
    Point p1 = Point(p.x - r, p.y - r);
    Point p2 = Point(q.x + r, q.y + r);
    Rect R(p1,p2);
    Rect I = R.intersection(nlogonia);
    events.pb({I.p1.x, I.p2.x,I.p1.y, ENTRY});
    events.pb({I.p1.x, I.p2.x,I.p2.y, EXIT});
  }
  
  sort(all(events));
  SegTree st;

  ll area = 0;
  ll total_area = (nlogonia.p2.y - nlogonia.p1.y) * (nlogonia.p2.x - nlogonia.p1.x);

  ll prev_y = 0;

  for(auto [ql, qr, y, val] : events) {
    area += 1LL * st.query() * (y - prev_y);
    st.modify(0, 200000, ql, qr, val);
    prev_y = y;
  }
  
  ld tax = (ld)area/total_area;
  tax *= 100;
  return tax >= P;
}

int main(){
  fastio;

  cin >> n;
  segs.resize(n);

  for(int i=0;i<n;i++){
    cin >> segs[i].p.x >> segs[i].p.y >> segs[i].q.x >> segs[i].q.y;  
    if(segs[i].p.x > segs[i].q.x) swap(segs[i].p, segs[i].q);
    if(segs[i].p.y > segs[i].q.y) swap(segs[i].p, segs[i].q);
  }
  
  cin >> P;

  Point p1,p2;
  cin >> p1.x >> p1.y >> p2.x >> p2.y;
  nlogonia.p1 = p1, nlogonia.p2 = p2;

  int l = 1;
  int r = 1e6 + 5;
  int ans = 0;

  while(l <= r){
    int m = (l+r)/2;
    if(can(m)) ans = m, r = m-1;
    else l = m+1;
  }

  cout << ans << endl;

  return 0;
}