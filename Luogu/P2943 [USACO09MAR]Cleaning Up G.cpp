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

const int N=1e5+7,Mod=998244353,INF=1e9+7;
int n,m,a,f[N],st[N],cl[N],tot;

int main(){
	n=read(),m=read();
	int sz=sqrt(n)+1;
	for(int i=1,p;i<=n;i++){
		a=read(),p=0,st[0]=i,cl[0]=a,f[i]=INF;
		for(int j=1;j<=tot;j++)if(cl[j]==a)p=j;
		if(p!=0){
			cl[p]=cl[p-1];
			for(int j=p-1;j>=1;j--)cl[j]=cl[j-1],st[j]=st[j-1],f[i]=min(f[i],j*j+f[st[j]-1]);;
			for(int j=p;j<=tot;j++)f[i]=min(f[i],j*j+f[st[j]-1]);
		}
		else{
			for(int j=tot+1;j>=1;j--)st[j]=st[j-1],cl[j]=cl[j-1],f[i]=min(f[i],j*j+f[st[j]-1]);
			++tot;
			if(tot>=sz)--tot;
		}
	}
	printf("%d\n",f[n]);
	return 0;
}
