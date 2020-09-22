#ifndef EDITCOMBOBOX_H
#define EDITCOMBOBOX_H

#include<QComboBox>
#include<QListWidget>
#include<QLineEdit>

//可编辑的ComboBox
class EditComboBox : public QComboBox
{
    Q_OBJECT

public:
    EditComboBox(QWidget *parent=0);
    ~EditComboBox();

public:
    int FindItemIndex(const QString &text);

    void SetText(const QString & text);
    QStringList TextList();

    void CulTextNextCount(const QString & text,int &nextCount);

    void updateItems(const QStringList & itemList);

public slots:
    void OnChooseItem(const QString &str);
    void OnDeleteItem(const QString &str);

    void OnAddItem();
    void OnReturnPressed();

private:
    QListWidget *m_listWidget;
    QLineEdit *m_lineEdit;
    QString m_text;
};

#endif // EDITCOMBOBOX_H
