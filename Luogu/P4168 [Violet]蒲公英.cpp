#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>

#define ll long long

using namespace std;

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-')qry=-1;qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-'0',qrc=getchar();return qrx*qry;}

const int N=5e4+7,Mod=1004535809,INF=1e9+7;
int n,m,a[N],b[N],K,num[300][300],ct[300][300],val[N],cnt[N];
map<int,int> mp;
vector<int> v[N];

void sol(int x,int l,int r,int& mn,int& mc){
	int L=0,R=v[x].size()-1,y;
	while(L<=R){
		int M=(L+R)>>1;
		if(v[x][M]>=l)y=M,R=M-1;
		else L=M+1;
	}
	if((mc==0)||(y+mc<signed(v[x].size())&&v[x][y+mc]<=r)
	||(y+mc-1<signed(v[x].size())&&v[x][y+mc-1]<=r&&x<mn)){
		L=y,R=v[x].size()-1;
		int res=y;
		while(L<=R){
			int M=(L+R)>>1;
			if(v[x][M]<=r)res=M,L=M+1;
			else R=M-1;
		}
		mn=x,mc=res-y+1;
	}
	return;
}

signed main(){
	n=read(),m=read(),K=200;
	for(int i=1;i<=n;i++)b[i]=a[i]=read();
	sort(b+1,b+n+1);
	for(int i=1,j=0;i<=n;i++)if(b[i]!=b[i-1])mp[b[i]]=++j,val[j]=b[i];
	for(int i=1;i<=n;i++)a[i]=mp[a[i]],v[a[i]].push_back(i);
	for(int i=0;i<=n/K;i++){
		int p=i*K,nm=0,mc=0;
		if(p==0)++p;
		for(int j=i;j<=n/K;j++){
			while(p<min(n+1,(j+1)*K)){
				cnt[a[p]]++;
				if(cnt[a[p]]>mc||(cnt[a[p]]==mc&&a[p]<nm))nm=a[p],mc=cnt[a[p]];
				p++;
			}
			num[i][j]=nm,ct[i][j]=mc;
		}
		for(int j=1;j<=n;j++)cnt[j]=0;
	}
	for(int i=1,l,r,ans=0;i<=m;i++){
		l=(read()+ans-1)%n+1,r=(read()+ans-1)%n+1;
		if(l>r)swap(l,r);
		int L=l/K+1,R=r/K-1,mn=0,mc=0;
		if(L<=R){
			mn=num[L][R],mc=ct[L][R];
			for(int j=l;j<L*K;j++)sol(a[j],l,r,mn,mc);
			for(int j=(R+1)*K;j<=r;j++)sol(a[j],l,r,mn,mc);
		}
		else for(int j=l;j<=r;j++)sol(a[j],l,r,mn,mc);
		printf("%d\n",val[mn]),ans=val[mn];
	}
	return 0;
}

