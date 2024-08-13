#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,x,y,k; 

signed main(){
    cin>>T;
    while(T--){
        cin>>x>>y>>k;
        int r=0;
        while(k>1){
            ++r;
            printf("%d %d\n%d %d\n",x-r,y,x+r,y);
            k-=2;
        }
        if(k)printf("%d %d\n",x,y);
    }
    return 0;
}


