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

    std::string text;
    std::ifstream file(path);

    while(std::getline(file, text)) {
        auxVec.push_back(text);
    }

    for(int i = 0; i < auxVec.size(); i++) {
        int pos = rand() % auxVec.size();

        /*if(mem.contains(auxVex[pos])) {

        }*/

        mem.push_back(auxVec[pos]);
    }

    return mem;

}


int main() {
    
    std::vector<std::string> memoria;

    std::string ler;
    std::string path = ".\\arquivos\\";

    std::cout << "Insira qual para leitura: ";
    std::cin >> ler;

    path = path + ler + ".txt";
    
    int choice;
    std::cout << "Insira o modo de leitura desejado (1. Sequencial) (2. Random): ";
    std::cin >> choice;

    std::string text;

    std::cout << text << std::endl;

    //file.open(path + ler + ".txt");
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