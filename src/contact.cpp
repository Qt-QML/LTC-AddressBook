#include "contact.h"

Contact::Contact(QString firstName, QString secondName, QString phone)
    : m_phone {phone},
      m_firstName {firstName},
      m_surname {secondName}
{
}

QString Contact::phone() const
{
    return m_phone;
}

QString Contact::firstName() const
{
    return m_firstName;
}

QString Contact::surname() const
{
    return m_surname;
}
