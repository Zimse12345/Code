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
#define Lid ch[id][0]
#define Rid ch[id][1]
#define M ((L+R)>>1)

using namespace std;

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-')qry=-1;qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int Mod=1e9+7,N=24e6+7,INF=1e18;
int n,tot=1;
signed ch[N][2],rt=1;
char sta[N],tag[N];

void pushdown(int id,bool lf){
	if(!id)return;
	if(!lf&&sta[id]==1){
		if(!Lid)Lid=++tot;
		if(!Rid)Rid=++tot;
		if(sta[id]==1)tag[Lid]=tag[Rid]=1;
	}
	if(tag[id]==1){
		sta[id]=1;
		if(!lf)tag[Lid]=tag[Rid]=1;
	}
	else if(tag[id]==2){
		sta[id]=0;
		if(!lf)tag[Lid]=tag[Rid]=2;
	}
	else if(tag[id]==3){
		if(sta[id]==0)sta[id]=1;
		else if(sta[id]==1)sta[id]=0;
		if(!lf){
			tag[Lid]=3-tag[Lid];
			tag[Rid]=3-tag[Rid];
		}
	}
	tag[id]=0;
	return;
}

void update(int L,int R,signed& id,int l,int r,int op){
	pushdown(id,L==R);
	if(r<L||R<l)return;
	if(l<=L&&r>=R)tag[id]=op,pushdown(id,L==R);
	else{
		if(!Lid)Lid=++tot;
		if(!Rid)Rid=++tot;
		if(sta[id]==1)tag[Lid]=tag[Rid]=1;
		update(L,M,Lid,l,r,op);
		update(M+1,R,Rid,l,r,op);
		if(sta[Lid]==0&&sta[Rid]==0)sta[id]=0;
		else if(sta[Lid]==1&&sta[Rid]==1)sta[id]=1;
		else sta[id]=2;
	}
	return;
}

int query(int L,int R,int id){
	
	if(!id)return L;
	pushdown(id,L==R);
	if(sta[id]==0)return L;
	if(sta[id]==2){
		int x=query(L,M,Lid);
		if(x)return x;
		return query(M+1,R,Rid);
	}
	return 0;
}

signed main(){
	n=read();
	for(int I=1;I<=n;I++){
		int op=read(),l=read(),r=read();
		update(1,1e18,rt,l,r,op);
		int ans=query(1,1e18,1);
		if(!ans)ans=INF+1;
		printf("%lld\n",ans);
	}
	return 0;
}

