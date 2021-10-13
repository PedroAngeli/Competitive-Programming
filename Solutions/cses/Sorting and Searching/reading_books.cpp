#include <bits/stdc++.h>

using namespace std;

int main(){

  int n;
  cin >> n;

  long long sum = 0;
  long long maior = 0;

  for(int i=0;i<n;i++){
    long long a;
    cin >> a;
    sum += a;
    maior = max(maior,a);
  }

  if(2*maior > sum)
    cout << 2*maior << endl;
  else
    cout << sum << endl;

 

  return 0;
}