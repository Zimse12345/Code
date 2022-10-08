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
while(qrc<'0'||qrc>'9'){if(qrc=='-')qry=-1;qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=5500,Mod=998244353,INF=1e9+7;
int T,n,m,pre[N],suf[N],g[N][N];
char s[N],t[N];

signed main(){
	T=read();
	while(T--){
		n=read(),m=read();
		scanf("%s",s+1);
		scanf("%s",t+1);
		for(int i=1;i<=n;i++){
			pre[i]=pre[i-1];
			if(pre[i]<m&&s[i]==t[pre[i]+1])++pre[i];
		}
		suf[n+1]=0;
		for(int i=n;i>=1;i--){
			suf[i]=suf[i+1];
			if(suf[i]<m&&s[i]==t[m-suf[i]])++suf[i];
		}
		if(pre[n]!=m){
			printf("-1\n");
			continue;
		}
		int ans=INF;
		for(int i=1;i<=n;i++){
			for(int j=0;j<=pre[i];j++){
				g[i][j]=i;
				if(j){
					if(s[i]==t[j])g[i][j]=min(g[i][j],g[i-1][j-1]);
				}
			}
		}
		suf[n+1]=0;
		for(int i=0;i<=n;i++){
			for(int j=0;j<=pre[i];j++)if(suf[i+1]>=m-j){
				int pos=g[i][j],sum=n-i;
				if(pos)sum+=1+pos+i-j;
				ans=min(ans,sum);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

