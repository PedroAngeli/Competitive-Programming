#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

const int nax = 1e5 + 5;
long long pref[nax];

long long query(int i,int j){
  if(i==0)
    return pref[j];

  return pref[j] - pref[i-1];
}

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  long long d;

  cin >> n >> d;

  vector <pair <int,int> > friends(n);

  for(int i=0;i<n;i++){
    cin >> friends[i].first >> friends[i].second;
  }

  sort(friends.begin(),friends.end());

   pref[0] = friends[0].second;

  for(int i=1;i<n;i++)
    pref[i] = pref[i-1] + friends[i].second;

  long long ans = 0;

  for(int i=0;i<n;i++){
    int l = i;
    int r = n-1;
    int pos = 0;
    int cur = friends[i].first;

    while(l <= r){
      int m = (l+r)/2;
      int x = friends[m].first;

      if(cur + d > x){
        l = m+1;
        pos = max(m,pos);
      }else{
        r = m-1;
      }
    }

    ans = max(ans, query(i,pos));
  }

  cout << ans << endl;

  
  return 0;
}