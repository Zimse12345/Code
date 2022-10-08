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

inline int read(){int qrx=0;char qrc=getchar();while(qrc<'0'||qrc>'9')qrc=getchar();
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx;}

const int N=2e3+7,Mod=998244353,INF=1e9+7;
int n,m,k,b[N];
ll ans,g[N][N];
int stk[N],top,RR[N];

signed main(){
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++){
		for(int j=1,nd,rm;j<=n;j++){
			nd=k%j?k/j+1:k/j,rm=i-nd+1;
			if(rm>0)g[i][j]=rm*(rm+1)/2;
			g[i][j]+=g[i][j-1];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)b[j]=read()?0:b[j]+1;
		top=0,stk[++top]=m+1;
		for(int j=m;j>=1;j--){
			while(top>0&&b[stk[top]]>b[j])--top;
			if(b[stk[top]]==b[j])RR[j]=RR[stk[top]],RR[stk[top--]]=0;
			else RR[j]=stk[top]-1;
			stk[++top]=j;
		}
		top=0,stk[++top]=0;
		for(int j=1;j<=m;j++){
			while(top>0&&b[j]<=b[stk[top]])--top;
			if(b[j]!=b[j-1]&&b[j]){
				int L=stk[top]+1,R=RR[j];
				if(R)ans+=g[R-L+1][b[j]]-g[R-L+1][max(b[L-1],b[R+1])];
			}
			stk[++top]=j;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
