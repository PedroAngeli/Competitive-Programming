#include <bits/stdc++.h>
using namespace std;
const int max_x = 1e3 + 1;
const int max_y = 1e3 + 1;
int ft[max_x][max_y]; //1 - indexed
//Updates BIT (sums val in position (x, y))
//O(lg(n)*lg(m))
void update(int x, int y, int val){
    while(x < max_x){
      int y1 = y;
      while(y1 < max_y){
        ft[x][y1] += val;
        y1 += (y1 & (-y1));
      }
      x += (x & (-x));
    }
}
//Sum in square (1, 1) - (x, y)
//O(lg(n)*lg(m))
int sum_range(int x,int y){
  int ret = 0;
  while(x > 0){
    int y1 = y;
    while(y1 > 0){
      ret += ft[x][y1];
      y1 -= (y1 & (-y1));
    }
    x -= (x & (-x));
  }
  return ret;
}
//Sum in square (x1, y1) - (x2, y2)
//O(lg(n)*lg(m))
int query(int x1, int y1,int x2,int y2){
  return sum_range(x2, y2) - sum_range(x2, y1 - 1) - 
  sum_range(x1 - 1,y2) + sum_range(x1-1,y1-1);
}