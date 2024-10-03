#include "AnimalMisterio.h"
#include "Reserva.h"
#include "Configuracao.h"

AnimalMisterio::AnimalMisterio(Reserva &reserva, int x, int y): Animal('M',5,2,Configuracao::getSAnimalMisterio(),Configuracao::getPAnimalMisterio(),Configuracao::getVAnimalMisterio(),reserva,x,y) {
    especie = "AnimalMisterio";
}

Animal *AnimalMisterio::duplica() {
    return new AnimalMisterio(*this);
}

AnimalMisterio::~AnimalMisterio() noexcept = default;

void AnimalMisterio::passaInstante() {

    saude--;
    fome+=2;
    if(fome>=12 && fome <16){
        diminuiSaude(4);
        deslocaAnimalMisterio(4);
    }else if(fome>=16) {
        diminuiSaude(5);
        deslocaAnimalMisterio(8);
    }else{
        deslocaAnimalMisterio(2);
    }

    duracaoVida--;
    if(duracaoVida == 0 || saude == 0){
        morreAnimalMisterio();
    }

    if (duracaoVida == 25 || duracaoVida == 15 || duracaoVida == 5) {
        reproduzAnimalMisterio();
    }
}

void AnimalMisterio::deslocaAnimalMisterio(int valor) {
    int direcao, horizontal, vertical;
    int linha, coluna;

    //CHEIRA MISTERIO
    for(int i = -percecao; i < percecao; i++){
        for(int j = -percecao; j < percecao; j++){
            linha = x+i;
            coluna = y+j;
            reserva.verificaCoordenadas(linha, coluna);
            Alimento *alimento = reserva.getZonas().at(linha).at(coluna)->getAlimento();
            if(alimento == nullptr)
                continue;
            for(int k = 0; k < alimento->getCheiro().size(); k++){
                if(alimento->getCheiro().at(k) == "Misterio"){
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


    //ALEATORIO
    horizontal = valor;
    vertical = valor;

    direcao = rand()%2;
    if(direcao == 0){
        horizontal = -horizontal;
    }
    direcao = rand()%2;
    if(direcao == 0)
        vertical = -vertical;

    reserva.removeAnimalReserva(id);

    x += horizontal;
    y += vertical;
    reserva.verificaCoordenadas(x, y);

    reserva.getZonas().at(x).at(y)->adicionaAnimal(this);

}


void AnimalMisterio::comeAlimento(Alimento *alimento) {
    alimento->setConsumido(true);
    diminuiSaude(alimento->getValorToxico());
    fome--;
}

bool AnimalMisterio::reproduzAnimalMisterio() {
    int pos, novoX, novoY;

    pos = (rand()%10)-5;
    novoX = x+pos;
    novoY = y+pos;

    reserva.verificaCoordenadas(novoX, novoY);

    Configuracao::setSAnimalMisterio(saude*2);
    if(reserva.adicionaAnimalReserva('m', novoX, novoY))
        return true;

    return false;
}

void AnimalMisterio::morreAnimalMisterio() {
    reserva.mataAnimalReserva(id);
}

string AnimalMisterio::getAsString() const {
    ostringstream oss;

    oss << Animal::getAsString();
    oss << "Especie: " << especie << endl;
    oss << "Duracao de Vida: " << duracaoVida << endl;
    oss << "Peso: " << peso << endl;
    oss << "Saude: " << saude << endl;
    oss << "Fome: " << fome << endl;

    return oss.str();
}