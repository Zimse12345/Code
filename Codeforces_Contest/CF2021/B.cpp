#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,x,a[N],t[N],ans;

signed main(){
    cin>>T;
    while(T--){
        cin>>n>>x;
        for(int i=0;i<=n;i++)t[i]=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(a[i]<=n)++t[a[i]];
        }
        for(int i=0;i<=n;i++){
            if(!t[i]){
                ans=i;
                break;
            }
            if(i+x<=n)t[i+x]+=t[i]-1;
        }
        printf("%d\n",ans);
    }
    return 0;
}


