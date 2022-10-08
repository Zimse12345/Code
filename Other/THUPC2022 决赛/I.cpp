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

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-')qry=-1;qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=64,Mod=998244353,INF=1e9+7;
int n,m,a[N][N],b[N][N],k,q,S,Tot,cntq;
int cl[N][N],vis[N][N],sz;

struct qres{
	int rcnt,main1,main2,sc;
	qres(int rcnt=0,int main1=0,int main2=0,int sc=0):rcnt(rcnt),main1(main1),main2(main2),sc(sc){}
}qu[10];

void dfs(int x,int y,int z){
	if(!cl[x][y]||vis[x][y]||a[x][y]!=z)return;
	++sz,vis[x][y]=1;
	dfs(x+1,y,z),dfs(x-1,y,z),dfs(x,y-1,z),dfs(x,y+1,z);
	return;
}

void Clear(){
	for(int j=1;j<=m;j++){
		int p=n;
		for(int i=n;i>=1;i--)if(!cl[i][j]){
			a[p][j]=a[i][j],b[p][j]=b[i][j];
			--p;
		}
		for(int i=1;i<=p;i++)a[i][j]=b[i][j]=0;
	}
	return;
}

void see(){
	printf("--------------\n");
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)printf("%lld ",a[i][j]);
		printf("\n");
	}
	printf("-----------\n");
}

int dis(int x_1,int y_1,int x_2,int y_2){
	return abs(x_1-x_2)+abs(y_1-y_2);
}

void boom(int i,int j){
	if(b[i][j]==1){
		for(int jj=1;jj<=m;jj++)if(!cl[i][jj])cl[i][jj]=1,boom(i,jj);
	}
	if(b[i][j]==2){
		for(int ii=1;ii<=n;ii++)if(!cl[ii][j])cl[ii][j]=1,boom(ii,j);
	}
	if(b[i][j]==3){
		for(int jj=1;jj<=m;jj++)if(!cl[i][jj])cl[i][jj]=1,boom(i,jj);
		for(int ii=1;ii<=n;ii++)if(!cl[ii][j])cl[ii][j]=1,boom(ii,j);
	}
	if(b[i][j]==4){
		for(int x=i-1;x<=i+1;x++){
			for(int y=j-1;y<=j+1;y++){
				if(1<=x&&x<=n&&1<=y&&y<=m)if(!cl[x][y])cl[x][y]=1,boom(x,y);
			}
		}
	}
	if(b[i][j]==5){
		for(int x=i-2;x<=i+2;x++){
			for(int y=j-2;y<=j+2;y++){
				if(1<=x&&x<=n&&1<=y&&y<=m)if(!cl[x][y])cl[x][y]=1,boom(x,y);
			}
		}
	}
	if(b[i][j]==6){
		for(int x=1;x<=n;x++){
			for(int y=1;y<=m;y++){
				if(a[x][y]==a[i][j])if(!cl[x][y])cl[x][y]=1,boom(x,y);
			}
		}
	}
	return;
}

qres sol(int r){
	// 第 r 轮 消除,返回(次数,主色1,主色2,分数)
	int s=0,main1=0,main2=0;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cl[i][j]=0,vis[i][j]=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]&&a[i+1][j]==a[i][j]&&a[i+2][j]==a[i][j])cl[i][j]=cl[i+1][j]=cl[i+2][j]=1;
			if(a[i][j]&&a[i][j+1]==a[i][j]&&a[i][j+2]==a[i][j])cl[i][j]=cl[i][j+1]=cl[i][j+2]=1;
		}
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(cl[i][j]){
		if(!main1)main1=a[i][j];
		else if(main1&&a[i][j]!=main1)main2=a[i][j];
		sz=0;
		dfs(i,j,a[i][j]);
		sz=max(0ll,sz-3);
		s+=sz*sz*50;
	}
	if(!main1){
		return qres(0,0,0,0);
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(cl[i][j]){
		boom(i,j);
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(a[i][j]&&cl[i][j])s+=r*a[i][j],--Tot;
	Clear();
//	see();
//	printf("<%d>\n",Tot);
	qres t=sol(r+1);
//	printf("[%d %d]\n",s,t.sc);
	t.rcnt++,t.sc+=s,t.main1=main1,t.main2=main2;
	return t;
}

int exS(){
	// 额外分,qu[1-5] 
	int res=0;
	for(int i=0;i<32;i++){
		int ss[8],tt=0,tagg=1;
		for(int j=1;j<=5;j++){
			if(i&(1<<(j-1))){
				if(!qu[j].main2){
					tagg=0;break;
				}
				ss[tt++]=qu[j].main2;
			}
			else{
				ss[tt++]=qu[j].main1;
			}
		}
		if(!tagg)continue;
		sort(ss,ss+5);
		if(ss[0]!=ss[1]&&ss[1]!=ss[2]&&ss[2]!=ss[3]&&ss[3]!=ss[4])res=max(res,50+ss[4]);
		else if(ss[0]==ss[4])res=max(res,1000+ss[0]*10);
		else if(ss[0]==ss[3]||ss[1]==ss[4])res=max(res,750+ss[1]*5);
		else if(ss[0]==ss[2]&&ss[3]==ss[4])res=max(res,500+3*ss[0]+ss[4]);
		else if(ss[0]==ss[1]&&ss[2]==ss[4])res=max(res,500+ss[0]+3*ss[4]);
		else if(ss[0]==ss[2]||ss[1]==ss[3]||ss[2]==ss[4])res=max(res,300+3*ss[2]);
		else{
			int d1=0,d2=0;
			for(int i=0;i<4;i++)if(ss[i]==ss[i+1]){
				if(!d1)d1=ss[i];
				else d2=ss[i];
			}
			if(!d2)res=max(res,100+2*d1);
			else res=max(res,200+2*d2+d1);
		}
	}
	return res;
}

signed main(){
	n=read(),m=read(),k=read(),q=read();
	Tot=n*m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)a[i][j]=read();
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)b[i][j]=read();
	}
	int tag=1;
	while(q--){
		int x_1=read(),y_1=read(),x_2=read(),y_2=read();
		if(!a[x_1][y_1]||!a[x_2][y_2]||dis(x_1,y_1,x_2,y_2)!=1){
			tag=0;
			continue;
		}
		swap(a[x_1][y_1],a[x_2][y_2]),swap(b[x_1][y_1],b[x_2][y_2]);
		qres t=sol(1);
		if(!t.rcnt){
			swap(a[x_1][y_1],a[x_2][y_2]),swap(b[x_1][y_1],b[x_2][y_2]);
			tag=0;
			continue;
		}
		S+=80*(t.rcnt-1)*(t.rcnt-1);
		S+=t.sc;
		for(int i=1;i<=4;i++)qu[i]=qu[i+1];
		qu[5]=t;
		++cntq;
		if(cntq==5){
			S+=exS();
			cntq=0;
		}
//		printf("%d\n",S);
	}
	if(tag)S+=1000;
	if(!Tot)S+=10000;
	printf("%lld\n",S);
	return 0;
}

