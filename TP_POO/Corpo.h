#ifndef TP_CORPO_H
#define TP_CORPO_H

#include "Alimento.h"

class Animal;

class Corpo : public Alimento{
public:
    Corpo(Reserva &reserva, int x, int y, int vN, int vT);
    ~Corpo() override;
    Alimento* duplica();

    void passaInstante();
    void desapareceCorpo();

private:
    int valorNutritivoInicial;
    int vN;
    int vT;

};


#endif //TP_CORPO_H
