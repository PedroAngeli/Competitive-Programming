#include <bits/stdc++.h>

using namespace std;

#define endl '\n'


int main(){
  
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  while(true){
    vector <int> c;
    vector <int> x;

    int cf;
    char aux;

    while(scanf("%d",&cf) == 1){
      scanf("%c",&aux);
      c.push_back(cf);
      if(aux == '\n')
        break;
    }

    if(c.size() == 0)
      break;

    while(scanf("%d",&cf) == 1){
      scanf("%c",&aux);
      x.push_back(cf);
      if(aux == '\n')
        break;
    }

    for(int i=0;i<x.size();i++){
      int sz = c.size();
      long long ans = 0;
      for(int j=0;j<sz;j++){
        ans += (c[j]*pow(x[i],sz-j-1));
      }
      if(i < x.size() - 1) cout << ans << " ";
      else cout << ans << endl;
    }
  }
  
  
  return 0;
}