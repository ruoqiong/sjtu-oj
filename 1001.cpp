#include<iostream>
using namespace std;
int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    int d[c];
    int i,j;
    j=0;
    for(i=0;i<c;i++){
        cin>>d[c];
        if(d[c]<=a+b){
            j++;
        }
    }
    cout<<j;
    return 0;
}
