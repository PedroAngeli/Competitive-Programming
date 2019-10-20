#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
 
  char vet[] = {'f','f','r','c','f','c','r'};
 
  int f, r, c;
  int maior = 0;
 
  scanf("%d %d %d", &f,&r,&c);
 
  for(int i=0;i<7;i++){
 
    int df = f/3, dr = r/2, dc = c/2;
    int menor = min(df, min(dr,dc));
    int resp = menor * 7;
    int rf = f-menor*3, rr = r-menor*2, rc = c-menor*2;
    
    for(int j=i;j<i+7;j++){
      if(vet[j%7] == 'f'){
        if(rf){
          rf--;
        resp++;
        continue;
        }
        else break;
      }
      
      if(vet[j%7] == 'r'){
        if(rr){
          rr--;
        resp++;
        continue;
        }
        else break;
      }
      
 
      if(vet[j%7] == 'c'){
        if(rc){
          rc--;
        resp++;
        continue;
        }
        else break;
      }
      
    }
   
    maior = max(maior,resp);
  }
 
  printf("%d\n",maior);
  return 0;
}