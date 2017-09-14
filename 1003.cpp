#include<iostream>
using namespace std;
int main()
{
    int L,W,r,a,b;
    cin>>L>>W;
    int m[L][W];
    int i,j;
    for(i=0;i<L;i++){
        for(j=0;j<W;j++){
            cin>>m[i][j];
        }
    }
    cin>>a>>b;

    int sum,s;
    s=0;
    for(i=0;i<=(L-a);i++){
        for(j=0;j<=(W-b);j++){
            int k,h;
            sum=0;
            for(k=i;k<i+a;k++){
                for(h=j;h<j+b;h++){
                    sum=sum+m[k][h];
                }
            }
            if(s<sum){
                s=sum;
            }
        }
    }
    cout<<s;
    return 0;
}
