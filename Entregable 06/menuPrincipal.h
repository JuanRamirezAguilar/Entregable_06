#ifndef MENUPRINCIPAL_H
#define MENUPRINCIPAL_H

#include <string>
#include "fileMaster.h"
#include "menuConsultas.h"
#include "menuMedicos.h"

#include "StandarLibrary.h"
#include "Colores.h"

class MenuPrincipal {
    private:
        std::string opc;

        fileMaster miFileMaster;
        MenuConsultas miMenuConsultas;
        menuMedicos miMenuMedicos;
    
    public:    
        MenuPrincipal();
        ~MenuPrincipal();

        void setOpc(std::string);
        std::string getOpc();
        void menu();
        void salir();
        void consultas();
        void medicos();
        void pacientes();
        void diagnosticos();
        void medicamentos();
        void enConstruccion();
};

#endif