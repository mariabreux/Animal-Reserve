
#ifndef TP_POO_CANGURU_H
#define TP_POO_CANGURU_H

#include "Animal.h"
#include "Configuracao.h"

class Canguru : public Animal {
public:
    Canguru(Reserva &reserva, int x, int y);
    Animal* duplica();
    ~Canguru() override;

    void passaInstante();

    void deslocaCanguru(int valor);
    void morreCanguru();
    void reproduzCanguru();

    string getAsString() const override;



};


#endif //TP_POO_CANGURU_H
