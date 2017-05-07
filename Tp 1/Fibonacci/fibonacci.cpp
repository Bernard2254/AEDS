#include <iostream>
#include <stdio.h>

using namespace std;

int calls;

int call(int n){
 calls++;
    if(n==0)
        return 1;
    if(n==1)
        return 1;
    return call(n-1)+call(n-2);
}

int main()
{
    long fibs;
    int n,f;
    cin>>n;
    for(int i=0;i<n;i++){
        fibs=0;
        int minus1=1;
        int minus2=1;
        cin>>f;
        for(int j=0;j<f;j++){
            if(j!=1)
                fibs+=minus1;
            minus1=minus2;
            minus2=fibs;
        }
        calls=0;
        call(f);
        printf("fib(%d) = %d calls = %ld\n",f,calls-1,fibs);
    }


    return 0;
}