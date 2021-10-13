#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

bool isPrime(long long n){
 set <long long> div;

  for(long long i=2;i*i<=n;i++){
      if(n%i==0)
        div.insert(i),div.insert(n/i);
  }

  return div.size() == 0;
}

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  long long n;
  cin >> n;

  set <long long> div;

  for(long long i=2;i*i<=n;i++){
      if(n%i==0)
        div.insert(i),div.insert(n/i);
  }

  if(div.size() == 0){
    cout << 1 << endl;
    cout << 0 << endl;
    return 0;
  }

  for(auto it=div.begin();it!=div.end();it++){
    if(!isPrime(*it)){
      cout << 1 << endl;
      cout << *it << endl;
      return 0;
    }
  }

  cout << 2 << endl;
  return 0;
}