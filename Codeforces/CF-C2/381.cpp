#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'

int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL); 

  int m;

  cin >> m;
  vector <long long> vet(m+1);
  vector <long long> pref(m+1,0);
  vector <int> type(m+1);

  for(int i=1;i<=m;i++){
    cin >> type[i];
    if(type[i] == 1){
      cin >> vet[i];
      pref[i] = pref[i-1] + 1;
    }else{
      cin >> vet[i];
      long long c;
      cin >> c;
      pref[i] = pref[i-1] + c*vet[i];
    }
  }

  int n;
  cin >> n;

  while(n--){
    long long idx;
    cin >> idx;
    int pos = lower_bound(pref.begin()+1,pref.end(),idx)-pref.begin();
     while(type[pos] == 2){
        idx -= pref[pos-1];
        idx = (idx-1)%vet[pos] + 1;
        pos = lower_bound(pref.begin()+1,pref.end(),idx)-pref.begin();
      }

    cout << vet[pos] << " ";
  }
  
  cout << endl;
  
  
  return 0;
}