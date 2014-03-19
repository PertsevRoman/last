/* 
 * File:   DataModel.cpp
 * Author: joker
 * 
 * Created on 2 Март 2014 г., 0:40
 */

#include "DataModel.h"

DataModel::DataModel() {
    init();
    sets();
}

DataModel::DataModel(const DataModel& orig) {
}

DataModel::~DataModel() {
    connection->close();
    
    delete statement;
    delete pstmt;
    delete res;
    delete connection;
}

void DataModel::init() {
    host   = "127.0.0.1";
    user   = "root";
    passwd = "SweetOctober16";
    schema = "marks";
    
    driver     = get_driver_instance();
    connection = driver->connect("tcp://" + host + ":" + std::to_string(port), user, passwd);
    
    statement  = connection->createStatement();
}

void DataModel::sets() {
    connection->setSchema(schema);
}

std::string DataModel::getNextRandLitera() {
    return "кошка";
}

void DataModel::setLiterasMark(std::vector<std::string> literas, std::string mark) {
}

bool DataModel::baseCheck() {
    return true;
}

std::string& DataModel::getHost() {
    return host;
}

void DataModel::setHost(const std::string& host) {
    if(this->host != host) {
        this->host = host;
    }
}

std::string& DataModel::getUser() {
    return user;
}

void DataModel::setUser(const std::string& user) {
    if(this->user != user) {
        this->user = user;
    }
}

std::string& DataModel::getPasswd() {
    return passwd;
}

void DataModel::setPasswd(const std::string& passwd) {
    if(this->passwd != passwd) {
        this->passwd = passwd;
    }
}

std::string& DataModel::getSchemaName() {
    return schema;
}

void DataModel::setSchemaName(const std::string& schema) {
    if(this->schema != schema) {
        this->schema = schema;
    }
}

unsigned& DataModel::getPort() {
    return port;
}

void DataModel::setPort(unsigned port) {
    this->port = port;
}