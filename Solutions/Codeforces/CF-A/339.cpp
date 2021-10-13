#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  char c;
  int vet[105];
  int i = 0;
  while(cin >> c){
    if(c >= '0' & c <= '9')
      vet[i++] = c-'0';
  }

  sort(vet,vet+i);

  if(i == 1)
    cout << vet[0] << endl;
  else{
    for(int k=0;k<i;k++){
      if(k == i-1)
      cout << vet[k];

      else
      cout << vet[k] << "+";
    }

    cout << endl;
  }
  
  return 0;
}