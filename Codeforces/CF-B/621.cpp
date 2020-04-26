#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  long long n;
  cin >> n;
  long long ans = 0;

  unordered_map <int,int> m1;
  unordered_map <int,int> m2;

  while(n--){
    int x,y;
    cin >> x >> y;
    m1[x-y]++;
    m2[x+y]++;
  }
  
  for(auto it = m1.begin();it != m1.end();it++){
    int x = it->second;
    ans += (x*(x-1))/2;
  }

  for(auto it = m2.begin();it != m2.end();it++){
    int x = it->second;
    ans += (x*(x-1))/2;
  }

  cout << ans << endl;

  return 0;
}