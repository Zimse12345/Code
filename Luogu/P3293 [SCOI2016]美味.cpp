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
#define M ((L+R)>>1)

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=2e5+7,Mod=998244353,INF=1e9+7;
int n,m,rt[N],ch[N*64][2],v[N*64],tot;

void update(int L,int R,int _id,int& id,int x){
	if(!id)id=++tot;
	v[id]=v[_id]+1;
	if(L^R){
		if(x<=M)update(L,M,ch[_id][0],ch[id][0],x),ch[id][1]=ch[_id][1];
		else update(M+1,R,ch[_id][1],ch[id][1],x),ch[id][0]=ch[_id][0];
	}
	return;
}

bool query(int L,int R,int _id,int id,int l,int r){
	if(!id||R<l||L>r)return false;
	if(l<=L&&r>=R)return v[id]>v[_id];
	if(L==R)return false;
	if(query(L,M,ch[_id][0],ch[id][0],l,r))return true;
	return query(M+1,R,ch[_id][1],ch[id][1],l,r); 
}

signed main(){
	n=read(),m=read();
	for(int i=1,x;i<=n;i++){
		x=read();
		update(0,262143,rt[i-1],rt[i],x);
	}
	for(int i=1,b,x,l,r;i<=m;i++){
		b=read(),x=read(),l=read(),r=read();
		int L=-x,R=262143-x;
		for(int j=17;j>=0;j--){
			if(b&(1<<j)){
				if(query(0,262143,rt[l-1],rt[r],L,M))R=M;
				else L=M+1;
			}
			else{
				if(query(0,262143,rt[l-1],rt[r],M+1,R))L=M+1;
				else R=M;
			}
		}
		printf("%d\n",b^(L+x));
	}
	return 0;
}

