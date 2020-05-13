#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  
 int n,k;

 cin >> n >> k;
 int cnt[n+1] = {0};

 for(int i=0;i<k;i++){
   int d;
   cin >> d;
   while(d--){
     int a;
     cin >> a;
     cnt[a]++;
   }
 }

 int ans = 0;

 for(int i=1;i<=n;i++)
  if(cnt[i] == 0)
    ans++;

  cout << ans << endl;
  return 0;
}