#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
 
int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
 
  int t;
  cin >> t;
  while(t--){
   int n,m,a,b;
   cin >> n >> m >> a >> b;
   vector <vector<int>> ans(n,vector<int>(m,0));
   if(n*a != m*b){
     cout << "NO" << endl;
   }else{
     cout << "YES" << endl;
     int count =0;
     for(int i=0;i<n;i++){
       for(int j=0;j<a;j++){
         ans[i][(j+count)%m]=1;
       }
       count+=a;
     }

     for(int i=0;i<n;i++){
       for(int j=0;j<m;j++)
        cout << ans[i][j];
      cout << endl;
     }
   }
  }
 
  return 0;
}