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

const int N=1e4+7,Mod=998244353,INF=1e9+7;
int n,k[2],s[2][N],f[N][2],cnt[N][2],vis[N][2];

void dp(int pos,int x){
	if(vis[pos][x]++)return;
	for(int i=1,from;i<=k[x^1];i++){
		from=(pos-s[x^1][i]+n)%n;
		if(!from)continue;
		if(f[pos][x]){
			cnt[from][x^1]++;
			if(cnt[from][x^1]==k[x^1])dp(from,x^1);
		}
		else f[from][x^1]=1,dp(from,x^1);
	}
	return;
}

signed main(){
	n=read();
	k[0]=read();for(int i=1;i<=k[0];i++)s[0][i]=read();
	k[1]=read();for(int i=1;i<=k[1];i++)s[1][i]=read();
	dp(0,0),dp(0,1),cnt[0][0]=k[0],cnt[0][1]=k[1];
	for(int i=1;i<n;i++){
		if(f[i][0]==1)printf("Win ");
		else if(cnt[i][0]==k[0])printf("Lose ");
		else printf("Loop ");
	}
	printf("\n");
	for(int i=1;i<n;i++){
		if(f[i][1]==1)printf("Win ");
		else if(cnt[i][1]==k[1])printf("Lose ");
		else printf("Loop ");
	}
	printf("\n");
	return 0;
}

