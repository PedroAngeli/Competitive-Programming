#include <bits/stdc++.h>

using namespace std;

#define endl '\n'


int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

 int n;
 cin >> n;

 bool tiraMeio = false;

 while(n--){
   int x;

   cin >> x;

   if(x % 2==0){
     cout << x/2 << endl;
   }else{
     if(tiraMeio){
       if(x < 0)
        cout << x/2 - 1 << endl;
       else
        cout << x/2 << endl;
     }else{
       if(x < 0)
        cout << x/2 << endl;
      else
        cout << x/2 + 1 << endl;
     }

     tiraMeio = !tiraMeio;
   }
 }

  return 0;
}