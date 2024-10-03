
#include "Alimento.h"
#include "Reserva.h"

Alimento::Alimento(char letra, int valorNutritivo, int valorToxico, int duracaoVida, Reserva &reserva, int x, int y)
        : id(Reserva::getNextId()), letra(letra), valorNutritivo(valorNutritivo), valorToxico(valorToxico),
          duracaoVida(duracaoVida), reserva(reserva), x(x), y(y) {

}

Alimento::Alimento(const Alimento &alimento) : letra(alimento.letra), valorNutritivo(alimento.valorNutritivo),
                                               valorToxico(alimento.valorToxico), duracaoVida(alimento.duracaoVida),
                                               reserva(alimento.reserva), x(alimento.x), y(alimento.y) {

}

Alimento *Alimento::duplica() {

}

Alimento::~Alimento() noexcept = default;

int Alimento::getId() const {
    return id;
}

char Alimento::getLetra() const {
    return letra;
}

const string &Alimento::getTipoAlimento() const {
    return tipoAlimento;
}

int Alimento::getValorNutritivo() const {
    return valorNutritivo;
}

int Alimento::getValorToxico() const {
    return valorToxico;
}

int Alimento::getDuracaoVida() const {
    return duracaoVida;
}

bool Alimento::isConsumido() const {
    return consumido;
}

void Alimento::setConsumido(bool consumido) {
    Alimento::consumido = consumido;
}

const vector<string> &Alimento::getCheiro() const {
    return cheiro;
}

int Alimento::getX() const {
    return x;
}

int Alimento::getY() const {
    return y;
}

string Alimento::getAsString() const {

    ostringstream os;

    os << "ID: " << getId() << endl;
    os << "Tipo de alimento: " << getTipoAlimento() << endl;
    os << "Duracao de vida: " << getDuracaoVida() << endl;
    os << "Valor nutritivo: " << getValorNutritivo() << endl;
    os << "Toxicidade: " << getValorToxico() << endl;

    return os.str();
}















