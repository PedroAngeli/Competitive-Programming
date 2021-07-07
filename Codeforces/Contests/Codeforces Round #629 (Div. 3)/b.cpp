#include <bits/stdc++.h>

using namespace std;

vector <long long> pa;

int main(){

  pa.push_back(1);

  for(long long i=2;i<=1000000;i++){
    pa.push_back(((1+i)*i)/2);
  }

  int t;
  cin >> t;

  while(t--){
    long long n,k;
    cin >> n >> k;

    string b;
    b.resize(n,'a');

    auto it = upper_bound(pa.begin(),pa.end(),k);
    it--;

    int idx = it - pa.begin();
    
    if(k == pa[idx]){
      b[n-2-idx] = 'b';
      b[n-1-idx] = 'b';
    }else{
      b[n-2-idx-1] = 'b';
      b[n-1-(k-pa[idx]-1)] = 'b';
    }

    cout << b << endl;
  }

  return 0;
}