
#include <QGuiApplication>
#include <QVector3D>
#include <QColor>

#include <Qt3DCore/QEntity>
#include <Qt3DCore/QTransform>
#include <Qt3DExtras/QCuboidMesh>
#include <Qt3DExtras/QOrbitCameraController>
#include <Qt3DExtras/QPhongMaterial>
#include <Qt3DExtras/Qt3DWindow>
#include <Qt3DExtras/QForwardRenderer>
#include <Qt3DRender/QCamera>
#include <Qt3DRender/QPointLight>

#include <QMouseEvent>

#include <QtMath>

class HoverRotateWindow : public Qt3DExtras::Qt3DWindow
{
 Qt3DCore::QTransform* transform_ = nullptr;
 QPoint last_pos_;
 bool has_last_pos_ = false;
 bool dragging_ = false;

 QColor converges_color_ = QColor(245, 185, 66);
 QColor diverges_color_ = QColor(66, 245, 173);
 QColor cycles_color_ = QColor(245, 66, 242);
 QColor default_231_color_ = QColor(255, 158, 176);

 QVector<int> color_codes_;
 int color_codes_count_ = 0;

 void add_color_code(int val)
 {
  val &= 3; //  just to be sure

  if(color_codes_count_ % 8) // 1 - 7
    color_codes_.last() |= (val << (color_codes_count_ % 8));
  else  //if(color_codes_count_) // 8, 16 ...
    color_codes_.push_back(val);

  ++color_codes_count_;
 }

public:

 explicit HoverRotateWindow();

protected:

 void mousePressEvent(QMouseEvent *event) override
 {
  if (event->button() == Qt::LeftButton)
  {
   last_pos_ = event->pos();
   dragging_ = true;
  }
  Qt3DExtras::Qt3DWindow::mousePressEvent(event);
 }

 void mouseMoveEvent(QMouseEvent *event) override
 {
  if (dragging_ && transform_)
  {
   const QPoint delta = event->pos() - last_pos_;
   last_pos_ = event->pos();

   const QQuaternion rotY = QQuaternion::fromAxisAndAngle(QVector3D(0.0f, 1.0f, 0.0f), delta.x() * 0.4f);
   const QQuaternion rotX = QQuaternion::fromAxisAndAngle(QVector3D(1.0f, 0.0f, 0.0f), delta.y() * 0.4f);
   transform_->setRotation(rotY * rotX * transform_->rotation());
  }

  Qt3DExtras::Qt3DWindow::mouseMoveEvent(event);
 }

 void mouseReleaseEvent(QMouseEvent *event) override
 {
  if (event->button() == Qt::LeftButton)
  {
   dragging_ = false;
  }
  Qt3DExtras::Qt3DWindow::mouseReleaseEvent(event);
 }

 void wheelEvent(QWheelEvent *event) override
 {
  if(transform_)
  {
   const float delta = event->angleDelta().y() / 120.0f;
   const float factor = qPow(1.1f, delta); // Smooth 10% step per notch
   const float newScale = qBound(0.1f, transform_->scale() * factor, 10.0f);
   transform_->setScale(newScale);
  }
  Qt3DExtras::Qt3DWindow::wheelEvent(event);
 }

};


static Qt3DCore::QEntity* create_cube_universe_lattice(Qt3DCore::QEntity *rootEntity,
  QVector<int> starts, QVector<int> color_codes, QVector<QColor> colors,
  int gridSize_x = 3, int gridSize_y = 3, int gridSize_z = 3, float spacing = 2.5f, float cubeSize = 1.0f);


//static HoverRotateWindow*
