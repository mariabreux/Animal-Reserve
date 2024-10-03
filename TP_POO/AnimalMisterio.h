
#ifndef TP_POO_ANIMALMISTERIO_H
#define TP_POO_ANIMALMISTERIO_H

#include "Animal.h"
#include "Configuracao.h"

class AnimalMisterio : public Animal {
public:
    AnimalMisterio(Reserva &reserva, int x, int y);
    ~AnimalMisterio() override;
    Animal* duplica();

    void passaInstante();

    void deslocaAnimalMisterio(int valor);
    void morreAnimalMisterio();
    void comeAlimento(Alimento* alimento);
    bool reproduzAnimalMisterio();
    string getAsString() const override;

};


#endif //TP_POO_ANIMALMISTERIO_H
