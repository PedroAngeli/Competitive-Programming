#include <cstdio>
#include <cmath>
 
long long unsigned int gcd(long long unsigned int a, long long unsigned int b) 
{
    if(b == 0)
        return a;
 
    return gcd(b,a % b);
}
 
 
int main(){
 
    long long unsigned int n,m,q;
 
    scanf("%llu %llu %llu",&n,&m,&q);
 
    for(int i=0;i<q;i++){
        long long unsigned int s1,s2,e1,e2;
        scanf("%llu %llu %llu %llu",&s1,&s2,&e1,&e2);
        long long unsigned int mdc = gcd(n,m);
        bool can = true;
 
        long double x;
        long double y;
        
        if(s1 == 1)
            x = s2*((long double)mdc/n);
        else 
            x = s2*((long double)mdc/m);
 
        if(e1 == 1)
            y = e2*((long double)mdc/n);
        else
            y = e2*((long double)mdc/m);
 
        x = ceill(x);
        y = ceill(y);
 
        if(x!=y)
            can = false;
 
        if(can){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }
 
    return 0;
}