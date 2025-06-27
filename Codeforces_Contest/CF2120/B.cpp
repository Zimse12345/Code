#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,s;

signed main(){
    cin>>T;
    while(T--){
        cin>>n>>s;
        int ans=0;
        while(n--){
            int x,y,dx,dy;
            cin>>dx>>dy>>x>>y;
            if(dx<0)x=s-x;
            if(dy<0)y=s-y;
            if(x==y)++ans;
        }
        printf("%d\n",ans);
    }
    return 0;
}


