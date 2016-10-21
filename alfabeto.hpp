#ifndef _ALFABETO_H_
#define _ALFABETO_H_
#include <set>
namespace CYA{
    class alfabeto_t{
        private:
            std::set<char> alfabeto_;
            char simb_vacio_='~';   // OJO, no está añadido pero lo reconoce
        public:
            alfabeto_t(void);
            ~alfabeto_t(void);

            void dar_simb(char);
            void camb_simb_vac(char);
            char obt_simb_vac(void);

            bool esta_simb(char);
    };
}
#endif //_ALFABETO_H_
