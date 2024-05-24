//
// Created by Moise on 5/21/2024.
//

#ifndef OOP_JOC_H
#define OOP_JOC_H
#include <iostream>
#include <string>
#include "generaretablou.h"
#include "linii.h"
#include "verif.h"

using namespace std;

template <typename S = std::string, typename I = int>
class Joc : public verif<S, I> {
private:
    I suma;
    I miza;
public:
    Joc(S a, I suma, I miza);

    Joc& operator=(const Joc& a);
    friend std::ostream &operator << (std::ostream &o, const Joc<int, std::string> &x);
    friend std::istream &operator >> (std::istream &i, Joc<int, std::string> &x);
    friend generaretablou;
    friend linii;
    void jocul();
    ~Joc() = default;
};

template <typename S, typename I>
Joc<S, I>::Joc(S a, I suma, I miza) : verif<S, I>(std::move(a)) {
    this->suma = suma;
    this->miza = miza;
}

template <typename S, typename I>
Joc<S, I>& Joc<S, I>::operator=(const Joc<S, I>& a) {
    if (this != &a) {
        suma = a.suma;
        miza = a.miza;
    }
    return *this;
}

template <typename S, typename I>
std::ostream &operator<<(std::ostream &o, const Joc<S, I> &x) {
    o << x.suma << '\n';
    return o;
}

template <typename S, typename I>
std::istream &operator>>(std::istream &i, Joc<S, I> &x) {
    i >> x.suma;
    return i;
}

template <typename S, typename I>
void Joc<S, I>::jocul() {
    linii p;
    p.generarelinii();
    I miza3 = miza;
    while (suma >= miza3) {
        S caracter;
        std::cin >> caracter;
        verif<S, I>* st = new Joc<S, I>(caracter, 1, 1);
        I ok = 0;
        if (auto strverif = dynamic_cast<verif<S, I>*>(st)) {
            caracter = strverif->verificare();
            ok = 1;
        }
        delete st;
        if (ok == 1) {
            if (caracter == "miza") {
                I y;
                std::cin >> y;
                miza3 = y;
            }
            if (caracter == "stop")
                break;
            suma = suma - miza3;
            generaretablou c{};
            c.generare();
            for (I i = 1; i <= 3; i++) {
                for (I j = 1; j <= 5; j++) {
                    I raspuns = c.get2(i, j);
                    if (raspuns <= 4)
                        std::cout << char(raspuns + 1);
                    if (raspuns == 5)
                        std::cout << char(12);
                    if (raspuns == 6)
                        std::cout << char(14);
                    if (raspuns == 7)
                        std::cout << "7";
                    if (raspuns == 8)
                        std::cout << char(21);
                    if (raspuns == 9)
                        std::cout << char(15);
                    if (raspuns == 10)
                        std::cout << char(127);
                    std::cout << " ";
                }
                std::cout << '\n';
            }
            I plata = 0;
            for (I l = 1; l <= 10; l++) {
                std::pair<I, I> start = p.getnext(l, 1);
                I cnt = 1;
                I simbol = c.get2(start.first, start.second);
                for (I i = 2; i <= 5; i++) {
                    I a = c.get2(start.first, start.second);
                    std::pair<I, I> urm = p.getnext(l, i);
                    I b = c.get2(urm.first, urm.second);
                    if (a == b || a == 10 || b == 10)
                        cnt++;
                    else
                        break;
                }
                if (simbol >= 2 && simbol <= 5) {
                    if (cnt == 3)
                        plata = plata + miza3;
                    if (cnt == 4)
                        plata = plata + 3 * miza3;
                    if (cnt == 5)
                        plata = plata + 6 * miza3;
                }
                if (simbol == 1) {
                    if (cnt == 3)
                        plata = plata + 2 * miza3;
                    if (cnt == 4)
                        plata = plata + 4 * miza3;
                    if (cnt == 5)
                        plata = plata + 10 * miza3;
                }
                if (simbol == 6) {
                    if (cnt == 3)
                        plata = plata + 4 * miza3;
                    if (cnt == 4)
                        plata = plata + 8 * miza3;
                    if (cnt == 5)
                        plata = plata + 17 * miza3;
                }
                if (simbol == 7) {
                    if (cnt == 2)
                        plata = plata + miza3;
                    if (cnt == 3)
                        plata = plata + 5 * miza3;
                    if (cnt == 4)
                        plata = plata + 15 * miza3;
                    if (cnt == 5)
                        plata = plata + 20 * miza3;
                }
                if (simbol == 8) {
                    if (cnt == 3)
                        plata = plata + 4 * miza3;
                    if (cnt == 4)
                        plata = plata + 12 * miza3;
                    if (cnt == 5)
                        plata = plata + 20 * miza3;
                }
            }
            if (plata > 0) {
                std::cout << "Castig: " << plata << ". Dublezi ? (da/nu)\n";
                S s;
                std::cin >> s;
                if (s != "da") {
                    std::cout << "";
                } else {
                    I k = 5;
                    while (k > 0) {
                        std::cout << "rosie sau neagra ? (r/n)\n";
                        char ch;
                        std::cin >> ch;
                        std::random_device rd;
                        std::mt19937 gen(rd());
                        std::uniform_int_distribution<I> dis(0, 1);
                        I raspuns = dis(gen);
                        if (raspuns) {
                            plata = plata * 2;
                            if (ch == 'r')
                                std::cout << "rosie\n";
                            else
                                std::cout << "neagra\n";
                        } else {
                            if (ch == 'r')
                                std::cout << "neagra\n";
                            else
                                std::cout << "rosie\n";
                            plata = 0;
                            break;
                        }
                        std::cout << "continui ? (da/nu)\n";
                        S s2;
                        std::cin >> s2;
                        if (s2 == "nu")
                            break;
                        else
                            k = k - 1;
                    }
                }
            }
            suma = suma + plata;
            std::cout << "Suma: " << suma << " " << "Castig " << plata << '\n';
            std::cout << '\n';
        }
    }
}

#endif // OOP_JOC_H