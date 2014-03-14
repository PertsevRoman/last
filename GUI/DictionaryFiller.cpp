/* 
 * File:   MapFiller.cpp
 * Author: joker
 * 
 * Created on 9 Март 2014 г., 1:07
 */
#include "DictionaryFiller.h"

DictionaryFiller::DictionaryFiller(Wt::WContainerWidget* parent) : Wt::WContainerWidget(parent) {
    init();
    sets();
}

DictionaryFiller::DictionaryFiller(const DictionaryFiller& orig) {
}

DictionaryFiller::~DictionaryFiller() {
}

void DictionaryFiller::init() {
    header      = new Wt::WText(RU("Оценка тональности лексических единиц"));
    lay         = new Wt::WGridLayout();
    image       = new Wt::WImage();
    markSlider  = new Wt::WSlider(Wt::Vertical);
    send        = new Wt::WPushButton(RU("Оценить"));
    
    ya = new YandexImageAPI();
}

void DictionaryFiller::sets() {
    setLayout(lay);
    
    lay->addWidget(header, 0, 0, 1, 2);
    lay->addWidget(image, 1, 0, 2, 1);
    lay->addWidget(markSlider, 1, 1, 1, 1);
    lay->addWidget(send, 2, 1, 1, 2);
    
    lay->setRowStretch(1, 1);
    lay->setColumnStretch(0, 1);
    
    markSlider->setRange(0, 10);
    
    ya->setTag("танк");
    
    send->clicked().connect(this, &DictionaryFiller::startYA);
}

void DictionaryFiller::startYA() {
    ya->request();
}