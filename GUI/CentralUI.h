/* 
 * File:   CentralUI.h
 * Author: joker
 *
 * Created on 2 Март 2014 г., 0:44
 */

#ifndef CENTRALUI_H
#define	CENTRALUI_H

#define BOOST_SIGNALS_NO_DEPRECATION_WARNING
#define RU(x) Wt::WString::fromUTF8(x)

#include <Wt/WContainerWidget>
#include <Wt/WGridLayout>
#include <Wt/WText>
#include <Wt/WNavigationBar>
#include <Wt/WPanel>
#include <Wt/WVBoxLayout>
#include <Wt/WLength>
#include <Wt/WPushButton>
#include <Wt/WToolBar>
#include <Wt/WStackedWidget>

#include "DictionaryFiller.h"

class CentralUI : public Wt::WContainerWidget {
    Wt::WGridLayout     *lay;
    Wt::WNavigationBar  *naviBar;
    Wt::WVBoxLayout     *toolsLay;
    /*Инструментарий для работы со словарем*/
    Wt::WPanel          *vocabInst;
    Wt::WToolBar        *vocabTools;
    Wt::WPushButton     *vocabTableEdit;
    Wt::WPushButton     *vocabFill;
    Wt::WPushButton     *vocabDump;
    /*Инструменарий для оценивания информационного поля*/
    Wt::WPanel          *infSphereInst;
    Wt::WToolBar        *infSphereTools;
    Wt::WPushButton     *search;
    Wt::WPushButton     *createReport;
    /*Обработчик словаря*/
    Wt::WStackedWidget  *opDocks;
    DictionaryFiller           *mapFiller;
    
public:
    CentralUI(Wt::WContainerWidget* parent = 0);
    CentralUI(const CentralUI& orig);
    virtual ~CentralUI();
    
private:
    void init();
    void sets();
};

#endif	/* CENTRALUI_H */

