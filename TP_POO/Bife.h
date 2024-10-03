#ifndef TP_BIFE_H
#define TP_BIFE_H

#include "Alimento.h"

class Bife:public Alimento {
public:
    Bife(Reserva &reserva, int x, int y);
    Alimento* duplica();
    ~Bife() override;

    void passaInstante();
    void desapareceBife();
};


#endif //TP_BIFE_H
