#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

vector <int> odd;
vector <int> even;

int qtdodd;
int qtdeven;

int main(){
  int n;
  scanf("%d",&n);

  for(int i=0;i<n;i++){
    int a;
    scanf("%d",&a);

    if(a%2 == 0){
      qtdeven++;
      even.push_back(a);
    }
    else{
      qtdodd++;
      odd.push_back(a);
    }
  }

  if(abs(qtdeven-qtdodd) <= 1){
    printf("0\n");
  }
  else{
    int resp = 0;

    if(qtdodd > qtdeven){
        sort(odd.begin(),odd.end());
        for(int i=0;i<(qtdodd-qtdeven)-1;i++)
          resp += odd[i];
    }else{
        sort(even.begin(),even.end());
        for(int i=0;i<(qtdeven-qtdodd)-1;i++)
          resp += even[i];
    }

    printf("%d\n",resp);
  }


  
  return 0;
}