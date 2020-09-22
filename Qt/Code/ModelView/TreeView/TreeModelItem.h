#ifndef TREEMODELITEM_H
#define TREEMODELITEM_H

#include<QList>
#include<QVector>

#include"DataType.h"

struct TreeModelItemPrivate;

class TreeModelItem
{
public:
    TreeModelItem(TreeModelDataPtr data,TreeModelItem *parent=0);
    ~TreeModelItem();

public:
    void appendChild(TreeModelItem *child);
    void removeChild(TreeModelItem *child);

    int childCount() const;
    int colunmCount() const;

    TreeModelItem  *child(int row);
    TreeModelItem *parent();

    int row() const;
    QVariant data() const;

private:
    TreeModelItemPrivate *_p;


};

#endif // TREEMODELITEM_H
