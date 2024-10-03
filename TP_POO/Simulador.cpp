#include "Simulador.h"
#include "Configuracao.h"


Simulador::Simulador(Reserva &reserva) : reserva(reserva) {

}

void Simulador::iniciaReserva(int *linhas, int *colunas) {

    if(leFicheiro("constantes.txt"))
        cout << "Variaveis dos animais configuradas!" << endl;

    string input;

    cout << "Tamanho da Reserva (linhas colunas): ";
    getline(cin, input);

    while (true) {
        istringstream iss(input);
        iss >> *linhas >> *colunas;

        if (iss) {
            if (Reserva::validaDimensoes(*linhas, *colunas))
                break;
        }
        cout << "Tamanho Invalido!" << endl;
        getline(cin, input);

    }

}

void Simulador::escolheComando() {
    string comando;
    bool escolhido;

    do {
        cout << reserva.printReserva();

        cout << "Comando: ";
        getline(cin, comando);

        if (comando == "exit")
            break;
        else
            escolhido = verificaComando(comando);

        if (!escolhido) {
            cout << "Erro no comando '" << comando << "'" << endl;
        }

    } while (comando != "exit");
}

bool Simulador::verificaComando(const string &comando) {

    istringstream ss(comando);
    string primArg;
    bool escolhido;

    ss >> primArg;            //ss fica com o primeiro argumento do comando

    if (primArg == "animal")
        escolhido = criaAnimal(comando);
    else if (primArg == "kill" || primArg == "killid")
        escolhido = mataAnimal(comando);
    else if (primArg == "food")
        escolhido = colocaAlimento(comando);
    else if (primArg == "feed" || primArg == "feedid")
        escolhido = alimentaAnimais(comando);
    else if (primArg == "nofood")
        escolhido = removeAlimento(comando);
    else if (primArg == "empty")
        escolhido = eliminaNaPos(comando);
    else if (primArg == "see")
        escolhido = veNaPos(comando);
    else if (primArg == "info")
        escolhido = veInfo(comando);
    else if (primArg == "n")
        escolhido = passaInstante(comando);
    else if (primArg == "anim")
        escolhido = listaIdAnimais(comando);
    else if (primArg == "alim")
        escolhido = listaIdAlimentos(comando);
    else if (primArg == "visanim")
        escolhido = listaIdAnimaisVisiveis(comando);
    else if (primArg == "store")
        escolhido = armazenaReserva(comando);
    else if (primArg == "restore")
        escolhido = reativaReserva(comando);
    else if (primArg == "load")
        escolhido = execFicheiros(comando);
    else if (primArg == "slide")
        escolhido = deslocaArea(comando);
    else
        return false;

    return escolhido;
}

bool Simulador::criaAnimal(const string &args) {
    istringstream ss(args);
    string comando;
    char letra;
    int linha, coluna;
    ss >> comando >> letra;

    if (ss >> linha >> coluna) {
        return reserva.adicionaAnimalReserva(letra, linha, coluna);
    } else {
        linha = rand() % reserva.getNLinhas();
        coluna = rand() % reserva.getNColunas();
        return reserva.adicionaAnimalReserva(letra, linha, coluna);
    }
}

bool Simulador::mataAnimal(const string &args) {

    istringstream ss1(args), ss2(args);
    string comando;
    int id, linha, coluna;
    ss1 >> comando >> linha >> coluna;
    ss2 >> comando >> id;

    if (ss1) {
        if (comando != "kill")
            return false;

        return reserva.mataAnimal(linha, coluna);

    } else if (ss2) {
        if (comando != "killid")
            return false;
        else {
            reserva.mataAnimalReserva(id);
            return true;
        }
    }
    return false;

}


bool Simulador::colocaAlimento(const string &args) {
    istringstream ss1(args);
    istringstream ss2(args);
    string comando;
    char letra;
    int linha, coluna;

    ss1 >> comando >> letra >> linha >> coluna;
    ss2 >> comando >> letra;

    if (ss1) {
        if (letra == 'p')
            return false;
        return reserva.adicionaAlimentoReserva(letra, linha, coluna, 0, 0);
    }

    if (ss2) {
        if (letra == 'p')
            return false;
        linha = rand() % reserva.getNLinhas();
        coluna = rand() % reserva.getNColunas();

        return reserva.adicionaAlimentoReserva(letra, linha, coluna, 0, 0);
    }
    return false;
}

bool Simulador::alimentaAnimais(const string &args) {
    istringstream ss1(args), ss2(args);
    string comando;
    int linha, coluna, id, pontosNutri, pontosToxicos;

    ss1 >> comando >> linha >> coluna >> pontosNutri >> pontosToxicos;
    if (ss1) {
        if (comando != "feed" || pontosNutri < 0 || pontosToxicos < 0)
            return false;
        return reserva.alimentaAnimaisLC(linha, coluna, pontosNutri, pontosToxicos);

    } else {
        ss2 >> comando >> id >> pontosNutri >> pontosToxicos;
        if (ss2) {
            if (comando != "feedid" || pontosNutri < 0 || pontosToxicos < 0)
                return false;

            return reserva.alimentaAnimaisId(id, pontosNutri, pontosToxicos);

        }

    }
}


bool Simulador::removeAlimento(const string &args) {
    istringstream ss1(args), ss2(args);
    string comando;
    int linha, coluna, id;

    ss1 >> comando >> linha >> coluna;
    ss2 >> comando >> id;

    if (ss1) {
        Alimento *alimento = reserva.getZonas().at(linha).at(coluna)->getAlimento();
        if (alimento != nullptr)
            reserva.removeAlimentoReserva(alimento->getId());
        return true;
    }

    if (ss2) {
        for (auto z: reserva.getZonas()) {
            for (auto it: z) {
                if (it->getAlimento() != nullptr) {
                    Alimento *alimento = it->getAlimento();
                    if (alimento->getId() == id)
                        reserva.removeAlimentoReserva(id);
                }
            }
        }
        return true;
    }

    return false;
}

bool Simulador::eliminaNaPos(const string &args) {
    istringstream ss(args);
    string comando;
    int linha, coluna;

    ss >> comando >> linha >> coluna;

    if (ss)
        return reserva.eliminaPos(linha, coluna);

    return false;

}

bool Simulador::veNaPos(const string &args) {
    istringstream ss(args);
    string comando;
    int linha, coluna;

    ss >> comando >> linha >> coluna;

    if (ss) {
        return reserva.veNaPosicao(linha, coluna);
    }
    return false;
}

bool Simulador::veInfo(const string &args) {
    istringstream ss(args);
    string comando;
    int id;
    ss >> comando >> id;
    if (ss)
        return reserva.veInfo(id);

    return false;

}

bool Simulador::passaInstante(const string &args) {
    istringstream ss1(args), ss2(args), ss3(args);
    int numInstantes, pausa;
    string comando;

    ss1 >> comando;
    ss2 >> comando >> numInstantes;
    ss3 >> comando >> numInstantes >> pausa;

    if (ss3) {
        reserva.aumentaInstante(numInstantes);

        for (int i = 0; i < numInstantes; i++) {
            for (auto it: reserva.getZonas()) {
                for (auto z: it) {
                    for (Animal *a: z->getAnimais()) {
                        a->setAvancouInstante(false);
                    }
                }
            }
            for (auto it: reserva.getZonas()) {
                for (auto z: it) {
                    if (z->getAnimais().empty() && z->getAlimento() == nullptr) {
                        continue;
                    } else {

                        for (Animal *a: z->getAnimais()) {
                            if (!a->isAvancouInstante()) {
                                a->passaInstante();
                                a->setAvancouInstante(true);
                            }

                        }
                        if (z->getAlimento() == nullptr) {
                            continue;
                        } else
                            z->getAlimento()->passaInstante();
                    }
                }

            }
            if (i < numInstantes - 1) {
                cout << reserva.printReserva() << endl;
                sleep(pausa);
            }

        }
        return true;
    }
    if (ss2) {
        reserva.aumentaInstante(numInstantes);

        for (int i = 0; i < numInstantes; i++) {
            for (auto it: reserva.getZonas()) {
                for (auto z: it) {
                    for (Animal *a: z->getAnimais()) {
                        a->setAvancouInstante(false);
                    }
                }
            }
            for (auto it: reserva.getZonas()) {
                for (auto z: it) {
                    if (z->getAnimais().empty() && z->getAlimento() == nullptr) {
                        continue;
                    } else {

                        for (Animal *a: z->getAnimais()) {
                            if (!a->isAvancouInstante()) {
                                a->passaInstante();
                                a->setAvancouInstante(true);
                            }

                        }
                        if (z->getAlimento() == nullptr) {
                            continue;
                        } else
                            z->getAlimento()->passaInstante();
                    }
                }
            }
            if (i < numInstantes - 1) {
                cout << reserva.printReserva();
            }
        }
        return true;
    }
    if (ss1) {
        reserva.aumentaInstante(1);
        for (auto it: reserva.getZonas()) {
            for (auto z: it) {
                for (Animal *a: z->getAnimais()) {
                    a->setAvancouInstante(false);
                }
            }
        }
        for (auto it: reserva.getZonas()) {
            for (auto z: it) {
                if (z->getAnimais().empty() && z->getAlimento() == nullptr) {
                    continue;
                } else {

                    for (Animal *a: z->getAnimais()) {
                        if (!a->isAvancouInstante()) {
                            a->passaInstante();
                            a->setAvancouInstante(true);
                        }

                    }
                    if (z->getAlimento() == nullptr) {
                        continue;
                    } else
                        z->getAlimento()->passaInstante();
                }
            }

        }
        return true;
    }

    return false;

}

bool Simulador::listaIdAnimais(const string &args) {
    istringstream ss(args);
    string comando;
    ss >> comando;

    if(ss)
        return reserva.listaAnimaisPorId();
    return false;
}

bool Simulador::listaIdAlimentos(const string &args) {
    istringstream ss(args);
    string comando;
    ss >> comando;

    if(ss)
        return reserva.listaAlimentosPorId();
    return false;
}

bool Simulador::listaIdAnimaisVisiveis(const string &args) {
    istringstream ss(args);
    string comando;
    ss >> comando;

    if (ss)
        return reserva.listaAnimaisVisiveis();

    return false;
}

bool Simulador::armazenaReserva(const string &args) {
    istringstream ss(args);
    string comando, nome;

    ss >> comando >> nome;

    if (ss) {
        for (auto storeReserva: getStoreReserva()) {
            if (storeReserva.first == nome)
                return false;
        }
        return adicionaStoreReserva(nome, reserva);
    }

    return false;
}

bool Simulador::reativaReserva(const string &args) {
    istringstream ss(args);
    string comando, nome;

    ss >> comando >> nome;

    if (ss) {
        for (auto storeReserva: getStoreReserva()) {
            if (storeReserva.first == nome) {
                reserva = storeReserva.second;
                return true;
            }
        }
    }

    return false;
}

bool Simulador::execFicheiros(const string &args) {

    string comando, nomeFicheiro;
    istringstream iss(args);
    iss >> comando >> nomeFicheiro;

    if (iss) {
        ifstream ficheiro;
        ficheiro.open(nomeFicheiro);

        if (!ficheiro.is_open()) {
            cout << "Erro a abrir ficheiro" << endl;
            return false;
        }

        string comandoFicheiro;
        while (getline(ficheiro, comandoFicheiro)) {
            if (!verificaComando(comandoFicheiro))
                cout << "Erro no comando '" << comando << "'" << endl;
        }
        ficheiro.close();
        return true;
    }

    return false;
}

bool Simulador::deslocaArea(const string &args) {
    string comando, direcao;
    int valorSlide;
    istringstream iss(args);
    iss >> comando >> direcao >> valorSlide;

    if (iss)
        return reserva.deslizaArea(direcao, valorSlide);

    return false;
}

bool Simulador::leFicheiro(const string &nomeFicheiro) {
    ifstream ficheiro;
    string linha;

    ficheiro.open(nomeFicheiro.c_str());
    if (!ficheiro.is_open()) {
        cout << "Erro a abrir ficheiro!" << endl;
        return false;
    }

    while (getline(ficheiro, linha)) {
        if (!Configuracao::configuraFicheiro(linha)) {
            cout << "Erro a configurar as variaveis!" << endl;
            return false;
        }
    }
    ficheiro.close();
    return true;

}

const map<string, Reserva> Simulador::getStoreReserva() const {
    return storeReserva;
}

bool Simulador::adicionaStoreReserva(const string &nome, Reserva reservaStore) {
    storeReserva.insert({nome, reservaStore});
    return true;
}


