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
int T,n,a[N];

signed main(){
	T=read();
	while(T--){
		n=read();
		int mx0=0,mx1=0,tag=1;
		for(int i=1;i<=n;i++){
			a[i]=read();
			if(a[i]&1){
				if(mx1>a[i])tag=0;
				mx1=max(mx1,a[i]);
			}
			else{
				if(mx0>a[i])tag=0;
				mx0=max(mx0,a[i]);
			}
		}
		if(!tag)printf("No\n");
		else printf("Yes\n");
	}
	return 0;
}

