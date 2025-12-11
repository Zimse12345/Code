#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int n,m,a[N]; 

signed main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    while(m--){
        int ty,x,y;
        scanf("%d%d%d",&ty,&x,&y);
        if(ty==2)y=-y;
        a[x]+=y;
    }
    for(int i=1;i<=n;i++)printf("%d ",a[i]);
    return 0;
}


