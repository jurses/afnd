#include <iostream>
#include <string>
#include "estado.hpp"
#include "afnd.hpp"

std::ostream& mostrar_menu(std::ostream& os){
    int opcion=-1;
    std::string nom_arc;
    os << "Abrir archivo: ";
    std::getline(std::cin, nom_arc);

    CYA::afnd_t mi_nfa;
    std::ifstream ifs(nom_arc, std::ifstream::in);
    mi_nfa.lee(ifs);

    while(opcion!=0){
        os << std::endl;
        os << "0. Salir" << std::endl;
        os << "1. Mostrar afnd" << std::endl;
        os << "2. ¿Es DFA?" << std::endl;
        os << "3. Mostrar estados de muerte" << std::endl;
        os << "4. Analizar la cadena" << std::endl;

        std::cin >> opcion;
        os << "_______________________________________" << std::endl;
        
        switch(opcion){
            case 1: mi_nfa.mostrar_nfa(std::cout);
                    break;
            case 2: os << std::boolalpha << mi_nfa.es_dfa() << std::noboolalpha;
                    break;
            case 3: mi_nfa.mostrar_est_muerte(std::cout);
                    break;
            case 4: //mi_nfa.analizar_cad();
                    break;
            case 0: os << "Salimos." << std::endl;
                    break;
            default: os << "Opción incorrecta" << std::endl;
        }
    }

    return os;
}

int main(void){
    mostrar_menu(std::cout);
}
