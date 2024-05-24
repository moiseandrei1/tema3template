#include <iostream>
#include <map>
#include <algorithm>
#include "Joc.h"
map <int, int> mp;
pair <int, int> p[2005];
int sortare(pair <int, int> a, pair <int, int> b)
{
    return a.second < b.second;
}

int main() {
    std::cout << "Pentru a juca introduceti 2 inturi (suma initiala de bani, si miza pe care jucati), si pentru a genera un tabel nou\n";
    std::cout << "scrieti un caracter. Daca doriti sa schimbati miza scrieti 'miza' si dupa aceea numarul nou.\n";
    std::cout << "Pentru a opri jocul scrieti stop\n";
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++)
    {
        int a;
        cin >> a;
        mp[a] ++;
    }
    int cnt = 0;
    for(auto it : mp)
    {
        cnt ++;
        p[cnt] = make_pair(it.first, it.second);
    }
    sort(p + 1, p + cnt + 1, sortare);
    for(int i = 1; i <= cnt; i ++)
    {
        cout << "Ai introdus " << p[i].second;
        if(p[i].second == 1)
            cout << " bacnota de ";
        else
            cout << " bacnote de ";
        cout << p[i].first;
        if(p[i].first == 1)
            cout << " leu\n";
        else
            cout << " lei\n";
    }
    int suma2, miza2;
    std::cin >> suma2 >> miza2;
    std::string ss;// Create a verif object with ss
    Joc a(ss, suma2, miza2);
    a.jocul();
    return 0;
}