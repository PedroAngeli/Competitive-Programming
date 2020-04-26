#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

bool isPa(vector <int> vet){
  set <int> s;

  for(int i=1;i<vet.size();i++)
    s.insert(vet[i]-vet[i-1]);

  return s.size() == 1;
}

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  map <int, vector <int> > mapa;

 for(int i=0;i<n;i++){
   int a;
   cin >> a;
   mapa[a].push_back(i);
 }

 vector <pair <int,int> > ans;

 for(auto it = mapa.begin();it != mapa.end();it++){
   vector <int> vet = it->second;
   int x = it->first;

   if(vet.size() == 1)
    ans.push_back({x,0});
   else if(isPa(vet)){
     ans.push_back({x,vet[1]-vet[0]});
   }
 }

  cout << ans.size() << endl;
 for(int i=0;i<ans.size();i++)
  cout << ans[i].first << " " << ans[i].second << endl;
  
  return 0;
}