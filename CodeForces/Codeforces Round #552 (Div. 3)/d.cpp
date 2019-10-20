#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
 
    int N,B,A; 
    scanf("%d %d %d",&N,&B,&A);
    int vet[N];
 
    for(int i=0;i<N;i++)
        scanf("%d",&vet[i]);
 
    int b = B, a = A;
 
    int resp = 0;
 
    for(int i=0;i<N;i++){
        if(vet[i]){
            if(a == A){
                a--;
            }
            else if(b){
                b--;
                a++;
        }else if(a){
          a--;  
        } else break;
        }
        else{
            if(a){
                a--;
            }
            else if(b){
                b--;
            }
            else break;
        }
        
        resp++;
    }
 
    printf("%d\n",resp);
    
 
    return 0;
}