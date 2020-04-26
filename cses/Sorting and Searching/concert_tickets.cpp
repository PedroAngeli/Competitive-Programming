#include <bits/stdc++.h>

using namespace std;

int main(){

 int n,m;
 cin >> n >> m;

 multiset <int, greater<int> > tickets;
 vector <int> clients(m);

 for(int i=0;i<n;i++){
   int a;
   cin >> a;
   tickets.insert(a);
 }
 
 for(int i=0;i<m;i++)
  cin >> clients[i];

  for(int i=0;i<m;i++){
    long long p = clients[i];
    auto it = tickets.lower_bound(p);

    if(it != tickets.end()){
      cout << *it << "\n";
      tickets.erase(it);
    }else{
      cout << "-1\n";
    }
  }


  

  return 0;
}