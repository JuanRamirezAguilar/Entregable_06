#ifndef MENUMEDICOS_H
#define MENUMEDICOS_H

#include "ArchivoMedico.h"

class menuMedicos {
    private:
        std::string opc;
        ArchivoMedico miArchivoMedico;

    public:
        menuMedicos();
        ~menuMedicos();

        void setOpc(std::string valorOpc);
        std::string getOpc();

        void menu();
        void agregar();
        void eliminar();
        void buscar();
        void importarArchivo();
};

#endif