#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

bool isSorted(int a[],int n){
  for(int i=0;i<n-1;i++){
    if(a[i] > a[i+1])
      return false;
  }

  return true;
}

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int t = 1;
  cin >> t;

  while(t--){
    int n;
    cin >> n;
    int a[n];
    int b[n];
    for(int i=0;i<n;i++)
      cin >> a[i];
    for(int i=0;i<n;i++)
      cin >> b[i];

    if(isSorted(a,n)){
      cout << "Yes" << endl;
      continue;
    }

    bool one = false;
    bool zero = false;

    for(int i=0;i<n;i++)
      if(b[i] == 0)
        zero = true;
      else
        one = true;

      if(one && zero)
        cout << "Yes" << endl;
      else
        cout << "No" << endl;
  }

  return 0;
}