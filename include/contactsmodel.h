#pragma once

#include <QAbstractListModel>
#include "contactsreader.h"
#include "contact.h"

class ContactsModel : public QAbstractListModel
{
    Q_OBJECT

public:
    ContactsModel(QObject* parent = nullptr);

    static void registerMe(const std::string& moduleName);

    int rowCount(const QModelIndex& parent) const override;
    QVariant data(const QModelIndex& index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;

    Q_INVOKABLE void startManualUpdate();
private:
    std::vector<Contact> m_contacts;
    ContactsReader m_reader;

    enum ContactRoles {
        Name = Qt::ItemDataRole::UserRole + 1,
        Surname,
        Phone
    };

    bool updateContacts();
};
