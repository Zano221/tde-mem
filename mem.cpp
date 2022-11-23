#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>
#include <iomanip>

//Funcao inutil
std::vector<std::string> insertSAM(std::vector<std::string> vec) {
    
    std::vector<std::string> mem;

    return mem;
}

std::vector<std::string> insertRAM(std::vector<std::string> auxVec) {

    std::vector<std::string> mem;
    //std::vector<std::string> auxVec;
    //auxVec = vec;

    int pos = 0;
    while(auxVec.size()) {
        srand(time(0));
        int randomPos = rand() % auxVec.size();
        std::cout << randomPos << std::endl;

        mem.push_back(auxVec[randomPos]);
        auxVec.erase(auxVec.begin()+randomPos);

        std::string auxString = auxVec[pos];
        pos++;
    }

    return mem;

}


int main() {
    
    std::vector<std::string> memoria, readVec;
    std::chrono::time_point<std::chrono::system_clock> start, end;

    std::string ler;
    std::string path;
    std::string text;
    std::ifstream file;

    bool isOpen = false;

    while(!isOpen) {
        std::cout << "Carregue um arquivo de texto: ";
        std::cin >> ler;

        path = ".\\arquivos\\" + ler + ".txt";
        file.open(path);

        if(!file.is_open()) {
            std::cout << std::endl << "  === Erro! Arquivo nao existe! ===    " << std::endl << std::endl;
        }
        else {
            isOpen = true;
        }

    }

    while(std::getline(file, text)) {
            readVec.push_back(text);
        }
    
    std::string tipoMem;
    int choice;
    std::cout << "Insira o modo de leitura desejado (1. Sequencial) (2. Random): ";
    std::cin >> choice;

    bool isEscolha = false;

    //Inserir
    while(!isEscolha) {
        switch(choice) {
        case 1:
            tipoMem = "SAM";
            isEscolha = true;
            memoria = readVec;
            break;
        case 2:
            tipoMem = "RAM";
            isEscolha = true;
            memoria = insertRAM(readVec);
            break;
        }

        if(!isEscolha) {
            std::cout << std::endl << "  === Erro! Escolha nao existe! (1. Sequencial) (2. Random) ===    " << std::endl << std::endl;
            std::cout << "Insira o modo de leitura desejado (1. Sequencial) (2. Random): ";
            std::cin >> choice;
        }
    }
    
    
    std::cout << " --- LISTA --- " << std::endl;
    for(int i = 0; i < memoria.size(); i++) {
        std::cout << i << ". " << memoria[i] << std::endl;
    }
    
    //Busca
    int searchPos = 0;
    bool isEncontrado = false;

    std::cout << "Elemento a Buscar: ";
    while(!isEncontrado) {
        std::cin >> ler;

    
        start = std::chrono::system_clock::now();
        for(int i = 0; i < memoria.size(); i++) {

            if(ler == memoria[i]) {
                isEncontrado = true;
                break;
            }

            searchPos++;
        }
        end = std::chrono::system_clock::now();

        if(!isEncontrado) {
            searchPos = 0;
            std::cout << std::endl << "  === Erro! Elemento nao existe! Procure novamente ===    " << std::endl << std::endl;
            std::cout << "Elemento a Buscar: ";
        }

    }
    

    std::chrono::duration<double> tempo = end - start;

    //Printar na tela
    std::setprecision(1);
    std::cout << std::endl << std::endl << "  === [RESULTADO] === " << std::endl << std::endl;
    std::cout << "Tipo: " << tipoMem << std::endl; 
    std::cout << "Posicao: " << searchPos << std::endl; 
    std::cout << "Duracao de Pesquisa: " << tempo.count()*60*60 << " segundos" << std::endl << std::endl; 
}