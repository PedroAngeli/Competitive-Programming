#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define f first
#define s second
using ll = long long;
using ii = pair <int,int>;
using pll = pair <ll,ll>;
using vi = vector <int>;
using vll = vector <ll>;
using vii = vector <ii>;
using vpll = vector<pll>;

int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int n,m;
  cin >> n >> m;

  vpll islands(n);

  for(int i=0;i<n;i++)
    cin >> islands[i].f >> islands[i].s;
  
  map <ll,vi> bridges;

  for(int i=0;i<m;i++){
    ll x;
    cin >> x;
    bridges[x].push_back(i);
  }
  
  vector <pair <ll,int > > gaps;

  for(int i=0;i<n-1;i++){
    gaps.push_back({islands[i+1].f-islands[i].s,i});
  }

  sort(gaps.begin(),gaps.end(),[&](auto p1,auto p2){
    return (p1.f > p2.f) || (p1.f == p2.f && p1.s < p2.s);
  });

  vi ans(n-1);

  for(int i=0;i<n-1;i++){
    int idx = gaps[i].s;
    ll mn = gaps[i].f;
    ll mx = islands[idx+1].s - islands[idx].f;

    auto it1 = bridges.lower_bound(mn);

    if(it1 == bridges.end()){
      cout << "No" << endl;
      return 0;
    }

    auto it2 = bridges.lower_bound(mx);

    if(it2 == bridges.end())
      it2--;

    if(it2 != bridges.begin() && it2->f > mx)
      it2--;
    
    if(it2->f >= mn && it2->f <= mx){
      int pos = it2->s.back();
      ans[idx] = pos+1;
      it2->s.pop_back();
      if(it2->s.size() == 0)
        bridges.erase(it2);
    }else{
      cout << "No" << endl;
      return 0;
    }
    
  }

  cout << "Yes" << endl;
  for(int x:ans)
    cout << x << " ";
  cout << endl;

  return 0;
}