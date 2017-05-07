#include <iostream>

using namespace std;

int abs(int n){
    if(n<0)
        return -n;
    return n;
}

int main(){
    int n,i,c,mino,wine[100001],buyers[100001],sellers[100001],sizeB,sizeS;
    long long work;
    while(cin>>n,n){
        sizeS=0;
        sizeB=0;
        work=0;
        for(i=0;i<n;i++){
            cin>>wine[i];
            if(wine[i]<0)
                sellers[sizeS++]=i;
            else
                buyers[sizeB++]=i;
        }
        for(c=0;c<sizeB;){
            for(i=0;i<sizeS;i++){
                if(-wine[sellers[i]]<wine[buyers[c]])
                    mino=-wine[sellers[i]];
                else
                   mino=wine[buyers[c]];
                wine[sellers[i]]+=mino;
                wine[buyers[c]]-=mino;
                work+=abs(buyers[c]-sellers[i])*mino;
                if(wine[sellers[i]]==0){
                  sizeS--;
                  for(n=i;n<sizeS;n++)
                    sellers[n]=sellers[n+1];
                  i--;
                }
                if(wine[buyers[c]]==0){
                    c++;
                    break;
                }
            }
        }
        cout<<work<<endl;
    }
    return 0;
}
