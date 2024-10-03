
#include "Reserva.h"
#include "Animal.h"
#include "Alimento.h"
#include "Ovelha.h"
#include "Lobo.h"
#include "Canguru.h"
#include "AnimalMisterio.h"
#include "Coelho.h"
#include "Relva.h"
#include "Cenoura.h"
#include "Corpo.h"
#include "Bife.h"
#include "AlimentoMisterio.h"

const int Reserva::minLinhas = 16;
const int Reserva::minColunas = 16;
const int Reserva::maxLinhas = 500;
const int Reserva::maxColunas = 500;

const int Reserva::areaVisivel = 16;

int Reserva::ids = 1;

int Reserva::instante = 1;

Reserva::Reserva(int linhas, int colunas) : nLinhas(linhas), nColunas(colunas), x(0), y(0) {
    criaZonas();

}

Reserva::Reserva(const Reserva &reserva) {
    *this = reserva;
}

Reserva &Reserva::operator=(const Reserva &reserva) {
    if (this == &reserva)
        return *this;

    nLinhas = reserva.nLinhas;
    nColunas = reserva.nColunas;
    zonasReserva.clear();
    for (auto z: reserva.zonasReserva) {
        vector<Zona *> novasZonas;
        for (auto it: z) {
            novasZonas.push_back(it->duplica());
        }
        zonasReserva.push_back(novasZonas);
    }

    instante = reserva.instant;
    ids = reserva.id;
    id = reserva.id;
    instant = reserva.instant;

    return *this;
}

Reserva *Reserva::duplica() {
    id = ids;
    return new Reserva(*this);
}

Reserva::~Reserva() {
    for (int i = 0; i < nLinhas; i++) {
        for (int j = 0; j < nColunas; j++) {
            delete zonasReserva[i][j];
        }
    }
}

bool Reserva::validaDimensoes(int linhas, int colunas) {
    if (linhas < minLinhas || linhas > maxLinhas)
        return false;
    if (colunas < minColunas || colunas > maxColunas)
        return false;

    return true;
}

void Reserva::criaZonas() {

    for (int i = 0; i < this->nLinhas; i++) {
        vector<Zona *> novasZonas;

        for (int j = 0; j < this->nColunas; j++) {
            novasZonas.push_back(new Zona(i + 1, j + 1));
        }
        zonasReserva.push_back(novasZonas);
    }
}

string Reserva::printReserva() {
    ostringstream oss;

    oss << endl << "    |";
    for (int i = getY(); i < getY() + areaVisivel; i++) {
        oss << " " << i;
        if (i < 10)
            oss << "  |";
        else if (i < 100)
            oss << " |";
        else if (i < 1000)
            oss << "|";
    }
    oss << endl;
    for (int i = getX(); i < getX() + areaVisivel; i++) {
        oss << " " << i;
        if (i < 10)
            oss << "  | ";
        else if (i < 100)
            oss << " | ";
        else if (i < 1000)
            oss << "| ";
        for (int j = getY(); j < getY() + areaVisivel; j++)
            oss << zonasReserva.at(i).at(j)->getAsString() << " | ";

        oss << endl;
    }
    return oss.str();
}


//ANIMAIS

bool Reserva::adicionaAnimalReserva(char letra, int x, int y) {
    Animal *novo = nullptr;

    if (letra == 'c') {
        novo = new Coelho(*this, x, y);
    } else if (letra == 'o') {
        novo = new Ovelha(*this, x, y);
    } else if (letra == 'l') {
        novo = new Lobo(*this, x, y);
    } else if (letra == 'g') {
        novo = new Canguru(*this, x, y);
    } else if (letra == 'm') {
        novo = new AnimalMisterio(*this, x, y);
    }

    if (letra != 'c' && letra != 'o' && letra != 'l' && letra != 'g' && letra != 'm')
        return false;

    zonasReserva.at(x).at(y)->adicionaAnimal(novo);

    return true;
}

void Reserva::removeAnimalReserva(int id) {
    for (auto z: getZonas()) {
        for (auto a: z)
            for (auto it: a->getAnimais()) {
                if (it->getId() == id) {
                    a->removeAnimal(id);
                }
            }
    }
}

void Reserva::mataAnimalReserva(int id) {
    for (auto z: getZonas()) {
        for (auto a: z)
            for (auto it: a->getAnimais()) {
                if (it->getId() == id) {
                    a->mataAnimal(id);
                    adicionaAlimentoReserva('p', it->getX(), it->getY() + 1, it->getVn(), it->getVt());
                }
            }
    }

}

//ALIMENTOS

bool Reserva::adicionaAlimentoReserva(char letra, int x, int y, int vN, int vT) {
    Alimento *novo = nullptr;

    if (letra == 'r') {
        novo = new Relva(*this, x, y);
    } else if (letra == 't') {
        novo = new Cenoura(*this, x, y);
    } else if (letra == 'p') {
        novo = new Corpo(*this, x, y, vN, vT);
    } else if (letra == 'b') {
        novo = new Bife(*this, x, y);
    } else if (letra == 'a') {
        novo = new AlimentoMisterio(*this, x, y);
    }


    if (letra != 'r' && letra != 't' && letra != 'p' && letra != 'b' && letra != 'a')
        return false;

    zonasReserva.at(x).at(y)->adicionaAlimento(novo);

    return true;
}

void Reserva::removeAlimentoReserva(int id) {

    for (auto z: getZonas()) {
        for (auto a: z) {
            Alimento *alimento = a->getAlimento();
            if (alimento != nullptr) {
                if (alimento->getId() == id) {
                    a->removeAlimento(id);
                }
            }
        }
    }
}

//METODOS COMANDOS
bool Reserva::mataAnimal(int linha, int coluna) {
    vector<Animal *> animais = getZonas().at(linha).at(coluna)->getAnimais();
    if (animais.empty())
        return false;
    else {
        for (auto animal: animais) {
            mataAnimalReserva(animal->getId());
        }
    }
    return true;
}

bool Reserva::alimentaAnimaisLC(int linha, int coluna, int pontosNutri, int pontosToxicos) {
    vector<Animal *> animais = getZonas().at(linha).at(coluna)->getAnimais();

    if (animais.empty())
        return false;
    else {
        for (auto animal: animais) {
            animal->aumentaSaude(pontosNutri);
            animal->diminuiSaude(pontosToxicos);
        }
    }
    return true;
}

bool Reserva::alimentaAnimaisId(int id, int pontosNutri, int pontosToxicos) {
    for (auto it: getZonas()) {
        for (auto z: it) {
            if (!z->getAnimais().empty()) {
                for (Animal *a: z->getAnimais()) {
                    if (a->getId() == id) {
                        a->aumentaSaude(pontosNutri);
                        a->diminuiSaude(pontosToxicos);
                    }
                }
            }
        }
    }
    return true;
}

bool Reserva::eliminaPos(int linha, int coluna) {
    vector<Animal *> animais = getZonas().at(linha).at(coluna)->getAnimais();
    Alimento *alimento = getZonas().at(linha).at(coluna)->getAlimento();

    if (animais.empty() && alimento == nullptr)
        return false;
    else {
        for (auto animal: animais) {
            getZonas().at(linha).at(coluna)->mataAnimal(animal->getId());
        }
    }
    if (alimento != nullptr) {
        removeAlimentoReserva(alimento->getId());
    }

return true;
}

bool Reserva::veNaPosicao(int linha, int coluna) {
    vector<Animal *> animais = getZonas().at(linha).at(coluna)->getAnimais();
    Alimento *alimento = getZonas().at(linha).at(coluna)->getAlimento();

    if (animais.empty() && alimento == nullptr)
        return false;
    else {
        for (auto animal: animais) {
            cout << animal->getAsString() << endl;
        }
        if (alimento != nullptr) {
            cout << alimento->getAsString() << endl;
        }
    }
    return true;
}

bool Reserva::veInfo(int id) {
    for (auto it: getZonas()) {
        for (auto z: it) {
            if (!z->getAnimais().empty()) {
                for (Animal *a: z->getAnimais()) {

                    if (a->getId() == id) {
                        cout << a->getAsString();
                        return true;
                    }
                }
            }
        }

    }
    for (auto it: getZonas()) {
        for (auto z: it) {
            if (z->getAlimento() != nullptr) {
                Alimento *a = z->getAlimento();
                if (a->getId() == id) {
                    cout << a->getAsString();
                    return true;
                }
            }
        }
    }
    return true;
}

bool Reserva::listaAnimaisPorId() {
    for (auto it: getZonas()) {
        for (auto z: it) {
            if (!z->getAnimais().empty()) {
                for (Animal *a: z->getAnimais()) {
                    cout << a->getAsString() << endl;
                }
            }
        }
    }
    return true;
}

bool Reserva::listaAlimentosPorId() {
    for (auto it: getZonas()) {
        for (auto z: it) {
            if (z->getAlimento() != nullptr) {
                Alimento *a = z->getAlimento();
                cout << a->getAsString() << endl;

            }
        }
    }
    return true;
}

bool Reserva::listaAnimaisVisiveis() {
    for (int i = getX(); i < getX() + getAreaVisivel(); i++) {
        for (int j = getY(); j < getY() + getAreaVisivel(); j++) {
            vector<Animal *> animais = getZonas()[i][j]->getAnimais();
            for (auto it: animais) {
                cout << it->getAsString() << endl;
            }
        }
    }
    return true;
}

bool Reserva::deslizaArea(string direcao, int valorSlide) {
    int resSlide;

    if (valorSlide < 0)
        return false;
    if (direcao == "right") {
        resSlide = getY() + valorSlide;
        if (resSlide <= getNColunas() - getAreaVisivel()) {
            setY(getY() + valorSlide);
            return true;
        }
        return false;

    } else if (direcao == "left") {
        resSlide = getY() - valorSlide;

        if (resSlide >= 0) {
            setY(getY() - valorSlide);
            return true;
        }
        return false;
    } else if (direcao == "up") {
        resSlide = getX() - valorSlide;
        if (resSlide >= 0) {
            setX(getX() - valorSlide);
            return true;
        }
        return false;
    } else if (direcao == "down") {
        resSlide = getX() + valorSlide;
        if (resSlide <= getNLinhas() - getAreaVisivel()) {
            setX(getX() + valorSlide);
            return true;
        }
        return false;
    }
}

int Reserva::getNextId() {
    return ids++;
}

int Reserva::aumentaInstante(int valor) {
    return instante += valor;
}

void Reserva::verificaCoordenadas(int &x, int &y) {
    if (x < 0)
        x += getNLinhas();
    if (y < 0)
        y += getNColunas();
    if (x >= getNLinhas())
        x -= getNLinhas();
    if (y >= getNColunas())
        y -= getNColunas();
}

const vector<vector<Zona *>> &Reserva::getZonas() const {
    return zonasReserva;
}

int Reserva::getX() const {
    return x;
}

int Reserva::getY() const {
    return y;
}

void Reserva::setX(int x) {
    Reserva::x = x;
}

void Reserva::setY(int y) {
    Reserva::y = y;
}

int Reserva::getNLinhas() const {
    return nLinhas;
}

int Reserva::getNColunas() const {
    return nColunas;
}

const int Reserva::getAreaVisivel() {
    return areaVisivel;
}

int Reserva::getInstante() {
    return instante;
}






