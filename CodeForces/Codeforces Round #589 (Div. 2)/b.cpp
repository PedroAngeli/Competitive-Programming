#include <bits/stdc++.h>

using namespace std;

#define BRANCO 0
#define PRETO 1
#define NEUTRO -1
#define m 1000000007

int mat[1005][1005];
int linha[1005];
int coluna[1005];

int main(){

  int h,w;

  scanf("%d %d",&h,&w);

  memset(mat,NEUTRO,sizeof(int)*1005*1005);

  for(int i=0;i<h;i++){
    scanf("%d",&linha[i+1]);
  }

  for(int i=0;i<w;i++){
    scanf("%d",&coluna[i+1]);
  }

  //percorrendo as linhas
  for(int i=1;i<=h;i++){
    if(!linha[i]){
      mat[i][1] = BRANCO;
    }
    else{
      for(int j=1;j<=linha[i];j++){
        mat[i][j] = PRETO;
      }
      mat[i][linha[i]+1] = BRANCO;
    }
  }

  //percorrendo as colunas
  for(int i=1;i<=w;i++){
    if(!coluna[i]){
      if(mat[1][i] == PRETO){
        printf("0\n");
        return 0;
      }else{
        mat[1][i] = BRANCO;
      }
    }
    else{
      for(int j=1;j<=coluna[i];j++){
        if(mat[j][i] == BRANCO){
          printf("0\n");
          return 0;
        }
        else{
          mat[j][i] = PRETO;
        }
      }

      if(mat[coluna[i]+1][i] == PRETO){
        printf("0\n");
        return 0;
      }
      else{
        mat[coluna[i]+1][i] = BRANCO;
      }
    }
  }
  int resp = 1;

  for(int i=1;i<=h;i++){
    for(int j=1;j<=w;j++){
      // printf("%d",mat[i][j]);
      if(mat[i][j] == NEUTRO)
          resp = ((resp % m) * 2) % m;
    }
    // printf("\n");
  }
    

    printf("%d\n",resp);



  return 0;
}