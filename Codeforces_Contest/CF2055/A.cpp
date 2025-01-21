#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,a,b; 

signed main(){
    cin>>T;
    while(T--){
        cin>>n>>a>>b;
        int d=a-b;
        if(d<0)d=-d;
        if(d&1)printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}


