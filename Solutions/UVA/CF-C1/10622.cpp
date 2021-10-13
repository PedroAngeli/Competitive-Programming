#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int gcd(int a,int b){
  if(b == 0)
    return a;

  return gcd(b,a%b);
}

void solve(long long n, bool negative){
  long long div = 2;
  vector <int> v;

  while(div*div<=n){
    int cnt = 0;
    while(n % div == 0){
      n /= div;
      cnt++;
    }
    if(cnt)
      v.push_back(cnt);
      
    cnt = 0;
    div++;
  }

  if(n != 1)
    v.push_back(1);

  int len = v.size();
  int ans = v[0];
  for(int i=1;i<len;i++){
    int cur = v[i];
    ans = gcd(ans,cur);
  }

  if(negative){
    if(ans % 2 == 0){
      while(ans % 2 == 0)
        ans/=2;
    }
  }

    cout << ans << endl;
}


int main(){
  
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  long long n;

  while(cin >> n && n){
    bool negative = false;

    if(n < 0)
      n*=-1,negative = true;
    solve(n,negative);
  }

  return 0;
}