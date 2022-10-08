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

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int n,x,a[N],f[512][2048],ans;

signed main(){
//	freopen("d.in","r",stdin);
//	freopen("d.out","w",stdout);
	n=read(),x=read();
	for(int i=1;i<=n;i++)a[i]=read();
	if(n>12){
		for(int i=0;i<=n;i++){
			for(int j=1;j<=x;j++)f[i][j]=-1;
			f[i][0]=x-i;
		}
		for(int i=n;i>=1;i--){
			for(int j=0;j<=x;j++)if(f[i][j]>0){
				f[i-1][j]=max(f[i-1][j],f[i][j]-j-1);
				f[i-1][j+a[i]]=max(f[i-1][j+a[i]],f[i][j]-j-1-a[i]);
			}
		}
		for(int i=0;i<=x;i++)if(f[0][i]>=0)ans=i;
		printf("%d\n",ans);
		return 0;
	}
	else{
		for(int i=0;i<(1<<n);i++){
			int c=0,p=0,w=0;
			for(int j=0;j<n;j++)if(i&(1<<j))p=j,w+=a[j+1];
			c=p+1;
			for(int j=p,e=1;j>=0;j--){
				if(i&(1<<j))e+=a[j+1];
				c+=e;
			}
			if(c<=x)ans=max(ans,w);
		}
		printf("%d\n",ans);
	}
	return 0;
}

