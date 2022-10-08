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
int T,n,ma[N],mb[N],ans[N];
struct p{
	int a,b,id;
	p(int a=0,int b=0,int id=0):a(a),b(b),id(id){}
}s[N],t[N];
inline bool cmp1(p& A,p& B){return A.a<B.a;}
inline bool cmp2(p& A,p& B){return A.b<B.b;}

signed main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;i++)s[i].a=read(),s[i].id=i;
		for(int i=1;i<=n;i++)s[i].b=read(),t[i]=s[i];
		sort(s+1,s+n+1,cmp1),sort(t+1,t+n+1,cmp2);
		int wina=t[n].a,winb=s[n].b;
		ma[n+1]=mb[n+1]=INF;
		for(int i=n;i>=1;i--)ma[i]=min(ma[i+1],t[i].a),mb[i]=min(mb[i+1],s[i].b);
		
		while(1){
			int tag=0;
			int L=1,R=n,p=0;
			while(L<=R){
				int M=(L+R)>>1;
				if(s[M].a>=wina)p=M,R=M-1;
				else L=M+1;
			}
			if(mb[p]<winb)tag=1,winb=mb[p];
			L=1,R=n,p=0;
			while(L<=R){
				int M=(L+R)>>1;
				if(t[M].b>=winb)p=M,R=M-1;
				else L=M+1;
			}
			if(ma[p]<wina)tag=1,wina=ma[p];
			if(!tag)break;
		}
		for(int i=1;i<=n;i++){
			if(s[i].a>=wina||s[i].b>=winb)ans[s[i].id]=1;
			else ans[s[i].id]=0;
		}
		
		for(int i=1;i<=n;i++)printf("%d",ans[i]);
		printf("\n");
	}
	return 0;
}

