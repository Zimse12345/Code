#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,m,q;

signed main(){
    cin>>T;
    while(T--){
        cin>>n>>m>>q;
        int x,y;
        cin>>x>>y;
        if(x>y)swap(x,y);
        while(q--){
            int p;
            cin>>p;
            if(p<x)printf("%d\n",x-1);
            else if(p>y)printf("%d\n",n-y);
            else printf("%d\n",(y-x)/2);
        }
    }
    return 0;
}


