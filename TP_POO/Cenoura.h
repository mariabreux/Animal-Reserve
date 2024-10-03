//
// Created by beatr on 29/12/2022.
//

#ifndef TP_CENOURA_H
#define TP_CENOURA_H

#include "Alimento.h"

class Cenoura: public Alimento{
public:
    Cenoura(Reserva &reserva, int x, int y);
    Alimento* duplica();
    ~Cenoura() override;

    void passaInstante();
    void desapareceCenoura();
};


#endif //TP_CENOURA_H
