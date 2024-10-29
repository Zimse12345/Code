#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <list>
#include <math.h>
#include <functional> 

#define endl '\n'
#define pii pair<int, int>
#define pdd pair<double, double> 
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define codeforces cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false)
#define bendl(x) x.begin(), x.end()
#define siz(x) ((int)(x).size())
#define int long long
using namespace std;

const int Mod=1000000007,M=1024;
int tt,n,a[1000001],p[1000001],f[2][1000001];

int fpow(int x,int y=Mod-2){
    int z=1;
    while(y){
        if(y&1)z=x*z%Mod;
        x=x*x%Mod,y/=2;
    }
    return z;
}

signed main(){
    scanf("%lld",&tt);
    while(tt--){
        scanf("%lld",&n);
        for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
        int t=0;
        int inv10000=fpow(10000),mul=1;
        for(int i=0;i<M;i++)f[t][i]=0;
        f[t][0]=1;
        for(int i=1;i<=n;i++){
            scanf("%lld",&p[i]);
            p[i]=p[i]*inv10000%Mod;
            if(p[i]==1){
                for(int j=0;j<M;j++)f[t^1][j]=f[t][j^a[i]];
                t^=1;
                continue;
            }
            mul=mul*(1-p[i])%Mod;
            p[i]=p[i]*fpow(1-p[i])%Mod;
            for(int j=0;j<M;j++)f[t^1][j]=(f[t][j]+f[t][j^a[i]]*p[i])%Mod;
            t^=1;
        }
        int sum=0;
        for(int i=0;i<M;i++){
            sum=(sum+i*i*f[t][i]%Mod*mul)%Mod;
        }
        if(sum<0)sum+=Mod; 
        printf("%lld\n",sum);
    }
    return 0;
}


