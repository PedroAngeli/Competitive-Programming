#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
 

int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL); 
 
  int t = 1;
  // cin >> t;

  while(t--){
    int n;
    cin >> n;
    set <pair <int,int> > ans;
    int x = 10;
    int y = 10;

    while(n--){
      ans.insert({x,y});
      ans.insert({x,y+1});
      ans.insert({x,y-1});
      ans.insert({x-1,y-1});
      ans.insert({x-1,y});
      ans.insert({x+1,y});
      ans.insert({x+1,y+1});
      x++;
      y++;
    }

    cout << ans.size() << endl;

    for(auto it=ans.begin();it != ans.end();it++){
      cout << it->first << " " << it->second << endl;
    }
  }
 
  
  return 0;
}