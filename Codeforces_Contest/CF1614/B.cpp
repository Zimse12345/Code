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

using namespace std;

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=2e6+7,INF=1e9;
int T,n,ans[N];
struct b{
	int a,id;
	b(int a=0,int id=0):a(a),id(id){}
	bool operator < (const b& A)const{return a>A.a;} 
}s[N];

signed main(){
	T=read();
	while(T--){
		n=read();
		ll dis=0;
		for(int i=1,a;i<=n;i++)a=read(),s[i]=b(a,i);
		sort(s+1,s+n+1);
		for(int i=1;i<=n;i++){
			if(i&1)ans[s[i].id]=(i+1)/2;
			else ans[s[i].id]=-(i+1)/2;
			dis+=2ll*s[i].a*((i+1)/2);
		}
		printf("%lld\n",dis);
		for(int i=0;i<=n;i++)printf("%d ",ans[i]);
		printf("\n");
	}
	return 0;
}
