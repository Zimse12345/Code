// Author:Zimse  Data:2023-06-
#include <bits/stdc++.h>
#define pc putchar
#define pb push_back
#define inv fpow
#define int long long
//#define M ((L+R)/2)
namespace OI{const int INF=1.001e9,Mod=998244353;int read(){int x=0
,y=1;char c=getchar();while(c<48||57<c){if(c==45)y=-1;c=getchar();}
while(47<c&&c<58)x=x*10+c-48,c=getchar();return x*y;}void wr(int x)
{if(x<0)pc(45),x=-x;if(x>=10)wr(x/10);pc(48+x%10);}void wri(int x){
wr(x),pc(32);}void _wri(int x){wr(x),pc(10);}void iF(const char*x){
freopen(x,"r",stdin);}void oF(const char*x){freopen(x,"w",stdout);}
inline int fpow(long long x,int y=Mod-2){int z=1;while(y){if(y&1)z=
x*z%Mod;x=x*x%Mod,y/=2;}return z;}inline void _max(int&x,int y){if(
x<y)x=y;}inline void _min(int&x,int y){if(y<x)x=y;}inline void _mod
(int&x,int y){(x+=y)%=Mod;}}using namespace OI;using namespace std;

const int N=5.01e7;
int T,n,tot,ans;
signed prime[N/5],pr[N],mu[N],sum_mu[N];
unordered_map<int,int> Mu;

int calc_mu(int x){
	if(x<N)return sum_mu[x];
	if(Mu.count(x))return Mu[x];
	int res=1,l=2,r;
	while(1){
		r=x/(x/l);
		res-=(r-l+1)*calc_mu(x/l);
		l=r+1;
		if(l>x)break;
	}
	res%=Mod;
	Mu[x]=res;
	return res;
}

signed main(){
    iF("math.in");
    oF("math.out");
    
    mu[1]=1;
    for(int i=2;i<N;i++){
        if(!pr[i])pr[i]=i,prime[++tot]=i,mu[i]=-1;
        for(int j=1;j<=tot&&prime[j]*i<N;j++){
            pr[prime[j]*i]=prime[j],mu[prime[j]*i]=-mu[i];
            if(pr[i]==prime[j]){
                mu[prime[j]*i]=0;
                break;
            }
        }
    }
    for(int i=1;i<N;i++)sum_mu[i]=sum_mu[i-1]+mu[i];
    T=read();
    while(T--){
        n=read(),ans=0;
        int l=2,r=0;
        for(int i=2;i*i*i<=n;i++)_mod(ans,-mu[i]*(n/i/i%Mod)*(n/i/i%Mod)),l=max(l,i*i+1);
        while(l<=n){
            r=n/(n/l);
            int L=ceil(sqrt(l)),R=floor(sqrt(r));
            int d=(n/L/L)%Mod;
            _mod(ans,-(calc_mu(R)-calc_mu(L-1))*d%Mod*d);
            l=r+1;
        }
        _mod(ans,Mod);
        _wri(ans);
    }
    return 0;
}



