//广度搜索问题
#include<iostream>
using namespace std;
int main()
{
    int L;
    cin>>L;
    int a[L][L];
    int x[L*L],y[L*L],m=0;
    int n_x[L*L],n_y[L*L],n=0; //备份，防止被覆盖
    int k=0;
    int d[][2]={{1,0},{0,-1},{-1,0},{0,1}};
    for(int i=0;i<L;i++){
        for(int j=0;j<L;j++){
            cin>>a[i][j];
            if(a[i][j]==1){
                x[m]=i;
                y[m]=j;
                ++m;
            }
        }
    }
    while(1)
    {
        n=0;
        int nx,ny;
        for(int i=0;i<m;i++){
            for(int j=0;j<4;j++){
                nx=x[i]+d[j][0];
                ny=y[i]+d[j][1];
                if(nx<0||ny<0||nx>=L||ny>=L)
                    continue;
                else{
                    if(a[nx][ny]==0){
                        a[nx][ny]=1;
                        n_x[n]=nx;
                        n_y[n]=ny;
                        ++n;
                    }
                }
            }
        }
        if(n<=0) break;
        for(int i=0;i<n;i++){
            x[i]=n_x[i];
            y[i]=n_y[i];
        }
        m=n;
        ++k;
    }
    cout<<k;
    return 0;
}
