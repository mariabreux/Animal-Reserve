
#include "Animal.h"
#include "Reserva.h"
#include "Alimento.h"


Animal::Animal(char letra, int peso, int fome, int saude, int percecao, int duracaoVida, Reserva &reserva, int x, int y)
        : id(Reserva::getNextId()), letra(letra), peso(peso),
          fome(fome), saude(saude), percecao(percecao), duracaoVida(duracaoVida), reserva(reserva), x(x), y(y),
          avancouInstante(false) {

}

Animal::Animal(const Animal &animal) : letra(animal.letra), peso(animal.peso), fome(animal.fome), saude(animal.saude),
                                       percecao(animal.percecao), duracaoVida(animal.duracaoVida),
                                       reserva(animal.reserva), x(animal.x), y(animal.y) {

}

Animal *Animal::duplica() {

}

Animal::~Animal() noexcept = default;

void Animal::passaInstante() {

}

void Animal::aumentaSaude(int valor) {
    saude += valor;
}

void Animal::diminuiSaude(int valor) {
    int res = saude - valor;
    if (res <= 0)
        saude = 0;
    else
        saude = res;
}


string Animal::getAsString() const {
    ostringstream os;

    os << "ID: " << getId() << endl;

    return os.str();
}

Animal *Animal::procuraMaisPesado(vector<Animal *> animais) {
    auto it = max_element(animais.begin(), animais.end(), [](const Animal *a, const Animal *b){
        return a->getPeso() < b->getPeso();
    });

    if (it != animais.end()) {
        return *it;
    } else {
        return nullptr;
    }
}

int Animal::getPeso() const {
    return peso;
}

int Animal::getFome() const {
    return fome;
}

int Animal::getSaude() const {
    return saude;
}

int Animal::getId() const {
    return id;
}

const char &Animal::getLetra() const {
    return letra;
}

int Animal::getDuracaoVida() const {
    return duracaoVida;
}

const string &Animal::getEspecie() const {
    return especie;
}

int Animal::getX() const {
    return x;
}

int Animal::getY() const {
    return y;
}

bool Animal::isAvancouInstante() const {
    return avancouInstante;
}

void Animal::setAvancouInstante(bool avancouInstante) {
    Animal::avancouInstante = avancouInstante;
}

int Animal::getVn() const {
    return vN;
}

int Animal::getVt() const {
    return vT;
}
















