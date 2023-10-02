#include "menuPrincipal.h"

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

#define ALTURA_BORDE 100
#define ANCHURA_BORDE 150
#define ANCHURA_PANTALLA 1366
#define ALTURA_PANTALLA 768

const std::string Titulo = "Sistema Integral de Registros Medicos";

MenuPrincipal::MenuPrincipal() : opc("") {
    std::string nameFile = "";
    std::cout << "Dame el nombre del archivo a importar(Si antes ya importaste el archivo, deja el espacio en blanco): ";
    fflush(stdin);
    std::getline(std::cin, nameFile);
    if (!nameFile.empty()) {
        miFileMaster.importBackup("archivo_consultas.file");
    }
    miMenuMedicos.importarArchivo();
}

MenuPrincipal::~MenuPrincipal() {}

void MenuPrincipal::setOpc(std::string valorOpc) { opc = valorOpc; }
std::string MenuPrincipal::getOpc() { return opc; }

void MenuPrincipal::menu() {
    std::string opciones;
    AltEnter();
    do {
        system(CLEAR);
        std::cout<<ARB; setborder(ALTURA_BORDE, ANCHURA_BORDE); std::cout<<RTNC;

        gotoxy(((ANCHURA_BORDE - int(Titulo.length())) / 2), 3);
        std::cout << VB << Titulo <<RTNC;

        gotoxy(3, 7);
        std::cout <<GB; std::cout << "Opciones del Menu:";
        gotoxy(3, 9);
        std::cout <<GB; std::cout << "Consultas.           [ " <<RF<< "A" <<GB " ]";
        gotoxy(3, 10);
        std::cout <<GB; std::cout << "Medicos.             [ " <<RF<< "B" <<GB " ]";
        gotoxy(3, 11);
        std::cout <<GB; std::cout << "Pacientes.           [ " <<RF<< "C" <<GB " ]";
        gotoxy(3, 12);
        std::cout <<GB; std::cout << "Diagnosticos.        [ " <<RF<< "D" <<GB " ]";
        gotoxy(3, 13);
        std::cout <<GB; std::cout << "Medicamentos.        [ " <<RF<< "E" <<GB " ]";
        gotoxy(3, 14);
        std::cout <<GB; std::cout << "Salir del programa.  [ " <<RF<< "X" <<GB " ]";

        gotoxy(3, 16);
        std::cout <<GB << "Tu opcion ==> ";
        gotoxy(18, 16);
        std::cout <<RF; std::getline(std::cin, opciones); setOpc(opciones); std::cout <<RTNC;

        if (opc == "A" or opc == "a") { consultas(); }
        else if (opc == "B" or opc == "b") { medicos(); }
        else if (opc == "C" or opc == "c") { enConstruccion(); }
        else if (opc == "D" or opc == "d") { enConstruccion(); }
        else if (opc == "E" or opc == "e") { enConstruccion(); }
        else if (opc == "X" or opc == "x") { salir(); }

        else { gotoxy(3, 18); std::cout <<GB; std::cout << "La opcion: \"" <<RB<< opc <<GB<< "\" no es una opcion valida..."<<RTNC; pausa(); }

    } while (opc != "X" and opc != "x");
}

void MenuPrincipal::salir() {
    gotoxy(3, 18);
    std::cout <<RB; std::cout << "Saliendo del programa..."<<RTNC; timeStop(2000);
}

void MenuPrincipal::consultas() {
    miMenuConsultas.menu();
}

void MenuPrincipal::medicos() {
    miMenuMedicos.menu();
}

void MenuPrincipal::pacientes() {

}

void MenuPrincipal::diagnosticos() {

}

void MenuPrincipal::medicamentos() {

}

void MenuPrincipal::enConstruccion() {
    gotoxy(3, 18); std::cout << RB << "Esta opcion del programa esta en construccion..."<<RTNC; pausa();
}