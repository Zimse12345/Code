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
#define Lid (id<<1)
#define Rid ((id<<1)|1)
#define M ((L+R)>>1)

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=2e5+7,Mod=998244353,INF=1e9+7;
int n,a[N],s[N*4];
inline int gcd(int x,int y){return y?gcd(y,x%y):x;}

void build(int L,int R,int id){
	if(L==R)s[id]=a[L];
	else{
		build(L,M,Lid),build(M+1,R,Rid);
		s[id]=gcd(s[Lid],s[Rid]);
	}
	return;
}

int query(int L,int R,int id,int l,int r){
	if(l>R||L>r)return 0;
	if(l<=L&&r>=R)return s[id];
	return gcd(query(L,M,Lid,l,r),query(M+1,R,Rid,l,r));
}

signed main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	build(1,n,1);
	for(int i=1,f=0,ans=0;i<=n;i++){
		int L=f+1,R=i,p=0;
		while(L<=R){
			int g=query(1,n,1,M,i);
			if(i-M+1>g)L=M+1;
			else if(i-M+1==g){p=M;break;}
			else R=M-1;
		}
		if(p)++ans,f=i;
		printf("%d ",ans);
	}
	printf("\n");
	return 0;
}

