#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string x, y,a[128][128];
int n, m, dp[128][128];

int main ()
{
    cin>>x>>y;
    n=x.size();
    m=y.size();

    for(int i=0; i<=n; i++)dp[i][0]=0;
    for(int j=0; j<=m; j++)dp[0][j]=0;

    for(int i=1; i<=n; i++){                                        //������� ������ �� ������ ������� �� ���������+1 (�� �� ����� �� ������� � ��������-1)
        for(int j=1; j<=m; j++){                                    //������� ������
            if(x[i-1]==y[j-1]){                                     //��� ���������� �������� �� �����
                dp[i][j]=dp[i-1][j-1]+1;                            //����������� ��������
                a[i][j]=a[i-1][j-1]+x[i-1];                         //� �������� ����� ��� ��������
            }
            else {                                                  //��� �� ��������, dp[i][j] � ����� �� ��-�������� ������
                if(dp[i-1][j]>dp[i][j-1]){
                    dp[i][j]=dp[i-1][j];
                    a[i][j]=a[i-1][j];
                }
                else {dp[i][j]=dp[i][j-1]; a[i][j]=a[i][j-1];}
            }
        }
    }

    cout<<dp[n][m]<<endl;
    cout<<a[n][m]<<endl;
    return 0;
}
