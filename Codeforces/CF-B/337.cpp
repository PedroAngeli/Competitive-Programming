#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int gcd(int a,int b){
  if(b == 0)
    return a;

  return gcd(b,a%b);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int a,b,c,d;

  cin >> a >> b >> c >> d;

  int mdc = gcd(d*a,c*b);
  int i = (d*a)/mdc;
  int j = (c*b)/mdc;

  int den = max(i,j);
  int num = min(i,j);
  
  cout << den-num << "/" << den << endl;


 
  return 0;
}