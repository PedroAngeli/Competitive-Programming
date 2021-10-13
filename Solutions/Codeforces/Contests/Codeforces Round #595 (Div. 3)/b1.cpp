#include <bits/stdc++.h>

using namespace std;

vector <int> vet;
vector <int> ans;

int solve(int i,int x){
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
    ans = vector <int> (n+1);

    for(int i=1;i<=n;i++)
      cin >> vet[i];

    for(int i=1;i<=n;i++){
      ans[i] = solve(vet[i],i);
    }

    for(int i=1;i<=n;i++)
      cout << ans[i] << " ";

    cout << endl;
   
  }

  return 0;
}