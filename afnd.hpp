#ifndef _AFND_H_
#define _AFND_H_
#include "alfabeto.hpp"
#include "estado.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
namespace CYA{
    class afnd_t{
        private:
            estado_t* est_prin_;    // estado principal/inicial.
            alfabeto_t alfabeto_;   // el alfabeto
            int n_est_; // nº de estados totales
            int est_inic_;
            std::vector<estado_t*> cjt_est_; // es un conjunto de estados para manejarlos mejor
            bool es_dfa_;
            void preparar_vector(int);
            void comprobar_si_dfa(void);
        public:
            afnd_t(void);
            ~afnd_t(void);

            void lee(std::ifstream&);
            bool es_dfa(void);
            std::ostream& mostrar_est_muerte(std::ostream&);
            std::ostream& mostrar_nfa(std::ostream&);
            //void analizar_cad(std::istream&);
    };
}
#endif // _AFND_H_
