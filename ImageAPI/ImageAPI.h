/* 
 * File:   ImageAPI.h
 * Author: joker
 *
 * Created on 13 Март 2014 г., 13:09
 */

#ifndef IMAGEAPI_H
#define	IMAGEAPI_H

#define BOOST_SIGNALS_NO_DEPRECATION_WARNING
#define RU(x) Wt::WString::fromUTF8(x)

#include <string>
#include <vector>

class ImageAPI {
protected:
    std::string tag;
    
public:
    ImageAPI();
    ImageAPI(const ImageAPI& orig);
    virtual ~ImageAPI();
    
    void setTag(const std::string& tag);
    std::string getTag();
    
    virtual void request() = 0;
    virtual void request(const std::string& tag) = 0;
    
    virtual std::vector<std::string> getTags() = 0;
    virtual std::string getImageLink() = 0;
private:
};

#endif	/* IMAGEAPI_H */