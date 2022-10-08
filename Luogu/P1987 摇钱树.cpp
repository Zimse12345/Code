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

const int N=1e3+7,Mod=998244353,INF=1e9+7;
int n,t,f[N],ans;
struct tree{
	int a,b;
	tree(int a=0,int b=0):a(a),b(b){}
	bool operator < (const tree& A)const{return b>A.b;}
}s[N];

int main(){
	while(1){
		n=read(),t=read(),ans=0;
		if(n==0&&t==0)break;
		for(int i=1;i<=n;i++)s[i].a=read();
		for(int i=1;i<=n;i++)s[i].b=read();
		sort(s+1,s+n+1);
		for(int i=0;i<=t;i++)f[i]=0;
		for(int i=1;i<=n;i++){
			for(int j=t;j>=1;j--)f[j]=max(f[j],f[j-1]+s[i].a-s[i].b*(j-1));
		}
		for(int i=0;i<=t;i++)ans=max(ans,f[i]);
		printf("%d\n",ans);
	}
	return 0;
}
