#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
 
  int n;
  cin >> n;
  if(n % 2 == 0)
    cout << "NO" << endl;
  else{
    cout << "YES" << endl;
    bool one = false;
    for(int i=1;i<=2*n;){
      cout << i << " ";
      if(one)
        i+=1;
      else
        i+=3;
      one = !one;
    }
    one = true;
    for(int i=2;i<=2*n;){
cout << i << " ";
      if(one)
        i+=1;
      else
        i+=3;
      one = !one;
    }
    cout << endl;
  }
  return 0;
}