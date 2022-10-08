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

const int N=2e5+7,Mod=998244353,INF=1e9+7;
int n,a[N],p1,p2,c1,c2,ans;

signed main(){
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		if(i!=1&&a[i]<a[i-1]){
			if(!p1)p1=i;
			++c1;
		}
		if(i!=1&&a[i]>a[i-1]){
			if(!p2)p2=i;
			++c2;
		}
	}
	if(c1==0){
		printf("0\n");
		return 0;
	}
	if(c2==0){
		printf("1\n");
		return 0;
	}
	if(c1==1)ans=min(p1-1,n-p1+3);
	else ans=min(p2,n-p2+2);
	printf("%d\n",ans);
	return 0;
}

