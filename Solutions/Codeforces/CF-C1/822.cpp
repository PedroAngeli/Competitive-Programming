#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

const long long INF = 1e18;
const int nax = 2e5 + 5;

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int n,x;
  cin >> n >> x;

  vector <pair<pair <int,int>, long long > > vet(n);

  for(int i=0;i<n;i++)
    cin >> vet[i].first.first >> vet[i].first.second >> vet[i].second; 
  
  sort(vet.begin(),vet.end());

  vector <pair<int,long long> > mn[nax+1];

  for(int i=0;i<n;i++)
      mn[vet[i].first.second-vet[i].first.first+1].push_back({vet[i].first.first,vet[i].second});

  for(int i=1;i<=nax;i++){
    for(int j=mn[i].size()-2;j>=0;j--){
      mn[i][j].second = min(mn[i][j].second, mn[i][j+1].second);
    }
  }

  long long ans = INF;

  for(int i=0;i<n;i++){
    int curL = vet[i].first.first;
    int curR = vet[i].first.second;
    int curLen = curR - curL + 1;
    long long curCost = vet[i].second;
    int need = x - curLen;

    if(need < 0)
      continue;

    int l = 0;
    int r = mn[need].size()-1;

    while(l <= r){
      int mid = (l+r)/2;

      if(mn[need][mid].first > curR){
        r = mid-1;
        ans = min(ans, curCost + mn[need][mid].second);
      }else
        l = mid + 1;
    }
  }

  if(ans == INF)
    cout << -1 << endl;
  else
  cout << ans << endl;


  return 0;
}