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

const int N=512,Mod=998244353,INF=1e9+7;
int n,L,R,a[N],s[N],t,b[N],ct[N],pos[N];
int num[N],m,ans,C[N][N],fac[N];

void dfs(int x,int v){
	if(R<v)return;
	if(v+(m-x)*n<L)return;
	if(L<=v&&v+(m-x)*n<=R){
		ans+=fac[m-x];
		return;
	}
	if(x<m){
		for(int i=m,cc=0;i>=1;i--){
			if(num[i]){
				s[++t]=num[i],num[i]=0;
				dfs(x+1,v+C[x+1][i]+cc);
				num[i]=s[t--];
			}
			else ++cc;
		}
	}
	return;
}

signed main(){
	fac[0]=1;
	for(int i=1;i<N;i++)fac[i]=(fac[i-1]*i)%Mod;
	n=read(),L=read(),R=read();
	for(int i=1;i<=n;i++){
		a[i]=read(),ct[a[i]]=1;
		if(!a[i])pos[++m]=i;
	}
	for(int i=1;i<=n;i++)if(a[i]){
		for(int j=1;j<i;j++)if(a[j]){
			if(a[j]>a[i])--L,--R;
		}
	}
	m=0;
	for(int i=1;i<=n;i++)if(!ct[i])num[++m]=i;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			for(int k=1;k<pos[i];k++)if(a[k]>num[j])++C[i][j];
			for(int k=pos[i]+1;k<=n;k++)if(a[k]&&a[k]<num[j])++C[i][j];
		}
	}
	dfs(0,0);
	printf("%d\n",ans);
	return 0;
}

