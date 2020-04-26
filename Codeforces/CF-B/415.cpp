#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  long long n,a,b;
  cin >> n >> a >> b;

  for(int i=0;i<n;i++){
    long long w;
    cin >> w;
    cout << (w*a)%b/a << " ";
  }

  cout << endl;

  
  return 0;
}