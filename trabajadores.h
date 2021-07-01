#ifndef TRABAJADORES_H
#define TRABAJADORES_H
#include <QObject>

class Trabajadores{

private:
    QString m_nombre;
    int m_horas;
    char m_jornada;
public:
    Trabajadores(QString nombre, int horas, char jornada);
    QString nombre() const;
    int horas() const;
    char jornada() const;
};

#endif // TRABAJADORES_H
