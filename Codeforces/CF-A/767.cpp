#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;

  cin >> n;
  set <int> s;
  int maior = n;
  bool vis[n+1] = {0};

  while(n--){
    int a;
    cin >> a;
    
    if(a == maior){
      vis[a] = true;
      int i;
      for(i=maior;i>=1;i--){
        if(vis[i])
          cout << i << " ";
        else break;
      }
      maior = i;
      cout << endl;
    }else{
      vis[a] = true;
      cout << endl;
    }
  }

  
  return 0;
}