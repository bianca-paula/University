#pragma once

#include <qwidget.h>
#include"Service.h"
#include <qlistwidget.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include "Domain.h"
#include <QtWidgets/QMainWindow>
#include "ui_GUI.h"

class GUI : public QMainWindow
{
    Q_OBJECT

public:
    GUI(Service& service, QWidget* parent = Q_NULLPTR);

private:
    Ui::GUIClass ui;
    Service& service;

    void populateProject();
    void createConnections();
    int getSelectedIndex();


    void sortElements();

    void showCars();
    //int get_selected_index(QListWidget* list);



};
