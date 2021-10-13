#include <bits/stdc++.h>

using namespace std;

#define endl '\n'


int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int a,x,y;
  cin >> a >> x >> y;
  int i;
  int temp = a;
  for(i=1;temp < y;i++){
    temp = a*i;
  }
  i--;

  if(y < a){
    if(x > -a/2.0 && x < a/2.0 && y > 0)
      cout << 1 << endl;
    else
      cout << -1 << endl;
  }else if(y == a){
    cout << -1 << endl;
  }else{
    if(i % 2 == 0){
      if(y < temp && x > -a/2.0 && x < a/2.0)
        cout << i + (i/2 - 1) << endl;
      else
        cout << -1 << endl;
    }else{
      if(y < temp){
        if(x < 0 && x > -a)
          cout << i + (i/2 - 1) << endl;
        else if(x > 0 && x < a)
          cout << i + i/2 << endl;
        else
          cout << -1 << endl;
      }else{
        cout << -1 << endl;
      }
    }
  }
    

  return 0;
}