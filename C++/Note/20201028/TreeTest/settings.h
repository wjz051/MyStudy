#ifndef SETTINGS_H
#define SETTINGS_H

#include <QObject>
#include <QVariant>

class ItemProperty: public QObject
{
    Q_OBJECT
public:
    enum ItemType{
        TYPE_INTEGER,
        TYPE_LANGUAGE,
        TYPE_FONT,
        TYPE_PATH
    };

    ItemProperty(int t, const QString& n, const QVariant& v, QObject* parent = Q_NULLPTR): type(t), name(n), value(v), QObject(parent) {}

    int type;
    QString name;
    QVariant value;
};

class Group: public QObject
{
    Q_OBJECT
public:
    Group(QObject *parent = Q_NULLPTR) : QObject(parent) {}
    ~Group() {
        qDeleteAll(items);
    }

    QString name;
    QList<ItemProperty*> items;
};

class Settings : public QObject
{
    Q_OBJECT
private:
    explicit Settings(QObject *parent = Q_NULLPTR);
public:
    ~Settings();

    static Settings* instance();

    QList<Group*> groups() const;
signals:

public slots:
private:
    static Settings* sInstance;
    class SettingsPrivate;
    const QScopedPointer<SettingsPrivate> d;
};

#define qSetting (Settings::instance())

#endif // SETTINGS_H
