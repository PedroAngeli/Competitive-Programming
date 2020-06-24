#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int t = 1;
  cin >> t;

  while(t--){
    string b;
    cin >> b;
    int n = b.size();
    bool printed = false;
    for(int i=0;i<n;i+=2){
      if(n-1 == i)
        printed = true;
      cout << b[i];

    }

    if(!printed)
      cout << b[n-1] << endl;
  }

  return 0;
}