#include <bits/stdc++.h>

using namespace std;

#define endl '\n'


int main(){
  
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  int cnt[5001] = {0};

  for(int i=0;i<n;i++){
    int a;
    cin >> a;
    cnt[a]++;
  }

  int ans = 0;
  for(int i=1;i<=n;i++)
    if(cnt[i] == 0)
      ans++;

  cout << ans << endl;

  return 0;
}