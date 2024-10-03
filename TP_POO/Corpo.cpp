#include "Corpo.h"
#include "Reserva.h"
#include "Configuracao.h"

Corpo::Corpo(Reserva &reserva, int x, int y, int vN, int vT): Alimento('p', vN, vT, 0, reserva, x, y) {
    cheiro = {"Carne"};
    valorNutritivoInicial = valorNutritivo;
    consumido = false;
}

Alimento *Corpo::duplica() {
    this->valorNutritivoInicial = valorNutritivoInicial;
    return new Corpo(*this);
}

Corpo::~Corpo() noexcept = default;


void Corpo::passaInstante() {

    desapareceCorpo();

    duracaoVida++;
    valorNutritivo--;

    if(duracaoVida < 2*valorNutritivoInicial)
        valorToxico++;
    else
        valorToxico = valorToxico;

}

void Corpo::desapareceCorpo() {
    if(consumido) {
        reserva.removeAlimentoReserva(id);
    }
}




