/* 
 * File:   ImageAPI.cpp
 * Author: joker
 * 
 * Created on 13 Март 2014 г., 13:09
 */

#include "ImageAPI.h"

ImageAPI::ImageAPI() {
}

ImageAPI::ImageAPI(const ImageAPI& orig) {
}

ImageAPI::~ImageAPI() {
}

std::string ImageAPI::getTag() {
    return tag;
}

void ImageAPI::setTag(const std::string& tag) {
    if(this->tag != tag) {
        this->tag = tag;
    }
}