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

const int N=1e3+7,Mod=998244353,INF=1e9+7;
int n,ans;
struct cow{
	int l,r;
	cow(int l=0,int r=0):l(l),r(r){};
	bool operator < (const cow& A)const{return r<A.r;}
}a[N];

int main(){
	n=read();
	for(int i=1,l,r;i<=n;i++)l=read(),r=read(),a[i]=cow(l,r);
	sort(a+1,a+n+1);
	int p1=0,p2=0;
	for(int i=1;i<=n;i++){
		if(p1>p2)swap(p1,p2);
		if(a[i].l>=p2)p2=a[i].r,++ans;
		else if(a[i].l>=p1)p1=a[i].r,++ans;
	}
	printf("%d\n",ans);
	return 0;
}
