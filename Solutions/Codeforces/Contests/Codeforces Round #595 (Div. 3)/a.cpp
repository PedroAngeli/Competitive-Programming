#include <bits/stdc++.h>

using namespace std;


int main(){

  int q;
  cin >> q;

  while(q--){
    int n;
    cin >> n;
    vector <int> s(n);
   
    int ans = 1;

    for(int i=0;i<n;i++)
      cin >> s[i];

    sort(s.begin(),s.end());

    for(int i=0;i<n-1;i++)
      if(abs(s[i] - s[i+1]) <= 1){
        ans = 2;
        break;
      }

    cout << ans << endl;
  }

  return 0;
}