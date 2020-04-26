#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n,b,d;

  cin >> n >> b >> d;

  long long a;
  long long sum = 0;
  int ans = 0;

  for(int i=0;i<n;i++){
    cin >> a;

    if(a <= b)
      sum+=a;

    if(sum > d){
      ans++;
      sum = 0;
    }
  }  

  cout << ans << endl;
   

  


  return 0;
}