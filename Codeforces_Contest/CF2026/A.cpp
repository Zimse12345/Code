#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,x,y,k;

signed main(){
    cin>>T;
    while(T--){
        cin>>x>>y>>k;
        int t=min(x,y);
        printf("%d %d %d %d\n%d %d %d %d\n",0,t,t,0,0,0,t,t);
    }
    return 0;
}


