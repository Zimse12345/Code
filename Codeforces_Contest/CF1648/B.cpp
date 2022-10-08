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
int T,n,c,a[N],t[N],s[N];

signed main(){
	T=read();
	while(T--){
		for(int i=1;i<=c;i++)t[i]=s[i]=0;
		n=read(),c=read();
		for(int i=1;i<=n;i++)a[i]=read(),t[a[i]]=1;
		for(int i=1;i<=c;i++)s[i]=s[i-1]+t[i];
		if(!t[1]){
			printf("No\n");
			continue;
		}
		int tag=1;
		for(int i=1;i<=c;i++)if(t[i]){
			for(int j=1;j*i<=c;j++){
				int L=j*i,R=min(i*(j+1)-1,c);
				if(s[R]-s[L-1]&&!t[j])tag=0;
			}
			if(!tag)break;
		}
		if(tag)printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}

