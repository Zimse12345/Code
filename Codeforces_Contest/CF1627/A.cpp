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

const int N=1e2+7,Mod=998244353,INF=1e9+7;
int T,n,m,r,c,ans;
char s[N][N];

signed main(){
	T=read();
	while(T--){
		n=read(),m=read(),r=read(),c=read(),ans=-1;
		for(int i=1;i<=n;i++){
			scanf("%s",s[i]+1);
			for(int j=1;j<=m;j++)if(s[i][j]=='B')ans=2;
		}
		for(int i=1;i<=m;i++)if(s[r][i]=='B')ans=1;
		for(int i=1;i<=n;i++)if(s[i][c]=='B')ans=1;
		if(s[r][c]=='B')ans=0;
		printf("%d\n",ans);
	}
	return 0;
}

