#include <bits/stdc++.h>

using namespace std;

#define endl '\n'


int main(){
  
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  char line[1030];

  while(true){
      while(scanf("%[^\n]%*c",line) == 1){
      string s = line;
      if(s[0] == '#')
        return 0;
      int n = s.size();
      
      long long g = 34943;
      long long message = 0;

      for(int i=0;i<n;i++){
        message = (message*256 + s[i])%g;
      }
      message = message*256*256;
      int crc = (g-message%g)%g;

      printf("%02X %02X\n",crc/256,crc%256);
    }
    printf("00 00\n");
    scanf("%*c");
  }
  
  return 0;
}