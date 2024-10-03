#include "Lobo.h"
#include "Reserva.h"
#include "Configuracao.h"

Lobo::Lobo(Reserva &reserva, int x, int y) : Animal('L', 15, 0, Configuracao::getSLobo(), Configuracao::getPLobo(),
                                                    Configuracao::getVLobo(), reserva, x, y) {
    especie = "Lobo";
    instante = 5 + (rand() % 40);

    vN = 10;
    vT = 0;

}

Lobo::~Lobo() noexcept = default;

Animal *Lobo::duplica() {
    return new Lobo(*this);
}

void Lobo::passaInstante() {
    fome += 2;
    if (fome > 15 && fome <= 25) {
        diminuiSaude(1);
        deslocaLobo(2);
    } else
        deslocaLobo(1);

    if (fome > 25) {
        diminuiSaude(2);
    }
    if (saude == 0) {
        morreLobo();
    }

    duracaoVida--;
    if (duracaoVida == instante) {
        reproduzLobo();
    }

}

void Lobo::deslocaLobo(int valor) {
    int direcao, horizontal, vertical;
    int linha, coluna;

    //CHEIRA CARNE
    for (int i = -percecao; i < percecao; i++) {
        for (int j = -percecao; j < percecao; j++) {
            linha = x + i;
            coluna = y + j;
            reserva.verificaCoordenadas(linha, coluna);
            Alimento *alimento = reserva.getZonas().at(linha).at(coluna)->getAlimento();
            if (alimento == nullptr)
                continue;
            for (int k = 0; k < alimento->getCheiro().size(); k++) {
                if (alimento->getCheiro().at(k) == "Carne") {
                    reserva.removeAnimalReserva(id);
                    x = linha;
                    y = coluna;
                    reserva.getZonas().at(x).at(y)->adicionaAnimal(this);
                    comeAlimento(alimento);
                    return;
                }
            }
        }
    }

    //PERSEGUE ANIMAL
    for (int i = -percecao; i < percecao; i++) {
        for (int j = -percecao; j < percecao; j++) {
            linha = x + i;
            coluna = y + j;
            reserva.verificaCoordenadas(linha, coluna);

            vector<Animal *> animais = reserva.getZonas().at(linha).at(coluna)->getAnimais();
            Animal *maiorPeso = procuraMaisPesado(animais);
            reserva.removeAnimalReserva(id);
            if (maiorPeso == nullptr )
                continue;
            else{
                if(maiorPeso->getEspecie() != "Lobo") {
                    if (fome > 15) {
                        if (x - maiorPeso->getX() < 0)
                            x += 3;
                        else
                            x -= 3;
                        if (y - maiorPeso->getY() < 0)
                            y += 3;
                        else
                            y -= 3;
                        reserva.verificaCoordenadas(x, y);
                    } else {
                        if (x - maiorPeso->getX() < 0)
                            x += 2;
                        else
                            x -= 2;
                        if (y - maiorPeso->getY() < 0)
                            y += 2;
                        else
                            y -= 2;
                        reserva.verificaCoordenadas(x, y);
                    }
                }
            }

            reserva.getZonas().at(x).at(y)->adicionaAnimal(this);
            if (maiorPeso->getPeso() < peso)
                mataAnimal(maiorPeso);
            else if (maiorPeso->getPeso() > peso)
                lutaAnimal(maiorPeso);

        }
    }

    //ALEATORIO
    horizontal = valor;
    vertical = valor;

    direcao = rand() % 2;
    if (direcao == 0) {
        horizontal = -horizontal;
    }
    direcao = rand() % 2;
    if (direcao == 0)
        vertical = -vertical;

    reserva.removeAnimalReserva(id);

    x += horizontal;
    y += vertical;
    reserva.verificaCoordenadas(x, y);

    reserva.getZonas().at(x).at(y)->adicionaAnimal(this);

}

void Lobo::mataAnimal(Animal *animal) {

    if (animal->getX() - x == 1 || animal->getX() - x == -1) {
        if (animal->getY() - y == 0) {
            reserva.mataAnimalReserva(animal->getId());
        }
    } else if (animal->getY() - y == 1 || animal->getY() - y == -1) {
        if (animal->getX() - x == 0) {
            reserva.mataAnimalReserva(animal->getId());
        }
    }
}


void Lobo::comeAlimento(Alimento *alimento) {

    aumentaSaude(alimento->getValorNutritivo());
    diminuiSaude(alimento->getValorToxico());
    alimento->setConsumido(true);

}

void Lobo::lutaAnimal(Animal *animal) {
    int morre;

    morre = rand() % 1;
    if (morre == 0) {
        morreLobo();
    } else
        reserva.mataAnimalReserva(animal->getId());

}

bool Lobo::reproduzLobo() {
    int pos, novoX, novoY;

    pos = (rand() % 30) - 15;
    novoX = x + pos;
    novoY = y + pos;

    reserva.verificaCoordenadas(novoX, novoY);

    if (reserva.adicionaAnimalReserva('l', novoX, novoY))
        return true;

    return false;
}

void Lobo::morreLobo() {

    reserva.mataAnimalReserva(id);
}

string Lobo::getAsString() const {
    ostringstream oss;

    oss << Animal::getAsString();
    oss << "Especie: " << especie << endl;
    oss << "Duracao de Vida: " << duracaoVida << endl;
    oss << "Peso: " << peso << endl;
    oss << "Saude: " << saude << endl;
    oss << "Fome: " << fome << endl;

    return oss.str();
}



