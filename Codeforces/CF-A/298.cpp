#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int cnt[1001];

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;

  string s;

  cin >> n;
  cin >> s;

  int posRi = 1e9;
  int posRf = -1;
  int posLf = -1;
  int posLi = 1e9;
  
  for(int i=1;i<=n;i++){
    if(s[i-1] == 'R'){
      posRi = min(posRi,i);
      posRf = max(posRf,i);
    }
    else if(s[i-1] == 'L'){
      posLf = max(posLf,i);
      posLi = min(posLi,i);
    }
      
  }

  if(posRi == 1e9){
    cout << posLf << " " << posLi - 1 << endl;
  }else if(posLi == 1e9){
    cout << posRi << " " << posRf + 1 << endl; 
  }else{
    cout << posLf << " " << posRf + 1 << endl;
  }

  return 0;
}