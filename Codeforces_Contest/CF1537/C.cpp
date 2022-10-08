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

int read(){
	int __x=0,__y=1;char __c=' ';
	while(__c<'0'||__c>'9'){__c=getchar();if(__c=='-'){__y=-1,__c=getchar();break;}}
	while(__c>='0'&&__c<='9')__x=__x*10+__c-'0',__c=getchar();
	return __x*__y;}

const int N=2e5+7,Mod=998244353,INF=1e9+7;

int T,n,u[N],h[N],a[N],m,b[N],tot[N],nx[N],la[N],d[N],dt;

int main(){
	scanf("%d",&T);
	while(T--){
		n=read();
		for(int i=1;i<=n;i++)h[i]=read(),u[i]=a[i]=0;
		sort(h+1,h+n+1);
		
		int c=INF;
		for(int i=2;i<=n;i++)if(h[i]-h[i-1]<c)c=h[i]-h[i-1];
		for(int i=2;i<=n;i++)if(h[i]-h[i-1]==c){
			u[i]=u[i-1]=1,a[1]=h[i-1],a[n]=h[i];
			break;
		}
		int t=1;m=0;
		
		for(int i=1;i<=n;i++){
			if(u[i]==0){//printf("<%d>\n",i);
				if(h[i]!=b[m])b[++m]=h[i],tot[m]=1,nx[m-1]=m,la[m]=m-1;
				else ++tot[m];
			}nx[m]=-1;
		}
		
		for(int i=nx[0];i!=-1;i=nx[i]){//printf("[%d %d]\n",i,b[i]);
			if(b[i]>a[1]){
				a[++t]=b[i],--tot[i];
				if(tot[i]==0)nx[la[i]]=nx[i],la[nx[i]]=la[i];
			}
		}//printf("(%d\n)",t);
		
		dt=0;
		for(int i=nx[0];i!=-1;i=nx[i]){//printf("[%d %d]\n",i,b[i]);
			if(b[i]<a[n]){
				d[++dt]=b[i],--tot[i];
				if(tot[i]==0)nx[la[i]]=nx[i],la[nx[i]]=la[i];
			}
		}//printf("(%d\n)",t);
		int e=n-1;
		for(int i=dt;i>=1;i--)a[e]=d[i],--e;
		
		while(1){
			if(t>=e)break;
			for(int i=nx[0];i!=-1;i=nx[i]){//printf("[%d %d]\n",i,b[i]);
				a[++t]=b[i],--tot[i];
				if(tot[i]==0)nx[la[i]]=nx[i],la[nx[i]]=la[i];
			}//printf("(%d\n)",t);
		}
		for(int i=1;i<=n;i++)printf("%d ",a[i]);
		printf("\n");
	}
	return 0;
}
