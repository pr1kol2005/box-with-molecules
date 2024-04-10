#include <QWidget>

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>

#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include <QGraphicsLineItem>
#include <QGraphicsPixmapItem>


namespace Ui {
class MainWidget;
}

namespace Ui {
class MainWidget;
}

class MainWidget : public QWidget {
  Q_OBJECT;

  Ui::MainWidget* ui_;
  QGraphicsScene* scene_;

 public:
  explicit MainWidget(QWidget* parent = nullptr);
  ~MainWidget();
};
