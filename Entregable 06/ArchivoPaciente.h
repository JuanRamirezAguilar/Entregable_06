#ifndef ARCHIVOPACIENTE_H
#define ARCHIVOPACIENTE_H

#include <fstream>
#include <string>
#include <sstream>

#include "Lista.h"

#include "Paciente.h"
#include "Nombre.h"
#include "Consulta.h"

#include "indexDuple.h"

#define NombreArchivo "archivoPacientes.txt"
#define archivoIndicePorNombre "archivoPacientesNombre.txt"
#define archivoIndicePorSeguroSocial "archivoPacientesSeguro.txt"

class ArchivoPaciente {
    private:
        std::fstream archivo;
        std::fstream indicePorNombre; // int, Nombre
        std::fstream indicePorSeguroSocial; // int, int

        Lista<indexDuple<int>> indexadoPorNombre;
        Lista<indexDuple<int>> indexadoPorSeguro;

        void reIndex();

        template <class T>
        Lista<indexDuple<T>> fileToList(std::fstream, Lista<indexDuple<T>>);

        template <class T>
        Lista<indexDuple<T>> listToFile(const Lista<indexDuple<T>>&, std::fstream&);

        template <class T>
        int getIndex(const Lista<T>&, const T&);

    public:
        ArchivoPaciente();
        ~ArchivoPaciente();
        void addData(const Paciente&);
        void addData(const Lista<Paciente>&);
        void delData(const int&);
        int findData(const Paciente&);
        void clear();

        void compress();
        Lista<Consulta> importBackup(std::string&);
        void exportBackup(std::string&);
};

#endif