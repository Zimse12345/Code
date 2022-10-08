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

int read(){int qrx=0,qry=1;char qrc=' ';
while(qrc<'0'||qrc>'9'){qrc=getchar();if(qrc=='-'){qry=-1,qrc=getchar();break;}}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-'0',qrc=getchar();return qrx*qry;}

const int N=1e5+7,Mod=998244353,INF=1e9+7;
int n,m,a[N],t[N],cnt,ans[N];
int prime[N],pr[N],pc;

int main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		for(int j=1;j*j<=a[i];j++)if(a[i]%j==0)t[j]=t[a[i]/j]=1;
	}
	
	for(int i=2;i<N;i++){
        if(!pr[i])pr[i]=i,prime[++pc]=i;
        for(int j=1;j<=pc&&i*prime[j]<N;j++){
            pr[i*prime[j]]=prime[j];
            if(pr[i]==prime[j])break;
        }
    }
	
	t[1]=0,pr[1]=1;
	for(int i=1;i<=m;i++){
		if(t[i/pr[i]]||t[pr[i]])t[i]=1;
		if(!t[i])ans[++cnt]=i;
	}
	printf("%d\n",cnt);
	for(int i=1;i<=cnt;i++)printf("%d\n",ans[i]);
	return 0;
}

