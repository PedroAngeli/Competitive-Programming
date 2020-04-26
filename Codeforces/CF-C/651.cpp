#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  unordered_map <long long,long long> x;
  unordered_map <long long,long long> y;
  map <pair<long long,long long>, long long> rep;
  set <pair <long long,long long> > s;
  
  for(int i=0;i<n;i++){
    long long a,b;
    cin >> a >> b;
    rep[{a,b}]++;
    x[a]++;
    y[b]++;
  }

  long long ans = 0;

  for(auto it = x.begin();it!=x.end();it++){
    long long qtd = it->second;
    ans += (qtd*(qtd-1))/2;
  }

  for(auto it = y.begin();it!=y.end();it++){
    long long qtd = it->second;
    ans += (qtd*(qtd-1))/2;
  }

  long long same = 0;

  for(auto it = rep.begin();it!=rep.end();it++){
    long long qtd = it->second;
    same += (qtd*(qtd-1))/2;
  }

  cout << ans - same << endl;
  return 0;
}