#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

ifstream fin ("input.txt");
ofstream fout ("output.txt");
const int nax = 1e2+1;
int n;
int vet[nax];
int r1,r2,c1,c2;
bool visitado[nax][100002];

int solve(int i, int j){

  queue <pair <pair<int,int>, int> > q;
  q.push({{i,j},0});

  while(!q.empty()){
    pair <int,int> cur = q.front().first;
    int dist = q.front().second;
    q.pop();

    int r = cur.first;
    int c = cur.second;

    if(r == r2 && c == c2)
      return dist;

    if(c+1 <= vet[r]+1 && !visitado[r][c+1])
      visitado[r][c+1] = true, q.push({{r,c+1},dist+1});
    
    if(c-1 >= 1 && !visitado[r][c-1])
      visitado[r][c-1] = true, q.push({{r,c-1},dist+1});

    if(r+1 <= n){
      if(c <= vet[r+1]+1 && !visitado[r+1][c])
        visitado[r+1][c] = true,q.push({{r+1,c},dist+1});
      else if(c > vet[r+1]+1 && !visitado[r+1][vet[r+1]+1])
        visitado[r+1][vet[r+1]+1] = true,q.push({{r+1,vet[r+1]+1},dist+1});
    }

    if(r-1 >= 1){
      if(c <= vet[r-1]+1 && !visitado[r-1][c])
       visitado[r-1][c] = true, q.push({{r-1,c},dist+1});
      else if(c > vet[r-1]+1 && !visitado[r-1][vet[r-1]+1])
        visitado[r-1][vet[r-1]+1] = true,q.push({{r-1,vet[r-1]+1},dist+1});
    }
  }
    return 0;
}

int main(){

  fin >> n;

  for(int i=1;i<=n;i++)
    fin >> vet[i];

  fin >> r1 >> c1 >> r2 >> c2;

  fout << solve(r1,c1) << endl;

  return 0;
}