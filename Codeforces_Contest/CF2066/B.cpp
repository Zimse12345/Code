#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,a[N],b[N],c[N],d[N];

signed main(){
    cin>>T;
    while(T--){
        cin>>n;
        int s=0;
        for(int i=0;i<=n+1;i++)b[i]=c[i]=d[i]=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(i==1)b[i]=a[i];
            else b[i]=min(b[i-1],a[i]);
            if(a[i])++s;
        }
        d[0]=1,c[n+1]=1;
        for(int i=n;i>=1;i--){
            if(a[i]<=n)++d[a[i]];
            c[i]=c[i+1];
            while(d[c[i]])++c[i];
        }
        for(int i=1;i<=n;i++){
            if(a[i]==0){
                ++s;
                break;
            }
            if(i<n&&b[i]<c[i+1])break;
        }
        printf("%d\n",s);
    }
    return 0;
}


