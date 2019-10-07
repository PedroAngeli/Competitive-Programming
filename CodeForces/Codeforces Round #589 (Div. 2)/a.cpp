#include <bits/stdc++.h>

using namespace std;


bool dif(int x){
  bool vet[10] = {false};

  while(x){
    int d = x%10;
    if(vet[d]){
      return false;
    }
    else{
      vet[d] = true;
    }
    x = x/10;
  }

  return true;
}

int main(){

  int l,r;


  scanf("%d %d",&l,&r);

  for(int i=l;i<=r;i++){
    if(dif(i)){
      printf("%d\n",i);
      return 0;
    }
  }

  printf("-1\n");

  return 0;
}