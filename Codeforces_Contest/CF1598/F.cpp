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

const int N=4e5+7,Mod=998244353,INF=1e9+7;
int n,q[N],a[N],b[N],c[N],d[N],len[N],ans,Len;
char s[21][N];

//void check(){
//	int k=0;
//	int res=0;
//	for(int i=1;i<=n;i++){
//		//printf("(%d %d %d %d %d %d)\n",a[q[i]],b[q[i]],c[q[i]],d[q[i]],k,res);
//		if(k==0)res+=d[q[i]];
//		if(k-a[q[i]]<0)break;
//		k-=a[q[i]];
//		if(k==0&&a[q[i]])res+=1+b[q[i]];
//		k+=c[q[i]];
//		
//	}
//	ans=max(ans,res);
//	//printf("[%d %d %d]\n",q[1],q[2],res);
//	return;
//}
//
//void dfs(int p,int k,int res,int L){
//	int rm=L;
//	rm-=k;
//	if(res+1+L/2<=ans)return;
//	if(p==n){
//		ans=max(ans,res);
//		return;
//	}
//	else{
//		for(int i=1;i<=n;i++)if(!vis[i]){
//			vis[i]=1,q[p+1]=i;
//			int kk=k,rres=res;
//			
//			if(kk==0)rres+=d[i];
//			if(kk-a[i]<0){
//				ans=max(ans,rres);
//				vis[i]=0;
//				continue;
//			}
//			kk-=a[i];
//			if(kk==0&&a[i])rres+=1+b[i];
//			kk+=c[i];
//			
//			dfs(p+1,kk,rres,L-len[i]);
//			vis[i]=0;
//		}
//	}
//	return;
//}

const int M=2e6;
int vis[M],f[M],K[M];
int sol(int z){
	if(z==0)return 0;
	if(vis[z])return f[z];
	vis[z]=1;
	int mx=-1,mv=0;
	for(int i=1;i<=n;i++)if(z&(1<<(i-1))){
		int v=1<<(i-1);
		int x=sol(z^v);
		if(x>mx)mx=x,mv=i;
	}
	int k=K[mv],res=mx;
	if(k==0)res+=d[mv];
	if(k-a[mv]<0);
	else{
		k-=a[mv];
		if(k==0&&a[mv])res+=1+b[mv];
		k+=c[mv];
		
	}
	f[z]=res,K[z]=k;
	return f[z];
}

int main(){
	n=read();
	for(int i=1;i<=n;i++){
		scanf("%s",s[i]+1);
		len[i]=strlen(s[i]+1);
		Len+=len[i];
		int p=0,x=0;
		for(int j=1;j<=len[i];j++){
			if(s[i][j]=='(')++p,++x;
			else --p,--x;
			if(p==0)++b[i];
			if(p<0)p=0,++a[i],b[i]=0;
			if(x==0&&a[i]==0)++d[i];
		}
		c[i]=p;
	}
	sol((1<<n)-1);
	//dfs(0,0,0,Len);
	printf("%d\n",f[(1<<n)-1]);
	return 0;
}

