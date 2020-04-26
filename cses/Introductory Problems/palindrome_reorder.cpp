#include <bits/stdc++.h>

using namespace std;

int main(){

  string a;
  
  cin >> a;
  int vet[30]={0};

  for(int i=0;i<a.size();i++){
    vet[a[i]-'A']++;
  }

  char c = '\0';
  bool can = false;
  string resp;
  int count = 0;

   for(int i=29;i>=0;i--){
     if(vet[i]){
       if(vet[i]%2 != 0){
         count++;
         if(count > 1){
           cout << "NO SOLUTION\n";
           return 0;
         }
         can = true;
         c = i;
       }else{
         for(int j=0;j<vet[i]/2;j++)
          resp.push_back(i+'A'); 
       }
     }
   }

   if(can)
    for(int i=0;i<vet[c];i++)
      resp.push_back(c+'A');

   for(int i=0;i<30;i++){
     if(vet[i] && vet[i]%2 == 0){
       for(int j=0;j<vet[i]/2;j++)
          resp.push_back(i+'A'); 
     }
   }

   cout << resp << endl;

  return 0;
}