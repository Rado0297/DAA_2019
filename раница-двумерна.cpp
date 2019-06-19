#include<iostream>
#include<utility>
#include<iomanip>
using namespace std;
int n, m, b;
pair<int, double>a[1024];
bool c[1024][1024];
double s[1024], maxi=-1;

int main ()
{
    cin>>n>>m;
    for(int i=0; i<n; i++){
        cin>>a[i].first>>a[i].second;                               //въвеждаме си елементите - тяхното тегло и цена
    }

    for(int i=1; i<=m; i++){                                        //за всички възможни тегла от 1 до M
        for(int j=0; j<n; j++){                                     //обикаляме предметите
            b=a[j].first;
            if(i>=b && s[i-b]+a[j].second>s[i] && c[i-b][j]==0){    //ако тежестта на предмета е по-малко от допустимото, добавянето му към раницата ще увеличи цената и предметът не е използвав
                s[i]=s[i-b]+a[j].second;                            //сумираме
                for(int h=0; h<n; h++)c[i][h]=c[i-b][h];            //и отбелязваме кои предмети сме използвали, за да получим сумата
                c[i][j]=1;                                          //отбелязваме предмета като използван
            }
        }
        if(s[i]>maxi)maxi=s[i];                                     //ако сумата е по-голяма от максималната, я приемаме за максимална
    }
    cout<<maxi<<endl;                                               //печатаме максималната сума

    return 0;
}
