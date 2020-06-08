# QtMatlabLibLoaderExample
A solution to run MATLAB with a C++ project. 
This project provides a solution to run MATLAB computational engine with a C++ project. As it also
* automatically locates current active MATLAB directory 
* dynamically loads MATLAB library
* provides a means to create MAT file from a C++ project (No MATLAB license or activation require)
* manages multiple process or multiple thread for MATLAB computation
* uses Qt for cross-platform solution

## Getting Started
*`This is not an standalone application but an example demonstrate how to make MATLAB work with a C++ project`*
In this project, we use the MATLAB engine to generate a random strong password and store the output to a MAT file. It's particular useful for a C++ research project that requires MATLAB computational power. The capability of writing output to a MAT file is helpful for analysing data in MATLAB afterwards. An interesting use of writing a MATLAB is that we can create a application to save output data to a MAT file without activating MATLAB at all, as long as you have a MATLAB bin library existing in the according location (such as `\Program Files\MATLAB\R2019a\bin\win64`). 

### Prerequisites
You will need either MinGw or MSVC compilier
The choice of environments can be either Qt5 or Visual Studio 2015+
Qt5 - [Qt](https://www.qt.io/download?utm_referrer=https%3A%2F%2Fwww.qt.io%2F)
MATLAB - [MATLAB](https://www.mathworks.com/products/matlab.html)

### Installing
*`This is not an standalone application but an example demonstrate how to make MATLAB work with a C++ project`*
You may open the project file "QtMatlabLibLoader.pro" with the Qt IDE and set up the project. The following steps will get you compile this sample project.
* Pull the repository to a local directory. 
* Change directory to the root of local repository.
* Compile with the following command under QT's command prompt window (MinGw)
```sh
qmake QtMatlabLibLoader.pro "CONFIG+=release"
mingw32-make.exe -j4
```
* Go to "release" subfolder and run the "QtMatlabLibLoader.exe"

## Deployment
*`This is not an standalone application but an example demonstrate how to make MATLAB work with a C++ project`*
You are free to distribute the souce as long you fulfill the open source distribution requirements.

## Authors
* **Yung-Yeh Chang** - *Initial work* - [DynamicLinkLib_Qt](https://github.com/yungyeh22/DynamicLinkLib_Qt)

## License
This project is licensed under the MIT License
