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

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e3+7,Mod=1e9+7,INF=1e9+7;
int n=1,k,w,p[N],a[N],f[N][N],ans;

inline int qp(int x,int k){int res=1;while(k){if(k&1ll)res=(res*x)%Mod;x=(x*x)%Mod,k/=2;}return res;}
inline int inv(int x){return qp(x,Mod-2);}

signed main(){
	k=read(),w=read();
	for(int i=1;i<=w;i++)p[i]=read(),a[i]=read(),n=(n*qp(p[i],a[i]))%Mod;
	for(int x=0,sum=0;x<=k+1;x++){
		sum=(sum+qp(x,k));
		for(int i=0;i<=k+1;i++)f[x][i]=qp(x,i);
		f[x][k+2]=sum;
	}
	for(int i=0;i<=k+1;i++){
		int t=i;
		for(int j=i;j<=k+1;j++)if(f[j][i]!=0){t=j;break;}
		for(int j=0;j<=k+2;j++)swap(f[i][j],f[t][j]);
		for(int j=0;j<=k+1;j++)if(j!=i&&f[j][i]!=0){
			int p=f[j][i]*inv(f[i][i])%Mod;
			for(int I=0;I<=k+2;I++)f[j][I]=(f[j][I]-f[i][I]*p)%Mod;
		}
		for(int j=0;j<=k+2;j++)if(j!=i)f[i][j]=f[i][j]*inv(f[i][i])%Mod;
		f[i][i]=1;
	}
	for(int i=0,x,y;i<=k+1;i++){
		x=1,y=k-i;
		if(y<0)y=Mod-2;
		for(int j=1;j<=w;j++)x=(x*(1-qp(p[j],y)))%Mod;
		ans=(ans+x*f[i][k+2]%Mod*qp(n,i))%Mod;
	}
	ans=(ans+Mod)%Mod;
	printf("%lld\n",ans);
	return 0;
}

