#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'

int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL); 

  int n;
  cin >> n;
  int ans = 0;
  int mxK = 0;

  for(int i=0;i<n;i++){
    int k,a;
    cin >> k >> a;
    int lg = ceil(log2(a)/2);
    mxK = max(mxK,k);
    ans = max(ans,k + lg);
  }

  cout << ans + (mxK == ans) << endl;
  

  return 0;
}