#include "calculosalario.h"

float CalculoSalario::salarioBruto() const{
    return m_salarioBruto;
}
float CalculoSalario::descuento() const{
    return m_descuento;
}
float CalculoSalario::salarioNeto() const{
    return m_salarioNeto;
}

QString CalculoSalario::getJornada(){
    switch(trabajadores->jornada()){
    case 'V':
        return "Vespertina";
        break;
    case 'M':
        return "Matutina";
        break;
    case 'N':
        return "Nocturna";
        break;
    }
    return "N/D";
}

CalculoSalario::CalculoSalario(QObject *parent) : QObject(parent){
}

CalculoSalario::CalculoSalario(Trabajadores &trabajadores)
{
    this->trabajadores = &trabajadores;
}

void CalculoSalario::calcular(){
    float  valorHora = 0;
    switch(trabajadores->jornada()){
    case 'V':
        valorHora = VALOR_HORA_VESPERTINO;
        break;
    case 'M':
        valorHora = VALOR_HORA_MATUTINO;
        break;
    case 'N':
        valorHora = VALOR_HORA_NOCTURNO;
        break;
    }
    m_salarioBruto = trabajadores->horas() * valorHora;
    m_descuento = m_salarioBruto * PORCENTAJE_DESCUENTO /100;
    m_salarioNeto = m_salarioBruto - m_descuento;
}

QString CalculoSalario::resultado(){
    QString str;
    str = "Obrero: " + trabajadores->nombre() + "\n";
    str += "Horas: " + QString::number(trabajadores->horas()) + "\n";
    str += "Jornada: " + getJornada() + "\n";
    str += "Salario Bruto: $" + QString::number(m_salarioBruto) + "\n";
    str += "Descuento: $" + QString::number(m_descuento) + "\n";
    str += "Salario Neto: $" + QString::number(m_salarioNeto) + "\n\n";
    return str;
}
