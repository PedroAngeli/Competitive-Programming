#include <bits/stdc++.h>

using namespace std;

#define endl '\n'


int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;

  cin >> n;
  int A[n];
  int B[n];

  for(int i=0;i<n;i++)
    cin >> A[i] >> B[i];

  int sa = 0;
  int sb = 0;
  string ans;
  ans.resize(n);

  for(int i=0;i<n;i++){
    if((sa + A[i]) - sb <= 500){
      sa += A[i];
      ans[i] = 'A';
    }else if((sb + B[i]) - sa <= 500){
      sb += B[i];
      ans[i] = 'G';
    }else{
      cout << -1 << endl;
      return 0;
    }
  }

  cout << ans << endl;
  return 0;
}