#ifndef TP_POO_LOBO_H
#define TP_POO_LOBO_H

#include "utils.h"
#include "Animal.h"

class Lobo : public Animal{
public:
    Lobo(Reserva &reserva, int x, int y);
    Animal* duplica();
    ~Lobo() override;

    void passaInstante();

    void deslocaLobo(int valor);
    void morreLobo();
    void comeAlimento(Alimento *alimento);
    bool reproduzLobo();
    void mataAnimal(Animal* animal);
    void lutaAnimal(Animal *animal);
    string getAsString() const override;

private:
    int instante;

};


#endif //TP_POO_LOBO_H
