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
    for(int i=0; i<=s; i++)dp[i]=INF;                   //отначало не можем да постигнем никоя сума
    dp[0]=0;                                            //сума 0 се постига с 0 елемента
    dp[1]=1;                                            //а сума 1 - с един
    for(int i=1; i<=s; i++){                           // обхождаме всички суми
       for(int j=0; j<n; j++){                          //за всеки един елемент
            if(dp[i-a[j]]+1<dp[i] && i-a[j]>=0)         //проверяваме дали можем да достигнем въпросната сума с този елемент и дали това е оптимално решение
                dp[i]=dp[i-a[j]]+1;                     //ако това е така, оптимизираме
        }

    }
    cout<<dp[s]<<endl;



    return 0;
}

