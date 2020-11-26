#ifndef PATHEDITOR_H
#define PATHEDITOR_H

#include <QWidget>

class PathEditor : public QWidget
{
    Q_OBJECT
public:
    explicit PathEditor(QWidget *parent = 0);
    ~PathEditor();

    void setPath(const QString& path);
    QString path() const;
signals:

public slots:
private:
    class PathEditorPrivate;
    const QScopedPointer<PathEditorPrivate> d;
};

#endif // PATHEDITOR_H
