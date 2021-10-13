#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int sumOfString(string s){
  int sum = 0;

  for(int i=0;i<s.size();i++)
    sum += s[i] - '0';

  return sum;
}

int sumOfDigits(int n){
  int sum = 0;
  
  while(n > 0){
    int dig = n % 10;
    sum += dig;
    n /= 10;
  }

  return sum;
}

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string s;

  cin >> s;

  if(s.size() == 1){
    cout << 0 << endl;
    return 0;
  }

  int n = sumOfString(s);
  int ans = 1;

  while(n >= 10){
    n = sumOfDigits(n);
    ans++;
  }

  cout << ans << endl;

  return 0;
}