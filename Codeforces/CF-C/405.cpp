#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  int sum = 0;
  int vet[n];

  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++){
      int a;
      cin >> a;
      if(i == j)
        sum += a,vet[i] = a;
    }

  int q;
  cin >> q;

  while(q--){
    int op;
    cin >> op;

    if(op == 3){
      cout << sum%2;
    }else{
      int u;
      cin >> u;
      u--;
      if(vet[u])
        sum--;
      else
        sum++;
      vet[u] = 1-vet[u];
    }
  }

  cout << endl;

  return 0;
}