#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

using ld = long double;
using ll = long long;

#define endl '\n'
#define f first
#define s second
#define ub  upper_bound
#define lb  lower_bound
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
template <class T>
	using ord_set = tree<T, null_type, less<T>, rb_tree_tag,
	tree_order_statistics_node_update>;
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

int n, q;
int resp;

map <int, int> freq_num;
map <int,int> freq_freq;

struct  Query{
  int idx, l, r;
};

void add(int x){
  freq_num[x]++;
  int f = freq_num[x];
  freq_freq[f]++;
  if(freq_freq[f] >= f)
    resp = max(resp, f);
}

void rem(int x){
  int f = freq_num[x];
  if(f == freq_freq[f])
    resp--;
  freq_num[x]--;
  freq_freq[f]--;
}

vector <int> MO(vector <int>& a, vector <Query>& querys){
  int l = 0;
  int r = -1;
  vector <int> ans(querys.size());

  int n = a.size();
  int sqrt_n = sqrt(n) + 1;
  sort(all(querys), [&](auto q1, auto q2){
    if((q1.l/sqrt_n) != (q2.l/sqrt_n)) return q1.l < q2.l;
    return q1.r < q2.r;
  });

  map <int,int> freq;
  int lgn = 16;

  for(Query q: querys){
    while(l > q.l){
      l--;
      add(a[l]);
    }

    while(r < q.r){
      r++;
      add(a[r]);
    }

    while(l < q.l){
      rem(a[l]);
      l++;
    }

    while(r > q.r){
      rem(a[r]);
      r--;
    }

    ans[q.idx] = resp;
  }
  
  return ans;
}


int main(){
  fastio;

  cin >> n >> q;
  vector <int> a(n);

  for(int i=0;i<n;i++)
    cin >> a[i];
  
  vector <Query> querys;

  for(int i=0;i<q;i++){
    int l, r;
    cin >> l >> r;
    l--, r--;
    querys.push_back({i, l, r});
  }

  vector <int> ans = MO(a, querys);

  for(int x:ans)
    cout << x << endl;
  
  return 0;
}