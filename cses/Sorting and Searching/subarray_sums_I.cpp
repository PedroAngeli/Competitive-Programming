#include <bits/stdc++.h>

using namespace std;


int main(){

 long long n,x;
 cin >> n >> x;
 vector <long long> vet(n);

 for(int i=0;i<n;i++)
  cin >> vet[i];

 long long acc = 0;
 int i=0,j=0;
 long long resp = 0;

 while(i < n){

   if(acc + vet[i] <= x){
     acc += vet[i];
     i++;
   }else{
      acc -= vet[j];
      j++;
   }
    
    if(acc == x){
     resp++;
   }

 }

 cout << resp << endl;

  return 0;
}