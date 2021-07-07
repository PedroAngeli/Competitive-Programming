#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

const int nax = 2e5 + 1;

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  vector <set <pair <int,int>,greater<pair<int,int>> > > s(nax);

  int n,q;
  cin >> n >> q;
  
  int rating[n+1];
  int garden[nax];

  for(int i=1;i<=n;i++){
    int b;
    cin >> rating[i] >> b;
    s[b].insert({rating[i],i});
    garden[i] = b;
  }

  set <pair <int,int> > ans;

  for(int i=1;i<nax;i++){
    if(s[i].size()){
        auto it = s[i].begin();
        int r = it->first;
        ans.insert({r,it->second});
    }
  }

  while(q--){
    int c,d;
    cin >> c >> d;
    int r = rating[c];
    int curGarden = garden[c];

    auto it = s[curGarden].begin();

    if(it->second == c){
      ans.erase({r,c});
      s[curGarden].erase({r,c});
      if(s[curGarden].size()){
        auto it = s[curGarden].begin();
        ans.insert({it->first,it->second});
      }
    }

    s[curGarden].erase({r,c});

    it = s[d].begin();

    if(r > it->first){
      ans.erase({it->first,it->second});
    }

    s[d].insert({r,c});
    it = s[d].begin();
    ans.insert({it->first,it->second});

    garden[c] = d;

    cout << ans.begin()->first << endl; 
  }
 
  return 0;
}