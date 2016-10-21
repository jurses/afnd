#include "estado.hpp"
namespace CYA{
    estado_t::estado_t(void):
        acepta_(false),
        muerte_(false),
        n_trans_(0)
    {}

    estado_t::~estado_t(void){
    }

    void estado_t::poner_muerte(void){
        acepta_=false;
        muerte_=true;
    }

    void estado_t::poner_acepta(void){
        acepta_=true;
        muerte_=false;
    }

    void estado_t::dar_estado(char a, estado_t* est_sig){
        estado_[a].push_back(est_sig);
        trans_.push_back(a);
    }

    estado_t* estado_t::obt_estado(char a, int x){
        return estado_[a][x];
    }

    int estado_t::obt_id(void){
        return id_;
    }

    void estado_t::dar_id(int id){
        id_=id;
    }

    int estado_t::obt_ntrans(void){
        return n_trans_;
    }

    void estado_t::dar_ntrans(int n_trans){
        n_trans_=n_trans;
    }

    bool estado_t::tiene_trans(void){
        return !estado_.empty();
    }

    bool estado_t::es_acepta(void){
        return acepta_;
    }

    bool estado_t::es_muerte(void){
        return muerte_;
    }

    char estado_t::obt_trans(int x){
        if(x>=trans_.size()){
            std::cerr << "Acceso a la transición con índice" << x
                << " equivocado" << std::endl;
            exit(EXIT_FAILURE);
        }
        return trans_[x];
    }

    bool estado_t::trans_ig(char a){
        return !estado_[a].empty();
    }

    int estado_t::n_mismas_trans(char a){
        return estado_[a].size();
    }

    void estado_t::estoy_muerto(void){
        if(acepta_)
            return;
        std::map<char, std::vector<estado_t*>>::iterator it=estado_.begin();
        while(it!=estado_.end()){
            for(int i=0; i<it->second.size(); i++){
                if(this!=it->second[i]){
                    muerte_=false;
                    return;
                }
            }
            it++;
        }
        muerte_=true;
    }

    bool estado_t::tengo_suceso(void){
        return !estado_.empty();
    }

    bool estado_t::extra_trans(void){
        std::map<char, std::vector<estado_t*>>::iterator it=estado_.begin();
        while(it!=estado_.end()){
            if(it->second.size()>1)
                return true;
            it++;
        }
        return false;
    }

    std::ostream& estado_t::mostrar_trans_est(std::ostream& os){
        std::map<char, std::vector<estado_t*>>::iterator it=estado_.begin();
        while(it!=estado_.end()){
            for(int i=0; i< it->second.size(); i++){
                os << it->first << ' ';
                os << it->second[i]->obt_id() << ' ';
            }
            it++;
        }
        
        return os;
    }
}
