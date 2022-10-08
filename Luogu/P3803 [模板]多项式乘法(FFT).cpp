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

const int N=1.5e6+7;
const double Pi=acos(-1);
int n,m;

struct CP{
	double x,y;
	CP(double x=0,double y=0):x(x),y(y){}
	CP operator + (const CP& A)const{return CP(x+A.x,y+A.y);}
	CP operator - (const CP& A)const{return CP(x-A.x,y-A.y);}
	CP operator * (const CP& A)const{return CP(x*A.x-y*A.y,x*A.y+y*A.x);}
}f[N*2],p[N*2],sav[N*2];

void fft(CP *f,int len,int tag){
	if(len==1)return;
	CP *fl=f,*fr=f+len/2;
	for(int k=0;k<len;k++)sav[k]=f[k];
	for(int k=0;k<len/2;k++)fl[k]=sav[k*2],fr[k]=sav[k*2+1];
	fft(fl,len/2,tag),fft(fr,len/2,tag);
	CP tG(cos(2.0*Pi/len),tag*sin(2.0*Pi/len)),buf(1,0);
	for(int k=0;k<len/2;k++){
		sav[k]=fl[k]+buf*fr[k];
		sav[k+len/2]=fl[k]-buf*fr[k];
		buf=buf*tG;
	}
	for(int k=0;k<len;k++)f[k]=sav[k];
	return;
}

signed main(){
	n=read(),m=read();
	for(int i=0;i<=n;i++)scanf("%lf",&f[i].x);
	for(int i=0;i<=m;i++)scanf("%lf",&p[i].x);
	for(m+=n,n=1;n<=m;n<<=1);
	fft(f,n,1),fft(p,n,1);
	for(int i=0;i<n;i++)f[i]=f[i]*p[i];
	fft(f,n,-1);
	for(int i=0;i<=m;i++)printf("%d ",int(f[i].x/n+0.49));
	return 0;
}

