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

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int n,m,ans[N],len,aans[N],llen;

void mul(int x){
	int p=0;
	for(int i=1;i<=len;i++){
		ans[i]=ans[i]*x+p;
		p=ans[i]/10,ans[i]%=10;
	}
	while(p)ans[++len]=p%10,p/=10;
	return;
}

void print(){
	while(llen>0&&aans[llen]==0)--llen;
	if(llen==0)printf("0\n");
	else for(int i=llen;i>=1;i--)printf("%lld",aans[i]);
	printf("\n");
	return;
}

signed main(){
	n=read(),m=read();
	if(n+3<m){
		printf("0\n");
		return 0;
	}
	ans[1]=len=1;
	for(int i=1;i<=n+2;i++)mul(i);
	for(int i=n+3;i>=n+4-m;i--)mul(i);
	for(int i=1;i<=len;i++)aans[++llen]=ans[i],ans[i]=0;
	len=0;
	if(n+2>=m){
		ans[1]=2,len=1;
		for(int i=1;i<=n+1;i++)mul(i);
		for(int i=n+2;i>=n+3-m;i--)mul(i);
	}
	llen=max(len,llen),len=llen;
	for(int i=1;i<=len;i++)aans[i]-=ans[i];
	for(int i=1;i<=llen;i++){
		while(aans[i]<0)aans[i]+=10,--aans[i+1];
	}
	print();
	return 0;
}

