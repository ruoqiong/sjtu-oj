#include<iostream>
using namespace std;
int main()
{
    unsigned int U,F,D;
    int M,T,i,n=0;
    cin>>M>>T>>U>>F>>D;
    char l[T];
    for(i=0;i<T;i++){
        cin>>l[i];
    }
    for(i=0;i<T;i++){
        if(l[i]=='u'||l[i]=='d')
            n=n+U+D;
        else
            n=n+2*F;
        if(n>M){
            cout<<i;
            break;
        }
    }
    if(n<M){
        cout<<T;
    }
    return 0;
}
