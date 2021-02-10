#include "customrectitem.h"

CustomRectItem::CustomRectItem(QGraphicsItem *parent):
    QGraphicsRectItem(parent)
{
    setAcceptDrops(true);
    setFlags(QGraphicsItem::ItemIsSelectable);
}

void CustomRectItem::setText(const QString &text){
    this->m_text = text;
    update();
}

void CustomRectItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
           QWidget *widget){
    QGraphicsRectItem::paint(painter, option, widget);
    painter->drawText(boundingRect(),m_text,
                      QTextOption(Qt::AlignCenter));
}

void CustomRectItem::dropEvent(QGraphicsSceneDragDropEvent *event){
     if (event->mimeData()->hasFormat("application/x-qabstractitemmodeldatalist")){
         QByteArray itemData = event->mimeData()->data(
                     "application/x-qabstractitemmodeldatalist");
         QDataStream stream(&itemData, QIODevice::ReadOnly);
         int row, col;
         QMap<int, QVariant> valueMap;
         stream >> row >> col >> valueMap;
         QString origText = m_text;
         if(!valueMap.isEmpty())
            setText(valueMap.value(0).toString());

         event->setDropAction(Qt::MoveAction);
         event->accept();

         if(!origText.isEmpty()){
             if(QListWidget* lWidget = qobject_cast<QListWidget*> (event->source()))
                  lWidget->addItem(origText);
         }
     }
     else
         event->ignore();
}
