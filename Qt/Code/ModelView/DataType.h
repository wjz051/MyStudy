#ifndef DATATYPE_H
#define DATATYPE_H

#include<QVector>
#include<QColor>
#include<QSharedPointer>

//model数据基类
struct AbstractModelData
{
    QString ModelID;
};
typedef QSharedPointer<AbstractModelData> AbstractModelDataPtr;
typedef QVector<AbstractModelDataPtr> AbstractModelDataArray;

//table数据结构
struct TableModelData:public AbstractModelData
{
    TableModelData(QStringList data=QStringList())
        :TableData(data),TableColor(Qt::black),TextColor(Qt::black){}

    QStringList TableData;
    QVariant TablePoint;
    QColor TableColor;
    QColor TextColor;
};
typedef QSharedPointer<TableModelData> TableModelDataPtr;
typedef QVector<TableModelDataPtr> TableModelDataArray;

//tree数据结构
struct TreeModelData:public AbstractModelData
{
    TreeModelData(QStringList data=QStringList())
        :TreeData(data),TreeColor(Qt::black){}

    QStringList TreeData;
    QVariant TreePoint;
    QColor TreeColor;
};
typedef QSharedPointer<TreeModelData> TreeModelDataPtr;
typedef QVector<TreeModelDataPtr> TreeModelDataArray;

#endif // DATATYPE_H
