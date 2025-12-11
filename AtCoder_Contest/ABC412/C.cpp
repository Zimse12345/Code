#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,a[N],s,t;

signed main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i];
        s=a[1],t=a[n];
        if(t<=s){
            printf("2\n");
            continue;
        }
        sort(a+1,a+n+1);
        int ans=2;
        for(int i=1;i<=n;i++){
            if(s*2>=t)break;
            if(a[i]>s*2){
                if(a[i-1]>s*2){
                    ans=-1;
                    break;
                }
                s=a[i-1],++ans;
            }
        }
        if(s*2>=t)printf("%d\n",ans);
        else printf("-1\n");
    }
    return 0;
}


