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
    int vet[n];

    for(int i=0;i<n;i++)
      cin >> vet[i];

    sort(vet,vet+n);

    vector <int> ans;
    int mid = (n-1)/2;

    if(n % 2 == 0){
      ans.push_back(vet[mid]);  
      ans.push_back(vet[mid+1]);
    }else{
      ans.push_back(vet[mid]);  
    }

     for(int i=mid-1;i>=0;i--){
        ans.push_back(vet[i]);
        ans.push_back(vet[n-i-1]);
    }

    for(int i =0;i<n;i++)
      cout << ans[i] << " ";
    cout << endl;
  }

  return 0;
}