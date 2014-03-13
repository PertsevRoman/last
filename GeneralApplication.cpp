/* 
 * File:   GeneralApplication.cpp
 * Author: joker
 * 
 * Created on 2 Март 2014 г., 0:41
 */
#include "GeneralApplication.h"

GeneralApplication::GeneralApplication(const Wt::WEnvironment& env) : Wt::WApplication(env) {
    init();
    sets();
}

GeneralApplication::~GeneralApplication() {
}

void GeneralApplication::init() {
    ui = new CentralUI(root());
}

void GeneralApplication::sets() {
    setTitle(Wt::WString::fromUTF8("Система анализа информационной тональности", false));
    
    const std::string *theme = environment().getParameter("theme");
    if(theme) {
        setTheme(new Wt::WCssTheme(*theme));
    } else {
        setTheme(new Wt::WBootstrapTheme(this));
    }
    
    root()->setLayout(new Wt::WVBoxLayout());
    root()->layout()->addWidget(ui);
}