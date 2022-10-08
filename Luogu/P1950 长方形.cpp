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

const int N=1e3+7,Mod=998244353,INF=1e9+7;
int n,m,a[N],q[N],p[N],t,ans;
char s[N][N];

signed main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[i][j]=='.')++a[j];
			else a[j]=0;
		}
		t=0;
		for(int j=1;j<=m;j++){
			if(a[j]==0){
				t=0;
				continue;
			}
			int pr=j;
			while(t>0&&a[j]<a[q[t]])pr=p[t],--t;
			if(t==0||a[q[t]]!=a[j])q[++t]=j,p[t]=pr;//printf("[%d %d %d %d]\n",t,j,a[j],p[t]);
			for(int k=1;k<=t;k++){
				ans+=(j-p[k]+1)*(a[q[k]]-a[q[k-1]]);
				//printf("(%d %d %d %d | %d %d)\n",i,j,k,(j-p[k]+1)*(a[q[k]]-a[q[k-1]]),q[k],p[k]);
			}
		}
		//printf("[%d %d]\n",i,ans);
	}
	printf("%lld\n",ans);
	return 0;
}
