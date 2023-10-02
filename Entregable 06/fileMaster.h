#ifndef FILEMASTER_H
#define FILEMASTER_H

#include <fstream>
#include <string>

#include "Lista.h"

#include "Consulta.h"
#include "indexDuple.h"
#include "Lista.h"

#define NombreArchivo "archivoMedicamentos.txt"
#define archivoIndicePorNombre "archivoConsultasNombre.txt"

class fileMaster {
    private:
        std::fstream archivo;
        Lista<Consulta> misConsultas;
        Lista<Medico> misMedicos;

    public:
        fileMaster();
        ~fileMaster();

        Lista<Consulta> getMisConsultas();
        Lista<Medico> getMisMedicos();

        void importBackup(const std::string&);
};

#endif