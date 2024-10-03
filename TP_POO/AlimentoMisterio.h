//
// Created by David on 07/01/2023.
//

#ifndef TP_POO_ALIMENTOMISTERIO_H
#define TP_POO_ALIMENTOMISTERIO_H


#include "Alimento.h"

class AlimentoMisterio: public Alimento{
public:
    AlimentoMisterio(Reserva &reserva, int x, int y);
    Alimento* duplica();
    ~AlimentoMisterio() override;

    void passaInstante();
    void desapareceAlimentoMisterio();

private:
    int nasceInstante;
};



#endif //TP_POO_ALIMENTOMISTERIO_H
