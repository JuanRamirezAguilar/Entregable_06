#include "Paciente.h"

#include <iostream>

// Constructores
Paciente::Paciente() : numSeguroSocial(""), telefono(0) {} // default
Paciente::Paciente(Nombre nom, std::string nss, Fecha fdn, Domicilio dom, long long tel) : nombre(nom), numSeguroSocial(nss),
fechaDeNacimiento(fdn), domicilio(dom), telefono(tel) {} // Paremetrizado
Paciente::Paciente(const Paciente& copia) : nombre(copia.nombre), numSeguroSocial(copia.numSeguroSocial),
fechaDeNacimiento(copia.fechaDeNacimiento), domicilio(copia.domicilio), telefono(copia.telefono) {} // Copia

// Destructor
Paciente::~Paciente() {}

// Metodos
std::string Paciente::toString() const{
    return nombre.toString() + ", " + numSeguroSocial + ", " + fechaDeNacimiento.toString()
    + ", " + domicilio.toString() + ", " + std::to_string(telefono);
}

// Setters
void Paciente::setNombre(Nombre valorNombre) {nombre = valorNombre;}
void Paciente::setNumSeguroSocial(std::string valorSeguro) {numSeguroSocial = valorSeguro;}
void Paciente::setFechaDeNacimiento(Fecha valorFecha) {fechaDeNacimiento = valorFecha;}
void Paciente::setDomicilio(Domicilio valorDomiciio) {domicilio = valorDomiciio;}
void Paciente::setTelefono(long long valorTelefono) {telefono = valorTelefono;}

// Getters
Nombre Paciente::getNombre() const {return nombre;}
std::string Paciente::getNumSeguroSocial() const {return numSeguroSocial;}
Fecha Paciente::getFechaDeNacimiento() const {return fechaDeNacimiento;}
Domicilio Paciente::getDomicilio() const {return domicilio;}
long long Paciente::getTelefono() const {return telefono;}

// Operadores
Paciente& Paciente::operator = (const Paciente& copia) {
    if (this == &copia) { return *this; }
    nombre = copia.nombre;
    numSeguroSocial = copia.numSeguroSocial;
    fechaDeNacimiento = copia.fechaDeNacimiento;
    domicilio = copia.domicilio;
    telefono = copia.telefono;
    return *this;
}

bool Paciente::operator == (const Paciente& comparado) const{
    return numSeguroSocial == comparado.numSeguroSocial;
}

bool Paciente::operator == (const Nombre& comparado) const{
    return nombre == comparado;
}

bool Paciente::operator != (const Paciente& comparado) const {
    return numSeguroSocial != comparado.numSeguroSocial;
}

bool Paciente::operator != (const Nombre& comparado) const {
    return nombre != comparado;
}

bool Paciente::operator < (const Paciente& comparado) const {
    return numSeguroSocial < comparado.numSeguroSocial;
}

bool Paciente::operator > (const Paciente& comparado) const {
    return numSeguroSocial > comparado.numSeguroSocial;
}

bool Paciente::operator <= (const Paciente& comparado) const {
    return numSeguroSocial <= comparado.numSeguroSocial;
}

bool Paciente::operator >= (const Paciente& comparado) const {
    return numSeguroSocial >= comparado.numSeguroSocial;
}

std::ostream& operator << (std::ostream& out, const Paciente& objSalida) {
    out << objSalida.nombre << objSalida.numSeguroSocial << "*" << objSalida.fechaDeNacimiento 
    << objSalida.domicilio << objSalida.telefono << "*";
    return out; 
}

std::istream& operator >> (std::istream& in, Paciente& objEntrada) {
    std::string myString;
    Nombre auxNombre;
    Domicilio auxDomicilio;
    Fecha auxFecha;

    std::getline(in, myString, '*');
    objEntrada.setNumSeguroSocial(myString);

    in >> auxNombre;
    objEntrada.setNombre(auxNombre);

    in >> auxFecha;
    objEntrada.setFechaDeNacimiento(auxFecha);

    in >> auxDomicilio;
    objEntrada.setDomicilio(auxDomicilio);

    std::getline(in, myString, '*');
    std::string numero;
    char caracter;
    
    for (int i = 0; i < int(myString.length()); i++) {
        caracter = char(myString[i]);
        if (caracter != ' ') {
            numero += caracter;
        }
        
    }
    if (!std::isdigit(numero[0])) {
        objEntrada.setTelefono(0);
    } else {
        objEntrada.setTelefono(std::stoll(numero));
    }

    return in;
}