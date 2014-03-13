/* 
 * File:   YandexImageAPI.h
 * Author: joker
 *
 * Created on 13 Март 2014 г., 13:27
 */

#ifndef YANDEXIMAGEAPI_H
#define	YANDEXIMAGEAPI_H

#define BOOST_SIGNALS_NO_DEPRECATION_WARNING
#define RU(x) Wt::WString::fromUTF8(x)

#include <Wt/Http/Client>
#include <Wt/Http/Message>

#include <cstdlib>
#include <iostream>
#include <fstream>

#include <boost/system/error_code.hpp>

#include "ImageAPI.h"

class YandexImageAPI : public ImageAPI {
    std::string         cache;
    Wt::Http::Client    *client;
    
public:
    YandexImageAPI();
    YandexImageAPI(const YandexImageAPI& orig);
    virtual ~YandexImageAPI();
    
    void request();
    void request(const std::string& tag);
    
    std::vector<std::string> getTags();
    std::string getImageLink();
    
private:
    void analyse(boost::system::error_code err, const Wt::Http::Message& response);
    void extractTags();
    void extractImageLink();
};

#endif	/* YANDEXIMAGEAPI_H */

