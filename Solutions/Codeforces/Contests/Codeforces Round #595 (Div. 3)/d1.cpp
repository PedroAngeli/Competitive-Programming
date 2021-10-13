#include <bits/stdc++.h>

using namespace std;


int main(){

  int n,k;

  cin >> n >> k;
  vector < pair <int,int> > segmentos;
  vector <int> pontos(205,0);
  vector <bool> removido(n,false);
  vector <int> ans;

  int e = 1e9 + 5;
  int d = 0;

  for(int i=0;i<n;i++){
    int l,r;
    cin >> l >> r;
    segmentos.push_back(make_pair(l,r));

    for(int j=l;j<=r;j++)
      pontos[j]++;

    e = min(e,l);
    d = max(d,r);
  }

  for(int i=e;i<=d;i++){
    if(pontos[i] > k){
       int maior = 0;
       int idx = 0;
       
      for(int j=0;j<n;j++){
         int l = segmentos[j].first;
         int r = segmentos[j].second;
        
        if(l <= i && i <=r && !removido[j]){
          if(r > maior){
            maior = r;
            idx = j;
          }
        }
      }
      
      removido[idx] = true;
      ans.push_back(idx);
      int l = segmentos[idx].first;
      int r = segmentos[idx].second;

      for(int j=l;j<=r;j++)
        pontos[j]--;

      i--;
    }
  }

  cout << ans.size() << endl;

  for(int i=0;i<ans.size();i++)
    cout << ans[i]+1 << " ";

  cout << endl;

  
  return 0;
}