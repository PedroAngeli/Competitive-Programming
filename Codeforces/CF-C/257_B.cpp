#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

vector <int> solve(int first, int n,int m){
  int red = 1;
  int blue = 0;
  
  vector <int> seq;

  if(first == red)
    seq.push_back(red), n--;
  else
    seq.push_back(blue), m--;

  int turn = 1;

  while(n || m){
    if(turn){
      if(seq.back() == red && m)
        m--,seq.push_back(blue);
      else if(seq.back() == blue && n)
        n--,seq.push_back(red);
      else if(n)
        n--,seq.push_back(red);
      else
        m--,seq.push_back(blue);
    }else{
      if(seq.back() == red && n)
        n--,seq.push_back(red);
      else if(seq.back() == blue && m)
        m--,seq.push_back(blue);
      else if(n)
        n--,seq.push_back(red);
      else
        m--,seq.push_back(blue);
    }
    turn = 1-turn; 
  }

  return seq;
}

pair <int,int> points(vector <int> seq){
  int len = seq.size();
  int p=0,v=0;

  for(int i=0;i<len-1;i++)
    if(seq[i] == seq[i+1])
      p++;
    else
      v++;

  return {p,v};
}
int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int n,m;
  cin >> n >> m;
  
  int red = 1;
  int blue = 0;
  
  vector <int> seq1 = solve(red, n,m);
  vector <int> seq2 = solve(blue,n,m);
  pair <int,int> n1 = points(seq1);
  pair <int,int> n2 = points(seq2);

  if(n1.first > n2.first)
    cout << n1.first << " " << n1.second << endl;
  else 
    cout << n2.first << " " << n2.second << endl;
  return 0;
}