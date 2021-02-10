#include "mainwindow.h"

MainWindow::MainWindow()
{
    setWindowTitle("Drag and drop from QListWidget v2");
    resize(350,250);

    createListWidget();
    createSceneAndView();
    createGraphicsItems();
    createLayout();
}

void MainWindow::createListWidget(){
    itemListWidget = new QListWidget;
    QStringList itemList;
    itemList << "gray" << "blue" << "orange";
    itemListWidget->addItems(itemList);
    itemListWidget->setFixedWidth(100);
    itemListWidget->setDragEnabled(true);
}

void MainWindow::createSceneAndView(){
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,200,200);
    view = new QGraphicsView;
    view->setScene(scene);
}

void MainWindow::createGraphicsItems(){
    QRectF rect(0,0,70,40);
    CustomRectItem *rItem1 = new CustomRectItem;
    scene->addItem(rItem1);
    rItem1->setRect(rect);
    rItem1->setPos(70,20);
    rItem1->setBrush(QColor("#FF8C69"));

    CustomRectItem *rItem2 = new CustomRectItem;
    scene->addItem(rItem2);
    rItem2->setRect(rect);
    rItem2->setPos(70,80);
    rItem2->setBrush(QColor("#C0C0C0"));

    CustomRectItem *rItem3 = new CustomRectItem;
    scene->addItem(rItem3);
    rItem3->setRect(rect);
    rItem3->setPos(70,140);
    rItem3->setBrush(QColor("#87CEEB"));
}

void MainWindow::createLayout(){
    QFrame *frame = new QFrame;
    QHBoxLayout *frameLayout = new QHBoxLayout(frame);
    frameLayout->addWidget(itemListWidget);
    frameLayout->addWidget(view);
    setCentralWidget(frame);
}

void MainWindow::keyPressEvent(QKeyEvent *event){
    if(event->key() == Qt::Key_Delete){
        foreach(QGraphicsItem *item, scene->selectedItems())
            if(CustomRectItem *rItem = qgraphicsitem_cast<CustomRectItem*> (item)){
                itemListWidget->addItem(rItem->text());
                rItem->setText(QString());
            }
        scene->clearSelection();
    }
    QMainWindow::keyPressEvent(event);
}
