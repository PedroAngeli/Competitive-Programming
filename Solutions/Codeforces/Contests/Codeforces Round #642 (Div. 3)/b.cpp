#include <bits/stdc++.h>

using namespace std;

#define endl '\n'


int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while(t--){
    int n,k;
    cin >> n >> k;
    int a[n];
    int b[n];

    for(int i=0;i<n;i++)
      cin >> a[i];

    for(int i=0;i<n;i++)
      cin >> b[i];

    for(int i=0;i<k;i++){
      sort(a,a+n);
      sort(b,b+n);
      if(a[0] < b[n-1])
        swap(a[0],b[n-1]);
    }

    int ans = 0;
    for(int i=0;i<n;i++)
      ans+=a[i];

    cout << ans << endl;

  }

  return 0;
}