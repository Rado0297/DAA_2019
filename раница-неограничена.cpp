#include<iostream>
#include<algorithm>
#define INF 999999
using namespace std;
int dp[5100], s, n, a[3100];
bool flag;


int main ()
{
    cin>>s>>n;
    for(int i=0; i<n; i++)cin>>a[i];
    for(int i=0; i<=s; i++)dp[i]=INF;                   //�������� �� ����� �� ��������� ����� ����
    dp[0]=0;                                            //���� 0 �� ������� � 0 ��������
    dp[1]=1;                                            //� ���� 1 - � ����
    for(int i=1; i<=s; i++){                           // ��������� ������ ����
       for(int j=0; j<n; j++){                          //�� ����� ���� �������
            if(dp[i-a[j]]+1<dp[i] && i-a[j]>=0)         //����������� ���� ����� �� ��������� ���������� ���� � ���� ������� � ���� ���� � ��������� �������
                dp[i]=dp[i-a[j]]+1;                     //��� ���� � ����, ������������
        }

    }
    cout<<dp[s]<<endl;



    return 0;
}

