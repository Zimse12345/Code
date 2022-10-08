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
int n,a[N],b[N],pos[N],t,ans=1,A[N],B[N],m;

signed main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)b[i]=read();
	for(int i=1;i<(1<<n);i++){
		t=0;
		for(int j=0;j<n;j++)if(i&(1<<j))pos[++t]=j+1;
		int tag=1;
		for(int j=1;j<t;j++){
			m=0;
			for(int k=pos[j]+1;k<=pos[j+1];k++)A[++m]=a[k],B[m]=b[k];
			sort(A+1,A+m+1);
			sort(B+1,B+m+1);
			for(int k=1;k<=m;k++)if(A[k]!=B[k]){tag=0;break;}
			if(!tag)break;
		}
		if(!tag)continue;
		m=0;
		for(int j=pos[t]+1;j<=n;j++)A[++m]=a[j],B[m]=b[j];
		for(int j=1;j<=pos[1];j++)A[++m]=a[j],B[m]=b[j];
		sort(A+1,A+m+1);
		sort(B+1,B+m+1);
		for(int j=1;j<=m;j++)if(A[j]!=B[j]){tag=0;break;}
		ans+=tag;
	}
	printf("%d\n",ans);
	return 0;
}

