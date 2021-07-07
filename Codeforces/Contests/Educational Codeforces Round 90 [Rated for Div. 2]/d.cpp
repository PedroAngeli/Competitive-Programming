#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
 
int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  
  int t = 1;
  cin >> t;

  while(t--){
    int n;
    cin >> n;

    long long vet[n];
    long long sum = 0;

    for(int i=0;i<n;i++){
      cin >> vet[i];
      if(i % 2 == 0)
        sum += vet[i];
    }

    vector <long long> change(n,0);

    for(int i=0;i<n-1;i++){
      if(i % 2 == 0)
        change[i] = vet[i+1]-vet[i];
      else
        change[i] = vet[i]-vet[i+1];
    }

    long long mx1 = 0;
    long long mx2 = 0;

    long long s1 = 0;
    long long s2 = 0;

    for(int i=0;i<n;i++){
      if(i % 2 == 0)
        s1 += change[i];
      else
        s2 += change[i];

      s1 = max(s1,0LL);
      s2 = max(s2,0LL);
      
      mx1 = max(mx1,s1);
      mx2 = max(mx2,s2);
    }

    long long ans = sum + max(mx1,mx2);

    cout << ans << endl;
  }
  
   
  return 0;
}