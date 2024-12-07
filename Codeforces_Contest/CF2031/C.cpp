#include <bits/stdc++.h>
using namespace std;

const int N=2.01e5;
int T,n;

signed main(){
    cin>>T;
    while(T--){
        cin>>n;
        if(n%2==0){
            for(int i=1;i<=n/2;i++)printf("%d %d ",i,i);
            printf("\n");
        }
        else if(n>26){
            int t=14;
            printf("1 2 2 3 3 4 4 5 5 1 6 6 7 7 9 8 10 11 9 12 10 11 13 12 8 1 13 ");
            for(int i=28;i<=n;i+=2)printf("%d %d ",t,t),++t;
            printf("\n");
        }
        else printf("-1\n");
    }
    return 0;
}


