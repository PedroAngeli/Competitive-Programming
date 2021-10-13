#include <bits/stdc++.h>

using namespace std;


int main(){

 int n;
 cin >> n;
 vector <int> vet(n);

 for(int i=0;i<n;i++)
  cin >> vet[i];

 stack <pair <int,int> > p;

 for(int i=0;i<n;i++){
   while(!p.empty() && p.top().first >= vet[i]){
     p.pop();
   }

   if(p.empty())
    cout << "0 ";
   else
    cout << p.top().second + 1 << " ";

    p.push({vet[i],i});
 }
 cout << endl;

  return 0;
}