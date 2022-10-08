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

const int N=3e5+7,Mod=998244353,INF=1e9+7;
int T,n,q,a[N],p1[N],p2[N],q1[N],q2[N],c1[N],c2[N];
char s[N];
vector<int> h[2][N];

int sol(int l,int r,int W){
	int o=(l+1)%2;
	int wt=W;
	if(!o)wt+=p1[l-1]+q2[r+1];
	else wt+=p2[l-1]+q1[r+1];
	int L=0,R=h[o][wt].size()-1;
	while(L<=R){
		int M=(L+R)>>1;
		if(h[o][wt][M]<l)L=M+1;
		else if(h[o][wt][M]>r)R=M-1;
		else return h[o][wt][M];
	}
//	printf("%d00%d00%d\n",l,r,wt);
	return -1; 
}

int main(){
	T=read();
	while(T--){
		n=read(),q=read();
		scanf("%s",s+1);
		for(int i=1;i<=n;i++){
			if(s[i]=='-')a[i]=0;
			else a[i]=1;
		}
		
		for(int i=1;i<=n;i++){
			p1[i]=p1[i-1]+(a[i]^((i+1)%2));
			p2[i]=p2[i-1]+(a[i]^(i%2));
		}
		q1[n+1]=q2[n+1]=0;
		for(int i=n;i>=1;i--){
			q1[i]=q1[i+1]+(a[i]^((i+1)%2));
			q2[i]=q2[i+1]+(a[i]^(i%2));
		}
		
		for(int i=0;i<=n;i++)h[0][i].resize(0),h[1][i].resize(0);
		for(int i=1;i<=n;i++){
			c1[i]=p1[i-1]+q2[i+1];
			c2[i]=p2[i-1]+q1[i+1];//printf("[%2d %2d %2d %2d]\n",i,p1[i],q2[i],c1[i]);
			h[0][c1[i]].push_back(i);
			h[1][c2[i]].push_back(i);
		}
		
		while(q--){
			int l=read(),r=read();
			int k=r-l+1;
			int sum=0;
			
			if(l%2)sum=p1[r]-p1[l-1];
			else sum=p2[r]-p2[l-1];
			
			if(sum*2==k){
				printf("0\n");
				continue;
			}
			if(k%2==1){
				printf("1\n");
				int ans=sol(l,r,k/2);
				printf("%d\n",ans);
			}
			else{
				printf("2\n");
				int ans=sol(l,r-1,k/2-1);
				printf("%d %d\n",ans,r);
			}
		}
	}
	return 0;
}
