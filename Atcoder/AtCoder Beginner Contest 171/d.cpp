#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

const int nax = 1e5 + 5;
int freq[nax];

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  long long sum = 0;

  for(int i=0;i<n;i++){
    long long x;
    cin >> x;
    sum += x;
    freq[x]++;
  }

  int q;
  cin >> q;

  while(q--){
    long long b,c;
    cin >> b >> c;
    long long elementsRemoved = freq[b];
    freq[b] = 0;
    sum = sum - elementsRemoved*b + elementsRemoved*c;
    freq[c] += elementsRemoved;
    cout << sum << endl;
  }
 
  return 0;
}