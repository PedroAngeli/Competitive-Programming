#include <cstdio>
#include <string>
#include <iostream>
 
using namespace std;
 
int main(){
 
    int k;
 
    scanf("%d",&k);
 
    string a,b,s,r;
    s.resize(k+3,0);
    
    cin >> a;
    cin >> b;
 
    for(int i=0;i<k;i++){
        a[i]-='a';
        b[i]-='a';
    }
 
    int q = 0;
 
    for(int i=k-1;i>=0;i--){
        s[i+1] = (q + a[i] + b[i])%26;
        q = (q + a[i] + b[i]) > 25;
        s[i] = q;
    } 
 
    int resto = 0;
 
   for(int i=0;i<k+1;i++){
       r.push_back((s[i] + 26*resto)/2);
       resto = (s[i] + 26*resto) % 2;
   }
 
   for(int i=1;i<=k;i++){
       printf("%c",r[i] + 'a');
   }
 
   printf("\n");
 
    return 0;
}