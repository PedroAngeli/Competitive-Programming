#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n,m;

  cin >> n >> m;

  char c;
  bool color = false;

  for(int i=0;i<n;i++)  
    for(int j=0;j<m;j++){
      cin >> c;
      if(c == 'C' || c == 'M' || c == 'Y')
        color = true;
    }

    if(color)
      cout << "#Color" << endl;
    else
      cout << "#Black&White" << endl;
  return 0;
}