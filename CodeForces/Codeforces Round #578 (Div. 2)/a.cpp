#include <cstdio>
#include <cstring>

bool hotel[10];

int charToI(char a){
  return a - '0';
}

int main(){

  int n;
  scanf("%d%*c",&n);
  char str[n];

  scanf("%s",str);

  int tam = strlen(str);

  for(int i=0;i<tam;i++){
    if(str[i] == 'L'){
      for(int j=0;j<10;j++){
        if(!hotel[j]){
          hotel[j] = true;
          break;
        }
      }
    }else if(str[i] == 'R'){
      for(int j=9;j>=0;j--){
        if(!hotel[j]){
          hotel[j] = true;
          break;
        }
      }
    }else{
      int num = charToI(str[i]);
      hotel[num] = 0;
    }
  }

  for(int i=0;i<10;i++){
    printf("%d",hotel[i]);
  }

  printf("\n");

  return 0;
}


