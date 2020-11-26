### 数据库通用翻页类

[TOC]
****
1. 自动按照设定的每页多少行数据分页
2. 只需要传入表名/字段集合/每页行数/翻页指示按钮/文字指示标签
3. 提供公共静态方法绑定字段数据到下拉框
4. 建议条件字段用数字类型的主键,速度极快
5. 增加线程查询符合条件的记录总数,数据量巨大时候不会卡主界面
6. 提供查询结果返回信号,包括当前页/总页数/总记录数/查询用时
7. 可设置所有列或者某一列对齐样式例如居中或者右对齐
8. 可设置增加一列,列的位置,标题,宽度
9. 可设置要查询的字段集合

#### 设置中文显示乱码问题
```cpp
#if (QT_VERSION <= QT_VERSION_CHECK(5,0,0))
#if _MSC_VER
    QTextCodec *codec = QTextCodec::codecForName("gbk");
#else
    QTextCodec *codec = QTextCodec::codecForName("utf-8");
#endif
    QTextCodec::setCodecForLocale(codec);
    QTextCodec::setCodecForCStrings(codec);
    QTextCodec::setCodecForTr(codec);
#else
    QTextCodec *codec = QTextCodec::codecForName("utf-8");
    QTextCodec::setCodecForLocale(codec);
#endif
```

#### 打开数据库
```cpp
    QSqlDatabase dbConn = QSqlDatabase::addDatabase("QSQLITE");
    dbConn.setDatabaseName(qApp->applicationDirPath() + "/TA.db");
    if (dbConn.open()) {
        qDebug() << "连接数据库成功!";
    } else {
        qDebug() << "连接数据库失败!";
    }
```

### 查找数据

* `QSqlQueryModel->setQuery(const QString &query, const QSqlDatabase &db = QSqlDatabase());`设置sql查询
* `QTableView->setModel(QAbstractItemModel *model);`tableView设置Model
* 查询数据
```cpp
    QSqlQuery query(QSqlDatabase::database(connName));
    query.exec("select " + columnName + " from " + tableName + " order by " + orderColumn + " asc");
    while (query.next()) {
        foreach (QComboBox *cbox, cboxs) {
            cbox->addItem(query.value(0).toString());
        }
    }
```

