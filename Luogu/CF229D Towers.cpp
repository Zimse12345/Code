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
#define Lid (id<<1)
#define Rid ((id<<1)|1)
#define M ((L+R)>>1)

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=5e3+7,Mod=998244353,INF=1e9;
int n,a[N],sum[N],f[N][N],ans=INF,t[N][N];

signed main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read(),sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++){
		f[i][1]=i-1;
		for(int j=2;j<=i;j++){
			f[i][j]=INF;
			int L=1,R=j-1,p=0;
			while(L<=R){
				if(sum[i]-sum[j-1]>=sum[j-1]-sum[M-1])p=M,R=M-1;
				else L=M+1;
			}
			if(p)f[i][j]=t[j-1][p]+i-j;
		}
		t[i][i]=f[i][i];
		for(int j=i-1;j>=1;j--)t[i][j]=min(f[i][j],t[i][j+1]);
	}
	for(int i=1;i<=n;i++)ans=min(ans,f[n][i]);
	printf("%d\n",ans);
	return 0;
}

