#include "afnd.hpp"

namespace CYA{
    afnd_t::afnd_t(void){}

    afnd_t::~afnd_t(void){
        for(int i=1; i<cjt_est_.size(); i++)
            delete cjt_est_[i];
    }


    void afnd_t::lee(std::ifstream& ifs){
        if(ifs.is_open()){
            int id_aux, n_trans, id_sig;
            bool acepta;
            char trans;

            ifs >> n_est_;
            ifs >> est_inic_;
            preparar_vector(n_est_);
            est_prin_ = cjt_est_[est_inic_];
            for(int i=0; i<n_est_; i++){
                ifs >> id_aux;
                ifs >> acepta;
                if(acepta)
                    cjt_est_[id_aux]->poner_acepta();
                ifs >> n_trans;
                cjt_est_[id_aux]->dar_ntrans(n_trans);
                for(int j=0; j<n_trans; j++){
                    ifs >> trans;
                    alfabeto_.dar_simb(trans);
                    ifs >> id_sig;
                    cjt_est_[id_aux]->dar_estado(trans, cjt_est_[id_sig]);
                }
                cjt_est_[id_aux]->estoy_muerto();
            }
            comprobar_si_dfa();
        }else{
            std::cerr << "No se pudo abrir el archivo" << std::endl;
            exit(EXIT_FAILURE);
        }
    }

    void afnd_t::preparar_vector(int tam){
        cjt_est_.resize(tam);
        for(int i=0; i<cjt_est_.size(); i++){
            cjt_est_[i] = new estado_t;
            cjt_est_[i]->dar_id(i);
        }
    }

    std::ostream& afnd_t::mostrar_est_muerte(std::ostream& os){
        for(int i=0; i<cjt_est_.size(); i++)
            if(cjt_est_[i]->es_muerte())
                os << 'q' << i;
    }

    void afnd_t::comprobar_si_dfa(void){
        if(alfabeto_.esta_simb('~')){
            std::cout << "Se encontró ~" << std::endl;
            es_dfa_ = false;
            return;
        }

        for(int i=0; i<cjt_est_.size(); i++){
            if(cjt_est_[i]->extra_trans()){
                es_dfa_ = false;
                return;
            }
        }

        es_dfa_=true;
    }

    bool afnd_t::es_dfa(void){
        return es_dfa_;
    }
    
    /*
    void afnd_t::analizar_cad(void){
        std::string cadena;
        std::vector<estado_t*> vect_est;
        estado_t* estado_aux=est_prin_;
        estado_t* estado_trans=NULL; // estado transición antiguo
    }
    */

    std::ostream& afnd_t::mostrar_nfa(std::ostream& os){
        os << n_est_ << std::endl;
        os << est_inic_ << std::endl;
        for(int i=0; i<n_est_; i++){
            os << cjt_est_[i]->obt_id() << ' ';
            os << cjt_est_[i]->es_acepta() << ' ';
            os << cjt_est_[i]->obt_ntrans() << ' ';
            cjt_est_[i]->mostrar_trans_est(std::cout);
            os << std::endl;
        }
    }
}
