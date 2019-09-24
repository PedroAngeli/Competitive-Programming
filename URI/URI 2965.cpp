#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int n,k;
int pai[100005];
int alt[100005];
bool temFilho[100005];
bool morto[100005];
vector < pair<int,int> > folhas;

bool cmp(pair<int,int> a,pair<int,int> b){
  return a.first > b.first || a.first == b.first && a.second < b.second;
}

bool cmp2(int a,int b){
  return a > b;
}

int calculaAltura(int no){
  if(no == -1){
    return 0;
  }

  return 1 + calculaAltura(pai[no]);
}

int dfs(int no){
  if(no == -1 || morto[no]){
    return 0;
  }

  morto[no] = true;

  return 1 + dfs(pai[no]);
}

int main(){

  scanf("%d %d",&n,&k);

  pai[1] = -1;
  alt[1] = 1;

  for(int i=1;i<=n-1;i++){
    int p;
    scanf("%d",&p);
    pai[i+1] = p;
    temFilho[p] = true;
  }

  for(int i=2;i<=n;i++){

    if(!temFilho[i]){
      alt[i] = calculaAltura(i);
      folhas.push_back({alt[i], i});
    }
  }

  sort(folhas.begin(),folhas.end(),cmp);

  int tam = folhas.size();
  

  vector <int> vet;

  for(int i=0;i<tam;i++){
    int altura = folhas[i].first;
    int no = folhas[i].second;
    int mortos = dfs(no);
    vet.push_back(mortos);
  }

  sort(vet.begin(),vet.end(),cmp2);

  int resp = 0;
  int tam2 = vet.size();

  for(int i=0;i<k && i<tam2;i++){
    resp += vet[i];
  }

  printf("%d\n", resp);

  
  return 0;
}