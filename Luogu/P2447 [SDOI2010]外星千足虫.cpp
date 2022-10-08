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
#include <bitset>

#define ll long long
#define ull unsigned long long

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=2e3+7,Mod=998244353,INF=1e9+7;
int n,m,k;
bitset<N> f[N];
char s[N];

signed main(){
	n=read(),m=read();
	for(int i=1;i<=m;i++){
		scanf("%s",s+1);
		for(int j=1;j<=n;j++)f[i][j]=s[j]-'0';
		f[i][0]=read();
	}
	for(int i=1;i<=n;i++){
		int t=0;
		for(int j=i;j<=m;j++)if(f[j][i]){t=j;break;}
		if(!t){printf("Cannot Determine\n");return 0;}
		swap(f[i],f[t]),k=max(k,t);
		for(int j=1;j<=m;j++)if((i^j)&&f[j][i])f[j]^=f[i];
	}
	printf("%d\n",k);
	for(int i=1;i<=n;i++){
		if(f[i][0])printf("?y7M#\n");
		else printf("Earth\n");
	}
	return 0;
}

