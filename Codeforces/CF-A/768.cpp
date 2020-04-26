#include <bits/stdc++.h>

using namespace std;

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int n;

  cin >> n;
  
  int vet[n];

  set <int> s1;
  set <int, greater<int> > s2;


  for(int i=0;i<n;i++){
    cin >> vet[i];
    s1.insert(vet[i]);
    s2.insert(vet[i]);
  }

  int ans = 0;

  for(int i=0;i<n;i++){
    auto it1 = s1.upper_bound(vet[i]);
    auto it2 = s2.upper_bound(vet[i]);

    if(it1 != s1.end() && it2 != s2.end())
      ans++;
  }
    

 cout << ans << endl;
  
  return 0;
}