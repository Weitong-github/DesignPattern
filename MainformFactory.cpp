#include "FileSpliiterFactory.h"

// MainForm应该依赖于抽象类，而不依赖于具体类

class MainForm {
    // TextBox* txtFilePath;
    // TextBox* txtFileNumber;
    // ProgressBar* proggressBar;
    SplitterFactory* factory;

public:
    MainForm(SplitterFactory* f) : factory(f) {}

    void Button1_Click() {

        ISplitter* splitter = factory->Create();

        splitter->split();
    }
};

// 依赖倒置原则