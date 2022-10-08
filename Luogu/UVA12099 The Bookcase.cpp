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

const int N=2400,INF=1e9+7;
struct book{
    int h,t;
    book(int h=0,int t=0):h(h),t(t){}
    bool operator < (const book& A)const{return h>A.h;}
}a[N];
int T,n,f[N][N],g[N][N],ans,s;

int main(){
	T=read();
	while(T--){
		ans=INF,n=read();
    	for(int i=1,h,t;i<=n;i++)h=read(),t=read(),a[i]=book(h,t);
    	sort(a+1,a+n+1);
    	for(int l=0;l<=1200;l++)for(int r=0;r<=1200;r++)f[l][r]=INF;
    	f[a[1].t][0]=a[1].h,s=a[1].t;
    	for(int i=2;i<=n;i++){
        	for(int l=0;l<=1200;l++)for(int r=0;r<=1200;r++)g[l][r]=f[l][r],f[l][r]=INF;
        	for(int l=0;l<=1200;l++)for(int r=0;r<=1200;r++){
        	    if(g[l][r]>=INF)continue;
        	    int t=a[i].t;
        	    f[l+t][r]=min(f[l+t][r],g[l][r]);
        	    if(r==0)f[l][r+t]=min(f[l][r+t],g[l][r]+a[i].h);
        	    else f[l][r+t]=min(f[l][r+t],g[l][r]);
        	    if(l+r==s)f[l][r]=min(f[l][r],g[l][r]+a[i].h);
        	    else f[l][r]=min(f[l][r],g[l][r]);
        	}
        	s+=a[i].t;
    	}
    	for(int i=1;i<=1200;i++)for(int j=1;j<=1200;j++){
    		if(i+j==s||f[i][j]>=INF)continue;
    		ans=min(ans,max(max(i,j),s-i-j)*f[i][j]);
		}
		printf("%d\n",ans);
	}
    return 0;
}

