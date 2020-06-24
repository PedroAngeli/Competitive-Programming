#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int t = 1;
  cin >> t;

  while(t--){
    long long n;
    cin >> n;
    long long ans = 1;

    set <long long,greater<long long> > s;
    for(long long i=2;i*i<=n;i++){
      if(n%i==0){
        s.insert(i);
        s.insert(n/i);
      }
    }

    if(s.size())
    ans = max(ans, *s.begin());

    n--;
    s.clear();

    for(long long i=2;i*i<=n;i++){
      if(n%i==0){
        s.insert(i);
        s.insert(n/i);
      }
    }
    if(s.size())
    ans = max(ans, *s.begin());

    cout << ans << endl;
  }

  return 0;
}