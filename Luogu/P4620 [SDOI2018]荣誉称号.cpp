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

const int N=1e7+7,Mod=998244353;
const ll INF=1e16;

int T,n,k,m,a[N],b[N],s[N],tg[N];
ll f[4096][256],g[4096][256],cnt[4096][256];
unsigned int SA, SB, SC;
int p, A, B;

unsigned int rng61(){
	SA ^= SA << 16;
	SA ^= SA >> 5;
	SA ^= SA << 1;
	unsigned int t = SA;
	SA = SB;
	SB = SC;
	SC ^= t ^ SA;
	return SC;
}

void gen(){
	scanf("%d%d%d%d%u%u%u%d%d", &n, &k, &m, &p, &SA, &SB, &SC, &A, &B);
	for(int i = 1; i <= p; i++)scanf("%d%d", &a[i], &b[i]);
	for(int i = p + 1; i <= n; i++){
		a[i] = rng61() % A + 1;
		b[i] = rng61() % B + 1;
	}
	return;
}

void build(int x){
	if(x>n)return;
	build(x*2),build(x*2+1);
	cnt[s[x]][a[x]%m]+=b[x];
	return;
}

void dp(int x,int d){
	if(s[x]!=x||x>n){
		g[x][0]=0;
		return;
	}
	if(d==k)tg[x]=1;
	dp(x*2,d+1),dp(x*2+1,d+1);
	tg[x]|=tg[x*2]|tg[x*2+1];
	if(!tg[x]){
		for(int i=0;i<m;i++)g[x][i]=0;
		return;
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++){
			g[x][(i+j)%m]=min(g[x][(i+j)%m],g[x*2][j]+g[x*2+1][j]+f[x][i]);
		}
	}
	return;
}

signed main(){
	T=read();
	while(T--){
		for(int i=0;i<4096;i++){
			for(int j=0;j<256;j++)f[i][j]=cnt[i][j]=0,g[i][j]=INF;
			tg[i]=0;
		}
		gen(),++k;
		for(int i=1;i<=n;i++){
			if(i>>k)s[i]=s[i>>k];
			else s[i]=i;
		}
		build(1);
		for(int i=1;i<=n;i++)if(s[i]==i){
			for(int x=0;x<m;x++){
				for(int y=0;y<m;y++)f[i][(x+y)%m]+=cnt[i][x]*y;
			}
		}
		dp(1,1);
		printf("%lld\n",g[1][0]);
	}
	return 0;
}

