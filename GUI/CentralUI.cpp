/* 
 * File:   CentralUI.cpp
 * Author: joker
 * 
 * Created on 2 Март 2014 г., 0:44
 */

#include "CentralUI.h"

CentralUI::CentralUI(Wt::WContainerWidget* parent) : Wt::WContainerWidget(parent) {
    init();
    sets();
}

CentralUI::CentralUI(const CentralUI& orig) {
}

CentralUI::~CentralUI() {
}

void CentralUI::init() {
    lay                 = new Wt::WGridLayout();
    naviBar             = new Wt::WNavigationBar();
    toolsLay            = new Wt::WVBoxLayout();
    
    vocabInst           = new Wt::WPanel();
    vocabTools          = new Wt::WToolBar();
    vocabTableEdit      = new Wt::WPushButton(RU("Редактор"));
    vocabFill           = new Wt::WPushButton(RU("Заполнение"));
    vocabDump           = new Wt::WPushButton(RU("Импорт/экспорт"));
    
    infSphereInst       = new Wt::WPanel();
    infSphereTools      = new Wt::WToolBar();
    search              = new Wt::WPushButton(RU("Анализ информационноо поля"));
    createReport        = new Wt::WPushButton(RU("Создание отчета"));
    
    opDocks             = new Wt::WStackedWidget();
    mapFiller           = new DictionaryFiller();
}

void CentralUI::sets() {
    setLayout(lay);
    setStyleClass("yellow-box");
    
    naviBar->setTitle("Blackmore");
    
    lay->addWidget(naviBar, 0, 0, 1, 2);
    lay->addLayout(toolsLay, 1, 0, 1, 1);
    lay->addWidget(opDocks, 1, 1, 1, 1);
    
    toolsLay->addWidget(vocabInst);
    toolsLay->addWidget(infSphereInst);
    toolsLay->addWidget(new Wt::WContainerWidget(), 1);
    
    vocabInst->setTitle(Wt::WString::fromUTF8("Работа со словарем"));
    vocabInst->setCollapsible(true);
    vocabInst->setCentralWidget(vocabTools);
    vocabTools->setMargin(10);
    vocabTools->addButton(vocabTableEdit);
    vocabTools->addButton(vocabFill);
    vocabTools->addButton(vocabDump);
    
    infSphereInst->setTitle(Wt::WString::fromUTF8("Работа с информационным полем"));
    infSphereInst->setCollapsible(true);
    infSphereInst->setCentralWidget(infSphereTools);
    infSphereTools->setMargin(10);
    infSphereTools->addButton(search);
    infSphereTools->addButton(createReport);
    
    opDocks->addWidget(mapFiller);
    opDocks->setCurrentIndex(0);
    
    lay->setRowStretch(1, 1);
    lay->setColumnStretch(1, 1);
}