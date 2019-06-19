#include<iostream>
using namespace std;
int n, b[1024];

int main ()
{
    cin>>n;                                 //търсим низ с дължина n
    b[1]=2;                                 //възможните варианти са (1) и (0)
    for(int i=2; i<=n; i++)b[i]=2*b[i-1];   //можем да добавим към всеки низ 1 или 0
    cout<<b[n]<<endl;                       //отговорът е в b[n]

    return 0;
}

//низ от n знака от 1 и 0 без ограничения
