#include <bits/stdc++.h>

using namespace std;

#define endl '\n'


int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  while(t--){
    int a,b,c,d;
    int e,f,g,h;
    

    cin >> a >> b >> c >> d;
    cin >> e >> f >> g >> h;

    int i = max(a,e);
    int j = max(b,f);
    int k = min(c,g);
    int l = min(d,h);

    if(i >= k || j >= l)
      cout << "No Overlap" << endl;
    else
      cout << i << " " << j << " " << k << " " << l << endl;
    
    if(t)
      cout << endl;
  }

  


  return 0; 
}