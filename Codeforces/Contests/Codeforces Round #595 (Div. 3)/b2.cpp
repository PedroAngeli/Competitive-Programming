#include <bits/stdc++.h>

using namespace std;

vector <int> vet;
vector <int> ans;
vector <int> ciclo;

int solve(int i,int x){
   ciclo.push_back(i);
  if(x == i)
    return 1;

  return 1 + solve(vet[i],x);
}

int main(){

  int q;
  cin >> q;

  while(q--){
    int n;
    cin >> n;
    vet = vector <int> (n+1);
    ans = vector <int> (n+1,0);

    for(int i=1;i<=n;i++)
      cin >> vet[i];

    for(int i=1;i<=n;i++){
      ciclo.clear();
      if(!ans[i]){
        ans[i] = solve(vet[i],i);
        for(auto &el : ciclo){
          ans[el] = ciclo.size();
        }
      }
    }

    for(int i=1;i<=n;i++)
      cout << ans[i] << " ";

    cout << endl;
   
  }

  return 0;
}