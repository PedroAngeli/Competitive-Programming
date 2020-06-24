#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'

typedef struct{
  int x,y,z,idx;
}Point;
 
int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
 
  int n;
  cin >> n;
  vector <Point> vet(n);
 
  for(int i=0;i<n;i++){
    cin >> vet[i].x >> vet[i].y >> vet[i].z;
    vet[i].idx = i+1;
  }
 
  sort(vet.begin(),vet.end(),[&](auto p1,auto p2){
    if(p1.z == p2.z){
      if(p1.y == p2.y){
        return p1.x < p2.x;
      }
      return p1.y < p2.y;
    }
    return p1.z < p2.z;
  });

  vector <Point> aux;

  for(int i=0;i<n;i++){
    int len = aux.size();
    if(vet[i].z == vet[i+1].z && vet[i].y == vet[i+1].y){
      cout << vet[i].idx << " " << vet[i+1].idx << endl;
      i++;   
    }else if(len && aux.back().z == vet[i].z){
       cout << aux.back().idx << " " << vet[i].idx << endl;
        aux.pop_back();
    }else{
      aux.push_back(vet[i]);
    }
  }

  int len = aux.size();
  for(int i=0;i<len;i+=2){
    cout << aux[i].idx << " " << aux[i+1].idx << endl;
  }

 
  
  
  return 0;
}