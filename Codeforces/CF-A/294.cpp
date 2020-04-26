#include <bits/stdc++.h>

using namespace std;


int main(){

 int n;
 cin >> n;
 int vet[n];

  for(int i=0;i<n;i++)
    cin >> vet[i];

  int m;

  cin >> m;

  while(m--){
    int x,y;
    cin >> x >> y;
    x--;

    if(x == 0){
      vet[x+1] += vet[x] - y;
    }else if(x == n-1){
      vet[x-1] += y-1;
    }else{
      vet[x-1] += y-1;
      vet[x+1] += vet[x] - y;
    }

    vet[x] = 0;
  }

  for(int i=0;i<n;i++)
    cout << vet[i] << endl;
  return 0;
}