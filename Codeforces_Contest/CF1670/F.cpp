#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <iostream>
#include <cstdlib>
#include <ctime>

#define int long long
#define ull unsigned long long

using namespace std;

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=4e3+7,Mod=1e9+7,INF=1e9+7;
int n,l,r,z,f[N][N],fac[N],_fac[N];
inline int qp(int x,int k){int res=1;while(k){if(k&1ll)res=(res*x)%Mod;x=(x*x)%Mod,k/=2;}return res;}
inline int inv(int x){return qp(x,Mod-2);}

int C(int x,int y){
	if(y>x)return 0;
	return fac[x]*_fac[y]%Mod*_fac[x-y]%Mod;
}

int sol(int x){
	if(x<z)return 0;
//	if(x==0)return z?0:1;
	int w=0;
	while((1ll<<(w+1))<=x)++w;
	for(int i=0;i<=w;i++)for(int j=0;j<=2*n;j++)f[i][j]=0;
	int Rm=1;//3 1 234 30
//	printf("( %d %d)",w,Rm);
	for(int i=Rm-((z&(1ll<<w))?1:0);i>=0;i-=2)f[w][i]=C(n,Rm-i);//printf("f[%d][%d]=%d\n",w,i,f[w][i]);
	for(int i=w-1;i>=0;i--){
		for(int j=0;j<=2*n;j++)if(f[i+1][j]){
			int rm=j*2+((x&(1ll<<i))?1:0);
			for(int k=((z&(1ll<<i))?1:0);k<=rm;k+=2){
				(f[i][min(rm-k,2*n)]+=f[i+1][j]*C(n,k))%=Mod;
//				printf("<%d %d %d> f[%d][%]+%d\n",k,j,rm,i,min(rm-k,2*n),f[i+1][j]*C(n,k));
			}
		}
	}
	int res=0;
 	for(int i=0;i<=2*n;i++)(res+=f[0][i])%=Mod;
	return res;
}

signed main(){
	n=read(),l=read(),r=read(),z=read();
	fac[0]=1;
	for(int i=1;i<N;i++)fac[i]=fac[i-1]*i%Mod;
	for(int i=0;i<N;i++)_fac[i]=inv(fac[i]);
	printf("%lld\n",((sol(r)-sol(l-1))%Mod+Mod)%Mod);
	return 0;
}

