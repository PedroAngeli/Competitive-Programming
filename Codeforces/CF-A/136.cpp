#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int cnt[4];

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  int vet[n+1];

  for(int i=0;i<n;i++){
    int a;
    cin >> a;
    vet[a] = i+1;
  }

  for(int i=0;i<n;i++){
    cout << vet[i+1] << " ";
  }

  cout << endl;
  return 0;
}