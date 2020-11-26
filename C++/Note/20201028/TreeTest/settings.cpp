#include "settings.h"
#include <QtWidgets>

Settings* Settings::sInstance = Q_NULLPTR;

class Settings::SettingsPrivate
{
public:
    QList<Group*> config;
};

Settings::Settings(QObject *parent)
    : QObject(parent), d(new SettingsPrivate)
{
    auto mainConfigGroup = new Group(this);
    mainConfigGroup->name = tr("Main Config");
    mainConfigGroup->items << new ItemProperty(ItemProperty::TYPE_INTEGER, tr("Config Version"), 12, mainConfigGroup);
    mainConfigGroup->items << new ItemProperty(ItemProperty::TYPE_LANGUAGE, tr("Language"), tr("Chinese"), mainConfigGroup);
    mainConfigGroup->items << new ItemProperty(ItemProperty::TYPE_FONT, tr("Font"), qApp->font(), mainConfigGroup);

    auto pathConfigGroup = new Group(this);
    pathConfigGroup->name = tr("Path Config");
    pathConfigGroup->items << new ItemProperty(ItemProperty::TYPE_PATH, tr("Main Path"), QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation), pathConfigGroup);

    d->config << mainConfigGroup << pathConfigGroup;
}

Settings::~Settings()
{
    qDeleteAll(d->config);
}

Settings* Settings::instance()
{
    if (!sInstance) {
        sInstance = new Settings(qApp);
    }
    return sInstance;
}

QList<Group*> Settings::groups() const
{
    return d->config;
}
