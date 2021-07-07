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

pair <pii, pii> find_left(pii p1, pii p2){
  int qtd = (p2.s - p1.s + 2)/2;
  pii r1 = p1;
  pii r2 = {p1.f, p1.s + qtd - 1};
  return {r1,r2};
}

pair <pii, pii> find_right(pii p1, pii p2){
  int qtd = (p2.s - p1.s + 2)/2;
  pii r1 = {p1.f, p1.s + qtd};
  pii r2 = p2;
  return {r1, r2};
}

pair <pii, pii> find_top(pii p1, pii p2){
  int qtd = (p2.f - p1.f + 2)/2;
  pii r1 = p1;
  pii r2 = {p1.f + qtd - 1, p1.s};
  return {r1,r2};
}

pair <pii, pii> find_bottom(pii p1, pii p2){
  int qtd = (p2.f - p1.f + 2)/2;
  pii r1 = {p1.f + qtd, p1.s};
  pii r2 = p2;
  return {r1,r2};
}

pair <pii,pii> find_tl(pii p1, pii p2){
  int qf = (p2.f - p1.f + 2)/2;
  int qs = (p2.s - p1.s + 2)/2;
  pii r1 = p1;
  pii r2 = {p1.f + qf - 1, p1.s + qs - 1};
  return {r1,r2};
}

pair <pii,pii> find_tr(pii p1, pii p2){
  int qf = (p2.f - p1.f + 2)/2;
  int qs = (p2.s - p1.s + 2)/2;
  pii r1 = {p1.f, p1.s + qs};
  pii r2 = {p1.f + qf - 1, p2.s};
  return {r1,r2};
}

pair <pii,pii> find_bl(pii p1, pii p2){
  int qf = (p2.f - p1.f + 2)/2;
  int qs = (p2.s - p1.s + 2)/2;
  pii r1 = {p1.f + qf, p1.s};
  pii r2 = {p2.f, p1.s + qs - 1};
  return {r1,r2};
}

pair <pii,pii> find_br(pii p1, pii p2){
  int qf = (p2.f - p1.f + 2)/2;
  int qs = (p2.s - p1.s + 2)/2;
  pii r1 = {p1.f + qf, p1.s + qs};
  pii r2 = p2;
  return {r1,r2};
}

void solve1(pii p1, pii p2, vector <vector <char> >& mat, string& ans){
  int c0 = 0, c1 = 0, total = 0;
  for(int i=p1.f;i<=p2.f;i++)
    for(int j=p1.s;j<=p2.s;j++)
        c0 += (mat[i][j] == '0'), c1 += (mat[i][j] == '1'), total++;
  
  if(c0 == total) ans += "0";
  else if(c1 == total) ans += "1";
  else{
    ans += "D";
    if(p2.f - p1.f == 0){
      solve1(find_left(p1,p2).f, find_left(p1,p2).s, mat, ans);
      solve1(find_right(p1,p2).f, find_right(p1,p2).s, mat, ans);
    }else if(p2.s - p1.s == 0){
      solve1(find_top(p1,p2).f, find_top(p1,p2).s, mat, ans);
      solve1(find_bottom(p1,p2).f, find_bottom(p1,p2).s, mat, ans);
    }else{
      solve1(find_tl(p1,p2).f, find_tl(p1,p2).s, mat, ans);
      solve1(find_tr(p1,p2).f, find_tr(p1,p2).s, mat, ans);
      solve1(find_bl(p1,p2).f, find_bl(p1,p2).s, mat, ans);
      solve1(find_br(p1,p2).f, find_br(p1,p2).s, mat, ans);
    }
  }
}

int idx;

void solve2(pii p1, pii p2, string& code, vector <vector <char> >& ans){
  if(code[idx] == 'D'){
    idx++;
    if(p2.f - p1.f == 0){
      solve2(find_left(p1,p2).f, find_left(p1,p2).s, code, ans);
      solve2(find_right(p1,p2).f, find_right(p1,p2).s, code, ans);
    }else if(p2.s - p1.s == 0){
      solve2(find_top(p1,p2).f, find_top(p1,p2).s, code, ans);
      solve2(find_bottom(p1,p2).f, find_bottom(p1,p2).s, code, ans);
    }else{
      solve2(find_tl(p1,p2).f, find_tl(p1,p2).s, code, ans);
      solve2(find_tr(p1,p2).f, find_tr(p1,p2).s, code, ans);
      solve2(find_bl(p1,p2).f, find_bl(p1,p2).s, code, ans);
      solve2(find_br(p1,p2).f, find_br(p1,p2).s, code, ans);
    }
  }else{
    for(int i=p1.f;i<=p2.f;i++)
      for(int j=p1.s;j<=p2.s;j++)
        ans[i][j] = code[idx];
    idx++;
  }
}

int main(){
  fastio;

  string line;

  while(getline(cin, line)){
    if(line == "#") break;
    stringstream ss(line);
    char type;
    int n,m;
    ss >> type >> n >> m;
    if(type == 'B'){
      string ans = "";
      vector <vector <char > > mat(n, vector <char>(m));
      for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
          cin >> mat[i][j];
      pii top_left = {0,0};
      pii bottom_right = {n-1,m-1};
      solve1(top_left, bottom_right, mat, ans);
      cout << "D";cout.width(4);cout << n;cout.width(4);cout << m << endl;
      vs formatted;
      string tmp = "";
      for(int i=0;i<sz(ans);i++){
        tmp += ans[i];
        if(sz(tmp) == 50){
          formatted.pb(tmp);
          tmp = "";
        }
      }
      if(sz(tmp)) formatted.pb(tmp);
      for(auto S:formatted) cout << S << endl;
    }else{
      string code;
      cin >> code;
      vector <vector <char> > ans(n, vector <char> (m));
      pii top_left = {0,0};
      pii bottom_right = {n-1,m-1};
      idx = 0;
      solve2(top_left, bottom_right, code, ans);
      cout << "B";cout.width(4);cout << n;cout.width(4);cout << m << endl;
      vs formatted;
      string tmp = "";

      for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
          tmp += ans[i][j];
          if(sz(tmp) == 50){
            formatted.pb(tmp);
            tmp = "";
          }
        }

      if(sz(tmp)) formatted.pb(tmp);
      for(auto S:formatted) cout << S << endl;
    }
    getline(cin,line);
  }
  return 0;
}