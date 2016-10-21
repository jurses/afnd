#include "alfabeto.hpp"

namespace CYA{
    alfabeto_t::alfabeto_t(void){}
    alfabeto_t::~alfabeto_t(void){}

    void alfabeto_t::dar_simb(char a){
        alfabeto_.insert(a);
    }

    void alfabeto_t::camb_simb_vac(char a){
        simb_vacio_ = a;
        alfabeto_.insert(a);
    }

    char alfabeto_t::obt_simb_vac(void){
        return simb_vacio_;
    }

    bool alfabeto_t::esta_simb(char a){
        std::set<char>::iterator it=alfabeto_.begin();
        while(it!=alfabeto_.end()){
            if(*it == a)
                return true;
            it++;
        }

        return false;
    }
}
