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

const int N=5e3+7,Mod=1e8,INF=1e9+7;
int n,m,f[2][N],c[2][N],p;
char s[N],t[N];

int main(){
	scanf("%s %s",s+1,t+1);
	n=strlen(s+1)-1,m=strlen(t+1)-1;
	
	for(int i=0;i<=m;i++)c[p][i]=1;
	c[1][0]=1;
	for(int i=1;i<=n;i++){
		p^=1;
		for(int j=1;j<=m;j++){
			c[p][j]=0;
			if(s[i]==t[j])f[p][j]=f[p^1][j-1]+1,c[p][j]+=c[p^1][j-1];
			else f[p][j]=max(f[p^1][j],f[p][j-1]);
			if(f[p][j]==f[p^1][j])c[p][j]+=c[p^1][j];
			if(f[p][j]==f[p][j-1])c[p][j]+=c[p][j-1];
			if(f[p][j]==f[p^1][j-1])c[p][j]-=c[p^1][j-1];
			c[p][j]%=Mod;
		}
	}
	printf("%d\n%d\n",f[p][m],c[p][m]);
	
	return 0;
}

