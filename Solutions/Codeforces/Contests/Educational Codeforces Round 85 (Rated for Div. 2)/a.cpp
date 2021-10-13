#include <bits/stdc++.h>

using namespace std;

int main(){

  int t;

  cin >> t;

  while(t--){
    int n;

    cin >> n;

    vector <int> p(n);
    vector <int> c(n);

    for(int i=0;i<n;i++)
      cin >> p[i] >> c[i];

    bool ans = true;

    if(c[0] > p[0])
      ans = false;
      
     for(int i=1;i<n;i++){

       if(p[i] < p[i-1]){
         ans = false;
         break;
       }

        if(c[i] < c[i-1]){
         ans = false;
         break;
       }

       if(c[i] > p[i]){
         ans = false;
         break;
       }

       if(c[i] - c[i-1] > p[i] - p[i-1]){
         ans = false;
         break;
       }
     }

     if(ans)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}