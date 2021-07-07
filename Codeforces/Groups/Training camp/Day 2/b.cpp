#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'

int solve(int num){
  set <int> divs;

  for(int i=1;i*i<=num;i++){
    if(num % i == 0){
      divs.insert(i);
      divs.insert(num/i);
    }
  }

  return divs.size();
}
 
int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
 
  int n;
  cin >> n;

  if(n == 1){
    cout << 3 << endl;
  }else if(n % 2 == 1){
    cout << 1 << endl;
  }else{
    for(int i=1;i<=1000;i++){
      int num = i*n + 1;
      int div = solve(num);
      if(div > 2){
        cout << i << endl;
        return 0;
      }
    }
  }
  
  return 0;
}