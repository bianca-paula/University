#include "GUI.h"
#include <qmessagebox.h>
#include <algorithm>
#include <vector>
#include <QDebug>
#include<QFont>
GUI::GUI(Service& service, QWidget* parent)
    : QMainWindow(parent), service{ service }
{
    ui.setupUi(this);
    this->populateProject();
    this->createConnections();
}

void GUI::populateProject()
{
    this->ui.elementsListWidget->clear();

    std::vector<Car> elements = this->service.sortElements();
   
    for (auto element : elements) {
        this->ui.elementsListWidget->addItem(QString::fromStdString(element.get_name() + "," + element.get_model()));

    }
}




void GUI::createConnections()
{
    QObject::connect(this->ui.showPushButton, &QPushButton::clicked, this, &GUI::showCars);




}


int GUI::getSelectedIndex()
{
    QModelIndexList indexes = this->ui.elementsListWidget->selectionModel()->selectedIndexes();

    if (indexes.size() == 0)
    {
        return -1;
    }
    int selectedIndex = indexes.at(0).row();
    return selectedIndex;
}





void GUI::sortElements()
{
    this->ui.elementsListWidget->clear();
    vector<Car> elements = this->service.sortElements();

    for (auto element : elements) {
        this->ui.elementsListWidget->addItem(QString::fromStdString(element.get_name() + "," + element.get_model()));

    }
}

void GUI::showCars()
{
    int numberOfCars = 0;
    string manufacturer = this->ui.carsLineEdit->text().toStdString();
    
    numberOfCars = this->service.showCars(manufacturer);
    std::string numberAsString = "";
    numberAsString += std::to_string(numberOfCars);
    QString carString = QString::fromStdString(numberAsString);
    this->ui.numbersLineEdit->setText(carString);
}

