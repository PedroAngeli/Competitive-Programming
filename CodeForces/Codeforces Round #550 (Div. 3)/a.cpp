#include <cstdio>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

int main(){
  int n;
  scanf("%d*c",&n);

  while(n--){
    int c[300] = {0};
    string line;
    cin >> line;

    sort(line.begin(),line.end());
    
    bool diverse = true;

    for(int i=0;i<line.size()-1;i++){

      c[line[i]]++;
      if(line[i]+1 != line[i+1] || c[line[i]] > 1){
        diverse = false;
        break;
      }
    }

    if(diverse)
      printf("Yes\n");
    else 
      printf("No\n");
  }
  return 0;
}