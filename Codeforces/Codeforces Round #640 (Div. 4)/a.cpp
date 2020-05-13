#include <bits/stdc++.h>

using namespace std;

#define endl '\n'


int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  while(t--){
    int n;
    cin >> n;

    int mult = 1;
    vector <int> ans;
    while(n){
      int dig = n%10;
      if(dig != 0){
        ans.push_back(dig*mult);
      }
      n/=10;
      mult*=10;
    }

    cout << ans.size() << endl;

    for(int i=0;i<ans.size();i++)
      cout << ans[i] << " ";

    cout << endl;
  }
    
  return 0;
}