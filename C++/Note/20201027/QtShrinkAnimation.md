### 主要测试QPropertyAnimation动画效果
* `QPropertyAnimation(QObject *target, const QByteArray &propertyName, QObject *parent = Q_NULLPTR)`target必须继承QObject,propertyName必须是target属性;
* `Q_PROPERTY(int fixSizeHeight READ fixSizeHeight WRITE setCusfixSizeHeight)`通过Q_PROPERTY设置属性;
* 绘制背景图
```cpp
    void CustomWidget::paintEvent(QPaintEvent *event)
    {
        Q_UNUSED(event);        

        QStyleOption opt;
        opt.init(this);
        QPainter p(this);
        style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this)   ;
    }   
    
    重写paintEvent，使用QPainter来绘制背景。    
    void Widget::paintEvent(QPaintEvent *event)
    {
        Q_UNUSED(event);    

        QPainter p(this);
        p.setPen(Qt::NoPen);
        p.setBrush(Qt::black);
        p.drawRect(rect());
    }
```