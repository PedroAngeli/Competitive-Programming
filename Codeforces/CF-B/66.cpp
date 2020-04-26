#include <bits/stdc++.h>

using namespace std;

#define endl '\n'


int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  int h[n];

  for(int i=0;i<n;i++)
    cin >> h[i];

  int resp = 0;

  for(int i=0;i<n;i++){
    int ans = 1;
    for(int j=i+1;j<n;j++){
      if(h[j] <= h[j-1])
        ans++;
      else
        break;
    }

    for(int j = i-1;j>=0;j--){
      if(h[j] <= h[j+1])
        ans++;
      else
        break;
    }

    resp = max(ans,resp);
  }

  cout << resp << endl;

  return 0;
}