#include "patheditor.h"
#include <QtWidgets>

class PathEditor::PathEditorPrivate
{
public:
    QLineEdit* edit = Q_NULLPTR;
    QPushButton* btn = Q_NULLPTR;
};

PathEditor::PathEditor(QWidget *parent)
    : QWidget(parent), d(new PathEditorPrivate)
{
    auto layout = new QHBoxLayout(this);
    layout->setContentsMargins(QMargins(0, 0, 0, 0));
    layout->addWidget(d->edit = new QLineEdit, 1);
    layout->addWidget(d->btn = new QPushButton(tr("&Choose")));
    setAutoFillBackground(true);

    d->edit->setFocus();

    connect(d->btn, &QPushButton::clicked, this, [this] {
        auto dir = QFileDialog::getExistingDirectory(this, tr("Choose Directory"));
        if (dir.isEmpty()) return;

        d->edit->setText(QDir::toNativeSeparators(QDir(dir).absolutePath()));
    });
}

PathEditor::~PathEditor()
{

}

void PathEditor::setPath(const QString &path)
{
    d->edit->setText(path);
}

QString PathEditor::path() const
{
    return d->edit->text();
}
