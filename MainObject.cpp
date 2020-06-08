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
    if (MManager::instance().isMatlabAvailable()) {
        std::cout << "MATLAB library is available." << std::endl;
        std::cout << "MATLAB C Library is found at:\""
                  << QDir::toNativeSeparators(MManager::instance().matlabDir().absolutePath()).toStdString()
                  << "\"" << std::endl;
        if (MLibs::instance().mxEngine().loadLib() && MLibs::instance().mxMatrix().loadLib()) {
            std::cout << "MATALB engine library loaded!" << std::endl;
            std::cout << "\nStart task - Generating a strong password...\n"  << std::endl;
            runCommand();
            std::cout << "Task completed."  << std::endl;
            MLibs::instance().mxEngine().unloadLib();
            MLibs::instance().mxMatrix().unloadLib();            
        }
        else {
            std::cout << "Failed to load MATALB engine library!" << std::endl;
        }
    }
    else {
        std::cout << "MATLAB is not available." << std::endl;
    }
    // End of implementation

    // End of run. Emit signal
    emit finished();
    std::cout << "Thread end" << std::endl;
}

int MainObject::runCommand() {
    GET_FP(MLibs::instance().mxMatrix().lib(),mxArrayToString,mxArrayToString)
    GET_FP(MLibs::instance().mxMatrix().lib(),mxDestroyArray,mxDestroyArray)
    int engineId = 0;
    std::cout << "\tSummon MATLAB computational engine..." << std::endl;
    MInterface eng = MManager::instance().getEngineById(engineId);
    std::cout << "\tLet's use MATLAB to generat a strong password" << std::endl;
    eng.runCommand("rng(round(second(datetime('now'))));r = floor(rand(1,16)*93)+33;password=char(r);");
    std::cout << "\tDone! Retriving output from MATLAB computational engine...." << std::endl;
    mxArray* mPassword = eng.getVar("password");
    std::string password = mxArrayToString(mPassword);    
    std::cout << "\tGenerated password: " << password << std::endl;
    std::cout << "\tClosing MATLAB engine..." << std::endl;
    MManager::instance().deleteEngineById(engineId);
    std::cout << "\tPreparing to save the password to a MAT file \"savedPassword.mat\"..." << std::endl;
    if (MLibs::instance().mxMat().loadLib()) { // Save the output to a MAT file
        GET_FP(MLibs::instance().mxMat().lib(),matOpen,matOpen)
        GET_FP(MLibs::instance().mxMat().lib(),matPutVariable,matPutVariable)
        GET_FP(MLibs::instance().mxMat().lib(),matClose,matClose)
        MATFile *pmat;
        pmat = matOpen("savedPassword.mat","w");
        if (pmat) {
            matPutVariable(pmat,"password",mPassword);
            matClose(pmat);
        }
        std::cout << "\tDone!" << std::endl;
    }
    mxDestroyArray(mPassword);
    return  0;
}
