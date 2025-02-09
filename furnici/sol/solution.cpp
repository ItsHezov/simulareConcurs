#include <fstream>
using namespace std;
ifstream cin("furnici.in");
ofstream cout("furnici.out");
int main()
{
    int l, n;
    cin >> l >> n;
    int sol = 0;
    for(int i = 1;i<=n;i++)
    {
        int poz; char directie;
        cin >> poz >> directie;
        if(directie == 'S')
            sol = max(sol,poz);
        else sol = max(sol,l - poz);
    }
    cout << sol << '\n';
    return 0;
}
