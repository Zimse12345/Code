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

const int N=2e5+7,Mod=998244353,INF=1e9+7;
int n,cnt,a[N],p[N],lmax[N],rmax[N],ans;
char s[N];

signed main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	a[0]='~';
	for(int i=1;i<=n;i++)a[++cnt]='|',a[++cnt]=s[i];
    a[++cnt]='|';
    for(int i=1,r=0,mid=0;i<=cnt;i++){
        if(i<=r)p[i]=min(p[mid*2-i],r-i+1);
        while(a[i-p[i]]==a[i+p[i]])++p[i];
        if(i+p[i]>r)r=i+p[i]-1,mid=i;
    }
    for(int i=1;i<=cnt;i++)lmax[i+p[i]-1]=max(lmax[i+p[i]-1],p[i]*2-1),rmax[i-p[i]+1]=max(rmax[i-p[i]+1],p[i]*2-1);
    for(int i=cnt-1;i>=1;i--)lmax[i]=max(lmax[i],lmax[i+1]-2);
    for(int i=2;i<=cnt;i++)rmax[i]=max(rmax[i],rmax[i-1]-2);
    for(int i=1;i<=cnt;i+=2){
        if(lmax[i]<=1||rmax[i]<=1)continue;
        ans=max(ans,(lmax[i]-1)/2+(rmax[i]-1)/2);
    }
    printf("%d\n",ans);
	return 0;
}
