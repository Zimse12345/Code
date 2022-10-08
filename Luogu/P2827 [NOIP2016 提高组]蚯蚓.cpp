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

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e5+7,Mod=998244353,INF=1e12+7;
int n,m,q,u,v,t;
priority_queue<int> a;
queue<int> b,c;

signed main(){
	n=read(),m=read(),q=read(),u=read(),v=read(),t=read();
	for(int i=1;i<=n;i++)a.push(read());
	for(int i=1,p1,p2,A,B,C;i<=m;i++){
		A=a.size()>0?a.top():-INF,B=b.size()>0?b.front():-INF,C=c.size()>0?c.front():-INF;
		A+=(i-1)*q,B+=(i-1)*q,C+=(i-1)*q;
		if(A>=B&&A>=C)p1=A*u/v,p2=A-p1,a.pop();
		else if(B>=A&&B>=C)p1=B*u/v,p2=B-p1,b.pop();
		else p1=C*u/v,p2=C-p1,c.pop();
		if(p1<p2)swap(p1,p2);
		b.push(p1-i*q),c.push(p2-i*q);
		if(i%t==0)printf("%lld ",p1+p2);
	}
	printf("\n");
	for(int i=1,A,B,C,p;i<=m+n;i++){
		A=a.size()>0?a.top():-INF,B=b.size()>0?b.front():-INF,C=c.size()>0?c.front():-INF;
		A+=m*q,B+=m*q,C+=m*q;
		if(A>=B&&A>=C)a.pop(),p=A;
		else if(B>=A&&B>=C)b.pop(),p=B;
		else c.pop(),p=C;
		if(i%t==0)printf("%lld ",p);
	}
	printf("\n");
	return 0;
}
