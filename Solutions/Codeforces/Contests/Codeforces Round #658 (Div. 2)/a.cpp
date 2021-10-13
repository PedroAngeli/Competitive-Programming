#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
  
int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
 
  int t = 1;
  cin >> t;

  while(t--){
    int n,m;

    cin >> n >> m;
    vector <bool> exists(1001,false);
    for(int i=0;i<n;i++){
      int x;
      cin >> x;
      exists[x] = true;
    }
    int ans = -1;
    for(int i=0;i<m;i++){
      int x;
      cin >> x;
      if(exists[x]){
        ans = x;
      }
    }


    if(ans == -1)
      cout << "NO" << endl;
    else{
      cout << "YES" << endl;
      cout << 1 << " " << ans << endl;
    }


    
  }
    
  return 0;
}