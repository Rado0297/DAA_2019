#include<iostream>
using namespace std;
int n, b[1024];

int main ()
{
    cin>>n;
    b[1]=1;
    b[2]=3;
    for(int i=3; i<=n; i++)b[i]=b[i-1]+b[i-2];  //формула на Фибоначи
    cout<<b[n]<<endl;


    return 0;
}

//низ от n знака от 1 и 0 без две единици в съседство една до друга
