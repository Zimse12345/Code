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

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int T,x,d,st[N],top;

signed main(){
	T=read();
	while(T--){
		x=read(),d=read();
		int tag=0,c=0;
		while(x%d==0)x/=d,++c;
		for(int i=2;i*i<=x;i++)if(x%i==0){tag=1;break;}
		if(c<=1)printf("NO\n");
		else if(c==2){
			if(tag)printf("YES\n");
			else printf("NO\n");
		}
		else{
			if(tag)printf("YES\n");
			else if(c==3){
				for(int i=2;i*i<=d;i++)if(d%i==0&&(x%i!=0||x%(d/i)!=0)){tag=1;break;}
				if(tag)printf("YES\n");
				else printf("NO\n");
			}
			else{
				for(int i=2;i*i<=d;i++)if(d%i==0){tag=1;break;}
				if(tag)printf("YES\n");
				else printf("NO\n");
			}
		}
	}
	return 0;
}

