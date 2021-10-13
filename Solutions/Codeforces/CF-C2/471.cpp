#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  
  int n;
  cin >> n;
  vector <pair <int,int> > vet(n);
  set <int> s;

  for(int i=0;i<n;i++){
    cin >> vet[i].first;
    vet[i].second = i;
    s.insert(vet[i].first);
  }

  if(s.size() == n || s.size() == n-1){
    cout << "NO" << endl;
    return 0;
  }

  vector <pair <int,int> > ans[3];

  sort(vet.begin(),vet.end(),[&](pair <int,int> p1,pair <int,int> p2){
    return (p1.first < p2.first) || (p1.first == p2.first && p1.second < p2.second);
  });

  ans[0] = vet;

  sort(vet.begin(),vet.end(),[&](pair <int,int> p1,pair <int,int> p2){
    return (p1.first < p2.first) || (p1.first == p2.first && p1.second > p2.second);
  });

  ans[1] = vet;

  bool choice = true;

  for(int i=0;i<n;i++){
    if(ans[0][i] == ans[1][i])
      ans[2].push_back(ans[0][i]);
    else{
      while(i < n-1 && ans[0][i].first == ans[0][i+1].first)
        ans[2].push_back(ans[0][i]),i++;

      ans[2].push_back(ans[0][i]);
      if(choice)
        swap(ans[2][i],ans[2][i-1]);
      choice = !choice;
    }
  }

  cout << "YES" << endl;
  
  for(int k=0;k<3;k++){
    for(int i=0;i<n;i++)
      cout << ans[k][i].second+1 << " ";
    cout << endl;
  }

  return 0;
}