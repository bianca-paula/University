#include "GUI.h"
#include <QtWidgets/QApplication>

#include "Repository.h"
#include "Domain.h"
#include "Service.h"
#include<string>
#include<memory>
using namespace std;


int main(int argc, char* argv[])
{
    QApplication a(argc, argv);

    Repository repository{ "file.txt" };

    Service service{ repository };
    service.Test_ShowCars();
    GUI gui{ service };

    

    gui.show();


    return a.exec();
}
