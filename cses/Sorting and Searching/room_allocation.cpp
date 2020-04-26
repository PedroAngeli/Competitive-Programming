#include <bits/stdc++.h>
 
using namespace std;
 
int n;
vector < pair <pair <int,int>, int > > vet;
const int INF = 1e9 + 7;
 
int main(){
 
  cin >> n;
 
  multiset <int, greater<int> > s;
  vet = vector < pair <pair <int,int>, int > >(n);
 
  for(int i=0;i<n;i++){
    int a,b;
    cin >> a >> b;
    vet[i] = {{a,b},i};
  }
 
  sort(vet.begin(),vet.end());
 
  int room = 0;
  int ans[n];
  map <int,vector <int> > mapa;
  map <int, int> countNum;

  for(int i=0;i<n;i++){
    int l = vet[i].first.first;
    int r = vet[i].first.second;
    int idx = vet[i].second;
    auto it = s.upper_bound(l);

     
 
    if(it == s.end()){
      s.insert(r);
      ans[idx] = ++room;
      mapa[r].push_back(room);
    }else{
      if(!countNum.count(*it))
        countNum[*it] = 0;
      countNum[*it]++;
      ans[idx] = mapa[*it][countNum[*it]-1];
      mapa[r].push_back(ans[idx]);
      s.erase(it);
      s.insert(r);
    }
  }
 
  cout << (int)s.size() << endl;
 
  for(int i=0;i<n;i++)
    cout << ans[i] << " ";
 
  cout << endl;
  
  return 0;
}