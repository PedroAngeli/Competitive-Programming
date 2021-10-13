#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

const int nax = 1e3 + 5;
bool occupied[nax];

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;

  cin >> n;

  vector <pair <pair <int,int>,int > > clients(n);

  for(int i=0;i<n;i++){
    cin >> clients[i].first.second >> clients[i].first.first;
    clients[i].second = i;
  }

  int k;
  cin >> k;
  vector <pair<int,int> > tables(k);

  for(int i=0;i<k;i++){
    cin >> tables[i].first;
    tables[i].second = i;  
  }

  sort(clients.begin(),clients.end());
  reverse(clients.begin(),clients.end());
  sort(tables.begin(),tables.end());

  int cnt = 0;
  int sum = 0;
  vector <pair <int,int> > ans;

  for(int i=0;i<n;i++){
    for(int j=0;j<k;j++){
      int r = tables[j].first;
      int c = clients[i].first.second;
      int p = clients[i].first.first;
      int idxC = clients[i].second;
      int idxT = tables[j].second;

      if(c <= r && !occupied[idxT]){
        sum += p;
        cnt++;
        occupied[idxT] = true;
        ans.push_back({idxC+1,idxT+1});
        break;
      }
    }
  }

  cout << cnt << " " << sum << endl;

  for(int i=0;i<cnt;i++){
    cout << ans[i].first << " " << ans[i].second << endl;
  }



  return 0;
}