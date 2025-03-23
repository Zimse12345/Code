#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,a[N],b[N]; 

signed main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i];
        sort(a+1,a+n+1);
        for(int i=1;i<=n;i++)cin>>b[i];
        sort(b+1,b+n+1);
        int x=0,y=0;
        for(int i=1;i<=n;i++){
            if(a[i]!=a[i-1])++x;
            if(b[i]!=b[i-1])++y;
        }
        if(x*y>=3)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}


