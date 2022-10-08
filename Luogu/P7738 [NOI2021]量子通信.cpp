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
inline void write(int x){if(x>10)write(x/10);putchar(x%10+'0');return;}

typedef unsigned long long ull;
const int N = 400001;
int n,m;
ull a1,a2;
bool s[N+1][256],t[256];
int tt[16];
int dic[N+1][16];
int hd[16][65536],nxt[N*16],id[N*16],ec;
inline void add(int ux,int uy,int v){nxt[++ec]=hd[ux][uy],hd[ux][uy]=ec,id[ec]=v;return;}

ull myRand(ull &k1, ull &k2){
    ull k3=k1,k4=k2;
    k1=k4,k3^=(k3<<23);
    k2=k3^k4^(k3>>17)^(k4>>26);
    return k2+k4;
}

void gen(){
    for(int i=1;i<=n;i++)for(int j=0;j<256;j++)s[i][j]=(myRand(a1,a2)&(1ull<<32))?1:0;
    return;
}

int main() {
	n=read(),m=read();
	scanf("%llu%llu",&a1,&a2);
	gen();
	for(int i=1;i<=n;i++){
		for(int j=0,p=0;j<16;j++){
			for(int w=0;w<16;w++)dic[i][j]=(dic[i][j]<<1)+s[i][p++];
			add(j,dic[i][j],i);
		}
	}
	for(int i=1,k,ans=0;i<=m;i++){
		char c=getchar();
		while((c<'0'||c>'9')&&(c<'A'||c>'F'))c=getchar();
		for(int I=0,j=0;I<64;I++){
			int v=c-'0';
			if(c>='A')v=c-'A'+10;
			for(int w=3;w>=0;w--)t[j++]=((v&(1<<w))?1:0)^ans;
			c=getchar();
		}
		k=read(),ans=0;
		for(int j=0,p=0;j<16;j++){
			tt[j]=0;
			for(int w=0;w<16;w++)tt[j]=(tt[j]<<1)+t[p++];
		}
		for(int j=0;j<16;j++){
			for(int eg=hd[j][tt[j]],q;eg;eg=nxt[eg]){
				q=id[eg];
				int ct=0;
				for(int w=0,x;w<16;w++){
					x=dic[q][w]^tt[w];
					while(x)++ct,x-=(x&(-x));
					if(ct>k)break;
				}
				if(ct<=k)ans=1;
				if(ans)break;
			}
			if(ans)break;
		}
		write(ans),putchar('\n');
	}
    return 0;
}

