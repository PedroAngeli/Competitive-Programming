#include <bits/stdc++.h>

using namespace std;


int main(){

  int n;
  cin >> n;

  vector <int> resp;

  for(int i=1;i<=n;i++)
    if(i%2==0)
      resp.push_back(i);

  for(int i=1;i<=n;i++)
    if(i%2!=0)
      resp.push_back(i);

  for(int i=1;i<resp.size();i++)
    if(abs(resp[i]-resp[i-1]) == 1)
    {
      cout << "NO SOLUTION" << endl;
      return 0;
    }

  for(int i=0;i<resp.size();i++)
    cout << resp[i] << " ";

  cout << endl;
  
  return 0;
}