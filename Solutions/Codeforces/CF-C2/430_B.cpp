#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  
  int n,k,x;

  cin >> n >> k >> x;
  vector <int> vet(n);

  for(int i=0;i<n;i++){
    cin >> vet[i];
  }
  int ans = 0;


  for(int i=1;i<n;i++){
    vector <int> tmp(vet.begin(),vet.end());
    int cnt = 0;
    if(tmp[i] == tmp[i-1] && tmp[i] == x){
      tmp.erase(tmp.begin()+i-1,tmp.begin()+i+1);
      cnt = 2;
      bool remove = true;
      while(remove){
        remove = false;
        for(int j=0;j<tmp.size()-1;j++){
          int qtd = 1;
          int idx = j;
          while(idx < tmp.size()-1 && tmp[idx] == tmp[idx+1])
            qtd++,idx++;
          if(qtd >= 3){
            if(idx == tmp.size()-1)
              tmp.erase(tmp.begin()+j,tmp.begin()+idx);
            else
              tmp.erase(tmp.begin()+j,tmp.begin()+idx+1);
            remove = true;
            cnt+=qtd;
            break;
          }
        }
      }
    }
    ans = max(ans,cnt);
  }

  cout << ans << endl;


  return 0;
}