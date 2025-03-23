#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6;
int T,n,m,a[N],ans;

int dr(int x,int y){
    if(x<=y)return y-x;
    return m-x+y;
}

int dl(int x,int y){
    return dr(y,x);
}

bool R(int x,int y){
    return dr(x,y)<=dl(x,y);
}

signed main(){
    cin>>T;
    while(T--){
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            a[i]%=m;
        }
        sort(a+1,a+n+1);
        for(int i=1;i<=n;i++)a[i+n]=a[i];
        int s=0,p=1;
        while(p<n&&R(a[1],a[p+1]))++p,s+=dr(a[1],a[p]);
        for(int i=p+1;i<=n;i++)s+=dl(a[1],a[i]);
        ans=s;
        for(int i=2;i<=n;i++){
            s-=dr(a[i-1],a[i])*(p-i+1);
            while(p<n+i-1&&R(a[i],a[p+1]))++p,s+=dr(a[i],a[p])-dl(a[i-1],a[p]);
            s+=dr(a[i-1],a[i])*(n-(p-i+1));
            ans=min(ans,s);
        }
        printf("%lld\n",ans);
    }
    return 0;
}


