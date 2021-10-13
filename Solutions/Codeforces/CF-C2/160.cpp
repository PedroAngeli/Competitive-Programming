#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
  
int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
 
  long long n,k;
  cin >> n >> k;

  vector <int> vet(n);

  for(int i=0;i<n;i++)
    cin >> vet[i];

  sort(vet.begin(),vet.end());

  long long qtd = 0;

  for(int i=0;i<n;i++){
    long long tam = 1;
    while(i < n-1 && vet[i] == vet[i+1])
      tam++,i++;
    qtd += (i-tam+1)*tam;
    if(qtd >= k){
      long long passed = (qtd-k)/tam;
      int j = i-tam;
      while(passed--)
        j--;
      cout << vet[i] << " " << vet[j] << endl;
      return 0;
    }
    qtd += tam*tam;
    if(qtd >= k){
      cout << vet[i] << " " << vet[i] << endl;
      return 0;
    }
    qtd += (n-i-1)*tam;
    if(qtd >= k){
      long long passed = (qtd-k)/tam;
      int j = n-1;
      while(passed--)
        j--;
      cout << vet[i] << " " << vet[j] << endl;
      return 0;
    }
  }




  return 0;
}