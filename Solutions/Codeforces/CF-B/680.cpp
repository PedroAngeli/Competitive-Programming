#include <bits/stdc++.h>

using namespace std;

#define endl '\n'


int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n,a;

  cin >> n >> a;
  
  int vet[n+1];

  for(int i=1;i<=n;i++){
    cin >> vet[i];
  }

  int i = a+1;
  int j = a-1;
  int ans = 0;

  if(vet[a])
    ans++;

  while(i <= n || j >= 1){
    
    if(j == 0 && vet[i])
      ans++;
    
    if(i == n+1 && vet[j])
      ans++;

    if(i <= n && j>=1 && i-a == a-j && vet[i] && vet[j])
      ans+=2;

    i = min(n+1,i+1);
    j = max(0,j-1);
  }

  cout << ans << endl;

  return 0;
}