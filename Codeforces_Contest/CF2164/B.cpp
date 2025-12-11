#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,a[N];

signed main(){
    cin>>T;
    while(T--){
        cin>>n;
        int x=0,y=0,tag=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(a[i]%2==0){
                if(x)y=a[i];
                else x=a[i];
            }
            if(i>1&&(a[i]%a[i-1])%2==0)tag=i;
        }
        if(y){
            printf("%d %d\n",x,y);
        }
        else if(tag){
            printf("%d %d\n",a[tag-1],a[tag]);
        }
        else{
            for(int i=1;i<=n;i++){
                for(int j=i+1;j<=n;j++)if((a[j]%a[i])%2==0){
                    x=a[i],y=a[j];
                    break;
                }
                if(y)break;
            }
            if(y){
                printf("%d %d\n",x,y);
            }
            else{
                printf("-1\n");
            }
        }
    }
    return 0;
}


