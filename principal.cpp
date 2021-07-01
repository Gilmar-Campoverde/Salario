#include "principal.h"
#include "ui_principal.h"
#include <QDebug>
#include <QMessageBox>

Principal::Principal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Principal)
{
    ui->setupUi(this);
    /*
     * Para leer un archivo sin necesidad de pedirle al usuario el nombre del archivo, path relativo
     *
    QFile f ("archivo_a_leer.txt");
    QTextStream in (&f);
    if (!f.open(QIODevice::ReadOnly)){
        qDebug() << "No se puede  abrir el archivo";
        return;
    }
    while(!in.atEnd()){
        qDebug("%s", qPrintable(in.readLine()));
    }
    f.close();
    */
}

Principal::~Principal(){
    delete ui;
}
void Principal::on_actionSalir_triggered(){
    this->close();
}

void Principal::on_cmdCalcular_clicked(){
    this->calcular();
}

void Principal::on_actionCalcular_triggered(){
    this->calcular();
}

void Principal::on_actionAbrir_triggered(){
    this->abrir();
}

void Principal::calcular(){
    //Obtener los datos
    QString nombre = ui->inNombre->text();
    if(nombre.isEmpty()){
        QMessageBox::warning(this, "Salarios", "No has proporcionado el nombre del obrero");
        return;
    }
    int horas = ui->inHoras->value();
    char jornada = '0';
    if(ui->inMatutina->isChecked()){
        jornada = 'M';
    }else if(ui->inVespertina->isChecked()){
        jornada = 'V';
    }else if (ui->inNocturna->isChecked()){
        jornada = 'N';
    }
    Trabajadores *w = new Trabajadores(nombre, horas, jornada);
    CalculoSalario *obj = new CalculoSalario(*w);
    obj->calcular();
    ui->outResultado->appendPlainText(obj->resultado());
    //borrar o encerar los controles/wigdgets
    this->borrar();
}

void Principal::borrar(){
    ui->inNombre->setText("");
    ui->inHoras->setValue(0);
    ui->inMatutina->setChecked(true);
    ui->inNombre->setFocus();
}

void Principal::nuevo(){
    ui->outResultado->clear();
}

void Principal::abrir()
{
    //Abrir un cuadro de dialogo para seleccionar el nombre y ubicacion del archivo a guardar
    QString fileName = QFileDialog::getOpenFileName(this, tr("Abrir"), QDir::home().absolutePath() , tr("Archivo de Texto (*.txt)"));
        QFile file(fileName);
        // Abrir el archivo si cumple la condicion para solo leerlo
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
            return;
        // declaramos un objeto apuntando a nuestro doc
        QTextStream arch(&file);
        while (!arch.atEnd()) {
            //Guardar la información del archivo
            QString informacion = arch.readAll();
            //Cargamos la información en el widget Plain Text
            ui->outResultado->setPlainText(informacion);
        }
        file.close();
}

void Principal::on_actionNuevo_triggered(){
    this->nuevo();
}

void Principal::on_actionAcerca_de_triggered()
{
    Acerca *acercaDe = new Acerca(this);
    acercaDe->setVersion(VERSION);
    acercaDe->show();
}

void Principal::on_actionGuardar_triggered(){
    //crear un objeto  QDir a partir  del directorio del usuario
    QDir directorio = QDir::home();
    // agregar el path absoluto  del objeto, un nombre por defecto  del archivo
    QString pathArchivo = directorio.absolutePath() + "/sin_nombre.txt";
    // abrir un  cuadro de dialogo  para seleccionar  el nombre  y ubicaion  del archivo a guardar
    QString fileName = QFileDialog::getSaveFileName(this, "Guardar Archivo",
                                                    pathArchivo,
                                                    "Archivo de texto (*.txt)");
    //qDebug() << fileName;
    //crear el archivo a partir del nombre arrojado por el cuadro de dialogo
    QFile f(fileName);
    // crear el objeto QTextStream (permite escribir sobre el archivo)
    QTextStream out(&f);
    // intentar abrir el archivo ya sea para escribir  (si no existe) o para agregar texto (si existiera)
    if(!f.open(QIODevice::WriteOnly | QIODevice::Append)){
        //Si no se puede abrir muestra mensaje de advertencia
        QMessageBox::warning(this, "Salarios", "No se puede abrir el archivo " + fileName);
        //salir de la funcion, no hace nada mas
        return;
    }
    // guardar el contenido del texto de resultado  en el archivo
    out << ui->outResultado->toPlainText();
    // cerrar el archivo siempre
    f.close();
    //mostrar mensaje en la barra de estado
    ui->statusbar->showMessage("Archivo guardado en " + fileName, 3000);
}


