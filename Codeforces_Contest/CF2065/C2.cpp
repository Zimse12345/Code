#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,m,a[N],b[N];
set<int> s;

signed main(){
    cin>>T;
    while(T--){
        cin>>n>>m;
        s.clear();
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<=m;i++)cin>>b[i],s.insert(b[i]);
        s.insert(2e9);
        a[0]=-2e9;
        int ans=1;
        for(int i=1;i<=n;i++){
            //b-a[i]>=a[i-1] 
            int x=*s.lower_bound(a[i-1]+a[i]);
            if(x<2e9){
                if(a[i]<a[i-1])a[i]=x-a[i];
                else a[i]=min(a[i],x-a[i]); 
            }
            if(a[i]<a[i-1]){
                ans=0;
                break;
            }
        }
        if(ans)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}


