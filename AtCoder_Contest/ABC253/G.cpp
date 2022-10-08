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

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=4e5+7,Mod=998244353,INF=1e9+7;
int n,L,R,a[N],b[N];

signed main(){
	n=read(),L=read(),R=read()-L+1;
	for(int i=1;i<=n;i++)a[i]=i;
	int p=1;
	--L;
	while(L>=(n-p))L-=(n-p),++p;
//	printf("[%d %d %d]\n",p,L,R);
	if(L){
		for(int i=L+p+1;i<=n;i++){
			swap(a[i],a[p]),--R;//printf("(%d %d)\n",i,p);
			if(!R)break;
		}
		++p;
	}
	L=p;
	int tot=0;
	while((n-p)&&R>=(n-p))R-=(n-p),++p,++tot;
	for(int i=0;i<tot;i++)b[i+L]=a[n-i];
	for(int i=L+tot;i<=n;i++)b[i]=a[i-tot];
	for(int i=L;i<=n;i++)a[i]=b[i];
//	printf("(%d %d)\n",p,R);
	if(R)for(int i=p+1;;i++){
		swap(a[p],a[i]);
		--R;
		if(!R)break;
	}
	for(int i=1;i<=n;i++)printf("%lld ",a[i]);
	printf("\n");
	return 0;
}

