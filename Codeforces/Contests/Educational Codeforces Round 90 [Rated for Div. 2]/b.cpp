#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
 
int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  
  int t = 1;
  cin >> t;

  while(t--){
    string s;
    cin >> s;
    int n = s.size();
    int cntO = 0;
    int cntZ = 0;

    for(int i=0;i<n;i++)
      if(s[i] == '1')
        cntO++;
      else
        cntZ++;
    
    int moves = min(cntO,cntZ);

    if(moves % 2 == 1)
      cout << "DA" << endl;
    else
      cout << "NET" << endl;
  }
  
   
  return 0;
}