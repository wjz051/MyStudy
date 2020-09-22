#ifndef MODELVIEW_H
#define MODELVIEW_H

#include <QWidget>

namespace Ui {
class ModelView;
}

class ModelView : public QWidget
{
    Q_OBJECT

public:
    explicit ModelView(QWidget *parent = 0);
    ~ModelView();

private:
    Ui::ModelView *ui;
};

#endif // MODELVIEW_H
