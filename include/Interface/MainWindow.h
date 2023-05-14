#pragma once

#include <QMainWindow>
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsView>

#include <Model/Model.h>
#include <Interface/Renderer.h>

class MainWindow : public QMainWindow {
    Q_OBJECT
private:
    int millisecondsPerFrame;
    QSize sceneSize;
    QPointF screenCenter;
    QTimer* timer;
    QGraphicsScene* scene;
    QGraphicsView* view;
    Model* model;
    int inputMask;
public:
    explicit MainWindow(int _millisecondsPerFrame, QSize _sceneSize);
    void onFrameStart();
    void paintEvent(QPaintEvent*) override;
    void keyPressEvent(QKeyEvent* event) override;
    void keyReleaseEvent(QKeyEvent* event) override;
};