#include<iostream>
using namespace std;
int n, b[1024];

int main ()
{
    cin>>n;                                 //������ ��� � ������� n
    b[1]=2;                                 //���������� �������� �� (1) � (0)
    for(int i=2; i<=n; i++)b[i]=2*b[i-1];   //����� �� ������� ��� ����� ��� 1 ��� 0
    cout<<b[n]<<endl;                       //��������� � � b[n]

    return 0;
}

//��� �� n ����� �� 1 � 0 ��� �����������
