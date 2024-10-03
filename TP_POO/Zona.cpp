
#include "Zona.h"


Zona::Zona(int linha, int coluna) : linha(linha), coluna(coluna), alimento(nullptr) {
}

Zona::Zona(const Zona &zona) {
    *this = zona;
}

Zona *Zona::duplica() {
    return new Zona(*this);
}

Zona &Zona::operator=(const Zona &zona) {
    if (this == &zona)
        return *this;

    if (zona.alimento != nullptr) {
        alimento = zona.alimento->duplica();
    } else
        alimento = nullptr;

    animais.clear();
    for (auto it: zona.animais) {
        animais.push_back(it->duplica());
    }
    linha = zona.linha;
    coluna = zona.coluna;

    return *this;
}

Zona::~Zona() {
    delete alimento;
    for (auto it: animais) {
        delete it;
    }
}

const vector<Animal *> &Zona::getAnimais() const {
    return animais;
}

void Zona::setAlimento(Alimento *alimento) {
    this->alimento = alimento;
}

Alimento *Zona::getAlimento() const {
    return alimento;
}


//ANIMAIS
bool Zona::adicionaAnimal(Animal *a) {
    animais.push_back(a);
    return true;
}

bool Zona::removeAnimal(int id) {

    for (auto it = animais.begin(); it < animais.end();) {
        if ((*it)->getId() == id) {
            animais.erase(it);
            return true;
        }
        ++it;
    }
    return false;
}

void Zona::mataAnimal(int id) {
    for (auto animal: getAnimais()) {
        if (removeAnimal(animal->getId())) {
            delete animal;
        }
    }
}

//ALIMENTOS
void Zona::adicionaAlimento(Alimento *a) {
    this->setAlimento(a);
}

void Zona::removeAlimento(int id) {
    if (alimento->getId() == id) {
        delete alimento;
        alimento = nullptr;
    }
}

const string Zona::getAsString() const {

    ostringstream os;

    if (alimento != nullptr)
        os << alimento->getLetra();

    if (!animais.empty())
        os << animais.at(0)->getLetra();

    if (alimento == nullptr && getAnimais().empty()) {
        os << "  ";
    } else if (alimento == nullptr || getAnimais().empty()) {
        os << " ";
    }

    return os.str();
}
