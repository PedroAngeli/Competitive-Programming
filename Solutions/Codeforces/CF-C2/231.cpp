#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
 
int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
 
  int n,k;
  cin >> n >> k;
 
  vector <long long> vet(n+1);
  for(int i=1;i<=n;i++)
    cin >> vet[i];
  sort(vet.begin()+1,vet.end());
  vector <long long> pref(n+1,0);
  for(int i=1;i<=n;i++)
    pref[i] = pref[i-1] + vet[i];
  
  int mxCnt = 1;
  int mnVal = vet[1];
 
  for(int i=1;i<=n;i++){
    int l = 1;
    int r = i;
    int bestFreq = 1;
 
    while(l <= r){
      int m = (l+r)/2;
      long long sum = m*vet[i] - (pref[i]-pref[i-m]);
 
      if(sum <= k){
        bestFreq = m;
        l = m+1;
      }else{
        r = m-1;
      }
    }
 
    if(bestFreq > mxCnt){
      mxCnt = bestFreq;
      mnVal = vet[i];
    }
  }
 
 
  cout << mxCnt << " " << mnVal << endl; 
  
  return 0;
}