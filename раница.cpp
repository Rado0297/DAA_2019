/*  Основна идея:  Можем да вземем предмети с общо тегло М.
Колко е най-голямата възможна стойност? Кои са те? */
#include<iostream>
#include<utility>
#include<vector>
#define INF 99999
using namespace std;
int n, m, s[1024], maxValue=-1, index;
pair<int, int> a[1024];
vector<vector <bool> > used;

int main ()
{
    cin>>n>>m;
    for(int i=0; i<n; i++)
        cin>>a[i].first>>a[i].second;
        //въвеждаме си теглото и стойността на предметите

    used.resize(m+1);
    used[0].resize(n+1);

    for(int i=1; i<=m; i++){         //за всяко едно тегло
        used[i].resize(n+1);  //преоразмеряваме си всеки вектор
        for(int j=0; j<n; j++){        //за всички предмети
            int price=a[j].first, value=a[j].second;
            if(i>=price && s[i-price]+value>s[i] && used[i-price][j]==0){
            //ако теглото не надвишава текущото, имаме оптимизация и
            //въпросния предмет не е използван до сега
                s[i]=s[i-price]+value;//отпимизираме стойността
                used[i]=used[i-price];//отбелязваме кои предмети сме използвали за постигане на предишното тегло
                used[i][j]=1;//отбелязваме текущия предмет за използван
            }
        }
        if(s[i]>maxValue){
            maxValue=s[i]; //отбелязваме коя е мексималната стойност
            index=i;  //и индекса
        }
    }
    cout<<"Max value = "<<maxValue<<endl;
    for(int i=0; i<n; i++)if(used[index][i]==1)cout<<i+1<<endl; //печатаме индексите на предметите, използвани за сумата

    return 0;
}

/*Пример:
8 70
30 5
15 3
50 9
10 1
20 2
40 7
5 1
65 12
Изход: 13*/
