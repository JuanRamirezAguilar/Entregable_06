#include "ArchivoPaciente.h"

//#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>

#include "Paciente.h"
#include "Nombre.h"
#include "Fecha.h"
#include "Domicilio.h"
#include "Hora.h"
#include "Medico.h"
#include "Diagnostico.h"
#include "Medicamento.h"
#include "Consulta.h"

ArchivoPaciente::ArchivoPaciente() {}

ArchivoPaciente::~ArchivoPaciente() {

}

template<class T>
Lista<indexDuple<T>> ArchivoPaciente::fileToList(std::fstream, Lista<indexDuple<T>>) {

}

Lista<Consulta> ArchivoPaciente::importBackup(std::string& nombreArchivo) {
    std::ifstream archivoEntrada;
    archivoEntrada.open(nombreArchivo, std::ios::in);
    Lista<Consulta> miLista;
    if (!archivoEntrada) {
        throw std::runtime_error("Error al abrir el archivo.");
    }

    std::string miCampo;
    while(!archivoEntrada.eof()) {

        std::getline(archivoEntrada, miCampo, '#');
        if (miCampo.empty()) { continue; }

        // Se instancian las clases necesarias
        Nombre miNombre;
        Fecha miFecha;
        Hora miHora;
        Domicilio miDomicilio;
        Paciente miPaciente;
        Medico miMedico;
        Medicamento miMedicamento;
        Diagnostico miDiagnostico;
        Consulta miConsulta;
        std::string codigo;

        std::stringstream flujoDeRegistro(miCampo);

        //std::cout << indice << ")._ " <<std::endl;

        // Toma la fecha de la consulta
        flujoDeRegistro >> miFecha;
        miConsulta.setFecha(miFecha);
        //std::cout << miFecha.toString() <<std::endl;
        
        // Toma la hora de la consulta
        flujoDeRegistro >> miHora;
        miConsulta.setHora(miHora);
        //std::cout << miHora.toString() <<std::endl;

        // Toma el codigo de la consulta
        std::getline(flujoDeRegistro, miCampo, '*');
        miConsulta.setCodigo(miCampo);
        //std::cout << miConsulta.getCodigo() <<std::endl;

        // Toma el Diagnostico de la consulta
        flujoDeRegistro >> miDiagnostico;
        miConsulta.setDiagnostico(miDiagnostico);
        //std::cout << miDiagnostico.toString() <<std::endl;

        // Toma el Medico de la consulta;
        flujoDeRegistro >> miMedico;
        miConsulta.setMedico(miMedico);
        //std::cout << miMedico.toString() <<std::endl;

        // Toma el Paciente de la consulta;
        flujoDeRegistro >> miPaciente;
        miConsulta.setPaciente(miPaciente);
        //std::cout << miPaciente.toString() <<std::endl;

        // Toma el Medicamento de la consulta;
        flujoDeRegistro >> miMedicamento;
        miConsulta.setMedicamento1(miMedicamento);
        flujoDeRegistro >> miMedicamento;
        miConsulta.setMedicamento2(miMedicamento);
        flujoDeRegistro >> miMedicamento;
        miConsulta.setMedicamento3(miMedicamento);

        // Se ingresa en la lista
        miLista.insertar(miConsulta);
        
        //std::cout << miLista.ult()->get_dato().toString();
        //std::cout <<std::endl<<std::endl;
        //indice++;

    }

    archivoEntrada.close();

    return miLista;

}