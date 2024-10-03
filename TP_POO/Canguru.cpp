
#include "Canguru.h"
#include "Reserva.h"

//TODO: fazer canguru
Canguru::Canguru(Reserva &reserva, int x, int y) : Animal('G', 10, 0, Configuracao::getSCanguru(),
                                                                              Configuracao::getPCanguru(),
                                                                              Configuracao::getVCanguru(),
                                                                              reserva, x, y) {
    especie = "Canguru";

    vN = 15;
    vT = 5;
}

Animal *Canguru::duplica() {
    return new Canguru(*this);
}

Canguru::~Canguru() noexcept = default;

void Canguru::passaInstante() {

    duracaoVida--;
    if (duracaoVida > 60) {
        deslocaCanguru(4);
    } else
        deslocaCanguru(1);

    if (duracaoVida >= 50) {
        peso = 20;
    }

    if (duracaoVida == 0) {
        morreCanguru();
    }
    if (duracaoVida == 40 || duracaoVida == 10) {
        reproduzCanguru();
    }
}

void Canguru::deslocaCanguru(int valor) {
    int direcao, horizontal, vertical;


    //ALEATORIO

    horizontal = valor;
    vertical = valor;

    direcao = rand() % 2;
    if (direcao == 0) {
        horizontal = -horizontal;
    }
    direcao = rand() % 2;
    if (direcao == 0) {
        vertical = -vertical;
    }

    reserva.removeAnimalReserva(id);

    x += horizontal;
    y += vertical;
    reserva.verificaCoordenadas(x, y);

    reserva.getZonas().at(x).at(y)->adicionaAnimal(this);

}

void Canguru::reproduzCanguru() {
    int novoX, novoY, pos;

    pos = (rand() % 9) - 4;
    novoX = x + pos;
    novoY = y + pos;

    reserva.verificaCoordenadas(novoX, novoY);

    reserva.adicionaAnimalReserva('g', novoX, novoY);
}


void Canguru::morreCanguru() {
    reserva.mataAnimalReserva(id);
}


string Canguru::getAsString() const {
    ostringstream oss;

    oss << Animal::getAsString();
    oss << "Especie: " << especie << endl;
    oss << "Duracao de Vida: " << duracaoVida << endl;
    oss << "Peso: " << peso << endl;
    oss << "Saude: " << saude << endl;
    oss << "Fome: " << fome << endl;

    return oss.str();
}





