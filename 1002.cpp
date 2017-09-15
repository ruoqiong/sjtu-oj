//采用前缀和的思想
#include<iostream>
using namespace std;
int main()
{
    int L,W,r,a,b;
    cin>>L>>W;
    int m[L][W],s[L][W];
    int i,j;
    for(i=0;i<L;i++){
        for(j=0;j<W;j++){
            cin>>m[i][j];
            if(i==0&&j==0)
                s[i][j]=m[i][j];
            else if(i>0&&j==0)
                s[i][j]=s[i-1][j]+m[i][j];
            else if(j>0&&i==0)
                s[i][j]=s[i][j-1]+m[i][j];
            else
                s[i][j]=s[i][j-1]+m[i][j]+s[i-1][j]-s[i-1][j-1];
        }
    }
    cin>>a>>b;
    int temp,result=0;
    for(i=0;i<=L-a;i++){
        for(j=0;j<=W-b;j++){
            if(i==0&&j==0)
                temp=s[a+i-1][b+j-1];
            else if(i>0&&j>0)
                temp=s[a+i-1][b+j-1]-s[a+i-1][j-1]-s[i-1][b+j-1]+s[i-1][j-1];
            else if(i==0&&j>0)
                temp=s[a+i-1][b+j-1]-s[a+i-1][j-1];
            else
                temp=s[a+i-1][b+j-1]-s[i-1][b+j-1];
            if(result<temp)
                result=temp;
        }
    }
    cout<<result;
    return 0;
}
