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
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=2e5+7,Mod=998244353,INF=1e9+7;
int T,n,a[N],t[N],tt[N],c,cc;

int main(){
	T=read();
	while(T--){
		n=read(),c=cc=0;
		int cnt=0;
		for(int i=1;i<=n;i++){
			a[i]=read();
			if(a[i])++cnt;
		}
		if(cnt%2==1){
			printf("No\n");
			continue;
		}
		
		for(int i=1;i<=n-2;i++){
			if((a[i]^a[i+1]^a[i+2])==0)a[i]=a[i+1]=a[i+2]=0,t[++c]=i;
			if(a[i]==0&&a[i+1]==0&&a[i+2]==0)continue;
			if(a[i]==1){
				t[++c]=i;
				a[i]=a[i+1]=a[i+2]=1;
				tt[++cc]=i;
			}
		}
		printf("Yes\n%d\n",c+cc);
		for(int i=1;i<=c;i++)printf("%d ",t[i]);
		for(int i=cc;i>=1;i--)printf("%d ",tt[i]);
		printf("\n");
	}
	return 0;
}

