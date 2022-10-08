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
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e2+7,Mod=998244353,INF=1e9+7;
int T,l,r;

int main(){
	T=read();
	while(T--){
		l=read(),r=read();
		int ans=r%l;
		int p=r/2;
		if(l<=p&&p<=r)ans=max(ans,r%p);
		p++;
		if(l<=p&&p<=r)ans=max(ans,r%p);
		printf("%d\n",ans);
	}
	return 0;
}

