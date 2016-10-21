#ifndef _ESTADO_H_
#define _ESTADO_H_
#include <map>
#include <vector>
#include <iostream>
#include <cstdlib>
namespace CYA{
    class estado_t{
        private:
            std::map<char, std::vector<estado_t*>> estado_;
            bool muerte_;
            bool acepta_;
            int id_;
            int n_trans_;
            std::vector<char> trans_;   // vector con las transiciones totales
        public:
            estado_t(void);
            ~estado_t(void);

            void poner_muerte(void);
            void poner_acepta(void);

            bool es_muerte(void);
            bool es_acepta(void);
            bool tiene_trans(void);

            estado_t* obt_estado(char, int=0); // obtiene el estado según la transición
            void dar_estado(char, estado_t*); // da el estado siguiente según transición

            int obt_id(void);
            void dar_id(int);

            int obt_ntrans(void);
            void dar_ntrans(int);

            void estoy_muerto(void);
            bool tengo_suceso(void);
            bool extra_trans(void);

            char obt_trans(int);
            bool trans_ig(char);
            int n_mismas_trans(char);
            
            virtual std::ostream& mostrar_trans_est(std::ostream&);
    };
}
#endif // _ESTADO_H
