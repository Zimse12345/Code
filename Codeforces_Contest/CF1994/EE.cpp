#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,k;

signed main(){
    cin>>T;
    while(T--){
        int ans=0,b[30];
        for(int i=0;i<30;i++)b[i]=0;
        
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>k;
            for(int j=1,x=0;j<k;j++)cin>>x;
            for(int i=0;i<=20;i++)if((1<<i)&k)++b[i];
        }
        for(int i=20;i>=0;i--){
            if(b[i])ans|=(1<<i);
            if(b[i]>1)ans|=(1<<i)-1;
        }
        printf("%d\n",ans);
    }
    return 0;
}



