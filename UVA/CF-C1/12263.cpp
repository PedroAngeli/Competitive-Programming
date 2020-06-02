#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

const int nax = 505;
int pos[nax];

int main(){
  
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  while(t--){
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
      int a;
      cin >> a;
      pos[a] = i;
    }

    int m;
    cin >> m;
    vector <pair<int,int> > changes;

    while(m--){
      int a,b;
      cin >> a >> b;
      changes.push_back({a,b});
    }
    bool can = true;

    while(changes.size() > 0){
      pair <int,int> cur;
      int idx = -1;
      for(int i=0;i<changes.size();i++){
        if(abs(pos[changes[i].first] - pos[changes[i].second]) == 1){
          idx = i;
          cur = changes[i];
          break;
        }
      }

      if(idx == -1){
        cout << "IMPOSSIBLE" << endl;
        can = false;
        break;
      }

      swap(pos[cur.first],pos[cur.second]);
      changes.erase(changes.begin()+idx);
    }

    if(can){
      vector <pair<int,int>> ans;
      for(int i=1;i<=n;i++){
        ans.push_back({pos[i],i});
      }

      sort(ans.begin(),ans.end());

      for(int i=0;i<n;i++){
        if(i == n-1)
          cout << ans[i].second << endl;
        else
          cout << ans[i].second << " ";
      }
    }
    
  }
    
  return 0;
}