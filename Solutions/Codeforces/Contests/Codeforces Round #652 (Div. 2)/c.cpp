#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
 
int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
 
  int t = 1;
  cin >> t;
 
  while(t--){
    int n,k;
    cin >> n >> k;

    vector <long long> vet(n);

    for(int i=0;i<n;i++)
      cin >> vet[i];
 
    vector <int> w(k);

    for(int i=0;i<k;i++)
      cin >> w[i];
    
    sort(w.begin(),w.end());
    reverse(w.begin(),w.end());
    sort(vet.begin(),vet.end());

    long long ans = 0;

    while(w.size() > 0 && w.back() == 1){
      ans += 2*vet.back();  
      vet.pop_back();
      w.pop_back();
    }
    
    int j = 0;

    for(int i=0;i<w.size();i++){
      ans += vet[j];
      j += w[i]-1;
    }

    for(int i=0;i<w.size();i++,j++){
      ans += vet[j];
    }

    cout << ans << endl;
  }
  
 
  return 0;
}