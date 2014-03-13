/* 
 * File:   GeneralApplication.h
 * Author: joker
 * Основной класс приложения
 * Created on 2 Март 2014 г., 0:41
 */

#ifndef GENERALAPPLICATION_H
#define	GENERALAPPLICATION_H

#define BOOST_SIGNALS_NO_DEPRECATION_WARNING

#include <Wt/WApplication>
#include <Wt/WEnvironment>
#include <Wt/WString>
#include <Wt/WVBoxLayout>
#include <Wt/WContainerWidget>
#include <Wt/WCssTheme>
#include <Wt/WBootstrapTheme>

#include "GUI/CentralUI.h"

class GeneralApplication : public Wt::WApplication {
    CentralUI           *ui;
    
public:
    GeneralApplication(const Wt::WEnvironment& env);
    virtual ~GeneralApplication();
    
private:
    void init();
    void sets();
};

#endif	/* GENERALAPPLICATION_H */

