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
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
};

class MainWindow : public QMainWindow {
Q_OBJECT
private:
    int millisecondsPerFrame;
    QSize sceneSize;
    QPoint screenCenter;
    QTimer* timer;
    QGraphicsScene* scene;
    GraphicsView* view;
    Model* model;
    int inputMask;
    qreal scale;
    QPoint mouseDirection;
public:
    explicit MainWindow(int _millisecondsPerFrame, QSize _sceneSize);
    void onFrameStart();
    void paintEvent(QPaintEvent*) override;
    void keyPressEvent(QKeyEvent* event) override;
    void keyReleaseEvent(QKeyEvent* event) override;
    void wheelEvent(QWheelEvent* event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
};