#include "Relva.h"
#include "Reserva.h"
#include "Configuracao.h"

Relva::Relva(Reserva &reserva, int x, int y) : Alimento('r', Configuracao::getNRelva(), Configuracao::getTRelva(),
                                                        Configuracao::getVRelva(), reserva, x, y) {
    tipoAlimento = "Relva";
    cheiro = {"Erva", "Verdura"};
    consumido = false;
    nasceInstante = duracaoVida * 0.75;
}

Alimento *Relva::duplica() {
    return new Relva(*this);
}

Relva::~Relva() noexcept = default;

void Relva::passaInstante() {
    int tentativa = 0;

    despareceRelva();

    duracaoVida--;

    if(duracaoVida <= nasceInstante)
        while(!nasceRelva() && tentativa >= 208){
            tentativa++;
        }

}

bool Relva::nasceRelva() {
    int posX, posY, novoX, novoY;

    posX = 4 + (rand() % 5);
    posY = 4 + (rand() % 5);
    novoX = x + posX;
    novoY = y + posY;

    reserva.verificaCoordenadas(novoX, novoY);

    Alimento *alimento = reserva.getZonas().at(novoX).at(novoY)->getAlimento();
    if (alimento != nullptr)
        return false;
    else {
        reserva.adicionaAlimentoReserva('r', novoX, novoY,0,0);
        return true;
    }
}

void Relva::despareceRelva() {

     if (consumido || duracaoVida == 0) {
         reserva.removeAlimentoReserva(id);
     }
}




