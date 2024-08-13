#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6;
int T,n,x[N],y[N],sx,sy,tx,ty;

signed main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++)cin>>x[i]>>y[i];
        cin>>sx>>sy>>tx>>ty;
        int d=(sx-tx)*(sx-tx)+(sy-ty)*(sy-ty),tag=1;
        for(int i=1;i<=n;i++){
            int _d=(x[i]-tx)*(x[i]-tx)+(y[i]-ty)*(y[i]-ty);
            if(_d<=d)tag=0; 
        }
        if(tag)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}


