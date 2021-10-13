#include <bits/stdc++.h>

using namespace std;


int main(){

  int n;

  cin >> n;

  int vet[n];

  for(int i=0;i<n;i++)
    cin >> vet[i];

  int a=0,b=0;

  int l=0,r=n-1;

  bool turn = 0;

  while(l <= r){

    if(!turn){
      if(vet[l] > vet[r])
       a+=vet[l],l++;
      else
      a+=vet[r],r--;
    }else{
      if(vet[l] > vet[r])
      b+=vet[l],l++;
      else
      b+=vet[r],r--;
    }

    turn = !turn;
  }

  cout << a << " " << b << endl;


  return 0;
}