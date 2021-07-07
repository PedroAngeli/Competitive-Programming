#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'


int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
 
  int n;
  cin >> n;
  vector <int> vet(n);
  vector <int> ans(n);

  for(int i=0;i<n;i++)
    cin >> vet[i];

  sort(vet.begin(),vet.end());
  reverse(vet.begin(),vet.end());

  if(n == 2){
    cout << vet[0] << " " << vet[1] << endl;
    return 0;
  }

  int l = n/2;
  int r = n/2;
  ans[l] = vet[0];
  l--;
  r++;
  for(int i=1;i<n;i++){
    if(i % 2 == 1)
      ans[l--] = vet[i];
    else
      ans[r++] = vet[i];
  }

  for(int i=0;i<n;i++)
    cout << ans[i] << " ";
  cout << endl;
  return 0;
}