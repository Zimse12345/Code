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

const int N=1e4+7,Mod=998244353,INF=1e9+7;
int A[N];

int Partition(int l,int r){
    int i=l,j=r,m=(l+r)/2;
    int pivot=A[m];
    A[m]=A[i];
    while(i<j){
        while(i<j&&A[j]>pivot)j--;
        if(i<j)A[i]=A[j];
        while(i<j&&A[i]<pivot)i++;
        if(i<j)A[j]=A[i];
    }
    A[i]=pivot;
    return i;
}

void QuickSort(int l,int r,int h){
    if(h>1&&l<r){
        int m=Partition(l,r);
        QuickSort(l,m-1,h-1);
        QuickSort(m+1,r,h-1);
    }
    return;
}

signed main(){
    int n=read(),k=read();
    for(int i=1;i<=n;i++)A[i]=read();
    QuickSort(1,n,5);
    for(int i=1;i<=n;i++)printf("%d ",A[i]);
    printf("\n");
    return 0;
}
