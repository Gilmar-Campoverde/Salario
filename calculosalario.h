#ifndef CALCULOSALARIO_H
#define CALCULOSALARIO_H
#include <QObject>
#include "trabajadores.h"

class CalculoSalario : public QObject
{
    Q_OBJECT
    Q_PROPERTY(float salarioBruto READ salarioBruto)
    Q_PROPERTY(float descuento READ descuento)
    Q_PROPERTY(float salarioNeto READ salarioNeto)
private:
    float const VALOR_HORA_MATUTINO = 5.15;
    float const VALOR_HORA_VESPERTINO = 8.50;
    float const VALOR_HORA_NOCTURNO = 12.65;
    float const PORCENTAJE_DESCUENTO = 9.5;

    Trabajadores *trabajadores;
    float m_salarioBruto;
    float m_descuento;
    float m_salarioNeto;
    QString getJornada();

public:
    explicit CalculoSalario(QObject *parent = nullptr);
    CalculoSalario(Trabajadores &trabajadores);
    void calcular();
    QString resultado();

    float salarioBruto() const;
    float descuento() const;
    float salarioNeto() const;
signals:

};
#endif // CALCULOSALARIO_H
