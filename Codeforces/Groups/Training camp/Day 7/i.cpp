#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'


int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
 
  int n;
  cin >> n;
  
  vector <int> a;
  for(int i=0;i<n;i++){
    int x;
    cin >> x;
    if(x)
      a.push_back(x);
  }
  for(int i=0;i<n-1;i++)
      a.push_back(a[i]);

  vector <int> b;

   for(int i=0;i<n;i++){
    int x;
    cin >> x;
    if(x)
      b.push_back(x);
  }

  int l1 = a.size();
  int l2 = b.size();

  int i=0;
  while(i < l1){
    int tmp = i;
    int j = 0;
    while(j < l2 && a[tmp] == b[j])
      tmp++,j++;
    if(j == l2){
      cout << "YES" << endl;
      return 0;
    }
    i++;
  }

  cout << "NO" << endl;
  return 0;
}