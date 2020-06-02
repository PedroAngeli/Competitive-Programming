#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  int vet[n];
  for(int i=0;i<n;i++)
    cin >> vet[i];

  long long ans = 0;

  for(int i=0;i<n;i++){
    long long cnt = 1;
    while(i < n-1 && vet[i] == vet[i+1])
      cnt++,i++;
    
    ans += ((cnt+1)*cnt)/2;
  }


  cout << ans << endl;

  return 0;
}