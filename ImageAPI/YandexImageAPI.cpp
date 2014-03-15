/* 
 * File:   YandexImageAPI.cpp
 * Author: joker
 * 
 * Created on 13 Март 2014 г., 13:27
 */

#include "YandexImageAPI.h"

YandexImageAPI::YandexImageAPI() : ImageAPI() {
    init();
    sets();
}

YandexImageAPI::YandexImageAPI(const YandexImageAPI& orig) {
}

YandexImageAPI::~YandexImageAPI() {
    delete publicClient;
    delete parser;
    delete apiClient;
}

void YandexImageAPI::analysePublicAnswer(boost::system::error_code err, const Wt::Http::Message& response) {
    if(!cache.empty()) {
        cache.clear();
    }
    
    if(response.status() == 200 || response.status() == 304) {
        cache = response.body();
        
        std::vector<std::string> vec = extractUsers();
        if(vec.size()) {
            boost::random::uniform_int_distribution<> dist(0, vec.size() - 1);
            std::string lucky = vec.at(dist(gen));
            apiClient->get("http://api-fotki.yandex.ru/api/users/" + lucky + "/tag/" + tag + "/photos/");
        } else {
            this->requestFailed();
            operating = false;
        }
    } else {
        this->requestFailed();
        operating = false;
        cache = std::string();
    }
}

bool YandexImageAPI::onOperating() {
    return operating;
}

void YandexImageAPI::analyseAPIAnswer(boost::system::error_code err, const Wt::Http::Message& response) {
    if(!cache.empty()) {
        cache.clear();
    }
    
    if(response.status() == 200 || response.status() == 304) {
        cache = response.body();
        
        std::vector<std::string> entries = getEntries(cache);
        
        if(entries.size()) {
            boost::random::uniform_int_distribution<> dist(0, entries.size() - 1);
            cache = entries.at(dist(gen));

            extractTags();
            extractImageLink();

            this->requestCompleted();
        } else {
            this->requestFailed();
            operating = false;
        }
    } else {
        this->requestFailed();
        operating = false;
        cache = std::string();
    }
    
    operating = false;
}

std::vector<std::string> YandexImageAPI::getEntries(const std::string& base) const {
    std::vector<std::string> result;
    
    boost::regex  ex("<entry>(.*?)</entry>");
    
    boost::sregex_iterator it(base.begin(), base.end(), ex);
    boost::sregex_iterator invalid;
    
    while(it != invalid) {
        result.push_back((*it++).str());
    }
    
    return result;
}

void YandexImageAPI::extractTags() {
    if(!tags.empty()) {
        tags.clear();
    }
    
    tree<htmlcxx::HTML::Node> domNode = parser->parseTree(cache);
    
    tree<htmlcxx::HTML::Node>::iterator it  = domNode.begin();
    tree<htmlcxx::HTML::Node>::iterator end = domNode.end();
    
    for(; it != end; ++it) {
        if(it->tagName() == "category") {
            it->parseAttributes();
            
            if(it->attribute("scheme").first) {
                if(it->attribute("term").first) {
                    tags.push_back(it->attribute("term").second);
                }
            }
        }
    }
}

std::vector<std::string> YandexImageAPI::extractUsers() {
    std::vector<std::string> result;
    
    tree<htmlcxx::HTML::Node> domNode = parser->parseTree(cache);
    
    tree<htmlcxx::HTML::Node>::iterator it      = domNode.begin();
    tree<htmlcxx::HTML::Node>::iterator end     = domNode.end();
    
    for(; it != end; ++it) {
        if(it->tagName() == "a") {
            it->parseAttributes();
            
            if(it->attribute("class").first && it->attribute("class").second == "b-user__link") {
                std::string href = it->attribute("href").second;
                
                boost::regex  ex("http://fotki.yandex.ru/users/([a-z0-9]+)/");
                boost::smatch cutRes;
                
                std::string::const_iterator start = href.begin();
                std::string::const_iterator end   = href.end();
                
                while(boost::regex_search(start, end, cutRes, ex)) {
                    result.push_back(cutRes[1]);
                    start = cutRes[1].second;
                }
            }
        }
    }
    
    return result;
}

void YandexImageAPI::extractImageLink() {
    tree<htmlcxx::HTML::Node> domNode = parser->parseTree(cache);
    
    tree<htmlcxx::HTML::Node>::iterator it      = domNode.begin();
    tree<htmlcxx::HTML::Node>::iterator end     = domNode.end();
    
    for(; it != end; ++it) {
        if(it->tagName() == "content") {
            it->parseAttributes();
            
            if(it->attribute("src").first) {
                imageURL = it->attribute("src").second;
                break;
            }
        }
    }
}

void YandexImageAPI::request() {
    operating = true;
    publicClient->get("http://fotki.yandex.ru/search.xml?text=" + tag);
}

void YandexImageAPI::init() {
    publicClient = new Wt::Http::Client();
    apiClient    = new Wt::Http::Client();
    parser       = new htmlcxx::HTML::ParserDom();
}

void YandexImageAPI::sets() {
    publicClient->done().connect(this, &YandexImageAPI::analysePublicAnswer);
    publicClient->setTimeout(30);
    
    apiClient->done().connect(this, &YandexImageAPI::analyseAPIAnswer);
    apiClient->setTimeout(30);
    
    operating = false;
}

void YandexImageAPI::request(const std::string& tag) {
    setTag(tag);
    request();
}

std::string YandexImageAPI::getImageLink() {
    return imageURL;
}

std::vector<std::string> YandexImageAPI::getTags() {
    return tags;
}