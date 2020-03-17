#include "contactsmodel.h"
#include <QDebug>
#include <QQmlEngine>

ContactsModel::ContactsModel(QObject* parent)
               : QAbstractListModel (parent)
{
    startManualUpdate();
}

void ContactsModel::registerMe(const std::string& moduleName)
{
    qmlRegisterType<ContactsModel>(moduleName.c_str(), 1, 0, "ContactsModel");
}

void ContactsModel::startManualUpdate()
{
    const bool success {updateContacts()};
    if (!success) {
        qWarning() << "Can't update contacts!";
    }
}

int ContactsModel::rowCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent)
    return static_cast<int>(m_contacts.size());
}

QVariant ContactsModel::data(const QModelIndex& index, int role) const
{
    int rowIndex = index.row();

    if (!index.isValid() || rowIndex > rowCount(index))
    {
        return {};
    }

    const Contact& requestedContact {m_contacts.at(static_cast<size_t>(rowIndex))};

    switch (role)
    {
        case ContactRoles::Name:
        {
            return QVariant::fromValue(requestedContact.firstName());
        }
        case ContactRoles::Surname:
        {
            return QVariant::fromValue(requestedContact.surname());
        }
        case ContactRoles::Phone:
        {
            return QVariant::fromValue(requestedContact.phone());
        }
        default:
        {
            qWarning() << "Invalid role passed!";
            return {};
        }
    }
}

QHash<int, QByteArray> ContactsModel::roleNames() const
{
    QHash<int, QByteArray> roles;

    roles[ContactRoles::Name] = "name";
    roles[ContactRoles::Surname] = "surname";
    roles[ContactRoles::Phone] = "phoneNumber";

    return roles;
}


bool ContactsModel::updateContacts()
{
    bool success {false};
    std::vector<Contact> contactsResult;

    std::tie(success, contactsResult) = m_reader.requestContactsBrowse();

    if (success) {
        emit beginResetModel();
        m_contacts = std::move(contactsResult);
        emit endResetModel();
    }

    return success;
}
