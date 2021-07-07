#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
 
 
int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
 
  int n;
  cin >> n;
  vector <string> a(n);
  vector <string> b(n);
  
  for(int i=0;i<n;i++)
    cin >> a[i];
  
  for(int i=0;i<n;i++)
    cin >> b[i];

  vector <bool> usedA(n,false);
  vector <bool> usedB(n,false);

  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(a[i] == b[j] && !usedB[j]){
        usedA[i] = true;
        usedB[j] = true;
        break;
      }
    }
  }
  int ans = 0;
  for(int i=0;i<n;i++){
    if(usedA[i])
      continue;
    for(int j=0;j<n;j++){
      if(usedB[j])
        continue;
      if(a[i].size() == b[j].size()){
        usedA[i] = true;
        usedB[j] = true;
        ans++;
      }
    }
  }

  cout << ans << endl;
  
  return 0;
}