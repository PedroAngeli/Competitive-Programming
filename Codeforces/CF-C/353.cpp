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

  char binary[n];
  int pos = 0;
  int ans = 0;
  vector <int> ones;

  for(int i=0;i<n;i++){
    cin >> binary[i];
    if(binary[i] == '1')
      ones.push_back(i),ans+=vet[i];
  }

  int pref[n];
  int suf[n];
  int len = ones.size();
  
  pref[0] = vet[0];
  for(int i=1;i<n;i++)
    pref[i] = pref[i-1]+vet[i];
  
  suf[n-1] = binary[n-1] == '1'? vet[n-1] : 0;

  for(int i=n-2;i>=0;i--){
    suf[i] = suf[i+1];
    if(binary[i] == '1')
      suf[i] += vet[i];
  }

  for(int i=0;i<len;i++){
    int cur = ones[i];

    if(cur == 0 && cur+1 < n)
      ans = max(ans,suf[cur+1]);
    else if(cur == n-1 && cur-1 >= 0)
      ans = max(ans,pref[cur-1]);
    else if(cur-1 >=0 && cur+1 < n)
      ans = max(ans,pref[cur-1] + suf[cur+1]);
  }


  cout << ans << endl;
    
  return 0;
}