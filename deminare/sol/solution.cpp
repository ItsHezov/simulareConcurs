#include <fstream>
using namespace std;
ifstream cin("deminare.in");
ofstream cout("deminare.out");
int v[501][501],n,m;

int solve(int iSize,int jSize)
{
    int current = 0 , maxi = 0;
    for(int i = iSize;i<=n;i++)
        for(int j = jSize;j<=m;j++)
        {
            current = v[i][j] - v[i-iSize][j] - v[i][j-jSize] + v[i-iSize][j-jSize];
            if(current>maxi)
                maxi = current;
        }
    return maxi;
}

int main()
{
    int cerinta, mine,lin,col;
    cin>>cerinta>>n>>m>>mine;
    if(cerinta==1)
    {
        int maxi = 0,v1[501]={0};
        for(int i = 1;i<=mine;i++)
        {
            cin>>lin>>col;
            v1[lin]++;
            if(v1[lin]>maxi)
                maxi = v1[lin];
        }
        for(int i = 1;i<=n;i++)
            if(v1[i] == maxi)
                cout<<i<<' ';
    }
    if(cerinta==2)
    {
    for(int i = 1;i<=mine;i++)
    {
       cin>>lin>>col;
       v[lin][col] = 1;
    }
       bool valid = false;
       for(int d = 1;d<=mine/d;d++)
       {
           if(mine%d==0)
           {
               if((mine/d<=n&&d<=m)||(d<=n&&mine/d<=m))
                    valid = true;
           }
       }
       if(!valid)
       {
           cout<<-1;
           return 0;
       }
       ///Construim suma partiala pe matrice
       for(int i = 1;i<=n;i++)
        for(int j = 1;j<=m;j++)
            v[i][j]+=v[i-1][j]+v[i][j-1]-v[i-1][j-1];
       ///Verificam toate submatricile valide si o gasim pe
       /// cea cu cele mai multe mine.
       int current = 0 , maxi = 0;
       for(int d = 1;d<=mine/d;d++)
        if(mine%d==0)
        {
           if(mine/d<=n&&d<=m)
           {
               current = solve(mine/d,d);
               if(current>maxi)
                maxi = current;
           }
           if(d<=n&&mine/d<=m)
           {
               current = solve(d,mine/d);
               if(current>maxi)
                maxi = current;
           }
        }
        cout<<mine - maxi<<'\n';
    }
    return 0;
}
