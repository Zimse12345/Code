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
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();break;}qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=300+7,Mod=998244353,INF=1e9+7;
int T,n,m,a[N];
int t[N];

struct p{
	int v,num;
	p(int v=0,int num=0):v(v),num(num){};
	bool operator <(const p& A)const{if(v==A.v)return num>A.num;return v<A.v;}
}s[N];

signed main(){
	T=read();
	while(T--){
		int ans=0;
		n=read(),n=read();
		for(int i=1;i<=n;i++)t[i]=0,a[i]=read(),s[i]=p(a[i],i);
		sort(s+1,s+n+1);
		for(int i=1;i<=n;i++){
			int x=0;
			for(int j=1;j<=n;j++)if(s[j].num==i){
				x=j;
				break;
			}
			for(int j=1;j<x;j++)ans+=t[j];
			++t[x];
		}
		printf("%d\n",ans);
	}
	return 0;
}
