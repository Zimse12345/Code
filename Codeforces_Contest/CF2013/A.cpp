#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,x,y; 

signed main(){
    cin>>T;
    while(T--){
        cin>>n>>x>>y;
        if(!n)printf("0\n");
        else printf("%d\n",(n-1)/min(x,y)+1);
    }
    return 0;
}


