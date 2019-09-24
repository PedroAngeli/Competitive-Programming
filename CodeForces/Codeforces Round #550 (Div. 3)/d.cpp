#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
 
 
using namespace std;
 
vector <int> vet;
vector <int> c;
 
int main(){
  int n;
  scanf("%d",&n);
  c.assign(200005,0);
 
  for(int i=0;i<n;i++){
    int a;
    scanf("%d",&a);
    c[a]++;
    vet.push_back(a);
  }
 
  int maior = max_element(c.begin(), c.end()) - c.begin();
  int pos = find(vet.begin(),vet.end(),maior) - vet.begin();
  
  printf("%d\n",n-c[maior]);
 
  for(int i=pos;i>0;i--){
    if(vet[i] > vet[i-1]){
      printf("1 %d %d\n", i,i+1);
      vet[i-1] = vet[i];
    }
    else if(vet[i] < vet[i-1]){
      printf("2 %d %d\n",i,i+1);
      vet[i-1] = vet[i];
    }
  }
 
  for(int i=0;i<n-1;i++){
    if(vet[i] > vet[i+1]){
      printf("1 %d %d\n",i+2,i+1);
    }
    else if(vet[i] < vet[i+1]){
      printf("2 %d %d\n",i+2,i+1);
    }
 
    vet[i+1] = vet[i];
 
  }
 
 
  return 0;
}