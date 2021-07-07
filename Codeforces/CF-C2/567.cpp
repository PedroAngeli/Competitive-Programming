#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  
  long long n,k;

  cin >> n >> k;
  vector <pair <int,int> > vet(n);

  for(int i=0;i<n;i++){
    cin >> vet[i].first;
    vet[i].second = i;
  }

 sort(vet.begin(),vet.end());

 long long ans = 0;
  const int INF = 1e9 + 7;

 for(int i=0;i<n;i++){
   int curIdx = vet[i].second;
   if(curIdx == 0 || curIdx == n-1)
    continue;
   long long curVal = vet[i].first;
   if(curVal % k)
    continue;

    long long search = curVal/k;
    pair <int,int> tmp = {search,-1};
    int p1 = lower_bound(vet.begin(),vet.end(),tmp) - vet.begin();
    if(vet[p1].first != search || (vet[p1].first == search && vet[p1].second >= curIdx))
      continue;
    tmp = {search,curIdx};
    int p2 = lower_bound(vet.begin(),vet.end(),tmp) - vet.begin();
    p2--;
    long long v1 = p2-p1+1;

    search = curVal*k;
    tmp = {search,INF};
    p2 = lower_bound(vet.begin(),vet.end(),tmp) - vet.begin();
    p2--;
    if(vet[p2].first != search || (vet[p2].first == search && vet[p2].second <= curIdx))
      continue;
    tmp = {search,curIdx};
    p1 = upper_bound(vet.begin(),vet.end(),tmp) - vet.begin();
    long long v2 = p2-p1+1;
    ans += v1*v2;
 }

 cout << ans << endl;
  
  return 0;
}