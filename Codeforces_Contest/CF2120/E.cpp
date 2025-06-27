#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6;
int T,n,k,a[N],pre[N],_pre[N];
int sum,ave,pos,S;

inline int calc(int x){
    return x*(x+1)/2;
}

inline int ck(int x){
//    printf("---------------ck(%lld)\n",x);
    int res=0,L=1,R=n;
    a[n+1]=ave+1;
    for(int i=1;i<=n;i++){
        if(a[i+1]*i-pre[i]>=x){
            int _sum=x+pre[i],cnt=i;
            int _ave=_sum/cnt;
            res+=calc(_ave)*(cnt-_sum%cnt)+calc(_ave+1)*(_sum%cnt);
            L=i+1;
            break;
        }
    }
    for(int i=n;i>=1;i--){
        if(pre[n]-pre[i-1]-a[i-1]*(n-i+1)>=x){
            int _sum=-x+pre[n]-pre[i-1],cnt=n-i+1;
            int _ave=_sum/cnt;
            res+=calc(_ave)*(cnt-_sum%cnt)+calc(_ave+1)*(_sum%cnt);
            R=i-1;
            break;
        }
    }
//    printf("(%lld %lld   %lld   %lld)\n",L,R,res,res+_pre[R]-_pre[L-1]+x*k); 
    res+=_pre[R]-_pre[L-1];
    return res+x*k;
}

signed main(){
    cin>>T;
    while(T--){
        cin>>n>>k;
        sum=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            sum+=a[i];
        }
        sort(a+1,a+n+1);
        for(int i=1;i<=n;i++){
            pre[i]=pre[i-1]+a[i];
            _pre[i]=_pre[i-1]+calc(a[i]);
        }
        ave=sum/n,pos=n-sum%n+1,S=0;
        for(int i=1;i<=n;i++){
            int v=(i<pos?ave:ave+1);
            if(a[i]<v)S+=v-a[i];
            else S+=a[i]-v;
        }
        S/=2;
//        printf("%lld\n",ck(0));
        int L=1,R=S,res=0;
        while(L<=R){
            int M=(L+R)/2;
            if(ck(M)<ck(M-1))res=M,L=M+1;
            else R=M-1;
        }
        printf("%lld\n",ck(res));
    }
    return 0;
}


