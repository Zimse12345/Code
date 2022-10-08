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
int n,nx[N],pr[N],ans[N];

int q(int a,int b,int x){
	printf("? ");
	for(int i=1;i<=n;i++){
		if(i==x)printf("%d ",b);
		else printf("%d ",a);
	}
	printf("\n");
	fflush(stdout);
	return read();
}

int main(){
	n=read();
	if(n==2){
		if(q(1,2,2)==1)printf("! 2 1\n");
		else printf("! 1 2\n");
		fflush(stdout);
		return 0;
	}
	for(int i=n;i>=1;i--){
		int x=q(1,2,i);
		if(x>0&&x<i)nx[i]=x,pr[x]=i;//printf("(%d->%d)",i,x);
		x=q(2,1,i);
		if(x>0&&x<i)nx[x]=i,pr[i]=x;//printf("(%d->%d)",x,i);
	}
	for(int i=1;i<=n;i++)if(pr[i]==0){
		int p=i,o=0;
		while(p!=0){
			ans[p]=++o;
			p=nx[p];
		}
		break;
	}
	printf("! ");
	for(int i=1;i<=n;i++)printf("%d ",ans[i]);
	printf("\n");
	fflush(stdout);
	return 0;
}
