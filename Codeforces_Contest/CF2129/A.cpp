#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,a[N],b[N],t[N]; 

signed main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i]>>b[i];
            t[i]=1;
            for(int j=1;j<i;j++){
                if(a[j]<=a[i]&&b[i]<=b[j])t[i]=0;
                if(a[i]<=a[j]&&b[j]<=b[i])t[j]=0;
            }
        }
        int cnt=0;
        for(int i=1;i<=n;i++)cnt+=t[i];
        printf("%d\n",cnt);
        for(int i=1;i<=n;i++)if(t[i])printf("%d ",i);
        printf("\n"); 
    }
    return 0;
}


