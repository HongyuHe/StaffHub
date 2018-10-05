#include "combodelegate.h"
#include <QComboBox>

ComboDelegate::ComboDelegate(QObject *parent) :
    QItemDelegate(parent)
{
}

QWidget *ComboDelegate::createEditor(QWidget *parent,const QStyleOptionViewItem &/*option*/,const QModelIndex &/*index*/) const
{
    QComboBox *editor = new QComboBox(parent);
    editor->addItem("第一组");
    editor->addItem("第二组");
    editor->addItem("第三组");
    editor->addItem("第四组");
    editor->addItem("第五组");
    editor->addItem("第六组");
    editor->addItem("第七组");
    editor->addItem("第八组");
    editor->addItem("第九组");
    editor->addItem("第十组");
    editor->addItem("第十一组");
    editor->installEventFilter(const_cast<ComboDelegate*>(this));
    return editor;
}

void ComboDelegate::setEditorData(QWidget *editor,const QModelIndex &index) const
{
    QString str =index.model()->data(index).toString();

    QComboBox *box = static_cast<QComboBox*>(editor);
    int i=box->findText(str);
    box->setCurrentIndex(i);
}

void ComboDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QComboBox *box = static_cast<QComboBox*>(editor);
    QString str = box->currentText();
    model->setData(index,str);
}

void ComboDelegate::updateEditorGeometry(QWidget *editor,const QStyleOptionViewItem &option, const QModelIndex &/*index*/) const
{
    editor->setGeometry(option.rect);
}
