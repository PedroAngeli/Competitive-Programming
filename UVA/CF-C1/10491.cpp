#include <bits/stdc++.h>

using namespace std;

#define endl '\n'


int main(){
  
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  long long v,c,s;

  while(cin >> v >> c >> s){
    long long sum = v+c;
    long long d = sum - s - 1;
    long long num = v*c + c*(c-1);
    long long den = d*sum;
    cout << fixed << setprecision(5) << (long double)num/den << endl; 
  }
  
  
  return 0;
}