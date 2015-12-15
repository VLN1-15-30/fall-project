#include "Utilities/utils.h"
#include <iostream>
#include "Services/list.h"

namespace utils {
    QSqlDatabase getDatabaseConnection()
    {
        QString connectionName = "hooper.sqlite";
        QSqlDatabase db;

        if(QSqlDatabase::contains(connectionName))
        {
            db = QSqlDatabase::database(connectionName);
        }
        else
        {
            db = QSqlDatabase::addDatabase("QSQLITE");
            db.setDatabaseName(connectionName);

            db.open();
        }

        return db;
    }

    void update(int rowId, string fieldname, string value, string tableName){

        QSqlQuery query;
        QString s;

        s = ( "UPDATE '%1' SET '%2' = '%3' WHERE id = '%4'" );

        QString field = fieldname.c_str();
        QString table = tableName.c_str();
        QString change = value.c_str();

        query.exec(s.arg(table).arg(field).arg(change).arg(rowId));
    }

    void deleteObj(int type, string name){

        QSqlQuery query;
        QString s;

        if(type == 0){

             s = ( "UPDATE persons SET deleted = 'YES' WHERE lastname = '%1'" );
             query.exec(s.arg(QString(name.c_str())));

        }
        else if (type == 1){

            s = ( "UPDATE computers SET deleted = 'YES' WHERE name = '%1'" );
            query.exec(s.arg(QString(name.c_str())));
        }
    }

    int countDatabaseInput(int type){

        QSqlQuery query;
        QString s;
        if(type == 0){
            s = ("SELECT Count(*) FROM persons WHERE deleted = 'NO'");
        }
        else if (type == 1){
            s = ("SELECT Count(*) FROM computers WHERE deleted = 'NO'");
        }
        query.exec(s);
        query.first();

        return query.value(0).toInt();
    }

    void closeDBConnection() {
        QSqlDatabase db;
        db.close();
    }

    void writeToFile(vector <person>& p){

        ofstream out_stream;
        out_stream.open("Result.txt", ios::app);
        if (out_stream.fail( ))
        {
            cout << "Failed to write to database."<<endl;
            return;
        }

        for (unsigned int i = 0; i< p.size(); i++) {
            person pers = p[i];
              out_stream << pers.getFirstName()<<";"<< pers.getLastName() << ";" << pers.getSex() <<";"<< pers.getBorn()<<";"<< pers.getDied() << endl;
        }

        out_stream.close( );

    }
}
