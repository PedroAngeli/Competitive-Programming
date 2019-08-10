#include <cstdio>
#include <initializer_list>

using namespace std;


int main(){

    for(int x : {4,5}){
        printf("%d\n",x);
    }
    return 0;
}