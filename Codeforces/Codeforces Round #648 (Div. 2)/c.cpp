#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int t = 1;
  // cin >> t;

  while(t--){
    int n;
    cin >> n;
    int a[n];
    int b[n];
    for(int i=0;i<n;i++)
      cin >> a[i];
    
    int pos[n+1];
    for(int i=0;i<n;i++){
      cin >> b[i];
      pos[b[i]] = i;
    }
    
    vector <pair <int,int> > shift;

    for(int i=0;i<n;i++){
      if(pos[a[i]] == i)
        shift.push_back({0,0});
      else if(pos[a[i]] > i){
        shift.push_back({pos[a[i]]-i,n-pos[a[i]]+i});
      }else{
        shift.push_back({pos[a[i]]+(n-i),i-pos[a[i]]});
      }
    }

    int cntL[n+1];
    int cntR[n+1];
    memset(cntL,0,sizeof cntL);
    memset(cntR,0,sizeof cntR);

    for(int i=0;i<n;i++){
      cntL[shift[i].first]++;
      cntR[shift[i].second]++;
    }

    int ans = 0;
    for(int i=0;i<=n;i++){
      ans = max({ans,cntL[i],cntR[i]});
    }

    cout << ans << endl;

  }

  return 0;
}