#ifndef COMBOBOXITEM_H
#define COMBOBOXITEM_H

#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>

class ComboBoxItem : public QWidget
{
    Q_OBJECT
public:
    explicit ComboBoxItem(const QString &str,QWidget *parent = 0);
    ~ComboBoxItem();


public:
    void setText(const QString & str);
    const QString text();

    virtual void mouseReleaseEvent(QMouseEvent *event);

signals:
    void chooseItem(const QString &str);
    void deleteItem(const QString &str);

private:
    QLabel *m_img;
    QLabel *m_label;
    QHBoxLayout *m_layout;
};

class ComboBoxAddItem:public QWidget
{
    Q_OBJECT

public:
    ComboBoxAddItem(QWidget *parent);
    ~ComboBoxAddItem();

public:
    virtual void mouseReleaseEvent(QMouseEvent *event);

signals:
    void addItem();

private:
    QLabel *m_label;
    QHBoxLayout *m_layout;



};




#endif // COMBOBOXITEM_H
