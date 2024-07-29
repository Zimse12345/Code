#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n;

signed main(){
    cin>>T;
    while(T--){
        cin>>n;
        if(n==3)printf("2\n1 2 2\n");
        else if(n==4)printf("3\n1 2 2 3\n");
        else if(n==5)printf("3\n1 2 2 3 3\n");
        else{
            printf("%d\n",min(n,4));
            for(int i=1;i<=n;i++)printf("%d ",(i-1)%4+1);
            printf("\n");
        }
    }
    return 0;
}


