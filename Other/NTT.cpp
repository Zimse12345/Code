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

using namespace std;

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-')qry=-1;qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=4194304,Mod=998244353,G=3;
inline int fpow(int x,int k){int res=1;while(k){if(k&1ll)res=(res*x)%Mod;x=(x*x)%Mod,k/=2;}return res;}
inline int inv(int x){return fpow(x,Mod-2);}

int n,m,A[N],B[N],bitrev[N];

void ntt(int* f,int len,int tag){
    for(int i=0;i<len;i++)if(i<bitrev[i])swap(f[i],f[bitrev[i]]);
    for(int p=2;p<=len;p*=2){
        int a=fpow(G,tag?(Mod-1)/p:(Mod-1)-(Mod-1)/p);
        for(int k=0;k<n;k+=p){
            for(int i=k,aa=1,j;i<k+p/2;i++,aa=(aa*a)%Mod){
                j=aa*f[i+p/2]%Mod;
                f[i+p/2]=f[i]-j;
                if(f[i+p/2]<0)f[i+p/2]+=Mod;
                f[i]+=j;
                if(f[i]>=Mod)f[i]-=Mod;
            }
        }
    }
    return;
}

signed main(){
	n=read()+1,m=read()+1;
	for(int i=0;i<n;i++)A[i]=read();
	for(int i=0;i<m;i++)B[i]=read();
	m+=n-1;
	for(n=1;n<m;n*=2);
    for(int i=0;i<n;i++)bitrev[i]=(bitrev[i/2]/2+((i&1)?n/2:0));
	ntt(A,n,1),ntt(B,n,1);
	for(int i=0;i<n;i++)A[i]=(A[i]*B[i])%Mod;
	ntt(A,n,0);
	for(int i=0;i<m;i++)A[i]=(A[i]*inv(n)%Mod+Mod)%Mod,printf("%lld ",A[i]);
	printf("\n");
	return 0;
}
