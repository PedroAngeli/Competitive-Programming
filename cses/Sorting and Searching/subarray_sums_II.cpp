#include <bits/stdc++.h>

using namespace std;


int main(){

 long long n,x;
 cin >> n >> x;
 vector <long long> vet(n);

 for(int i=0;i<n;i++)
  cin >> vet[i];

 long long acc = 0;
 map <long long,long long> mapa;
 long long resp = 0;

 for(int i=0;i<n;i++){
   acc += vet[i];


   if(acc == x)
    resp++;

   if(mapa.find(acc - x) != mapa.end()){
     resp += mapa[acc - x];
   }

   mapa[acc]++; 
 }

 cout << resp << endl;

  return 0;
}