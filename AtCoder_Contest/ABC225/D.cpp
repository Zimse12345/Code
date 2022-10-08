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

const int N=1e5+7,Mod=998244353,INF=1e9+7;
int n,q,nx[N],pr[N],ans[N],t;

int main(){
	n=read(),q=read();
	for(int i=1,op,x,y,p;i<=q;i++){
		op=read();
		if(op==1){
			x=read(),y=read();
			nx[x]=y,pr[y]=x;
		}
		if(op==2){
			x=read(),y=read();
			nx[x]=pr[y]=0;
		}
		if(op==3){
			p=read(),t=0;
			while(pr[p])p=pr[p];
			while(p)ans[++t]=p,p=nx[p];
			printf("%d ",t);
			for(int i=1;i<=t;i++)printf("%d ",ans[i]);
			printf("\n");
		}
	}
	return 0;
}
