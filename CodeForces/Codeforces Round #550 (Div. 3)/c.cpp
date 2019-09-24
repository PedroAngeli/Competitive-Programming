#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;


int main(){

  int n;
  scanf("%d",&n);

  vector <int> vet;
  vector <int> inc;
  vector <int> dec;

  for(int i=0;i<n;i++){
    int a;
    scanf("%d",&a);
    vet.push_back(a);
  }

  sort(vet.begin(),vet.end());

  inc.push_back(vet[0]);
  int can = true;

  for(int i=1;i<n;i++){
    if(vet[i] > inc[inc.size()-1]){
      inc.push_back(vet[i]);
    }
    else if(dec.size()){
      if(vet[i] > dec[dec.size()-1]){
        dec.push_back(vet[i]);
      }
      else{
        can = false;
        break;
      }
    }
    else{
      dec.push_back(vet[i]);
    }
  }

  if(can){
    printf("YES\n");
    printf("%d\n",(int)inc.size());

    for(int i=0;i<inc.size();i++){
      if(i == inc.size()-1)
        printf("%d\n",inc[i]);
      else
        printf("%d ",inc[i]);
    }

    printf("%d\n",(int)dec.size());

    for(int i=dec.size()-1;i>=0;i--){
      if(i == 0)
        printf("%d\n",dec[i]);
      else
        printf("%d ",dec[i]);
    }
  }
  else{
    printf("NO\n");
  }
  
  return 0;
}