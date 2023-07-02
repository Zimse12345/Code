#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,ax,ay,bx,by,cx,cy; 

signed main(){
    cin>>T;
    while(T--){
        cin>>ax>>ay>>bx>>by>>cx>>cy;
        int ans=1;
        if(bx<=ax&&cx<=ax)ans+=ax-max(bx,cx);
        if(bx>=ax&&cx>=ax)ans+=min(bx,cx)-ax;
        swap(ax,ay),swap(bx,by),swap(cx,cy);
        if(bx<=ax&&cx<=ax)ans+=ax-max(bx,cx);
        if(bx>=ax&&cx>=ax)ans+=min(bx,cx)-ax;
        printf("%d\n",ans);
    }
    return 0;
}



