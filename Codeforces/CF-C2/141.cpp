#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'

int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL); 

  int n;
  cin >> n;
  map <string,int> mp;

  vector <pair <int,string> > vet(n);
  for(int i=0;i<n;i++){
    cin >> vet[i].second >> vet[i].first;
  }
  sort(vet.begin(),vet.end());
  reverse(vet.begin(),vet.end());

  vector <pair <string,int> > ans(n, {"",0});

  for(int i=0;i<n;i++){
    int posMn = vet[i].first;
    string name = vet[i].second;
    bool findPos = false;

    for(int j=posMn;j<n;j++){
      if(ans[j].first == ""){
        ans[j].first = name;
        ans[j].second = 3000-posMn;
        findPos = true;
        break;
      }
    }

    if(!findPos){
      cout << -1 << endl;
      return 0;
    }
  }

  for(int i=0;i<n;i++)
    cout << ans[i].first << " " << ans[i].second << endl;
  return 0;
}