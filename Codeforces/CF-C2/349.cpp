#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'

int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL); 

  int n;
  cin >> n;
  long long mx = 0;
  long long sum = 0;

  for(int i=0;i<n;i++){
    long long x;
    cin >> x;
    mx = max(mx,x);
    sum += x;
  }

  cout << max(mx,(sum+n-2)/(n-1)) << endl;
  
  
  return 0;
}