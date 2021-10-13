#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
  
int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
 
  int t = 1;
  cin >> t;

  while(t--){
    int n;
    cin >> n;
    vector <int> vet(n);
    for(int i=0;i<n;i++)
      cin >> vet[i];

    vector <string> ans(n+1,string(100,'a'));
    
    for(int i=0;i<n;i++){
      int cur = vet[i];
      for(int j=0;j<cur;j++)
        ans[i+1][j] = ans[i][j];
      ans[i+1][cur] = ans[i][cur] + 1;
      if(ans[i+1][cur] > 'z')
        ans[i+1][cur] = 'b';
    }

    for(string s:ans)
      cout << s << endl;
  }
    
  return 0;
}