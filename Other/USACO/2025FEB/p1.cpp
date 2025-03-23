#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int f[7][1000][2];
int n,m,a[N];
long long ans;

void ck(int x){
    int a0=0,a1=0,a2=0;
    int b0=0,b1=0,b2=0;
    for(int i=1;i<=n;i++){
        swap(a0,b0),swap(a1,b1),swap(a2,b2);
        if(a[i]>=x){
            a2+=a1,a1=a0,a0=0;
            b2+=b1,b1=b0+1,b0=0;
        }
        else{
            ++b0;
        }
        ans+=a2;
        ans+=b1+b2;
        for(int j=i-5;j<=i;j++)if(j>0){
            int v=0,cnt=0;
            for(int k=j;k<=i;k++){
                v*=2;
                if(a[k]>=x)v++,cnt++;
            }
            if(((i-j+1)%2==0&&cnt>=2)||((i-j+1)%2==1&&cnt>=1)){
                if(!f[i-j+1][v][0])--ans;
            }
            else{
                if(f[i-j+1][v][0])++ans;
            }
        }
    }
}

signed main(){
    f[1][1][0]=f[1][1][1]=1;
    for(int len=2;len<7;len++){
        for(int x=0;x<(1<<len);x++){
            for(int i=0;i+1<len;i++){
                int l=(x&(1<<i))?1:0,r=(x&(1<<(i+1)))?1:0;
                f[len][x][0]|=f[len-1][(x&((1<<i)-1))+((l&r)<<i)+((x>>(i+2))<<(i+1))][1];
                f[len][x][1]|=f[len-1][(x&((1<<i)-1))+((l|r)<<i)+((x>>(i+2))<<(i+1))][0];
            }
        }
    }
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i],m=max(a[i],m);
    for(int i=1;i<=m;i++)ck(i);
    printf("%lld\n",ans);
    return 0;
}


