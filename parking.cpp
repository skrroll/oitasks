#include <bits/stdc++.h>
#define maxn 105
#define maxm 2009
using namespace std;

long long ceny[maxn];
long long masa[maxm];
long long gdzie[maxm];
bool odw[maxm];
queue <long long> q;
long long n, m, a;
long long wynik;

int main()
{
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        cin>>ceny[i];
    }
    for(int i=1; i<=m; i++)
    {
        cin>>masa[i];
    }

    for(int i=0; i<2*m; i++)
    {
        cin>>a;
        if(a>0)
        {
            for(int j=1; j<=n; j++)
            {
                if(!odw[j])
                {
                    wynik+=(long long)masa[a]*(long long)ceny[j];
                    odw[j]=true;
                    gdzie[a]=j;
                    break;
                }
                else if(j==n)
                {
                    q.push(a);
                }
            }
        }
        else
        {
            odw[gdzie[-1*a]]=false;
            if(!q.empty())
            {
                odw[gdzie[-1*a]]=true;
                wynik+=(long long)ceny[gdzie[-1*a]]*(long long)masa[q.front()];
                gdzie[q.front()]=gdzie[-1*a];
                q.pop();
            }
        }
    }

    cout<<wynik;
    return 0;
}
