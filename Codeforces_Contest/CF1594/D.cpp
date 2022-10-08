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

const int N=5e5+7,Mod=998244353,INF=1e9+7;
int T,n,m,fa[N],cnt[N],vis[N];
char s[100];
vector<int> k[N];

int F(int x){
	if(fa[x]!=x)fa[x]=F(fa[x]);
	return fa[x];
}

void lk(int a,int b){
	int A=F(a),B=F(b);
	if(A==B)return;
	if(cnt[A]<cnt[B])fa[A]=B,cnt[B]+=cnt[A];
	else fa[B]=A,cnt[A]+=cnt[B];
	return;
}

int main(){
	T=read();
	while(T--){
		n=read(),m=read();
		int tag=0,ans=0;
		for(int i=1;i<=2*n;i++){
			fa[i]=i,cnt[i]=1,vis[i]=0;
			k[i].resize(0);
		}
		
		for(int i=1,a,b;i<=m;i++){
			a=read(),b=read();
			scanf("%s",s+1);
			if(s[1]=='i'){
				int A=F(a),B=F(b);
				if(A==B){
					tag=1;
					//break;
				}
				lk(a,b+n),lk(a+n,b);
			}
			if(s[1]=='c'){
				int A=F(a),B=F(b+n);
				if(A==B){
					tag=1;
					//break;
				}
				lk(a,b),lk(a+n,b+n);
			}
		}
		if(tag){
			printf("-1\n");
			continue;
		}
		for(int i=1;i<=2*n;i++){
			int f=F(i);
			k[f].push_back(i);
		}
		for(int i=1;i<=2*n;i++)if(k[i].size()>0){
			if(vis[k[i][0]])break;
			int c1=0,c2=0;
			for(int j=0;j<k[i].size();j++){
				int v=k[i][j];
				vis[v]=1;
				if(v>n)++c2,vis[v-n]=1;
				else ++c1,vis[v+n]=1;
			}
			ans+=max(c1,c2);
		}
		printf("%d\n",ans);
	}
	return 0;
}
