#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
  
int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
 
  int n,m,k;

  cin >> n >> m >> k;
  vector <vector <int> > arrs(n,vector <int>(m));

  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
      cin >> arrs[i][j];

  vector <pair <int,int> > ans;
  vector <vector <bool> > used(m,vector <bool>(m,false));

  for(int i=0;i<m;i++){
    for(int j=i+1;j<m;j++){
      if(k == 0){
        for(vector <int> arr : arrs){
          if(arr[i] > arr[j] && !used[i][j]){
            swap(arr[i],arr[j]);
            used[i][j] = true;
            ans.push_back({i+1,j+1});
          }
        }
      }else{
        for(vector <int> arr : arrs){
          if(arr[j] > arr[i] && !used[i][j]){
            swap(arr[i],arr[j]);
            used[i][j] = true;
            ans.push_back({j+1,i+1});
          }
        }
      }
    }
  }

  int len = ans.size();
  cout << len << endl;
  for(int i=0;i<len;i++){
    cout << ans[i].first << " " << ans[i].second << endl;
  }


  return 0;
}