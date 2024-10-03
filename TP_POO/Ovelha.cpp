#include "Ovelha.h"
#include "Reserva.h"
#include "Configuracao.h"


Ovelha::Ovelha(Reserva &reserva, int x, int y) : Animal('O', (rand() % 5) + 4, 0, Configuracao::getSOvelha(),
                                                        Configuracao::getPOvelha(), Configuracao::getVOvelha(), reserva,
                                                        x, y) {

    especie = "Ovelha";
    vN = peso;
    vT = 0;

}

Animal *Ovelha::duplica() {
    return new Ovelha(*this);
}

Ovelha::~Ovelha() noexcept = default;

void Ovelha::passaInstante() {

    fome++;
    if (fome > 15 && fome <= 20) {
        diminuiSaude(1);
        deslocaOvelha(2);
    } else
        deslocaOvelha(1);

    if (fome > 20) {
        diminuiSaude(2);
    }

    duracaoVida--;
    if (duracaoVida == 0 || saude == 0) {
        morreOvelha();
    }

    if (duracaoVida == 20 || duracaoVida == 5) {
        reproduzOvelha();
    }

}

void Ovelha::deslocaOvelha(int valor) {
    int direcao, horizontal, vertical;
    int linha, coluna;

    //CHEIRA ERVA
    for (int i = -percecao; i < percecao; i++) {
        for (int j = -percecao; j < percecao; j++) {
            linha = x + i;
            coluna = y + j;
            reserva.verificaCoordenadas(linha, coluna);

            Alimento *alimento = reserva.getZonas().at(linha).at(coluna)->getAlimento();
            if (alimento == nullptr)
                continue;
            for (int k = 0; k < alimento->getCheiro().size(); k++) {
                if (alimento->getCheiro().at(k) == "Erva") {
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

    //FOGE DO ANIMAL
    for (int i = -percecao; i < percecao; i++) {
        for (int j = -percecao; j < percecao; j++) {
            linha = x + i;
            coluna = y + j;
            reserva.verificaCoordenadas(linha, coluna);
            vector<Animal *> animais = reserva.getZonas().at(linha).at(coluna)->getAnimais();
            for (auto it: animais) {
                if (it->getPeso() > 15) {
                    cout << "A fugir do " << it->getEspecie() << endl;
                    reserva.removeAnimalReserva(id);
                    if (x - it->getX() < 0) {
                        x--;
                    } else {
                        x++;
                    }
                    if (y - it->getY() < 0) {
                        y--;
                    } else {
                        y++;
                    }
                    if (x < 0)
                        x += reserva.getNLinhas();
                    if (y < 0)
                        y += reserva.getNColunas();
                    reserva.getZonas().at(x).at(y)->adicionaAnimal(this);
                    return;
                }
            }
        }
    }


    //ALEATORIO

    horizontal = 1 + (rand() % valor);
    vertical = 1 + (rand() % valor);

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

void Ovelha::morreOvelha() {
    reserva.mataAnimalReserva(id);
}

void Ovelha::comeAlimento(Alimento *alimento) {
    aumentaSaude(alimento->getValorNutritivo());
    diminuiSaude(alimento->getValorToxico());
    alimento->setConsumido(true);
}

bool Ovelha::reproduzOvelha() {
    int pos, novoX, novoY;

    pos = (rand() % 24) - 12;
    novoX = x + pos;
    novoY = y + pos;

    reserva.verificaCoordenadas(novoX, novoY);

    Configuracao::setSOvelha(saude);
    if (reserva.adicionaAnimalReserva('o', novoX, novoY))
        return true;

    return false;
}

string Ovelha::getAsString() const {
    ostringstream oss;

    oss << Animal::getAsString();
    oss << "Especie: " << especie << endl;
    oss << "Duracao de Vida: " << duracaoVida << endl;
    oss << "Peso: " << peso << endl;
    oss << "Saude: " << saude << endl;
    oss << "Fome: " << fome << endl;

    return oss.str();
}




