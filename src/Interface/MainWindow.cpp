#include <Interface/MainWindow.h>
#include <QKeyEvent>

void GraphicsView::wheelEvent(QWheelEvent *event) {event->ignore();}
void GraphicsView::mousePressEvent(QMouseEvent *event) {event->ignore();}
void GraphicsView::mouseReleaseEvent(QMouseEvent *event) {event->ignore();}
void GraphicsView::mouseMoveEvent(QMouseEvent *event) {event->ignore();}

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
    screenCenter = {this->size().width() / 2, this->size().height() / 2};
    this->setMouseTracking(true);

    auto* entity = new MovableEntity(100, {10, 10}, {500, 500});
    entity->setVelocity({100, 100});
    model->addEntity(wrap(entity));
    QPoint pos = {600, 500};
    for(int i = 0;i < 100;i++) {
        auto* wall = new Wall({10, 10}, 2, 2, pos);
        model->addEntity(wrap(wall));
        pos += {0, 10};
    }
    pos = {500, 600};
    for(int i = 0;i < 100;i++) {
        auto* wall = new Wall({10, 10}, 2, 2, pos);
        model->addEntity(wrap(wall));
        pos += {10, 0};
    }

    auto* player = new PlayerEntity(0, {10, 10}, {1000, 1000});
    player->init();
    model->setPlayerEntity(player);

    auto* enemy = new EnemyFilth(0, {10, 10}, {1200, 1200});
    enemy->init();
    model->addEntity(wrap(enemy));
}

void MainWindow::paintEvent(QPaintEvent *)
{
    scene->clear();
    auto* renderer = new Renderer_Wrapper;
    renderer->scale = scale;
    renderer->scene = scene;
    renderer->view = view;
    for(auto* entity : model->getEntities())
        interact(renderer, entity);
    interact(renderer, model->getPlayerEntity());
    delete renderer;
    this->setCentralWidget(view);
    centralWidget()->setAttribute(Qt::WA_TransparentForMouseEvents);
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    // to exit application
    if(event->key() == Qt::Key_Escape)
        this->close();

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
        case Qt::Key_Shift:
            inputMask |= INPUT::KEY_DASH;
            break;
        case Qt::Key_1:
            inputMask |= INPUT::KEY_1;
            break;
        case Qt::Key_2:
            inputMask |= INPUT::KEY_2;
            break;
        case Qt::Key_3:
            inputMask |= INPUT::KEY_3;
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
        case Qt::Key_Shift:
            inputMask &= ~INPUT::KEY_DASH;
            break;
        case Qt::Key_1:
            inputMask &= ~INPUT::KEY_1;
            break;
        case Qt::Key_2:
            inputMask &= ~INPUT::KEY_2;
            break;
        case Qt::Key_3:
            inputMask &= ~INPUT::KEY_3;
            break;
    }
}

void MainWindow::onFrameStart()
{
    timer->stop();
    model->setInputMask(inputMask);
    model->setMouseDirection(mouseDirection);
    model->update(0.001 * millisecondsPerFrame);
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

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    mouseDirection = (event->pos() - screenCenter);
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
        inputMask |= INPUT::MOUSE_1;
    if(event->button() == Qt::RightButton)
        inputMask |= INPUT::MOUSE_2;
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
        inputMask &= ~INPUT::MOUSE_1;
    if(event->button() == Qt::RightButton)
        inputMask &= ~INPUT::MOUSE_2;
}