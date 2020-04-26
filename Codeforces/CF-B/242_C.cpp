#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

map <pair<int,int>,bool> allowed;
map <pair<int,int>,bool> visitado;

bool valid(int i,int j){
  return i >= 1 && i<=1e9 && j>=1 && j<=1e9 && allowed.find({i,j}) != allowed.end() && !visitado[{i,j}];
}

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int x0,y0,x1,y1;

  cin >> x0 >> y0 >> x1 >> y1;

  int n;
  cin >> n;

  while(n--){
    int r,a,b;

    cin >> r >> a >> b;

    for(int i=a;i<=b;i++){
      allowed[{r,i}] = true;
      visitado[{r,i}] = false;
    }
  }

  queue <pair< pair<int,int> ,int > > q;
  q.push({{x0,y0},0});

  while(!q.empty()){
    auto p = q.front();
    q.pop();

    vector < pair<int,int> > mov = {{1,0},{-1,0},{0,-1},{0,1},{1,1},{-1,1},{-1,-1},{1,-1}};

    for(int i=0;i<8;i++){
      int dx = p.first.first + mov[i].first;
      int dy = p.first.second + mov[i].second; 
      int d = p.second;

      if(valid(dx,dy)){
        visitado[{dx,dy}] = true;

        if(dx == x1 && dy == y1){
          cout << d + 1 << endl;
          return 0;
        }
        q.push({{dx,dy},d+1});
      }
    }
  }

  cout << -1 << endl;

  return 0;
}