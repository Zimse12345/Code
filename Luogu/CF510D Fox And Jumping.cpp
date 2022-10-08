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

const int N=2e3+7,Mod=998244353,INF=1e9+7;
int n,v[N],c[N],p[N][N],tot[N],f[N][N],ans=INF;

signed main(){
	n=read();
	for(int i=1,x;i<=n;i++){
		x=v[i]=read();
		for(int j=2;j*j<=v[i];j++)if(x%j==0){
			p[i][++tot[i]]=j;
			while(x%j==0)x/=j;
		}
		if(x>1)p[i][++tot[i]]=x;
		for(int j=0;j<(1<<tot[i]);j++)f[i][j]=INF;
	}
	for(int i=1;i<=n;i++)c[i]=read(),f[i][(1<<tot[i])-1]=c[i];;
	for(int i=1;i<=n;i++){
		for(int j=(1<<tot[i])-1;j>0;j--){
			for(int k=1;k<=n;k++){
				int t=j;
				for(int w=1;w<=tot[i];w++)if(t&(1<<(w-1))){
					if(v[k]%p[i][w]>0)t^=(1<<(w-1));
				}
				f[i][t]=min(f[i][t],f[i][j]+c[k]);
			}
		}
		ans=min(ans,f[i][0]);
	}
	if(ans==INF)ans=-1;
	printf("%d\n",ans);
	return 0;
}

