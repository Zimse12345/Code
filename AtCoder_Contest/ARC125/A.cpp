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
int n,m,a[N],t[N];

int main(){
	n=read(),m=read();
	int y10=0,y11=0,y20=0,y21=0;
	for(int i=1;i<=n;i++){
		a[i]=read();
		if(a[i])y11=1;
		else y10=1;
	}
	for(int i=1;i<=m;i++){
		t[i]=read();
		if(t[i])y21=1;
		else y20=1;
	}
	
	if((y20&&(!y10))||(y21&&(!y11)))return !printf("-1\n");
	if(y20^y21){
		if(a[1]==t[1])return !printf("%d\n",m);
		int p=INF;
		for(int i=1;i<=n;i++)if(a[i]==t[1]){
			p=min(p,i-1);
			break;
		}
		for(int i=n;i>=1;i--)if(a[i]==t[1]){
			p=min(p,n-i+1);
			break;
		}
		return !printf("%d\n",m+p);
	}
	
	int u=a[1],p=INF,ans=0;
	for(int i=1;i<=n;i++)if(a[i]!=u){
		p=min(p,i-1);
		break;
	}
	for(int i=n;i>=1;i--)if(a[i]!=u){
		p=min(p,n-i+1);
		break;
	}
	
	ans=p+m,t[0]=u;
	for(int i=1;i<=m;i++)if(t[i]!=t[i-1])++ans;
	printf("%d\n",ans-1);
	
	return 0;
}
