/* 
 * File:   YandexImageAPI.cpp
 * Author: joker
 * 
 * Created on 13 Март 2014 г., 13:27
 */

#include <Wt/WString>

#include "YandexImageAPI.h"

YandexImageAPI::YandexImageAPI() : ImageAPI() {
    client = new Wt::Http::Client();
}

YandexImageAPI::YandexImageAPI(const YandexImageAPI& orig) {
}

YandexImageAPI::~YandexImageAPI() {
    delete client;
}

void YandexImageAPI::analyse(boost::system::error_code err, const Wt::Http::Message& response) {
    if(!cache.empty()) {
        cache.clear();
    }
    
    /*Работа с файлом*/
    std::ofstream f;
    f.open("out.txt");
    
    f << "Start request. Code: " << response.status() << std::endl;
    
    if(response.status() == 200 || response.status() == 304) {
        cache = response.body();
        
        f << cache;
        
        extractTags();
        extractImageLink();
    } else {
        cache = std::string();
        f << "Error: " << err.message() << std::endl;
    }
    
    f.close();
}

void YandexImageAPI::extractTags() {
}

void YandexImageAPI::extractImageLink() {
}

void YandexImageAPI::request() {
    client->done().connect(this, &YandexImageAPI::analyse);
    client->setTimeout(30);
    client->get("http://fotki.yandex.ru/search.xml?text=лимон");
}

void YandexImageAPI::request(const std::string& tag) {
    setTag(tag);
    request();
}

std::string YandexImageAPI::getImageLink() {
    std::string res;
    
    return res;
}

std::vector<std::string> YandexImageAPI::getTags() {
    std::vector<std::string> res;
    
    return res;
}