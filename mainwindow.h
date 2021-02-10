#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QHBoxLayout>
#include "customrectitem.h"
#include <QKeyEvent>

class MainWindow : public QMainWindow
{
public:
    MainWindow();
protected:
    void keyPressEvent(QKeyEvent *);
private:
    QListWidget* itemListWidget;
    QGraphicsView* view;
    QGraphicsScene* scene;

    void createWidgets();
    void createSceneAndView();
    void createGraphicsItems();
    void createLayout();
};

#endif // MAINWINDOW_H
