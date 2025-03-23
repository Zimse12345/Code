#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6;
int T,n,m,a[N],b[N],ans[N],k;

signed main(){
    cin>>T;
    while(T--){
        cin>>n>>m;
        k=0;
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<=m;i++)cin>>b[i];
        sort(a+1,a+n+1);
        sort(b+1,b+m+1);
        int al=1,ar=n,bl=1,br=m,aa=0,bb=0,sum=0;
        while(1){
            if(ar-al>bb&&br-bl>=aa){
                if(br-bl>aa&&ar-al>=bb&&b[br]-b[bl]>a[ar]-a[al]){
                    sum+=b[br]-b[bl];
                    ++bl,--br,++bb;
                }
                else{
                    sum+=a[ar]-a[al];
                    ++al,--ar,++aa;
                }
            }
            else if(br-bl>aa&&ar-al>=bb){
                sum+=b[br]-b[bl];
                ++bl,--br,++bb;
            }
            else if(ar-al>bb+1&&bl>1&&br<m){
                sum+=a[ar]-a[al]+a[ar-1]-a[al+1];
                al+=2,ar-=2,aa+=2;
                --bl,++br,--bb;
                sum-=b[br]-b[bl];
            }
            else if(br-bl>aa+1&&al>1&&ar<n){
                sum+=b[br]-b[bl]+b[br-1]-b[bl+1];
                bl+=2,br-=2,bb+=2;
                --al,++ar,--aa;
                sum-=a[ar]-a[al];
            }
            else break;
            ans[++k]=sum;
        }
        printf("%lld\n",k);
        for(int i=1;i<=k;i++)printf("%lld ",ans[i]);
        printf("\n");
    }
    return 0;
}


