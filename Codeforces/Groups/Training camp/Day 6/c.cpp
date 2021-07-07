#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'


int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
 
  int n;
  string s;
  cin >> n;
  cin >> s;
  
  int mx = 0;
  stack <char> p;

  for(int i=0;i<n;i++){
    char cur = s[i];
    if(cur == '[')
      p.push(cur);
    else
      p.pop();
    mx = max(mx,(int)p.size());
  }

  int h = mx*2 - 1;

  vector <vector <char> >ans(h+100,vector <char>(300,' ')) ;  
  stack <int> draw;
  int x = 0;

  for(int i=0;i<n;i++){
    char cur = s[i];
    if(cur == '['){
      if(draw.size() > 0)
        draw.push(draw.top()-2);
      else
        draw.push(h);
      if(i>0){
        if(s[i] == s[i-1])
          x++;
        else
          x+=2;
      }
      int height = draw.top();
      int y = h-height;
      y/=2;
      ans[y][x] = '+';
      ans[y][x+1] = '-';
      while(height--)
        ans[++y][x] = '|';
      ans[++y][x] = '+';
      ans[y][x+1] = '-';
    }
    else{
      int height = draw.top();
      draw.pop();
      int y = h-height;
      y/=2;
      if(s[i] == s[i-1])
        x++;
      else
        x+=3;
      ans[y][x] = '-';
      ans[y][x+1] = '+';
      while(height--)
        ans[++y][x+1] = '|';
      ans[++y][x] = '-';
      ans[y][x+1] = '+';
    }
  }

  int lastPos = 0;
  for(int i=0;i<300;i++)
    if(ans[0][i] != ' ')
      lastPos = i;
  
  for(int i=0;i<h+2;i++){
    for(int j=0;j<=lastPos;j++)
      cout << ans[i][j];
    cout << endl;
  }
  
    
  return 0;
}