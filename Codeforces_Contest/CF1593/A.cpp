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

const int N=1e2+7,Mod=998244353,INF=1e9+7;
int T,a,b,c,m; 

int main(){
	T=read();
	while(T--){
		a=read(),b=read(),c=read();
		m=max(a,max(b,c));
		if(a<m)printf("%d ",m-a+1);
		else if(b==m||c==m)printf("%d ",1);
		else printf("0 ");
		if(b<m)printf("%d ",m-b+1);
		else if(a==m||c==m)printf("%d ",1);
		else printf("0 ");
		if(c<m)printf("%d",m-c+1);
		else if(a==m||b==m)printf("%d",1);
		else printf("0");
		printf("\n");
	}
	return 0;
}
