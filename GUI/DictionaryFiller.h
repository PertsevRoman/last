/* 
 * File:   MapFiller.h
 * Author: joker
 *
 * Created on 9 Март 2014 г., 1:07
 */

#ifndef MAPFILLER_H
#define	MAPFILLER_H

#define BOOST_SIGNALS_NO_DEPRECATION_WARNING
#define RU(x) Wt::WString::fromUTF8(x)

#include <Wt/WContainerWidget>
#include <Wt/WSlider>
#include <Wt/WGridLayout>
#include <Wt/WImage>
#include <Wt/WText>
#include <Wt/WPushButton>

#include "../ImageAPI/YandexImageAPI.h"

class DictionaryFiller : public Wt::WContainerWidget {
    Wt::WGridLayout             *lay;
    Wt::WText                   *header;
    Wt::WSlider                 *markSlider;
    Wt::WImage                  *image;
    Wt::WPushButton             *send;
    
    /*TEST*/
    YandexImageAPI              *ya;
    
public:
    DictionaryFiller(Wt::WContainerWidget* parent = 0);
    DictionaryFiller(const DictionaryFiller& orig);
    virtual ~DictionaryFiller();
    
private:
    void init();
    void sets();
    void startYA();
};

#endif	/* MAPFILLER_H */

