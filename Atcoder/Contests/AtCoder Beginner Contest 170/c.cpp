#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

 int x,n;
 cin >> x >> n;
 int vet[n];
 for(int i=0;i<n;i++)
  cin >> vet[i];

 int ans = x;
 int mn = INT_MAX;

 for(int i=-100;i<=1000;i++){
   if(abs(x-mn) > abs(x-i)){
     bool contain = false;
     for(int j=0;j<n;j++){
       if(vet[j] == i)
        contain = true;
     }
     if(!contain){
       ans = i;
       mn = i;
     }
   }  
 }

 cout << ans << endl;
 
  return 0;
}