#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,a[N],ans[N],cnt;

inline int _abs(int x){
    return x<0?-x:x;
}

signed main(){
    cin>>T;
    while(T--){
        cin>>n;
        cnt=0;
        for(int i=1;i<=n;i++)cin>>a[i];
        while(1){
            int mx=0,f0=0;
            for(int i=1;i<=n;i++){
                mx=max(mx,a[i]);
                if(!a[i])f0=1;
            }
            if(mx>1){
                ans[++cnt]=mx/2;
                for(int i=1;i<=n;i++)a[i]=_abs(a[i]-mx/2);
            }
            else if(mx==1){
                ans[++cnt]=1;
                if(f0)cnt=-1;
                break;
            }
            else{
                break;
            }
        }
        printf("%d\n",cnt);
        if(cnt>=0){
            for(int i=1;i<=cnt;i++)printf("%d ",ans[i]);
            printf("\n");
        }
    }
    return 0;
}


