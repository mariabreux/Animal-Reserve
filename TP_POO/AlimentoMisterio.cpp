#include "AlimentoMisterio.h"
#include "Reserva.h"
#include "Configuracao.h"

AlimentoMisterio::AlimentoMisterio(Reserva &reserva, int x, int y): Alimento('a',
                                                                             Configuracao::getNAlimentoMisterio(),
                                                                             Configuracao::getTAlimentoMisterio(),
                                                                             Configuracao::getVAlimentoMisterio(),
                                                                             reserva,x,y) {
    tipoAlimento = "Misterio";
    cheiro = {"Misterio","Carne"};
    consumido = false;
}

Alimento *AlimentoMisterio::duplica() {
    return new AlimentoMisterio(*this);
}


AlimentoMisterio::~AlimentoMisterio() noexcept = default;

void AlimentoMisterio::passaInstante() {

    desapareceAlimentoMisterio();

    if (!consumido)
        duracaoVida--;


    if (duracaoVida % 5 == 0) {
        valorNutritivo+=2;
        valorToxico++;
    }
}

void AlimentoMisterio::desapareceAlimentoMisterio() {

    if(duracaoVida == 0 || consumido){
        reserva.removeAlimentoReserva(id);
    }
}

