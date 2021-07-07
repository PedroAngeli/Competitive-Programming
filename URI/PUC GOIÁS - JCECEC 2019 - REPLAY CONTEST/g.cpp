#include <bits/stdc++.h>

using namespace std;


int main(){

  long long n,m,s;

  cin >> n >> m >> s;

  long long fst = 0;
  long long sec = 0;
  

  for(int i=0;i<s;i++){
    long long x,y,h;
    cin >> x >> y >> h;

    long long tempy = (m*x)/n;

    if(y > tempy)
      fst+=h;
    else
      sec+=h;
  }

  cout << fst << " " << sec << endl;

  return 0;
}