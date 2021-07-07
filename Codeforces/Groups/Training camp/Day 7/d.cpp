#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'

int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
 
  long long a,b;
  cin >> a >> b;
  long long ans = 1;

  for(int i=0;i<b;i++)
    ans = (ans * a)%9;

  if(ans == 0)
    ans = 9;
  cout << ans << endl;

  return 0;
}