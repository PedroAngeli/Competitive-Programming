#include <bits/stdc++.h>
using namespace std;
const int nax = 1e5 + 1;
int ft[nax]; //1 - indexed
//Computes prefix sum (1..)
//O(lg n)
int query(int i){
  int ret = 0;
  while(i > 0){
    ret += ft[i];
    i -= (i & (-i));
  }
  return ret;
}
//Computes sum in range(l, r)
//O(lg n)
int query(int l, int r){
  if(l == 0) return query(r);
  return query(r) - query(l-1);
}
//Updates BIT (sums val in position i)
//O(lg n)
void update(int i, int val){
  if(i == 0) return;
  while(i < nax){
    ft[i] += val;
    i += (i & (-i));
  }
}