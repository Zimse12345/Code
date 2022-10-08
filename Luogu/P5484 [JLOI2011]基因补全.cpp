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

const int N=2e3+7,SZ=1e18,Mod=998244353,INF=1e9+7;
int n,m,f[N][200],g[N][200];
char s[N],t[N];
inline bool c(char a,char b){return (a=='A'&&b=='T')||(a=='C'&&b=='G')||(a=='T'&&b=='A')||(a=='G'&&b=='C');}

signed main(){
	n=read(),m=read();
	scanf("%s %s",s+1,t+1);
	for(int i=1;i<=n;i++){
		g[0][0]=g[0][1]=1;
		for(int j=1;j<=m;j++){
			g[j][0]=f[j][0];
			for(int k=1;k<=g[j][0];k++)g[j][k]=f[j][k];
		}
		for(int j=1;j<=m;j++){
			f[j][0]=g[j][0];
			for(int k=1;k<=f[j][0];k++)f[j][k]=g[j][k];
			
			if(c(s[i],t[j])){
				int s=0;
				for(int k=1;k<=max(f[j][0],g[j-1][0]);k++){
					if(k>f[j][0])++f[j][0];
					f[j][k]+=g[j-1][k]+s%SZ;
					s=s/SZ+f[j][k]/SZ;
					f[j][k]%=SZ;
				}
				while(s)f[j][++f[j][0]]=s%SZ,s/=SZ;
			}
		}
	}
	printf("%lld",f[m][f[m][0]]);
	for(int i=f[m][0]-1;i>=1;i--)printf("%018lld",f[m][i]);
	printf("\n");
	return 0;
}

