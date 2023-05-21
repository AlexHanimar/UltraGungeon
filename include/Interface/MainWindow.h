#pragma once

#include <QMainWindow>
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsView>

#include <Model/Model.h>
#include <Interface/Renderer.h>

class GraphicsView : public QGraphicsView {
Q_OBJECT
public:
    using QGraphicsView::QGraphicsView;
    void wheelEvent(QWheelEvent* event) override;
};

class MainWindow : public QMainWindow {
Q_OBJECT
private:
    int millisecondsPerFrame;
    QSize sceneSize;
    QPointF screenCenter;
    QTimer* timer;
    QGraphicsScene* scene;
    GraphicsView* view;
    Model* model;
    int inputMask;
    qreal scale;
public:
    explicit MainWindow(int _millisecondsPerFrame, QSize _sceneSize);
    void onFrameStart();
    void paintEvent(QPaintEvent*) override;
    void keyPressEvent(QKeyEvent* event) override;
    void keyReleaseEvent(QKeyEvent* event) override;
    void wheelEvent(QWheelEvent* event) override;
};