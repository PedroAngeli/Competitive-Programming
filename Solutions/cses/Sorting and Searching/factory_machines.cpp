#include <bits/stdc++.h>

using namespace std;

long long n,t;
vector <long long> times;
const long long INF = 1000000000000000000LL;

bool can(long long x){
  long long count = 0;

  for(int i=0;i<n;i++){
    count+=(x/times[i]);
    if(count >= t)
      return true;
  }

  return false;
}

int main(){

  cin >> n >> t;

  times = vector <long long> (n);

  for(int i=0;i<n;i++)
    cin >> times[i];

  long long l = 0, r = INF;
  long long ans = INF;

  while(l <= r){
    long long m = (l+r)/2;

    if(can(m)){
      ans = min(ans,m);
      r = m-1;
    }else{
      l = m+1;
    } 
  }

  cout << ans << endl;

  return 0;
}