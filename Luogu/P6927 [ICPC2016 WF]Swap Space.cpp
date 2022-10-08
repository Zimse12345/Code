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

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int n,ans;
struct node{
	int x,y;
	node(int x=0,int y=0):x(x),y(y){}
}a[N];

bool cmp(const node& A,const node& B){
	if(A.y>=A.x){
		if(B.y<B.x)return true;
		return A.x<B.x;
	}
	if(B.y>=B.x)return false;
	return A.y>B.y;
}

signed main(){
	n=read();
	for(int i=1,x,y;i<=n;i++)x=read(),y=read(),a[i]=node(x,y);
	sort(a+1,a+n+1,cmp);
	for(int i=1,s=0;i<=n;i++)ans=max(ans,a[i].x-s),s+=a[i].y-a[i].x;
	printf("%lld\n",ans);
	return 0;
}

