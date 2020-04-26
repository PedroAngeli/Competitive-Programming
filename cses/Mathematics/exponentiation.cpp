#include <bits/stdc++.h>

using namespace std;

int main(){
  
  int N;
  const long long modular = 1e9 + 7;

  cin >> N;
  
  while(N--){
    long long a,b;
    cin >> a >> b;

    bitset <64> binary(b);
    long long vet[64];
    int pos = 0;

    for(int i=63;i>=0;i--)
      if(binary[i] == 1){
        pos = i;
        break;
      }

  vet[pos] = a;

  for(int i=pos-1;i>=0;i--){
    long long temp = ((long long)(vet[i+1] * vet[i+1])) % modular;   

    if(binary[i] == 1){
      temp = (temp*a) % modular;
    }
     
    vet[i] = temp;    
  }

  if(b == 0){
    cout << "1" << endl;
  }
  else{
    cout << vet[0] << endl;
  }

  }
  
  return 0;
}