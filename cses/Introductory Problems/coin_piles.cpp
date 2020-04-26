#include <bits/stdc++.h>

using namespace std;

int main(){

  int t;
  cin >> t;

  while(t--){
    long long a,b;
     cin >> a >> b;

  if(a<b) swap(a,b);

  if(a>2*b) 
  {
     cout<<"NO" << endl;
   }
   else{
     if((a+b)%3==0) 
      {
        cout<<"YES"<< endl;
      }
  else cout<<"NO"<< endl;
   }

  
     
  }

  return 0;
}