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

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int n,m;
struct node{
	int x,y;
	node(int x=0,int y=0):x(x),y(y){}
	bool operator < (const node& A)const{return x<A.x;}
}a[N],b[N];
multiset<int> s;

signed main(){
	m=read(),n=read();
	for(int i=1;i<=m;i++)b[i].x=read();
	for(int i=1;i<=m;i++)b[i].y=read();
	for(int i=1;i<=n;i++)a[i].x=read();
	for(int i=1;i<=n;i++)a[i].y=read();
	sort(a+1,a+n+1);
	sort(b+1,b+m+1);
	s.insert(INF);
	for(int i=m,j=n;i>=1;i--){
		while(j>0&&a[j].x>=b[i].x)s.insert(a[j].y),--j;
		multiset<int>::iterator it=s.lower_bound(b[i].y);
		if((*it)==INF){
			printf("No\n");
			return 0;
		}
		s.erase(it);
	}
	printf("Yes\n");
	return 0;
}

