#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6;
int T,n,a[N],b[N],b2[N],b3[N];

signed main(){
    cin>>T;
    while(T--){
        cin>>n;
        int sum=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            sum+=a[i];
            b[i]=b2[i]=b3[i]=0;
        }
        if(sum%2==1){
            printf("-1\n");
            continue;
        }
        int p=0,s=0;
        while((s+a[p+1])*2<=sum)++p,s+=a[p];
        if(s*2==sum){
            printf("1\n");
            for(int i=1;i<=n;i++)printf("%lld ",a[i]);
            printf("\n");
            continue;
        }
        int y=sum-s-a[p+1]-s;
        int z=a[p+1]-y;
        //        printf("y=%lld  z=%lld\n",y,z);
        if(z/2>s){
            printf("-1\n");
            continue;
        }
        int S=s+a[p+1],P=0,ss=0;
        while((ss+a[P+1])*2<=S)++P,ss+=a[P];
        ss=max(ss,S-ss-a[P+1]);
        if(S-ss*2<=sum-S){
            ss=(S-(sum-S))/2;
//            printf("p=%lld P=%lld ss=%lld\n",p,P,ss);
            int rm=ss;
            for(int i=1;i<=P+1;i++)if(rm){
                b[i]=min(a[i],rm);
                rm-=b[i];
            }
            rm=ss;
            for(int i=p+1;i>=P+1;i--)if(rm){
                b[i]=min(a[i],rm);
                rm-=b[i];
            }
            printf("2\n");
            for(int i=1;i<=n;i++)printf("%lld ",b[i]);
            printf("\n");
            for(int i=1;i<=n;i++)printf("%lld ",a[i]-b[i]);
            printf("\n");
            continue;
        }
        
        int rm=z/2;
        for(int i=1;i<=p;i++){
            b[i]=max(0ll,a[i]-rm);
            b2[i]=a[i]-b[i];
            rm-=a[i]-b[i];
        }
        b[p+1]=y,rm=z/2;
        b2[p+1]=z/2,b3[p+1]=z/2;
        for(int i=n;i>p+1;i--){
            b[i]=max(0ll,a[i]-rm);
            b3[i]=a[i]-b[i];
            rm-=a[i]-b[i];
        }
        printf("3\n");
        for(int i=1;i<=n;i++)printf("%lld ",b[i]);
        printf("\n");
        for(int i=1;i<=n;i++)printf("%lld ",b2[i]);
        printf("\n");
        for(int i=1;i<=n;i++)printf("%lld ",b3[i]);
        printf("\n");
    }
    return 0;
}


