#include <bits/stdc++.h>

using namespace std;


int main(){

 int n;

 cin >> n;
 vector <string> vet(n);
 for(int i=0;i<n;i++){
   cin >> vet[i];
 }

 int ans = n;

 for(int i=0;i<n-1;i++){
   if(vet[i] == vet[i+1]){
     ans--;
   }
 }

 cout << ans << endl;


  return 0;
}