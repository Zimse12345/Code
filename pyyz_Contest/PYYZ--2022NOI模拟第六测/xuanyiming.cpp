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
while(qrc<'0'||qrc>'9'){if(qrc=='-')qry=-1;qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=5e4+7,Mod=998244353,INF=1e9+7;
const int Mx=1000;
int T,f[N][32],vis[N],g[N],fac[N],_fac[N],tc[N];
int a[N]; //����ͨ������
int b[N]; //�������� 
int c[N]; //ͼ������
//��ͨ������ c-a
//������ͨ c-a-b


inline int fpow(int x,int k){
	int res=1;
	while(k){
		if(k&1ll)res=(res*x)%Mod;
		x=(x*x)%Mod,k/=2; 
	}
	return res;
}

inline int inv(int x){
	return fpow(x,Mod-2);
}

inline int C(int x,int y){
	return fac[x]*_fac[y]%Mod*_fac[x-y]%Mod; 
}

void sol(int n){
	if(vis[n]++)return;
	for(int x=1,y=0;x<=n;x++){
		y=n-x;
		sol(y);
		if(y)(a[n]+=(c[x]-a[x])*C(n-1,x-1)%Mod*(c[y])%Mod)%=Mod;
		for(int k=1;k<=20;k++){
			//g[x] * f[y]
			for(int i=0;i<=k;i++){
//				if(i==0){
//					(f[n][k]+=C(k,i)*tc[y]*g[x]*C(n-1,x-1))%=Mod;
//					continue;
//				}
//				if(n==4&&k==2)printf("n=%lld x=%lld k=%lld i=%lld %lld*%lld*%lld*%lld\n",n,x,k,i,C(k,i),f[y][i],g[x],C(n-1,x-1));
				(f[n][k]+=C(k,i)*f[y][i]%Mod*g[x]%Mod*C(n-1,x-1)%Mod)%=Mod;
			}
			(f[n][k]+=f[y][k]*(c[x]-a[x]-b[x])%Mod*C(n-1,x-1)%Mod)%=Mod;
//			if(n==4&&x==3)printf("%lld*(%lld-%lld)*%lld\n",f[y][k],tc[x],f[x][0],C(n-1,x-1));
		}
	}
//	for(int i=0;i<=4;i++)printf("f[%lld][%lld] = %lld\n",n,i,f[n][i]);
	return;
}

signed main(){
	vis[0]=1;
	b[1]=g[1]=1;
	for(int i=0;i<=Mx;i++)c[i]=f[i][0]=fpow(2,i*(i-1)/2);
	for(int i=2;i<=Mx;i++)b[i]=g[i]=fpow(i,i-2);
	fac[0]=1;
	for(int i=1;i<=Mx;i++)fac[i]=(fac[i-1]*i)%Mod;
	for(int i=0;i<=Mx;i++)_fac[i]=inv(fac[i]);
//	
	sol(Mx);
//	for(int i=1;i<=Mx;i++)printf("%lld %lld %lld %lld <\n",i,c[i],a[i],b[i]);
//	return 0;
	T=read();
	while(T--){
		int n=read(),k=read();
		printf("%lld\n",(f[n][k]+Mod)%Mod);
	}
//	int n=read();
//	printf("%lld\n",(c[n]-a[n]+Mod)%Mod);
//	printf("%lld\n",(a[read()]+Mod)%Mod);
	return 0;
}

