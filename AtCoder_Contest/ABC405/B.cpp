#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int n,m,a[N],c[N],s;

signed main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(!c[a[i]])s++;
        c[a[i]]=1;
        if(s==m){
            printf("%d\n",n-i+1);
            return 0;
        }
    }
    printf("0\n");
    return 0;
}


