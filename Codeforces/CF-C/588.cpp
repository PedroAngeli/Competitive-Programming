#include <bits/stdc++.h>

using namespace std;

#define endl '\n'


int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  
  long long n;
  cin >> n;

  vector <long long> square;

  for(long long i=2;i<=1e6;i++)
    square.push_back(i*i);

  unordered_set <long long> s;

  long long ans = 0;

  for(long long i=1;i*i<=n;i++){
    if(n % i == 0){
      s.insert(i);
      s.insert(n/i);
    }
  }

  int m = square.size();

  for(auto it = s.begin();it!=s.end();it++){
    long long x = *it;
    bool lovely = true;

    for(int i=0;i<m;i++){
      long long cur = square[i];

      if(cur > x)
        break;
      
      if(x % cur == 0){
        lovely = false;
        break;
      }
    }

    if(lovely)
      ans = max(ans,x);
  }


  cout << ans << endl;


  return 0;
}