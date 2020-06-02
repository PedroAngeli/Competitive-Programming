#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

vector <long long> numbers;

void solve(int dig, int no_zeros, long long cur){
  if(dig == 18){
    numbers.push_back(cur);
    return;
  }

  solve(dig+1,no_zeros,cur*10);

  if(no_zeros < 3){
    for(int i=1;i<=9;i++){
      solve(dig+1,no_zeros+1,cur*10 + i);
    }
  }
}

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  solve(0,0,0);
  numbers.push_back(1e18);
  sort(numbers.begin(),numbers.end());
  cin >> t;
  while(t--){
    long long l,r;
    cin >> l >> r;
    auto it1 = upper_bound(numbers.begin(),numbers.end(),r);
    auto it2 = lower_bound(numbers.begin(),numbers.end(),l);
    cout << (int)(it1-it2) << endl; 
  }  
  
  return 0;
}