#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

 int n;
 long long x;

 cin >> n >> x;

 long long ice = x;
 int kids = 0;

 while(n--){
   char c;
   long long d;

   cin >> c >> d;

   if(c == '+'){
     ice += d;
   }else{
     if(ice >= d)
      ice -= d;
     else
      kids++;
   }
 }

 cout << ice << " " << kids << endl;
  
  return 0;
}