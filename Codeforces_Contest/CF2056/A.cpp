#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,m,x,y; 

signed main(){
    cin>>T;
    while(T--){
        cin>>n>>m;
        int X=m,Y=m;
        for(int i=1;i<=n;i++){
            cin>>x>>y;
            if(i!=1)X+=x,Y+=y;
        }
        printf("%d\n",(X+Y)*2);
    }
    return 0;
}


