#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int cntDiv(long long a){
  int ans = 1;
  long long div = 2;

  while(div*div<=a){
    int qtd = 0;
    while(a%div == 0)
      a/=div,qtd++;
    div++;
    ans *= (qtd+1);
    if(ans > 3)
      return 4;
  }

  if(a!=1)
    ans*=2;

  return ans;
}

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  long long a;
  cin >> n;
  
  while(n--){
    cin >> a;
    long long root = sqrt(a);
    if(root*root == a){
      int div = cntDiv(root);
      if(div == 2)
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    }else
      cout << "NO" << endl;
  }
  return 0;
}