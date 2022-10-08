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

const int N=1e2+7,M=2e4+7,Mod=998244353,INF=1e9+7;
int s,n,m,a[N][N],f[M][N],ans;

int main(){
	s=read(),n=read(),m=read();
	for(int i=1;i<=s;i++)for(int j=1;j<=n;j++)a[j][i]=read();
	for(int i=1;i<=n;i++){
		sort(a[i]+1,a[i]+s+1);
		int L=0;
		for(int j=0,tag;j<=m;j++){
			tag=0;
			while(L<s&&a[i][L+1]*2<j)++L,tag=1;
			if(j==0)tag=1;
			if(tag)for(int k=m;k>=j;k--)f[k][i]=max(f[k][i],f[k-j][i-1]+L*i);
		}
	}
	for(int i=0;i<=m;i++)ans=max(ans,f[i][n]);
	printf("%d\n",ans);
	return 0;
}
