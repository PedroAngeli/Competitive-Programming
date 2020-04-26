#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string s;
  cin >> s;
  
  int k;
  cin >> k;

  int n = s.size();

  while(k){
    bool trade = false;
    for(int i=0;i<n;i++){
      int pos = -1;
      char cur = s[i];
      char mx = 0;

      for(int j=i+1;j<=min(i+k,n-1);j++){
        if(s[j] > mx){
          pos = j;
          mx = s[j];
        }
      }

      if(mx > cur){
        k = k - (pos - i);
        for(int j=pos;j>i;j--)
          swap(s[j],s[j-1]);
        trade = true;
        break;
      }
    }

    if(!trade)
      break;
  }
  cout << s << endl;

    
  

  return 0;
}