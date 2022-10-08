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

const int N=1e5+7,Mod=998244353,INF=1e9+7;
int T,n,pre[N][400],f[N],tot,tot1,tot2;
inline int qp(int x,int k){int res=1;while(k){if(k&1ll)res=(res*x)%Mod;x=(x*x)%Mod,k/=2;}return res;}
inline int inv(int x){return qp(x,Mod-2);}

signed main(){
	n=1e5;
	for(signed i=1;i<=n;i++){
		int sum=0;
		signed s=signed(sqrt(i)),L=i;
		for(signed d=1;d<=s;d++){
			L=i/(d+1)+1,sum+=pre[i%L][d];
			if(sum>=Mod)sum-=Mod; 
		}
		for(signed d=1;d<L;d++){
			sum+=f[i%d];
			if(sum>=Mod)sum-=Mod;
		}
		f[i]=(sum*inv(i)+1)%Mod;
		for(signed j=1;j<=330;j++){
			if(i>=j){
				pre[i][j]=pre[i-j][j]+f[i];
				if(pre[i][j]>=Mod)pre[i][j]-=Mod;
			}
			else pre[i][j]=f[i];
		}
	}
	T=read();
	while(T--)printf("%lld\n",f[read()]);
	return 0;
}

