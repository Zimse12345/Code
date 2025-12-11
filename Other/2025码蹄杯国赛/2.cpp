#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int n,m,a[N]; 

signed main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        if(a[i]!=a[i-1])--m;
        if(m==0){
            printf("%d\n",a[i]);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}


