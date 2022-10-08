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

const int N=1e2+7,Mod=998244353,INF=1e9+7;
int T,n,a[N];

int main(){
	T=read();
	while(T--){
		int ans=INF;
		a[1]=read(),a[2]=read(),a[3]=read();
		sort(a+1,a+4);
		if(a[1]==a[2]){
			printf("%d\n",a[1]);
			continue;
		}
		if(a[2]==a[3]){
			printf("%d\n",a[2]);
			continue;
		}
		if(a[1]==0){
			printf("-1\n");
			continue;
		}
		if((a[3]-a[1])%3==0){
			ans=a[3];
		}
		if((a[3]-a[2])%3==0){
			ans=a[3];
		}
		if((a[2]-a[1])%3==0){
			ans=a[2];
		}
//		int k=a[2]-a[1];
//		if(k%3==0){//BC->(A=B)
//			ans=a[2];
//		}
//		k=a[3]-a[1];
//		if(k%3==0&&a[2]>=k/3){//BC->(A=C)
//			ans=min(ans,a[3]);
//		}
//		k=a[3]-a[2];
//		if(k%3==0&&a[1]>k/3){//AC->(B=C)
//			ans=min(ans,a[3]);
//		}
		if(ans>=INF)ans=-1;
		printf("%d\n",ans);
	}
	return 0;
}
