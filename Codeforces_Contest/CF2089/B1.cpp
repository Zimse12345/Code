#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6;
int T,n,k,a[N],b[N],aa[N],bb[N],stk[N];

int ck(int d){
    int s=0,tp=0;
    for(int i=0;i<n;i++){
        aa[i]=a[i];
        bb[i]=b[i];
    }
    for(int i=0,j=0;i<n;i++){
        if(aa[i]>0&&stk[tp]!=i)stk[++tp]=i;
        while(aa[i]>0){
            if(j>i+d-1)break;
            if(i+d-1<n&&j<i)break;
            if(i+d-1>=n&&j<i&&j>(i+d-1)%n)break;
            if(aa[j]>0&&stk[tp]!=j)stk[++tp]=j;
            while(bb[j]>0){
                int t=min(aa[stk[tp]],bb[j]);
                aa[stk[tp]]-=t,bb[j]-=t;
                if(!aa[stk[tp]])--tp;
                if(aa[i]==0)break;
            }
            if(!bb[j]){
                j=(j+1)%n;
            }
        }
        if(i==j)j=(j+1)%n;
    }
    for(int i=0;i<n;i++)s+=aa[i];
    return s;
}

signed main(){
    cin>>T;
    while(T--){
        cin>>n>>k;
        int s=0;
        for(int i=0;i<n;i++)cin>>a[i],s+=a[i];
        for(int i=0;i<n;i++)cin>>b[i];
        if(s<=k){
            printf("0\n");
            continue;
        }
        int L=1,R=n,ans=n;
        while(L<=R){
            int M=(L+R)/2;
            if(ck(M)<=k)ans=M,R=M-1;
            else L=M+1;
        }
        printf("%lld\n",ans);
    }
    return 0;
}


