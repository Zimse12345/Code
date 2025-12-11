#include <bits/stdc++.h>
using namespace std;

const int N=2.01e5,B=1000;
int n,q,a[N],b[N],f[3][210][N];

signed main(){
//    freopen("t.in","r",stdin);
//    freopen("t.out","w",stdout);
    
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    for(int i=1,x=-1;i<=n;i++){
        x=(x+a[i]+1)/2;
        b[i]=x;
    }
    for(int i=B;i<=n;i+=B){
        for(int j=0;j<3;j++){
            int x=b[i]+j-1;
            f[j][i/B][i]=x;
            for(int k=i+1;k<=n;k++){
                x=(x+a[k]+1)/2;
                f[j][i/B][k]=x;
            }
        }
    }
    for(int ii=1;ii<=q;ii++){
        int x,y;
        scanf("%d%d",&x,&y);
        int z=n+1,l=1,r=n;
        while(l<=r){
            int mid=(l+r)/2;
            if(a[mid]>x)z=mid,r=mid-1;
            else l=mid+1; 
        }
        y=n-y+1;
        if(y-z<=B*2+70){
            int xx=x;
            for(int i=z;i<=y;i++)xx=(xx+a[i]+1)/2;
            printf("%d\n",xx-x);
            continue;
        }
        int xx=x;
        for(int i=1;i<=60;i++){
            xx=(xx+a[z]+1)/2;
            ++z;
        }
        int zz=(z/B)*B;
        if(zz<z)zz+=B;
        while(z<=zz)xx=(xx+a[z]+1)/2,++z;
        
        int id=zz/B,ans=0;
        if(xx==b[zz]-1)ans=f[0][id][y]-x;
        if(xx==b[zz])ans=f[1][id][y]-x;
        if(xx==b[zz]+1)ans=f[2][id][y]-x;
        printf("%d\n",ans);
//        int ans=f(x,z,y);
//        printf("%d\n",ans);
    }
    return 0;
}


