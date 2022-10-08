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
int a,b,c,d,e,f;

signed main(){
	a=read(),b=read(),c=read(),d=read(),e=read(),f=read();
	if(a==c)printf("%d ",e);
	if(a==e)printf("%d ",c);
	if(e==c)printf("%d ",a);
	if(b==d)printf("%d ",f);
	if(b==f)printf("%d ",d);
	if(d==f)printf("%d ",b);
	printf("\n");
	return 0;
}

