#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  
  long long n;
  cin >> n;
  long long pref[n+1];
  pref[0] = 0;

  for(int i=0;i<n;i++){
    long long a;
    cin >> a;
    pref[i+1] = pref[i] + a;
  }

  

  set <long long> s;
  s.insert(0);
  long long ans = 0;

  for(long long i=0,j=0;i<n;i++){
    while(j < n && !s.count(pref[j+1])){
      j++;
      s.insert(pref[j]);
    }
    ans += j-i;
    s.erase(pref[i]);
  }


  cout << ans << endl;

  return 0;
}