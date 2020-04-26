#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;

  cin >> n;
  int menor = 4127;
  bool rated = false;
  bool maybe = true;

  while(n--){
    int a,b;
    cin >> a >> b;
    menor = min(menor,a);
    if(a!=b)
      rated = true;
    if(a > menor)
      maybe = false;
  }

  if(!rated && maybe){
    cout << "maybe\n";
  }

  if(rated){
    cout << "rated\n";
  }

  if(!rated && !maybe)
    cout << "unrated\n";
  

  return 0;
}