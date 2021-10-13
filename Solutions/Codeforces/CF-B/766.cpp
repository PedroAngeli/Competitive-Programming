#include <bits/stdc++.h>

using namespace std;

#define endl '\n'


int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

 
  int n;
  cin >> n;

  int vet[n];

  for(int i=0;i<n;i++)
    cin >> vet[i];

  sort(vet,vet+n);

  bool ans = false;

  for(int i=n-1;i>=2;i--)
    if(vet[i] < vet[i-1] + vet[i-2]){
      ans = true;
      break;
    }

  if(ans)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}