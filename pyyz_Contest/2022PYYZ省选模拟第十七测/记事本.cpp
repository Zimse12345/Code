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
#define M ((L+R)>>1)
#define Lid (id<<1)
#define Rid ((id<<1)|1)

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=4e5+7,Mod=998244353,INF=1e9+7;
int n,m,a[N],s[20][N],_2[N];

inline int q(int L,int R){
	if(R<L)swap(L,R);
	int len=R-L+1,t=_2[len];
	return min(s[t][R],s[t][L+(1<<t)-1]);
}

signed main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=s[0][i]=read();
	for(int i=2;i<=n;i++)_2[i]=_2[i>>1]+1;
	for(int i=1;i<=18;i++)for(int j=(1<<i);j<=n;j++)s[i][j]=min(s[i-1][j],s[i-1][j-(1<<(i-1))]);
	m=read();
	for(int i=1,r1,c1,r2,c2,ans;i<=m;i++){
		r1=read(),c1=read(),r2=read(),c2=read(),ans=INF;
		for(int j=1;j<=n;j++){
			int c=min(c1,q(r1,j));
			int C=q(j,r2);
			int d1=abs(r1-j)+abs(r2-j);
			ans=min(ans,min(d1+abs(min(c,C)-c2),d1+1+abs(min(a[j],C)-c2)));
		}
		ans=min(ans,abs(r1-r2)+c2+1);
		printf("%lld\n",ans);
	}
	return 0;
}

