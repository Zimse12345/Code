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

#define ll long long
#define ull unsigned long long

using namespace std;

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e2+7,M=160,Mod=998244353,INF=1e9+7;
int n,a[N],L[N],R[N],ans=INF;
int f[N][M*3];

signed main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read(),L[i]=read(),R[i]=read();
	for(int p=1;p<=n;p++){
		for(int j=0;j<M*2;j++)f[0][j]=INF;
		f[0][M]=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j<M*2;j++)f[i][j]=INF;
			for(int x=0;x<M*2;x++){
				for(int y=-M;y<M;y++){
					if(x-y<L[i-1]+M||x-y>R[i-1]+M)continue;
					if(y+a[i]+M<0||y+a[i]+M>M*2)continue;
					f[i][y+a[i]+M]=min(f[i][y+a[i]+M],f[i-1][x]+abs(y));
				}
			}
		}
		int w=INF;
		for(int i=L[n]+M;i<=R[n]+M;i++)w=min(w,f[n][i]);
		ans=min(ans,w);
//		printf("%d %d\n",p,w);
		int T=a[1],TL=L[1],TR=R[1];
		for(int i=1;i<n;i++)a[i]=a[i+1],L[i]=L[i+1],R[i]=R[i+1];
		a[n]=T,L[n]=TL,R[n]=TR;
	}
	printf("%d\n",ans);
	return 0;
}

