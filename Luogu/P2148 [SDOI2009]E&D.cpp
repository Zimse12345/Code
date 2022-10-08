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
int T,n,a,b,s;

int f(int a,int b){
	if((a&1)&&(b&1))return 0;
	return 1+f((a+1)/2,(b+1)/2);
}

signed main(){
	T=read();
	while(T--){
		n=read(),s=0;
		for(int i=1;i<=n/2;i++){
			a=read(),b=read();
			s^=f(a,b);
		}
		if(s)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}

