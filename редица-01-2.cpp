#include<iostream>
using namespace std;
int n, b[1024];

int main ()
{
    cin>>n;
    b[1]=1;
    b[2]=3;
    for(int i=3; i<=n; i++)b[i]=b[i-1]+b[i-2];  //������� �� ��������
    cout<<b[n]<<endl;


    return 0;
}

//��� �� n ����� �� 1 � 0 ��� ��� ������� � ��������� ���� �� �����
