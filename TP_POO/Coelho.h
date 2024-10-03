#ifndef TP_POO_COELHO_H
#define TP_POO_COELHO_H

#include "Animal.h"
#include "Configuracao.h"

class Coelho : public Animal {
public:
    Coelho(Reserva &reserva, int x, int y);
    Animal* duplica();
    ~Coelho() override;

    void passaInstante();
    //void deslocaAnimal() override;
    void deslocaCoelho(int valor);
    void morreCoelho();
    void comeAlimento(Alimento* alimento);
    bool reproduzCoelho();
    string getAsString() const override;


};


#endif //TP_POO_COELHO_H
