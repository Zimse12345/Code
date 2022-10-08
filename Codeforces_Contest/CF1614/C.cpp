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

using namespace std;

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=2e5+7,INF=1e9,Mod=1e9+7;
int T,n,m,a[N][32],s[N],p2[N];

signed main(){
	T=read();
	p2[0]=1;
	for(int i=1;i<N;i++)p2[i]=(p2[i-1]*2ll)%Mod;
	while(T--){
		n=read(),m=read();
		for(int i=1;i<=n;i++){
			for(int j=0;j<=30;j++)a[i][j]=0;
			s[i]=0;
		}
		while(m--){
			int l=read(),r=read(),x=read();
			for(int i=0;i<=30;i++)if(!(x&(1<<i)))a[l][i]++,a[r+1][i]--;
		}
		for(int i=1;i<=n;i++){
			for(int j=0;j<=30;j++){
				a[i][j]+=a[i-1][j];
				if(a[i][j]==0)s[i]|=(1<<j);
			}
		}
		int ans=0;
		for(int i=0;i<=30;i++){
			int tot=0;
			for(int j=1;j<=n;j++)if(s[j]&(1<<i))++tot;
			if(tot)ans=(ans+(1<<i)*p2[tot-1]%Mod*p2[n-tot]%Mod)%Mod;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
