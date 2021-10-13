#include <bits/stdc++.h>

using namespace std;


int main(){

  long long n,m,k;

  cin >> n >> m >> k;

  vector <long long> clients(n);
  vector <long long> apartments(m); 
  
  for(int i=0;i<n;i++)
    cin >> clients[i];
  
  for(int i=0;i<m;i++)
    cin >> apartments[i];

  sort(clients.begin(),clients.end());
  sort(apartments.begin(),apartments.end());

  int resp = 0;

  for(int i=0,j=0;i<n && j<m;){
    if(clients[i]-k <= apartments[j] && clients[i]+k >= apartments[j]){
      resp++;
      i++;
      j++;
    }else if(apartments[j] > clients[i]){
      i++;
    }else{
      j++;
    }
  }

  cout << resp << endl;
  
  return 0;
}