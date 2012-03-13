#include <QtDebug>
#include "settings.h"
#include "ui_settings.h"

Settings::Settings(QWidget *parent ,QSettings * settings) :
    QDialog(parent),
    ui(new Ui::Settings),
    m_settings(settings)
{
    ui->setupUi(this);

    connect(ui->buttonBox,SIGNAL(accepted()),this,SLOT(changesAccepted()));

}

Settings::~Settings()
{
    delete ui;
}

void Settings::showEvent(QShowEvent * event)
{
    qWarning()<<  "Settings : form show" ;

    //Load Settings
    if (m_settings != NULL) {
        if (m_settings->contains("MaxNoOfLines"))
            ui->sbMaxNoOfRawDataLines->setValue(m_settings->value("MaxNoOfLines").toInt());
        else
            ui->sbMaxNoOfRawDataLines->setValue(50);
    }

}

void Settings::changesAccepted()
{
    qWarning()<<  "Settings : changes accepted" ;

    //Save Settings
    if (m_settings != NULL) {
        m_settings->setValue("MaxNoOfLines",ui->sbMaxNoOfRawDataLines->value());
    }

}