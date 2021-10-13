#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

struct sort_pairs{
  bool operator()(pair <int,int> p1,pair<int,int> p2){
    int dif1 = p1.second - p1.first;
    int dif2 = p2.second - p2.first;
    if(dif1 == dif2)
      return p1.first < p2.first;
    return dif1 > dif2;
  }
};

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    set <pair <int,int>, sort_pairs> s;
    s.insert({1,n});
    int ans[n+1];

    for(int i=1;i<=n;i++){
      auto it = s.begin();
      int l = it->first;
      int r = it->second;
      s.erase(s.begin());
      int m;
      
      if((r-l+1) % 2 == 0){
        m = (l+r-1)/2;
      }else{
        m = (l+r)/2;
      }

      ans[m] = i;

        if(m-1 >= 0 && m-1>=l)
          s.insert({l,m-1});
        if(m+1 <= n && m+1 <= r)
        s.insert({m+1,r});
    }

    for(int i=1;i<=n;i++)
      cout << ans[i] << " ";

    cout << endl;
  }

  return 0;
}