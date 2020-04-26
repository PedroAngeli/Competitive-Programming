#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  set <int> s;

  int p;
  cin >> p;

  while(p--){
    int a;
    cin >> a;
    s.insert(a);
  }

   int q;
  cin >> q;

  while(q--){
    int a;
    cin >> a;
    s.insert(a);
  }

  if(s.size() == n){
    cout << "I become the guy.\n";
  }else{
    cout << "Oh, my keyboard!\n";
  }


  return 0;
}