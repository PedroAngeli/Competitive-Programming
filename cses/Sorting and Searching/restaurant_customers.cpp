#include <bits/stdc++.h>

using namespace std;


bool cmp(pair <int, int> a, pair <int, int> b){
  return a.second < b.second;
}

int main(){

  int n;

  cin >> n;

  vector < pair <int,int> > chegada;
  vector < pair <int,int> > saida;

  for(int i=0;i<n;i++){
    int a,b;
    cin >> a >> b;
    chegada.push_back({a,b});
    saida.push_back({a,b});
  }

  sort(chegada.begin(),chegada.end());
  sort(saida.begin(),saida.end(),cmp);

  int resp = 0;
  int count = 1;

  for(int i=1,j=0;i<n;i++){
    if(chegada[i].first < saida[j].second){
      count++;
    }else{
      j++;
      resp = max(resp, count);
    }
  }
  resp = max(resp, count);
  cout << resp << endl;

  return 0;
}