#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  
  int n;
  cin >> n;
  int mx = 0;
  int a;
  bool hasOdd = false;
  int mdc;
  set <int> s;
  vector <int> vet;

  for(int i=0;i<n;i++){
    cin >> a;
    if(i == 0)
      mdc = a;
    else
      mdc = __gcd(a,mdc);
    mx = max(mx,a);
    s.insert(a);
    vet.push_back(a);
    if(a % 2 == 1)
      hasOdd = true;
  }

  bool winAlice = true;

  int qtd = 0;

  if(hasOdd){
     qtd = mx-n;
  }else{
    qtd = mx/mdc - n;
  }

  if(qtd % 2 == 0)
    winAlice = false;

  if(winAlice)
    cout << "Alice" << endl;
  else
    cout << "Bob" << endl;
  return 0;
}