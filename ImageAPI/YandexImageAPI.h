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
#include <Wt/WString>

#include <cstdlib>
#include <iostream>
#include <fstream>

#include <boost/system/error_code.hpp>
#include <boost/regex.hpp>
#include <boost/foreach.hpp>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int_distribution.hpp>

#include <htmlcxx/html/ParserDom.h>

#include "ImageAPI.h"

class YandexImageAPI : public ImageAPI {
    std::string                 cache;
    Wt::Http::Client            *publicClient;
    Wt::Http::Client            *apiClient;
    
    htmlcxx::HTML::ParserDom    *parser;
    boost::random::mt19937      gen;
    
    std::string              imageURL;
    std::vector<std::string> tags;
    
    bool operating;
    
    std::ofstream f;
    
public:
    YandexImageAPI();
    YandexImageAPI(const YandexImageAPI& orig);
    virtual ~YandexImageAPI();
    
    void request();
    void request(const std::string& tag);
    
    std::vector<std::string> getTags();
    std::string getImageLink();
    
    bool onOperating();
    
private:
    void analysePublicAnswer(boost::system::error_code err, const Wt::Http::Message& response);
    void analyseAPIAnswer(boost::system::error_code err, const Wt::Http::Message& response);
    void extractTags();
    void extractImageLink();
    std::vector<std::string> extractUsers();
    std::vector<std::string> getEntries(const std::string& base) const;
    
    void init();
    void sets();
};

#endif	/* YANDEXIMAGEAPI_H */

