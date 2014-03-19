/* 
 * File:   DataModel.h
 * Author: joker
 * Класс осуществляет операции с базой данных
 * Created on 2 Март 2014 г., 0:39
 */

#ifndef DATAMODEL_H
#define	DATAMODEL_H

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

#include <string>
#include <vector>

class DataModel {
    sql::Driver            *driver;
    sql::Connection        *connection;
    sql::Statement         *statement;
    sql::ResultSet         *res;
    sql::PreparedStatement *pstmt;
    
    std::string host;
    std::string user;
    std::string passwd;
    std::string schema;
    unsigned    port;
    
public:
    DataModel();
    DataModel(const DataModel& orig);
    virtual ~DataModel();
    
    /**
     * Возвращает новое случайное слово из словаря
     * @return Слово
     */
    std::string getNextRandLitera();
    
    /**
     * Устанавливает оценку тональности для набора существующих словарных статей
     * @param literas Набор статей
     * @param mark Оценка
     */
    void setLiterasMark(std::vector<std::string> literas, std::string mark);
    
    /**
     * Проверяет целостность базы
     * @return true - если база доступна и правильно структурирована, иначе false
     */
    bool baseCheck();
    
    /*GETSET методы*/
    std::string& getHost();
    void setHost(const std::string& host);
    std::string& getUser();
    void setUser(const std::string& user);
    std::string& getPasswd();
    void setPasswd(const std::string& passwd);
    std::string& getSchemaName();
    void setSchemaName(const std::string& schema);
    unsigned& getPort();
    void setPort(unsigned port);
    
private:
    void init();
    void sets();
};

#endif	/* DATAMODEL_H */

