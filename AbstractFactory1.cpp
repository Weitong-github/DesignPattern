#include <vector>
using namespace std;


class IDBFactory {
public:
    virtual IDBConnection* CreateConnection() = 0;
    virtual IDBCommand* CreateCommand() = 0;
    virtual IDBDataReader* CreateDataReader() = 0;
};
// class IDBConnectionFactory {
// public:
//     virtual IDBConnection* Create() = 0;
// };
// class IDBCommandFactory {
// public:
//     virtual IDBCommand* Create() = 0; 
// };
// class IDBDataReaderFactory {
// public:
//     virtual IDBDataReader* Create() = 0; 
// };

class IDBConnection {

};
class IDBCommand {
public:
    virtual IDBDataReader* ExecuteReader() = 0;
    virtual ~IDBCommand(){}
};
class IDBDataReader {

};
// Sql
class SqlFactory : public IDBFactory {
public:
    virtual SqlConnection* CreateConnection() {
        return new SqlConnection();
    }
    virtual SqlCommand* CreateCommand() {
        return new SqlCommand();
    }
    virtual SqlDataReader* CreateDataReader() {
        return new SqlDataReader(); 
    }
};

// class SqlConnectionFactory : public IDBConnectionFactory {
// public:
//     virtual IDBConnection* Create() {
//         return new SqlConnection();
//     }
// };
// class SqlCommandFactory : public IDBCommandFactory {
// public:
//     virtual IDBCommand* Create() {
//         return new SqlCommand();
//     }
// };
// class SqlDataReaderFactory  : public IDBDataReaderFactory {
// public:
//     virtual IDBDataReader* Create() {
//         return new SqlDataReader();
//     }
// };


class SqlConnection:public IDBConnection {

};
class SqlCommand : public IDBCommand {
    virtual IDBDataReader* ExecuteReader() {

    }
};
class SqlDataReader : public IDBDataReader {

};
//Oracle
class OracleConnection:public IDBConnection {

};
class OracleCommand : public IDBCommand {
    virtual IDBDataReader* ExecuteReader() {

    }
};
class OracleDataReader : public IDBDataReader {

};

class EmployeeDAO {
    // IDBConnectionFactory* connectionFactory;
    // IDBCommandFactory* commandFactory;
    // IDBDataReaderFactory* dataReaderFacotry;
    IDBFactory* Factory;

public:

    EmployeeDAO(IDBFactory* f) : Factory(f) {}

    vector<EmployeeDAO> GetEmployees() {
        // IDBConnection* connection = new SqlConnection();
        IDBConnection* connection = Factory->CreateConnection();
        // connection->ConnectionString = "..."

        IDBCommand* command = Factory->CreateCommand();
        // command->CommandText = "..."
        // command->SetConnection(connection);

        IDBDataReader* reader = Factory->CreateDataReader();
        // while(reader->Read()) {

        // }
    }
};

void process() {
    SqlFactory* a = new SqlFactory();
    EmployeeDAO* b = new EmployeeDAO(a);
    b->GetEmployees();
}