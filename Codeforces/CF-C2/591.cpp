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

  int mx = 0;
  int ans[n];
  int cnt = 0;
  ans[0] = vet[0];
  ans[n-1] = vet[n-1];

  for(int i=1;i<n-1;i++){
    if(!vet[i] && vet[i-1] && vet[i+1]){
      cnt++;
    }else if(vet[i] && !vet[i-1] && !vet[i+1]){
      cnt++;
    }else{
      for(int j=i-cnt,c=0;c<(cnt+1)/2;j++,c++)
        ans[j] = vet[i-cnt-1];

      for(int j=i-1,c=0;c<(cnt+1)/2;j--,c++)
        ans[j] = vet[i];

      mx = max(mx,(cnt+1)/2);
      cnt = 0;
      ans[i] = vet[i];
    }
  }

  int i = n-1;
   for(int j=i-cnt,c=0;c<(cnt+1)/2;j++,c++)
        ans[j] = vet[i-cnt-1];

  for(int j=i-1,c=0;c<(cnt+1)/2;j--,c++)
        ans[j] = vet[i];

  mx = max(mx,(cnt+1)/2);

  cout << mx << endl;

  for(int i=0;i<n;i++)
    cout << ans[i] << " ";

  cout << endl;
  

  return 0;
}