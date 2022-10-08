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

const int N=1e2+7,Mod=998244353,INF=1e9+7;
int n,m;
char s[N];

int work(int x){
	int p=0;
	while((1<<p)<x)++p;
	return (p+1)*(1<<p);
}

int sol(int x){
	if(!x)return 0;
	if(x==1)return work(1);
	return sol(x/2)+sol(x-x/2)+work(x);
}

signed main(){
	n=read(),m=read();
	scanf("%s",s+1);
	for(int i=1,op,l,r;i<=m;i++){
		op=read(),l=read(),r=read();
		if(op==1){
			for(int j=l;j<=r;j++){
				if(s[j]=='0')s[j]='1';
				else s[j]='0';
			}
		}
		if(op==2){
			for(int j=l;j<=r;j++)s[j]='0';
		}
		if(op==3){
			for(int j=l;j<=r;j++)s[j]='1';
		}
		if(op==4){
			int x=0;
			for(int j=r;j>=l;j--)x=x*2+s[j]-'0';
			printf("%lld\n",sol(x));
		}
	}
	return 0;
}

