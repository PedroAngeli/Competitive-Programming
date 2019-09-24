#include <cstdio>
#include <cmath>     
#include <algorithm>
 
using namespace std;
 
    int main(){
      int t;
      scanf("%d",&t);
     
      while(t--){
        int n,m,k;
        scanf("%d %d %d",&n,&m,&k);
        int vet[n];
     
        for(int i=0;i<n;i++){
          scanf("%d",&vet[i]);
        }
      
        bool pode = true;
     
        for(int i=0;i<n-1;i++){
          int dif = abs(vet[i]-vet[i+1]);
 
          if(dif <= k){
              m+=vet[i]-max(0,vet[i+1]-k);
          }
          else{
              if(vet[i] > vet[i+1]){
                m+=vet[i]-max(0,vet[i+1]-k);
              }
              else{
                  m-=(dif-k);
              }
              if(m < 0){
                  pode = false;
                  break;
              }
          }
        }
     
        if(pode){
          printf("YES\n");
        }else{
          printf("NO\n");
        }
     
      }
     
      return 0;
    } 