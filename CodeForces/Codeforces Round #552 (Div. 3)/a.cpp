#include <bits/stdc++.h>

using namespace std;

int main(){

  int vet[4];
  int maior = 0;

  for(int i=0;i<4;i++){
    scanf("%d",&vet[i]);
    maior = max(maior, vet[i]);
  }

  int resp[3], j=0;

   for(int i=0;i<4;i++){
    if(vet[i] != maior)
      resp[j++] = maior - vet[i];
  }

  for(int i=0;i<3;i++){
    if(i == 2)
      printf("%d\n", resp[i]);
    else
      printf("%d ", resp[i]);
  }


  return 0;
}