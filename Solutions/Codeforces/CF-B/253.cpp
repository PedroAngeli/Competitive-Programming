#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

ifstream fin ("input.txt");
ofstream fout ("output.txt");

const int nax = 1e5 + 5;
int vet[nax];

int main(){

  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);

  int n;
  fin >> n;

  for(int i=0;i<n;i++)
    fin >> vet[i];
  
  sort(vet,vet+n);

 int j=0;
 int ans=n-1;

  for(int i=1;i<n;i++){
      while(j<=i && 2*vet[j]<vet[i])
            j++;

      ans = min(ans,n-1-i+j);
    }
  
  fout << ans << endl;

  return 0;
}