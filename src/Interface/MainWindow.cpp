#include <Interface/MainWindow.h>
#include <QKeyEvent>

enum KEY {
    W = 0b000001,
    A = 0b000010,
    S = 0b000100,
    D = 0b001000
};

MainWindow::MainWindow(int _millisecondsPerFrame, QSize _sceneSize)
    : millisecondsPerFrame(_millisecondsPerFrame)
    , sceneSize(_sceneSize)
    , scene(new QGraphicsScene(0, 0, sceneSize.width(), sceneSize.height(), this))
    , view(new QGraphicsView(scene))
    , screenCenter(1000, 1000)
    , inputMask(0)
{
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, [this](){this->onFrameStart();});
    model = new Model;
    timer->start(millisecondsPerFrame);
    showFullScreen();
    view->setFixedSize(this->size());

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
    view->centerOn(screenCenter);
    auto* renderer = new Renderer_Wrapper;
    renderer->scale = 1.0;
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
            inputMask |= KEY::W;
            break;
        case Qt::Key_A:
            inputMask |= KEY::A;
            break;
        case Qt::Key_S:
            inputMask |= KEY::S;
            break;
        case Qt::Key_D:
            inputMask |= KEY::D;
            break;
    }
}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    if(event->isAutoRepeat())
        return;
    switch(event->key()){
        case Qt::Key_W:
            inputMask &= ~KEY::W;
            break;
        case Qt::Key_A:
            inputMask &= ~KEY::A;
            break;
        case Qt::Key_S:
            inputMask &= ~KEY::S;
            break;
        case Qt::Key_D:
            inputMask &= ~KEY::D;
            break;
    }
}

void MainWindow::onFrameStart()
{
    timer->stop();
    model->update(0.001 * millisecondsPerFrame);
    if(inputMask & KEY::W)
        screenCenter += {0, -10};
    if(inputMask & KEY::A)
        screenCenter += {-10, 0};
    if(inputMask & KEY::S)
        screenCenter += {0, 10};
    if(inputMask & KEY::D)
        screenCenter += {10, 0};
    repaint();
    timer->start(millisecondsPerFrame);
}

