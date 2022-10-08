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

int read(){int qrx=0,qry=1;char qrc=' ';
while(qrc<'0'||qrc>'9'){qrc=getchar();if(qrc=='-'){qry=-1,qrc=getchar();break;}}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-'0',qrc=getchar();return qrx*qry;}

const int N=2e5+7,Mod=998244353,INF=1e9+7;
int n,a[N];

struct s{
	int x,y;
	s(int x=0,int y=0):x(x),y(y){};
	bool operator <(const s& A)const{return x<A.x;}
}p[N];

int check(int d){
	int maxyy=p[1].y;
	int minyy=p[1].y;
	int L=1;
	for(int i=1;i<=n;i++)if(p[i].x-p[1].x>=d){
		while(p[i].x-p[L].x>=d){
			maxyy=max(maxyy,p[L].y);
			minyy=min(minyy,p[L].y);
			++L;
		}
		if(abs(p[i].y-minyy)>=d||abs(p[i].y-maxyy)>=d)return 1;
	}
	return 0;
}

int main(){
	n=read();
	for(int i=1,x,y;i<=n;i++)x=read(),y=read(),p[i]=s(x,y);
	sort(p+1,p+n+1);
	int L=1,R=INF,ans=0;
	while(L<=R){
		int M=(L+R)>>1;
		if(check(M))ans=M,L=M+1;
		else R=M-1;
	}
	printf("%d\n",ans);
	return 0;
}

