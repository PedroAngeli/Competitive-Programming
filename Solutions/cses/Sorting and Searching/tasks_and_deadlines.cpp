#include <bits/stdc++.h>

using namespace std;

int main(){

  int n;
  cin >> n;
  vector <pair <int,int> > tasks(n);

  for(int i=0;i<n;i++){
    int a,d;
    cin >> a >> d;
    tasks[i] = {a,d};
  }

  sort(tasks.begin(),tasks.end());

  long long resp = 0;
  long long total = 0;

  for(int i=0;i<n;i++){
    total += tasks[i].first;
    resp += (tasks[i].second - total);
  }

  cout << resp << endl;

  return 0;
}