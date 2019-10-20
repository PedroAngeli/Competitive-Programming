#include <bits/stdc++.h>

using namespace std;

int main(){

  int n;
  scanf("%d",&n);

  int a[n];
  int maior = 0;
  int menor = 105;

  for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
    maior = max(maior,a[i]);
    menor = min(menor,a[i]);
  }

  int dif = (maior-menor);

  if(dif%2 == 0){
    for(int i=0;i<n;i++){
      if(a[i] != maior && a[i] != menor && a[i] != (maior - dif/2)){
        printf("-1\n");
        return 0;
      }
    }

    printf("%d\n", dif/2);
    return 0;
  }
  else{
      for(int i=0;i<n;i++){
        if(a[i] != maior && a[i] != menor){
          printf("-1\n");
          return 0;
        }
    }

    printf("%d\n",dif);
  }


  return 0;
}