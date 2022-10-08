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

const int N=4e5+7,Mod=998244353,INF=1e9+7;
int n,m,q,rt[N],ch[N*32][2],tot,tag[N*32],v[N],p[N];

void update(int id,int _id,int L,int R,int l,int r,int x){
	tag[_id]=tag[id],ch[_id][0]=ch[id][0],ch[_id][1]=ch[id][1];
	if(r<L||R<l)return;
	if(l<=L&&r>=R)tag[_id]+=x;
	else{
		int M=(L+R)/2;
		if(l<=M)ch[_id][0]=++tot,update(ch[id][0],ch[_id][0],L,M,l,r,x);
		if(r>M)ch[_id][1]=++tot,update(ch[id][1],ch[_id][1],M+1,R,l,r,x);
	}
	return;
}

int query(int id,int L,int R,int x){
	if(L==R)return tag[id];
	int M=(L+R)/2;
	if(x<=M)return tag[id]+query(ch[id][0],L,M,x);
	return tag[id]+query(ch[id][1],M+1,R,x);
}

signed main(){
	n=read(),m=read(),q=read();
	rt[0]=0;
	for(int i=1;i<=q;i++){
		int op=read();
		if(op==1){
			int l=read(),r=read(),x=read();
			rt[i]=++tot;
			update(rt[i-1],rt[i],1,m,l,r,x);
		}
		else{
			rt[i]=rt[i-1];
			if(op==2){
				int x=read(),y=read();
				v[x]=y,p[x]=i;
			}
			else{
				int x=read(),y=read(),ans=v[x];
				ans+=query(rt[i],1,m,y)-query(rt[p[x]],1,m,y);
				printf("%lld\n",ans);
			}
		}
	}
	return 0;
}

