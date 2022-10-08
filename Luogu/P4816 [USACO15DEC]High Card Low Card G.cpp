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

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int n,a[N],t[N],b[N],tot,ans;

int main(){
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read(),t[a[i]]=1;
		if(i>n/2)a[i]=-a[i];
	}
	sort(a+1,a+n/2+1);
	sort(a+n/2+1,a+n+1);
	for(int i=n/2+1;i<=n;i++)a[i]=-a[i];
	
	for(int i=1;i<=n*2;i++)if(!t[i])b[++tot]=i;
	int p=n/2+1;
	for(int i=1;i<=n/2;i++){
		while(p<=n&&b[p]<a[i])++p;
		if(p<=n&&b[p]>a[i])++ans,++p;
		else break;
	}
	p=n/2;
	for(int i=n/2+1;i<=n;i++){
		while(p>0&&b[p]>a[i])--p;
		if(p>0&&b[p]<a[i])++ans,--p;
		else break;
	}
	printf("%d\n",ans);
	return 0;
}
