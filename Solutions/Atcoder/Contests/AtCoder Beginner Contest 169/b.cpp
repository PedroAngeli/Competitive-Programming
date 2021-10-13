#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  long long a[n];
  long long ans[n];
  const long long mx = 1e18;

  for(int i=0;i<n;i++){
    cin >> a[i];
  }

  sort(a,a+n);

  ans[0] = a[0];

  for(int i=1;i<n;i++){

     if(ans[i-1] && a[i] > mx/ans[i-1]){
      ans[n-1] = -1;
      break;
    }

    ans[i] = a[i]*ans[i-1];
  }

  if(ans[n-1] > mx){
    ans[n-1] = -1;
  }

  cout << ans[n-1] << endl;

  return 0;
}