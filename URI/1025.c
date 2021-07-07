#include <stdio.h>
#include <stdlib.h>

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int bb(int x,int* vet,int n){
  int l = 0;
  int r = n-1;
  int pos = -1;

  while(l <= r){
    int m = (l+r)/2;
    
    if(vet[m] == x){
      r = m-1;
      pos = m;
    }else if(vet[m] < x)
      l = m+1;
    else
      r = m-1;
  }

  return pos;
}
int main(){

  int n,q;
  int ncase = 1;

  while(scanf("%d %d",&n,&q) == 2){
    if(!n && !q)
      break;
    int vet[n];
    printf("CASE# %d:\n",ncase++);
    int i;
    for(i=0;i<n;i++)
      scanf("%d",&vet[i]);
    
       qsort(vet, n, sizeof(int), cmpfunc);

    while(q--){
      int x;
      scanf("%d",&x);
      int pos = bb(x,vet,n);

      if(pos == -1)
        printf("%d not found\n",x);
      else
        printf("%d found at %d\n",x,pos+1);
    }

  }

    
  return 0;
}