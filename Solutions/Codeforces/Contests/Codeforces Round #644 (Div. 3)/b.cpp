#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    int vet[n];
    for(int i=0;i<n;i++)
      cin >> vet[i];
    sort(vet,vet+n);
    int mn = INT_MAX;
    for(int i=1;i<n;i++)
      mn = min(mn,vet[i]-vet[i-1]);

    cout << mn << endl;
  }

  return 0;
}