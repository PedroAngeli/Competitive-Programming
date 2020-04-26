#include <bits/stdc++.h>

using namespace std;

#define endl '\n'


int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  double l;

  cin >> n >> l;

  double vet[n];

  for(int i=0;i<n;i++)
    cin >> vet[i];

  
  sort(vet,vet+n);

  double ans = vet[0]-0;

  for(int i=1;i<n;i++)
    ans = max(ans,(vet[i]-vet[i-1])/2);

  ans = max(ans,l-vet[n-1]);

  cout << fixed << setprecision(15) << ans << endl;

  return 0;
}