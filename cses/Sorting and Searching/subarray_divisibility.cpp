#include <bits/stdc++.h>

using namespace std;


int main(){

 long long n;
 cin >> n;
 vector <long long> vet(n);

 for(int i=0;i<n;i++)
  cin >> vet[i];

 long long acc = 0;
 map <long long,long long> mapa;
 long long resp = 0;

 for(int i=0;i<n;i++){
   acc += vet[i];

   if(((acc % n) + n )%n == 0)
    resp++;

   if(mapa.find(((acc % n) + n )%n ) != mapa.end()){
     resp += mapa[((acc % n) + n )%n ];
   }

   mapa[((acc % n) + n )%n ]++; 
 }

 cout << resp << endl;

  return 0;
}