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

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=120,M=1200,Mod=998244353,INF=1e9+7;
int n,m,a[N],f[M][M][2],q[M],t;
char s[N][N];

int main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
	int p=0,Z=(1<<m)-1;
	for(int i=0;i<=Z;i++){
		for(int j=0;j<m;j++){
			if(i&(1<<j))a[j]=1;
			else a[j]=0;
		}
		int tag=1;
		for(int j=2;j<m;j++)if(a[j-2]+a[j-1]+a[j]>1){
			tag=0;
			break;
		}
		if(tag)q[++t]=i;
	}
	for(int i=1;i<=n;i++){
		p^=1;
		for(int j1=1;j1<=t;j1++)for(int j2=1;j2<=t;j2++)f[j1][j2][p]=0;
		for(int j1=1;j1<=t;j1++){
			int tag=1,tot=0;
			for(int k=0;k<m;k++)if(q[j1]&(1<<k)){
				if(s[i][k+1]=='H'){
					tag=0;
					break;
				}
				++tot;
			}
			if(tag==0)continue;
			for(int j2=1;j2<=t;j2++){
				if(q[j1]&q[j2])continue;
				for(int j3=1;j3<=t;j3++){
					if(q[j1]&q[j3])continue;
					if(q[j2]&q[j3])continue;
					f[j1][j2][p]=max(f[j1][j2][p],f[j2][j3][p^1]+tot);
				}
			}
		}
	}
	int ans=0;
	for(int j1=1;j1<=t;j1++)for(int j2=1;j2<=t;j2++)ans=max(ans,f[j1][j2][p]);
	printf("%d\n",ans);
	return 0;
}
