#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
 
 
int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
 
  long long n,h;
 
  cin >> h >> n;
 
  long long dest = n-1;
  int real = 0;
  long long ans = 0;
  int bin[55];
  int i = 0;
 
  int H = h;
  while(H--){
    bin[i++] = dest%2;
    dest/=2; 
  }
 
  i--;
 
  while(i >= 0){
    if(bin[i] == real)
      ans++, real=1-real;
    else
      ans+=(long long)pow(2,h), real = 1 - bin[i];
    i--;
    h--;
  }
 
  cout << ans << endl;
  
  return 0;
}