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

const int N=2e5+7,Mod=998244353,INF=1e9+7;
int n,m,tot[N];
char s[N];

struct seg{
	int sum[N<<2],len[N<<2];
	short tag[N<<2];
	char cl;
	
	void pushdown(int id){
		if(tag[id]>=0){
			if(tag[id]==0)sum[id]=0;
			else sum[id]=len[id];
			if(len[id]>1)tag[id<<1]=tag[(id<<1)|1]=tag[id];
			tag[id]=-1;
		}
		return;
	}
	
	void build(int L,int R,int id){
		len[id]=R-L+1,tag[id]=-1;
		if(L==R)sum[id]=(s[L]==cl)?1:0;
		else{
			int M=(L+R)>>1;
			build(L,M,id<<1),build(M+1,R,(id<<1)|1);
			sum[id]=sum[id<<1]+sum[(id<<1)|1];
		}
		return;
	}
	
	void update(int L,int R,int id,int l,int r,int x){
		pushdown(id);
		if(l<=L&&r>=R)tag[id]=x,pushdown(id);
		else{
			int M=(L+R)>>1;
			if(l<=M)update(L,M,id<<1,l,r,x);
			else pushdown(id<<1);
			if(r>M)update(M+1,R,(id<<1)|1,l,r,x);
			else pushdown((id<<1)|1);
			sum[id]=sum[id<<1]+sum[(id<<1)|1];
		}
		return;
	}
	
	int query(int L,int R,int id,int l,int r){
		pushdown(id);
		if(l<=L&&r>=R)return sum[id];
		int M=(L+R)>>1,res=0;
		if(l<=M)res+=query(L,M,id<<1,l,r);
		if(r>M)res+=query(M+1,R,(id<<1)|1,l,r);
		return res;
	}
}tree[26];

int main(){
	n=read(),m=read();
	scanf("%s",s+1);
	for(char i='a';i<='z';i++)tree[i-'a'].cl=i,tree[i-'a'].build(1,n,1);
	for(int i=1,l,r,op;i<=m;i++){
		l=read(),r=read(),op=read();
		for(int j=0;j<26;j++)tot[j]=tree[j].query(1,n,1,l,r);
		for(int j=0;j<26;j++)tree[j].update(1,n,1,l,r,0);
		if(op==1)for(int j=0;j<26;j++)if(tot[j]>0)tree[j].update(1,n,1,l,l+tot[j]-1,1),l+=tot[j];
		if(op==0)for(int j=25;j>=0;j--)if(tot[j]>0)tree[j].update(1,n,1,l,l+tot[j]-1,1),l+=tot[j];
	}
	for(int i=1;i<=n;i++)for(int j=0;j<26;j++)if(tree[j].query(1,n,1,i,i)>0){printf("%c",'a'+j);break;}
	printf("\n");
	return 0;
}
