#include <bits/stdc++.h>
using namespace std;

const int N=1.01e3;
int n,a[N][N],_a[N][N],c[N*2],x[N*2],y[N*2],A[N],B[N],p[N*2],_q[N*2],q[N*2];

signed main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1,v;j<=n;j++){
            cin>>v;
            a[i][j]=v;
            ++c[v];
            if(!x[v])x[v]=i,y[v]=j;
        }
    }
    for(int i=1;i<=n*2;i++){
        if(!A[c[i]])A[c[i]]=i;
        else B[c[i]]=i;
        q[i]=i;
    }
    p[A[n]]=n;
    for(int i=1;i<n;i++){
        if(x[A[i]]>x[B[i]]||(x[A[i]]==x[B[i]]&&y[A[i]]>y[B[i]])){
            p[A[i]]=n*2-i;
            p[B[i]]=i;
        }
        else{
            p[A[i]]=i;
            p[B[i]]=n*2-i;
        }
    }
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)a[i][j]=p[a[i][j]];
    for(int i=1;i<=n;i++){
        int t=0;
        for(int j=1;j<=n;j++)if(a[i][j]==1)t=1;
        if(!t)continue;
        for(int j=1;j<=n;j++)if(a[i][j]>n){
            int v=a[i][j];
            swap(q[v],q[n*2-v]);
        }
        break;
    }
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)_a[i][j]=a[i][j];
    for(int i=1;i<=n*2;i++)_q[i]=q[i],q[i]=i;
    swap(q[1],q[n*2-1]);
    for(int i=1;i<=n;i++){
        int t=0;
        for(int j=1;j<=n;j++)if(q[a[i][j]]==1)t=1;
        if(!t)continue;
        for(int j=1;j<=n;j++)if(q[a[i][j]]>n){
            int v=a[i][j];
            swap(q[v],q[n*2-v]);
        }
        break;
    }
    int tag=1,ttag=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(q[a[i][j]]<_q[_a[i][j]]){
                tag=0,ttag=1;
                break;
            }
            if(q[a[i][j]]>_q[_a[i][j]]){
                tag=1,ttag=1;
                break;
            }
        }
        if(ttag)break;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(tag)printf("%d",_q[_a[i][j]]+1);
            else printf("%d",q[a[i][j]]+1);
            if(j<n)printf(" ");
        }
        if(i<n)printf("\n");
    }
    return 0;
}
