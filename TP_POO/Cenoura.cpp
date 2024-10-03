#include "Cenoura.h"
#include "Reserva.h"
#include "Configuracao.h"

Cenoura::Cenoura(Reserva &reserva, int x, int y): Alimento('t', Configuracao::getNCenoura(),Configuracao::getTCenoura(),Configuracao::getVCenoura(),reserva,x,y) {
    tipoAlimento = "Cenoura";
    cheiro = {"Verdura"};
    consumido = false;
}

Alimento *Cenoura::duplica() {
    return new Cenoura(*this);
}

Cenoura::~Cenoura() noexcept = default;

void Cenoura::passaInstante() {

    desapareceCenoura();

    if(!consumido){
        duracaoVida++;
    }

    if(duracaoVida % 10 == 0){
        if(valorToxico < 3) {
            valorToxico++;
        }
    }

}

void Cenoura::desapareceCenoura() {

    if(consumido){
        reserva.removeAlimentoReserva(id);
    }
}




