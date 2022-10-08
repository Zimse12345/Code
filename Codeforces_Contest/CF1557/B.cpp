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
 
const int N=1e5+7,Mod=998244353,INF=1e9+7;
int T,n,k;
 
struct s{
	int v,w;
	s(int v=0,int w=0):v(v),w(w){}
	bool operator <(const s& A)const{return v<A.v;}
}a[N];
 
int main(){
	T=read();
	while(T--){
		n=read(),k=read();
		for(int i=1;i<=n;i++)a[i]=s(read(),i);
		sort(a+1,a+n+1);
		a[0].w=-1;int cnt=0;
		for(int i=1;i<=n;i++)if(a[i].w!=a[i-1].w+1)++cnt;
		if(cnt>k)printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}
