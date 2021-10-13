#include <bits/stdc++.h>

using namespace std;

int main(){

  int vet[5];

  for(int i=1;i<=4;i++)
    cin >> vet[i];

  char c;
  int ans = 0;
  while(cin >> c){
    int num = c-'0';
    ans += vet[num];
  }

  cout << ans << endl;

  return 0;
}