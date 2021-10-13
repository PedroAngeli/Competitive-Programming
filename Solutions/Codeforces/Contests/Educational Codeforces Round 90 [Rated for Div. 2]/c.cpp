#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
 
int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  
  int t = 1;
  cin >> t;

  while(t--){
    string s;
    cin >> s;

    int n = s.size();
    long long mn = INT_MAX;
    long long sum = 0;
    long long ans = 0;

    vector <bool> vis(n+1,false);

    for(int i=0;i<n;i++){
      if(s[i] == '+')
        sum++;
      else
        sum--;

      if(sum < 0 && !vis[abs(sum)]){
        ans += i+1;
        vis[abs(sum)] = true;
      }
    }

    cout << ans+n << endl;
  }
  
   
  return 0;
}