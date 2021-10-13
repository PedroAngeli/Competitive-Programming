#include <bits/stdc++.h>
using namespace std;
#define MAXVA 1005
#define MAXVB 1005
#define INF 0x3f3f3f3f
int VA, VB; //VA <= VB
//negar os custos para computar o emparelhamento máximo
int cost[MAXVA][MAXVB]; //1-indexed
//computa o emparelhamento mínimo em O(VA²VB)
int hungarian(){
  vector <int> pu(VA + 1), pv(VB + 1);
  vector <int> p(VB + 1), way(VB + 1);
  for(int i=1;i<=VA;i++){
    p[0] = i;
    int j0 = 0;
    vector <int> minv(VB+1, INF);
    vector <bool> used(VB+1, false);
    do{
      used[j0] = true;
      int i0 = p[j0], delta = INF, j1;
      for(int j=1;j<=VB;j++){
        if(used[j]) continue;
        int cur = cost[i0][j] - pu[i0] - pv[j];
        if(cur < minv[j])
          minv[j] = cur, way[j] = j0;
        if(minv[j] < delta)
          delta = minv[j], j1 = j;
      }
      for(int j=0;j<=VB;j++){
          if(used[j]) pu[p[j]] += delta, pv[j] -= delta;
          else minv[j] -= delta;
      }
      j0 = j1;
    }while(p[j0] != 0);
    do{
      int j1 = way[j0];
      p[j0] = p[j1];
      j0 = j1;
    }while(j0);
  }
  int result = 0;
  for(int j=1;j<=VB;j++)
    result += cost[p[j]][j];
  return result;
}