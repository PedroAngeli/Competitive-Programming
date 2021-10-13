#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

vector <pair <int,int> > vet;
int m;

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;

  cin >> n >> m;

  for(int i=0;i<m;i++){
    int a,b;
    cin >> a >> b;
    vet.push_back({b,a});
  }

  sort(vet.begin(),vet.end());
  reverse(vet.begin(),vet.end());
  
  int ans = 0;

  for(int i=0;i<m && n;i++){
    ans += vet[i].first * min(n,vet[i].second);
    n -= min(n,vet[i].second);
  }

  cout << ans << endl;
  

  return 0;
}