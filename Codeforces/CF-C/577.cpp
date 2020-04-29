#include <bits/stdc++.h>

using namespace std;

#define endl '\n'


bool can(int n){
  set <int> s;

  int div = 2;

  while(div*div<=n){
    if(n % div == 0){
      n/=div;
      s.insert(div);
    }else
      div++;
  }

  if(n!=1)
    s.insert(n);
  
  return s.size() == 1;
}

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  vector <int> ans;

  for(int i=2;i<=n;i++){
    if(can(i)){
      ans.push_back(i);
    }
  }

  cout << ans.size() << endl;

  for(int i=0;i<ans.size();i++)
    cout << ans[i] << " ";
  
  cout << endl;

  return 0;
}