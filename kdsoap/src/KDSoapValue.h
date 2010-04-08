#ifndef KDSOAPVALUE_H
#define KDSOAPVALUE_H

#include <QString>
#include <QVariant>
#include <QList>

/**
 * KDSoapValue represents a value in a SOAP argument list.
 * It is composed of the argument name, and actual value as a QVariant.
 */
class KDSoapValue
{
public:
    KDSoapValue(const QString& n, const QVariant& v)
        : m_name(n), m_value(v) {}

    QString name() const { return m_name; }

    // Can be any basic type, or a KDSoapValueList
    QVariant value() const { return m_value; }

private:
    QString m_name;
    QVariant m_value;
};

QDebug operator <<(QDebug dbg, const KDSoapValue &value);


/**
 * KDSoapValueList represents a list of arguments passed to a SOAP message.
 */
class KDSoapValueList : public QList<KDSoapValue>
{
public:
    /**
     * Convenience method for adding an argument (name and value) to the list.
     */
    void addArgument(const QString& argumentName, const QVariant& argumentValue)
    {
        append(KDSoapValue(argumentName, argumentValue));
    }

    /**
     * Convenience method for extracting the value of an argument by @p name.
     * If multiple arguments have the same name, the first match is returned.
     * This method mostly makes sense for the case where only one argument uses @p name.
     */
    QVariant value(const QString& name) const;
};

typedef QListIterator<KDSoapValue> KDSoapValueListIterator;

Q_DECLARE_METATYPE(KDSoapValueList)

#endif // KDSOAPVALUE_H