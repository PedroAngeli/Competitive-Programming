#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

const int nax = 2e5 + 1;

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  vector <int> vet(n);
  int mx = 0;

  for(int i=0;i<n;i++)
    cin >> vet[i], mx = max(mx,vet[i]);

  sort(vet.begin(),vet.end());

  vector <int> ans(mx+1,0);

  for(int i=0;i<n;i++){
    int cur = vet[i];
    for(int k=cur;k<=mx;k+=cur){
      ans[k]++;
    }
  }

  int resp = 0;

  for(int i=0;i<n;i++)
    if(ans[vet[i]] == 1)
      resp++;

  cout << resp << endl;
 
  return 0;
}