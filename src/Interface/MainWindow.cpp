#include <Interface/MainWindow.h>
#include <QKeyEvent>

void GraphicsView::wheelEvent(QWheelEvent *event) {event->ignore();}

MainWindow::MainWindow(int _millisecondsPerFrame, QSize _sceneSize)
        : millisecondsPerFrame(_millisecondsPerFrame)
        , sceneSize(_sceneSize)
        , scene(new QGraphicsScene(0, 0, sceneSize.width(), sceneSize.height(), this))
        , view(new GraphicsView(scene))
        , screenCenter(1000, 1000)
        , inputMask(0)
        , scale(1.0)
{
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, [this](){this->onFrameStart();});
    model = new Model;
    timer->start(millisecondsPerFrame);
    showFullScreen();
    view->setFixedSize(this->size());
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setMouseTracking(true);

    auto* entity = new MovableEntity(100, {10, 10}, {500, 500});
    entity->setVelocity({100, 100});
    model->addEntity(wrap(entity));
    QPoint pos = {600, 500};
    for(int i = 0;i < 100;i++) {
        auto* wall = new Wall({10, 10}, 1, 1, pos);
        model->addEntity(wrap(wall));
        pos += {0, 10};
    }
    pos = {500, 600};
    for(int i = 0;i < 100;i++) {
        auto* wall = new Wall({10, 10}, 1, 1, pos);
        model->addEntity(wrap(wall));
        pos += {10, 0};
    }
}

void MainWindow::paintEvent(QPaintEvent *)
{
    scene->clear();
    view->centerOn(screenCenter * scale);
    auto* renderer = new Renderer_Wrapper;
    renderer->scale = scale;
    renderer->scene = scene;
    renderer->view = view;
    for(auto* entity : model->getEntities())
        interact(renderer, entity);
    delete renderer;
    this->setCentralWidget(view);
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->isAutoRepeat())
        return;
    switch(event->key()){
        case Qt::Key_W:
            inputMask |= INPUT::KEY_W;
            break;
        case Qt::Key_A:
            inputMask |= INPUT::KEY_A;
            break;
        case Qt::Key_S:
            inputMask |= INPUT::KEY_S;
            break;
        case Qt::Key_D:
            inputMask |= INPUT::KEY_D;
            break;
    }
}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    if(event->isAutoRepeat())
        return;
    switch(event->key()){
        case Qt::Key_W:
            inputMask &= ~INPUT::KEY_W;
            break;
        case Qt::Key_A:
            inputMask &= ~INPUT::KEY_A;
            break;
        case Qt::Key_S:
            inputMask &= ~INPUT::KEY_S;
            break;
        case Qt::Key_D:
            inputMask &= ~INPUT::KEY_D;
            break;
    }
}

void MainWindow::onFrameStart()
{
    timer->stop();
    model->setInputMask(inputMask);
    model->update(0.001 * millisecondsPerFrame);
    if(inputMask & INPUT::KEY_W)
        screenCenter += {0, -10};
    if(inputMask & INPUT::KEY_A)
        screenCenter += {-10, 0};
    if(inputMask & INPUT::KEY_S)
        screenCenter += {0, 10};
    if(inputMask & INPUT::KEY_D)
        screenCenter += {10, 0};
    repaint();
    timer->start(millisecondsPerFrame);
}

void MainWindow::wheelEvent(QWheelEvent *event)
{
    qreal factor = 1.024;
    if(event->angleDelta().y() < 0)
        factor = 1.0 / factor;
    if(factor > 1)
        scale = std::min(scale * factor, 8.0);
    else
        scale = std::max(scale * factor, 0.125);
}
