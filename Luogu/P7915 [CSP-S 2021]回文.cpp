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

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int T,n,a[N],fr[N],pr[N],nx[N],ans[N];

void print(){
	int L=1,R=n;
	while(L<=R){
		if(ans[L]<=ans[R])printf("L"),++L;
		else printf("R"),--R;
	}
	printf("\n");
	return;
}

int main(){
	T=read();
	while(T--){
		n=read()*2;
		for(int i=1;i<=n;i++)fr[i]=pr[i]=nx[i]=ans[i]=0;
		for(int i=1;i<=n;i++){
			a[i]=read();
			if(fr[a[i]])nx[fr[a[i]]]=i,pr[i]=fr[a[i]];
			else fr[a[i]]=i;
		}
		int tag=1,k=2;
		ans[1]=1,ans[nx[1]]=n;
		int L1=2,R1=nx[1]-1,L2=nx[1]+1,R2=n;
		for(int i=L2;i<=R2;){
			while(L1<R1&&a[L1]==a[R1])ans[L1]=k,ans[R1]=n-k+1,++L1,--R1,++k;
			while(i<R2&&a[i]==a[R2])ans[i]=n-k+1,ans[R2]=k,++i,--R2,++k;
			if(i>R2)break;
			if(L1<=R1&&a[L1]==a[i])ans[L1]=k,ans[i]=n-k+1,++L1,++i,++k;
			else if(L1<=R1&&a[R1]==a[R2])ans[R1]=n-k+1,ans[R2]=k,--R1,--R2,++k;
			else{tag=0;break;}
		}
		while(L1<R1&&a[L1]==a[R1])ans[L1]=k,ans[R1]=n-k+1,++L1,--R1,++k;
		if(L1<=R1)tag=0;
		if(tag){
			print();
			continue;
		}
		
		ans[n]=1,ans[pr[n]]=n,tag=1,k=2;
		L1=1,R1=pr[n]-1,L2=pr[n]+1,R2=n-1;
		for(int i=L2;i<=R2;){
			while(L1<R1&&a[L1]==a[R1])ans[L1]=k,ans[R1]=n-k+1,++L1,--R1,++k;
			while(i<R2&&a[i]==a[R2])ans[i]=n-k+1,ans[R2]=k,++i,--R2,++k;
			if(i>R2)break;
			if(L1<=R1&&a[L1]==a[i])ans[L1]=k,ans[i]=n-k+1,++L1,++i,++k;
			else if(L1<=R1&&a[R1]==a[R2])ans[R1]=n-k+1,ans[R2]=k,--R1,--R2,++k;
			else{tag=0;break;}
		}
		while(L1<R1&&a[L1]==a[R1])ans[L1]=k,ans[R1]=n-k+1,++L1,--R1,++k;
		if(L1<=R1)tag=0;
		if(tag){
			print();
			continue;
		}
		printf("-1\n");
	}
	return 0;
}
