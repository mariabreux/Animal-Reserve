
#include "Coelho.h"
#include "Reserva.h"

Coelho::Coelho(Reserva &reserva, int x, int y) : Animal('C', 1 + (rand() % 4), 0, Configuracao::getSCoelho(),
                                                        Configuracao::getPCoelho(), Configuracao::getVCoelho(), reserva,
                                                        x, y) {

    especie = "Coelho";

}

Animal *Coelho::duplica() {
    return new Coelho(*this);
}

Coelho::~Coelho() noexcept = default;

void Coelho::passaInstante() {
    fome++;


    if (fome > 10 && fome <= 20) {
        diminuiSaude(1);
        deslocaCoelho(3);
    } else if (fome > 20) {
        diminuiSaude(2);
        deslocaCoelho(4);
    } else {
        deslocaCoelho(2);
    }

    duracaoVida--;
    if (duracaoVida == 0 || saude == 0) {
        morreCoelho();
    }

    if (duracaoVida == 6 || duracaoVida == 14 || duracaoVida == 22) {
        reproduzCoelho();
    }

}



void Coelho::deslocaCoelho(int valor) {
    int direcao, horizontal, vertical;
    int linha, coluna;

    //CHEIRA VERDURA
    for (int i = -percecao; i < percecao; i++) {  //linha (lado)
        for (int j = -percecao; j < percecao; j++) {
            linha = x + i;
            coluna = y + j;
            reserva.verificaCoordenadas(linha, coluna);
            Alimento *alimento = reserva.getZonas()[linha][coluna]->getAlimento();
            if (alimento == nullptr)
                continue;
            for (int k = 0; k < alimento->getCheiro().size(); k++) {
                if (alimento->getCheiro().at(k) == "Verdura") {
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
    for (int i = -percecao; i < percecao; i++) {  //linha (lado)
        for (int j = -percecao; j < percecao; j++) {
            linha = x + i;
            coluna = y + j;
            reserva.verificaCoordenadas(linha, coluna);
            vector<Animal *> animal = reserva.getZonas().at(linha).at(coluna)->getAnimais();
            for (auto it: animal) {
                if (it->getPeso() > 10) {
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
        horizontal = -horizontal; //esquerda
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

void Coelho::morreCoelho() {
    reserva.removeAnimalReserva(id);
}

void Coelho::comeAlimento(Alimento *alimento) {
    alimento->setConsumido(true);
    aumentaSaude(alimento->getValorNutritivo());
    diminuiSaude(alimento->getValorToxico());
    fome--;

}

bool Coelho::reproduzCoelho() {
    int nasceu, pos, novoX, novoY;

    nasceu = rand() % 2;

    if (nasceu == 1) {
        pos = (rand() % 20) - 10;   //-10 e 10
        novoX = x + pos;
        novoY = y + pos;

        reserva.verificaCoordenadas(novoX, novoY);

        reserva.adicionaAnimalReserva('c', novoX, novoY);
        return true;
    }
    return false;
}

string Coelho::getAsString() const {
    ostringstream oss;

    oss << Animal::getAsString();
    oss << "Especie: " << especie << endl;
    oss << "Duracao de Vida: " << duracaoVida << endl;
    oss << "Peso: " << peso << endl;
    oss << "Saude: " << saude << endl;
    oss << "Fome: " << fome << endl;

    return oss.str();
}











