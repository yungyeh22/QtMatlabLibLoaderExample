#include "MainObject.h"
#include <iostream>
#include <Matlab/MatlabEngineManager.h>

MainObject::MainObject(QObject *parent) {
    Q_UNUSED(parent)
}

MainObject::~MainObject() {

}

void MainObject::run() {
    std::cout << "Thread is starting" <<std::endl;
    // Implementation

    // End of implementation

    // End of run. Emit signal
    emit finished();
    std::cout << "Thread end" << std::endl;
}

int MainObject::runCommand() {

    return  0;
}
