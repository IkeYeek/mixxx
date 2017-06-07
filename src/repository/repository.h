#ifndef MIXXX_REPOSITORY_H
#define MIXXX_REPOSITORY_H


#include <QSqlDatabase>

#include "preferences/usersettings.h"

#include "util/db/dbconnection.h"


namespace mixxx {

class Repository : public QObject {
    Q_OBJECT

  public:
    static const QString kDefaultSchemaFile;
    static const int kRequiredSchemaVersion;

    static bool initDatabaseSchema(
            const QSqlDatabase& database,
            const QString& schemaFile = kDefaultSchemaFile,
            int schemaVersion = kRequiredSchemaVersion);

    explicit Repository(
            const UserSettingsPointer& pConfig);

    bool openDatabaseConnection() {
        return m_dbConnection.open();
    }
    void closeDatabaseConnection() {
        m_dbConnection.close();
    }

    QSqlDatabase database() const {
        return m_dbConnection.database();
    }

  private:
    DbConnection m_dbConnection;
};

} // namespace mixxx


#endif //  MIXXX_REPOSITORY_H
