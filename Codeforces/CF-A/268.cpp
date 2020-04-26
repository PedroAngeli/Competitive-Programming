#include <bits/stdc++.h>

using namespace std;

int main(){

  int n;
  cin >> n;

  int home[n];
  int guest[n];

  for(int i=0;i<n;i++)
    cin >> home[i] >> guest[i];

  int ans = 0;

  for(int i=0;i<n;i++)
    for(int j=i+1;j<n;j++){
      if(home[i] == guest[j]) 
        ans++;
      if(home[j] == guest[i])
        ans++;
    }

  cout << ans << endl;
  return 0;
}