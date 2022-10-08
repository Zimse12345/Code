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

const int N=1e2+7,Mod=998244353,INF=1e9+7;
int T,n,m,a[N][N];
char s[N][N];

signed main(){
	T=read();
	while(T--){
		n=read(),m=read();
		for(int i=1;i<=n;i++){
			scanf("%s",s[i]+1);
			for(int j=1;j<=m;j++)a[i][j]=s[i][j]-'0';
		}
		int tag=1;
		for(int i=1;i<n;i++){
			for(int j=1;j<m;j++){
				if(a[i][j]+a[i][j+1]+a[i+1][j]+a[i+1][j+1]==3)tag=0;
			}
		}
		if(tag)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}

