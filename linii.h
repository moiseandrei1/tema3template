//
// Created by Moise on 5/21/2024.
//

#ifndef OOP_LINII_H
#define OOP_LINII_H
#include <iostream>
using namespace std;
class linii{
private:
    std::pair <int, int> p[11][6];
public:
    std::pair<int, int> getnext(int a, int b);
    void generarelinii();
};


#endif //OOP_LINII_H
