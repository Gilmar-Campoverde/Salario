#include "trabajadores.h"

Trabajadores::Trabajadores(QString nombre, int horas, char jornada)
{
    m_nombre = nombre;
    m_horas = horas;
    m_jornada = jornada;
}

QString Trabajadores::nombre() const{
    return m_nombre;
}
int Trabajadores::horas() const{
    return m_horas;
}
char Trabajadores::jornada() const{
    return m_jornada;
}
