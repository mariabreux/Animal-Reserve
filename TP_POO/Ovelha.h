#ifndef TP_POO_OVELHA_H
#define TP_POO_OVELHA_H

#include "utils.h"
#include "Animal.h"

class Ovelha : public Animal{
public:
    Ovelha(Reserva &reserva, int x, int y);
    ~Ovelha() override;
    Animal* duplica();

    void passaInstante();

    void deslocaOvelha(int valor);
    void morreOvelha();
    void comeAlimento(Alimento *alimento);
    bool reproduzOvelha();
    string getAsString() const override;


};


#endif //TP_POO_OVELHA_H
