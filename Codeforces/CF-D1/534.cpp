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


int main(){
  fastio;
  int n;
  cin >> n;
  vi freq(n,0);
  vi ids[n];

  for(int i=0;i<n;i++){
    int x;
    cin >> x;
    freq[x]++;
    ids[x].push_back(i+1);
  }

  vi ans;

  int p = 0;

  while(ans.size() < n){
    while(p >= 0 && freq[p] == 0){
      p-=3;
    }

    if(p < 0){
      cout << "Impossible" << endl;
      return 0;
    }

    freq[p]--;
    ans.push_back(ids[p].back());
    ids[p].pop_back();
    p++;
  }

  cout << "Possible" << endl;
  for(int x:ans)
    cout << x << " ";
  cout << endl;
  
  return 0;
}