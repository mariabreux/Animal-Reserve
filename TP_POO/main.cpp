#include <iostream>
#include "utils.h"
#include "Reserva.h"
#include "Simulador.h"

int main() {
    int linhas, colunas;

    Simulador::iniciaReserva(&linhas, &colunas);
    Reserva r(linhas, colunas);
    Simulador s(r);
    s.escolheComando();

    return 0;
//TODO: canguru, store/restore, destrutores, organizar codigo
}

