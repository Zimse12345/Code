#include <cstdio>
#include <cstring>
#include <map>
#include <cmath>

using namespace std;

const long double d=0.9;
const int N=2048;
int n,a[N][N];
long double f[N][N],outdeg[N];

signed main(){
	scanf("%d",&n);
	long double nn=n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
			outdeg[i]+=a[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)if(a[j][i]){
			f[i][j]-=d/outdeg[j];
		}
		f[i][i]+=1.0;
		f[i][n+1]=(1.0-d)/nn;
	}
	for(int i=1;i<=n;i++){
		int t=0;
		for(int j=i;j<=n;j++)if(abs(f[j][i])>1e-9){t=j;break;}
		for(int j=1;j<=n+1;j++)swap(f[i][j],f[t][j]);
		for(int j=1;j<=n;j++)if(j!=i){
			long double p=f[j][i]/f[i][i];
			for(int k=1;k<=n+1;k++)f[j][k]-=p*f[i][k];
		}
		for(int j=1;j<=n+1;j++)if(j!=i)f[i][j]/=f[i][i];
		f[i][i]=1;
	}
	for(int i=1;i<=n;i++)printf("%.6lf\n",double(f[i][n+1]));
	return 0;
}

