#include <bits/stdc++.h>
using namespace std;

const int N=1.01e3;
int n,a[N][N];
char s[N][N];

signed main(){
    cin>>n;
    for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int x=s[i][j];
            if(i==1){
                if(j==n)a[2][n]=x;
                else a[1][j+1]=x;
            }
            else if(j==n){
                if(i==n)a[n][n-1]=x;
                else a[i+1][n]=x;
            }
            else if(i==n){
                if(j==1)a[n-1][1]=x;
                else a[n][j-1]=x;
            }
            else if(j==1){
                a[i-1][j]=x;
            }
            else a[i][j]=x;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)putchar(a[i][j]);
        putchar(10);
    }
    return 0;
}


