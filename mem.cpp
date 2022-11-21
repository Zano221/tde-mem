#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>
#include <iomanip>


std::vector<std::string> insertSAM(std::string path) {
    
    std::vector<std::string> mem;
    
    std::string text;
    std::ifstream file(path);
    while(std::getline(file, text)) {
        mem.push_back(text);
    }

    file.close();

    return mem;
}

std::vector<std::string> insertRAM(std::string path) {

    std::vector<std::string> mem;
    std::vector<std::string> auxVec;

    std::string text;
    std::ifstream file(path);

    while(std::getline(file, text)) {
        auxVec.push_back(text);
    }

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
    
    std::vector<std::string> memoria;
    std::chrono::time_point<std::chrono::system_clock> start, end;

    std::string ler;

    std::cout << "Carregue um arquivo de texto: ";
    std::cin >> ler;

    std::string path = ".\\arquivos\\" + ler + ".txt";
    
    int choice;
    std::cout << "Insira o modo de leitura desejado (1. Sequencial) (2. Random): ";
    std::cin >> choice;

    //Inserir
    switch(choice) {
        case 1:
            memoria = insertSAM(path); 
            break;
        case 2:
            memoria = insertRAM(path);
            break;
    }
    
    std::cout << " --- LISTA --- " << std::endl;
    for(int i = 0; i < memoria.size(); i++) {
        std::cout << i << ". " << memoria[i] << std::endl;
    }
    
    //Busca
    std::cout << "Elemento a Buscar: ";
    std::cin >> ler;

    int searchPos = 0;
    start = std::chrono::system_clock::now();
    for(int i = 0; i < memoria.size(); i++) {

        if(ler == memoria[i]) {
            break;
        }

        searchPos++;
    }
    end = std::chrono::system_clock::now();

    std::chrono::duration<double> tempo = end - start;

    //Printar na tela
    std::setprecision(1);
    std::cout << std::endl << "  === [RESULTADO] === " << std::endl << std::endl;
    std::cout << "Tipo: SAM/RAM" << std::endl; 
    std::cout << "Posicao: " << searchPos << std::endl; 
    std::cout << "Duracao de Pesquisa: " << tempo.count()*60*60 << " segundos" << std::endl; 
    std::cout << "Tipo: SAM/RAM" << std::endl; 
}