#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6,p=12;
int T,n,s[N],a[N],b[N];

bool ck(int l,int r,int ty){
    printf("? %d ",r-l+1+ty);
    for(int i=l;i<=r;i++)printf("%d ",i);
    if(ty)printf("%d ",l);
    printf("\n");
    fflush(stdout);
    int res=0;
    cin>>res;
    return res>0;
}

signed main(){
    cin>>T;
    b[0]=1;
    for(int i=1,sum=1;i<p;i++){
        while(b[i]*(b[i]+1)/2<=sum)++b[i];
        sum+=b[i]*(b[i]+1)/2;
//        printf("%d ",b[i]);
    }
    while(T--){
        cin>>n;
        int l=1,r=n;
        while(l+1<r){
            int mid=(l+r)/2;
            if(ck(l,mid,1))r=mid;
            else l=mid;
        }
        if(!ck(l,r,0))swap(l,r);
        for(int i=1;i<=n;i+=p){
            for(int j=0;j<p;j++)a[j]=min(i+j,n);
            int C=0;
            printf("? 582 ");
            for(int j=0;j<p;j++){
                printf("%d %d %d ",l,l,a[j]);C+=3;
                for(int k=1;k<b[j];k++)printf("%d %d ",l,a[j]),C+=2;
            }
            printf("\n");
            fflush(stdout);
            //printf("C=%d\n",C);return 0;
            int res=0;
            cin>>res;
            for(int j=p-1;j>=0;j--){
                if(res>=b[j]*(b[j]+1)/2)s[a[j]]=1,res-=b[j]*(b[j]+1)/2;
                else s[a[j]]=0;
            }
        }
        printf("! ");
        for(int i=1;i<=n;i++){
            if(s[i]==0)printf("(");
            else if(s[i]==1)printf(")");
            else printf("?");
        }
        printf("\n");
        fflush(stdout);
    }
    return 0;
}


