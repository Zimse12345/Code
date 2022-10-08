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

const int N=1e3+7,Mod=998244353,INF=1e9+7;
int n,w,ww,t[N],tt[N],sta[N],ssta[N],cnt,pos,tag,ans;
vector<int> mouse[N],mmouse[N],mmmouse;

signed main(){
	n=read()-1;read();
	if(n==0){
		printf("2\n");
		fflush(stdout);
		printf("1\n");
		return 0;
	}
	for(int i=0;i<=30;i++)if(n&(1<<i))w=i;
	for(int i=0;i<=30;i++)if(w&(1<<i))ww=i;
	++w,++ww,++n;
	for(int i=0;i<n;i++){
		for(int j=0;j<w;j++)if(i&(1<<j))mouse[j].push_back(i);
	}
	for(int i=0;i<ww;i++){
		for(int j=0;j<w;j++)if(j&(1<<i)){
			for(unsigned k=0;k<mouse[j].size();k++)t[mouse[j][k]]^=1;
		}
		for(int k=0;k<n;k++)if(t[k])mmouse[i].push_back(k),t[k]=0,tt[k]^=1;
	}
	for(int i=0;i<n;i++)if(tt[i])mmmouse.push_back(i);
	for(int i=0;i<w;i++){
		printf("%d %llu ",1,mouse[i].size());
		for(unsigned j=0;j<mouse[i].size();j++)printf("%d ",mouse[i][j]+1);
		printf("\n");
	}
	for(int i=0;i<ww;i++){
		printf("%d %llu ",1,mmouse[i].size());
		for(unsigned j=0;j<mmouse[i].size();j++)printf("%d ",mmouse[i][j]+1);
		printf("\n");
	}
	printf("%d %llu ",1,mmmouse.size());
	for(unsigned i=0;i<mmmouse.size();i++)printf("%d ",mmmouse[i]+1);
	printf("\n");
	printf("2\n");
	fflush(stdout);
	for(int i=0;i<w;i++){
		sta[i]=read()^1;
		if(sta[i])ans|=(1<<i);
	}
	for(int i=0;i<ww;i++)ssta[i]=read()^1,cnt^=ssta[i];
	cnt^=(read()^1);
	if(cnt){
		printf("%d\n",ans+1);
		fflush(stdout);
		return 0;
	}
	for(int i=0;i<ww;i++){
		cnt=ssta[i];
		for(int j=0;j<w;j++)if(j&(1<<i))cnt^=sta[j];
		if(cnt)pos|=(1<<i),tag=1;
	}
	ans^=(1<<pos);
	printf("%d\n",ans+1);
	fflush(stdout);
	return 0;
}

