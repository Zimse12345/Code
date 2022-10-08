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
#define M ((L+R)>>1)

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int n,m,a[N],b[N],s[N*2],mx[22][N],mn[22][N],_2[N];

inline int Max(int L,int R){
	if(L>R)return 0;
	int t=_2[R-L+1];
	return max(mx[t][R],mx[t][L+(1<<t)-1]);
}

inline int Min(int L,int R){
	if(L>R)return INF;
	int t=_2[R-L+1];
	return min(mn[t][R],mn[t][L+(1<<t)-1]);
}

bool check(int x){
	for(int i=1,p1=0,p2=1;i<=n*2;i++){
		int _l=s[i],_r=s[i]+x,f=0,bl=INF,br=0;
		while(p1<n&&a[p1+1]<_l)++p1;
		while(p2<=n&&a[p2]<=_r)++p2;
		bl=min(bl,Min(1,p1)),br=max(br,Max(1,p1)),f+=p1;
		bl=min(bl,Min(p2,n)),br=max(br,Max(p2,n)),f+=n-p2+1;
		if(bl>=_l&&br<=_r&&f<=m)return true;
	}
	return false;
}

signed main(){
	n=read(),m=read();
	for(int i=2;i<N;i++)_2[i]=_2[i>>1]+1;
	for(int i=1;i<=n;i++)s[i]=a[i]=read();
	for(int i=1;i<=n;i++)s[i+n]=b[i]=mx[0][i]=mn[0][i]=read();
	for(int i=1;i<=21;i++)for(int j=(1<<i);j<=n;j++){
		mx[i][j]=max(mx[i-1][j],mx[i-1][j-(1<<(i-1))]);
		mn[i][j]=min(mn[i-1][j],mn[i-1][j-(1<<(i-1))]);
	}
	sort(s+1,s+n*2+1);
	int L=0,R=1e9,ans=0;
	while(L<=R){
		if(check(M))ans=M,R=M-1;
		else L=M+1;
	}
	printf("%d\n",ans);
	return 0;
}

