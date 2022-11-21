#include <iostream>
#include <fstream>
#include <string>
#include <vector>


std::vector<std::string> insertIntoSequencial(std::string path) {
    
    std::vector<std::string> mem;
    
    std::string text;
    std::ifstream file(path);
    while(std::getline(file, text)) {
        mem.push_back(text);
    }

    file.close();

    return mem;
}

std::vector<std::string> insertIntoRandom(std::string path) {

    std::vector<std::string> mem;
    std::vector<std::string> auxVec;
    std::vector<std::string>::iterator it;

    std::string text;
    std::ifstream file(path);

    while(std::getline(file, text)) {
        auxVec.push_back(text);
    }

    int pos = 0;
    while(auxVec.size()) {
        int randomPos = rand() % auxVec.size();

        mem.push_back(auxVec[randomPos]);
        auxVec.erase(auxVec.begin()+randomPos);

        std::string auxString = auxVec[pos];
        pos++;
        std::cout << pos << std::endl;
    }

    return mem;

}


int main() {
    
    std::vector<std::string> memoria;

    std::string ler;

    std::cout << "Insira qual para leitura: ";
    std::cin >> ler;

    std::string path = ".\\arquivos\\" + ler + ".txt";
    
    int choice;
    std::cout << "Insira o modo de leitura desejado (1. Sequencial) (2. Random): ";
    std::cin >> choice;

    switch(choice) {
        case 1:
            memoria = insertIntoSequencial(path); 
            break;
        case 2:
            memoria = insertIntoRandom(path);
            break;
    }

    for(int i = 0; i < memoria.size(); i++) {
        std::cout << memoria[i] << std::endl;
    }

}