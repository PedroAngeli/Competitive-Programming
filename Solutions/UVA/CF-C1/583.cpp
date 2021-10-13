#include <bits/stdc++.h>

using namespace std;

#define endl '\n'


void solve(long long n,bool first){
  long long div = 2; 
  while(div*div<=n){
    while(n%div == 0){
      if(first)
        cout << div,first = false;
      else{
        cout << " x " << div;
      }
      n/=div;
    }
    div++;
  }

  if(n!=1){
    if(first)
        cout << n,first = false;
      else{
        cout << " x " << n;
      }
  }
    

  cout << endl;
}

int main(){
  
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  long long n;

  while(cin >> n && n){
    cout << n << " = ";
    bool first = true;

    if(n < 0)
      cout << -1, n *= -1,first = false;

    solve(n,first);
  }
  
  
  return 0;
}