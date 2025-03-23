#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,x; 

signed main(){
    cin>>T;
    while(T--){
        cin>>n>>x;
        int s=0;
        for(int i=1;i<=n;i++){
            int v=x;
            if((x|(i-1))==x)v=i-1;
            if(i==n&&(s|v)!=x)v=x;
            printf("%d ",v);
            s|=v;
        }
        printf("\n");
    }
    return 0;
}


