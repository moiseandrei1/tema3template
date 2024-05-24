#ifndef OOP_VERIF_H
#define OOP_VERIF_H
#include <iostream>
#include <string>
using namespace std;

template <typename S = std::string, typename I = int>
class verif {
private:
    S data;
public:
    explicit verif<S, I>(S str);
    S verificare();
    virtual ~verif() = default;
};

template <typename S, typename I>
verif<S, I>::verif(S str) : data(std::move(str)) {
}

template <typename S, typename I>
S verif<S, I>::verificare() {
    return data;
}

#endif //OOP_VERIF_H