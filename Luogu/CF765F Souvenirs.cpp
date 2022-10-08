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

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=3e5+7,Mod=998244353,INF=1e9+7;
int n,m,a[N],b[N];
int A[400][400],B[400][400],C[N],D[330][330][330],E[330][330][330];
int BlockSize,BlockCnt,BL[N],BR[N];

struct num{
	int val,pos;
	num(int val=0,int pos=0):val(val),pos(pos){}
	bool operator < (const num& obj)const{return val<obj.val;}
}v[N];

signed main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read(),v[i]=num(a[i],i);
	m=read();
	BlockSize=max(2,signed(sqrt(n)));
	BlockCnt=n/BlockSize;
	for(int i=0;i<=BlockCnt;i++){
		BL[i]=max(1,BlockSize*i),BR[i]=min(n,BlockSize*(i+1)-1);
		sort(v+BL[i],v+BR[i]+1);
	}
	for(int i=0;i<=BlockCnt;i++){
		A[i][i]=INF;
		for(int j=BL[i];j<BR[i];j++)A[i][i]=min(A[i][i],abs(v[j].val-v[j+1].val));
		for(int j=0;j<=BlockCnt;j++)if(i^j){
			A[i][j]=INF;
			int p1=BL[i],p2=BL[j];
			for(int k=BL[i];k<=BR[i];k++)C[k]=INF;
			while(p1<=BR[i]&&p2<=BR[j]){
				A[i][j]=min(A[i][j],abs(v[p1].val-v[p2].val));
				C[v[p1].pos]=min(C[v[p1].pos],abs(v[p1].val-v[p2].val));
				if(p2==BR[j]||abs(v[p1].val-v[p2].val)<abs(v[p1].val-v[p2+1].val))++p1;else ++p2;
			}
			D[i][0][j]=C[BL[i]],E[i][BR[i]-BL[i]][j]=C[BR[i]];
			for(int k=BL[i]+1;k<=BR[i];k++)D[i][k-BL[i]][j]=min(D[i][k-BL[i]-1][j],C[k]);
			for(int k=BR[i]-1;k>=BL[i];k--)E[i][k-BL[i]][j]=min(E[i][k-BL[i]+1][j],C[k]);
		}
	}
	for(int i=0;i<=BlockCnt;i++){
		B[i][i]=A[i][i];
		for(int j=i+1;j<=BlockCnt;j++){
			B[i][j]=B[i][j-1];
			for(int k=j;k>=i;k--)B[i][j]=min(B[i][j],A[k][j]);
			B[j][i]=B[i][j];
		}
	}
	for(int i=1,l,r,ans;i<=m;i++){
		l=read(),r=read(),ans=INF;
		int bl=l/BlockSize,br=r/BlockSize;
		if(bl+1<br)ans=B[bl+1][br-1];
		for(int j=bl+1;j<br;j++)ans=min(ans,min(E[bl][l-BL[bl]][j],D[br][r-BL[br]][j]));
		if(bl<br){
			int p1=BL[bl],p2=BL[br];
			while(p1<=BR[bl]&&p2<=BR[br]){
				if(v[p1].pos<l){++p1;continue;}
				if(v[p2].pos>r){++p2;continue;}
				ans=min(ans,abs(v[p1].val-v[p2].val));
				if(v[p1].val<v[p2].val)++p1;else ++p2;
			}
		}
		for(int from=INF*2,p1=BL[bl];p1<=BR[bl];p1++)if(v[p1].pos>=l&&v[p1].pos<=r)ans=min(ans,abs(from-v[p1].val)),from=v[p1].val;
		if(bl!=br)for(int from=INF*2,p1=BL[br];p1<=BR[br];p1++)if(v[p1].pos>=l&&v[p1].pos<=r)ans=min(ans,abs(from-v[p1].val)),from=v[p1].val;
		printf("%d\n",ans);
	}
	return 0;
}

