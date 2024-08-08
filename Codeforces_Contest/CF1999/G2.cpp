#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T;

signed main(){
    cin>>T;
    while(T--){
        int L=2,R=999;
        while(L<R){
            int lm=L+(R-L)/3,rm=R-(R-L)/3;
            printf("? %d %d\n",lm,rm);
            fflush(stdout);
            int x;
            cin>>x;
            if(x==lm*rm)L=rm+1;
            else if(x==lm*(rm+1))L=lm+1,R=rm;
            else R=lm;
        }
        printf("! %d\n",L);
        fflush(stdout);
    }
    return 0;
}


