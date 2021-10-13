#include <bits/stdc++.h>
using namespace std;
#define all(c) (c).begin(), (c).end()
struct  Query{
  int idx, l, r;
};
void add(int x){}
void rem(int x){}
//receives array a from input and querys
//returns answer to querys
//Ω(Q log Q + (Q + N)√N)
vector <int> MO(vector <int>& a, vector <Query>& querys){
  int l = 0;
  int r = -1;
  vector <int> ans(querys.size());
  int n = a.size();
  int sqrt_n = sqrt(n) + 1;
  sort(all(querys), [&](auto q1, auto q2){
    if((q1.l/sqrt_n) != (q2.l/sqrt_n)) return q1.l < q2.l;
    return q1.r < q2.r;
  });
  for(Query q: querys){
    while(l > q.l) add(a[--l]);
    while(r < q.r) add(a[++r]);
    while(l < q.l) rem(a[l++]);
    while(r > q.r) rem(a[r--]);
    //compute answer for query
    // ans[q.idx] = ???
  }
  return ans;
}