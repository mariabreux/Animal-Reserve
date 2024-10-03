#include "Bife.h"
#include "Reserva.h"
#include "Configuracao.h"

Bife::Bife(Reserva &reserva, int x, int y): Alimento('b', Configuracao::getNBife(),Configuracao::getTBife(),Configuracao::getVBife(),reserva,x,y) {
    tipoAlimento = "Bife";
    cheiro = {"Carne", "Ketchup"};
    consumido = false;
}

Alimento *Bife::duplica() {
    return new Bife(*this);
}

Bife::~Bife() noexcept = default;


void Bife::passaInstante() {
    duracaoVida--;

    desapareceBife();

    if(valorNutritivo == 0)
        valorNutritivo = 0;
    else valorNutritivo--;
}

void Bife::desapareceBife() {
    if(duracaoVida == 0 || consumido){
        reserva.removeAlimentoReserva(id);
    }
}




