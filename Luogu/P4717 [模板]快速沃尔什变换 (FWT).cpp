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

const int N=1024*1024,Mod=998244353;
int n,A[N],B[N],a[N],b[N];

void re(){
	for(int i=0;i<(1<<n);i++)a[i]=A[i],b[i]=B[i];
	return;
}

void mul(){
	for(int i=0;i<(1<<n);i++)a[i]=(a[i]*b[i])%Mod;
	return;
}

void print_ans(){
	for(int i=0;i<(1<<n);i++)printf("%lld ",(a[i]+Mod)%Mod);
	printf("\n");
	return;
}

void FWT_OR(int* f,int x){
	for(int o=2,k=1;o<=(1<<n);o*=2,k*=2){
		for(int i=0;i<(1<<n);i+=o){
			for(int j=0;j<k;j++){
				(f[i+j+k]+=f[i+j]*x)%=Mod;
			}
		}
	}
	return;
}

void FWT_AND(int* f,int x){
	for(int o=2,k=1;o<=(1<<n);o*=2,k*=2){
		for(int i=0;i<(1<<n);i+=o){
			for(int j=0;j<k;j++){
				(f[i+j]+=f[i+j+k]*x)%=Mod;
			}
		}
	}
	return;
}

void FWT_XOR(int* f,int x){
	for(int o=2,k=1;o<=(1<<n);o*=2,k*=2){
		for(int i=0;i<(1<<n);i+=o){
			for(int j=0;j<k;j++){
				(f[i+j]+=f[i+j+k])%=Mod;
				(f[i+j+k]+=f[i+j]-f[i+j+k]*3)%=Mod;
				(f[i+j]*=x)%=Mod;
				(f[i+j+k]*=x)%=Mod;
			}
		}
	}
	return;
}

signed main(){
	n=read();
	for(int i=0;i<(1<<n);i++)A[i]=read();
	for(int i=0;i<(1<<n);i++)B[i]=read();
	re(),FWT_OR(a,1),FWT_OR(b,1),mul(),FWT_OR(a,-1),print_ans();
	re(),FWT_AND(a,1),FWT_AND(b,1),mul(),FWT_AND(a,-1),print_ans();
	re(),FWT_XOR(a,1),FWT_XOR(b,1),mul(),FWT_XOR(a,499122177),print_ans();
	return 0;
}

