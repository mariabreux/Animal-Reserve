
#ifndef TP_RELVA_H
#define TP_RELVA_H

#include "Alimento.h"

class Relva:public Alimento {

public:
    Relva(Reserva &reserva, int x, int y);
    Alimento* duplica();
    ~Relva() override;

    void passaInstante();
    bool nasceRelva();
    void despareceRelva();

private:
    int nasceInstante;

};


#endif //TP_RELVA_H
