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
#define Lid (ch[id][0])
#define Rid (ch[id][1])

using namespace std;

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=4e5+7,M=2e7+7,MAX=1e9,Mod=1e9+1;
int n,T[N];
int ch[M][2],lv[M],rv[M],tag[M],ct=1;

void pushdown(int id,int L,int R){
	if(L!=R){
		int M=(L+R)>>1;
		if(!Lid)Lid=++ct,lv[Lid]=L,rv[Lid]=M;
		if(!Rid)Rid=++ct,lv[Rid]=M+1,rv[Rid]=R;
	}
	if(tag[id]!=0){
		lv[id]+=tag[id],rv[id]+=tag[id];
		if(L!=R)tag[Lid]+=tag[id],tag[Rid]+=tag[id];
		tag[id]=0;
	}
	return;
}

void update1(int L,int R,int id,int t){
	pushdown(id,L,R);
	if(lv[id]>=t)return;
	if(rv[id]<t)++tag[id],pushdown(id,L,R);
	else if(L!=R){
		int M=(L+R)/2;
		update1(L,M,Lid,t),update1(M+1,R,Rid,t);
		++lv[id];
	}
	return;
}

void update2(int L,int R,int id,int t){
	pushdown(id,L,R);
	if(rv[id]<=t)return;
	if(lv[id]>t)--tag[id],pushdown(id,L,R);
	else if(L!=R){
		int M=(L+R)/2;
		update2(L,M,Lid,t),update2(M+1,R,Rid,t);
		--rv[id];
	}
	return;
}

int query(int L,int R,int id,int x){
	if((!Lid)&&(!Rid))return lv[id]+tag[id]+x-L;
	pushdown(id,L,R);
	int M=(L+R)/2;
	if(x<=M)return query(L,M,Lid,x);
	return query(M+1,R,Rid,x);
}

signed main(){
	n=read();
	lv[1]=0,rv[1]=MAX;
	
	for(int i=1,k,ans=0;i<=n;i++){
		T[i]=read();
		update1(0,MAX,1,T[i]),update2(0,MAX,1,T[i]);
		
		k=read();
		while(k--){
			int x=(read()+ans)%Mod;
			ans=query(0,MAX,1,x);
			printf("%lld\n",ans);
		}
	} 
	return 0;
}
