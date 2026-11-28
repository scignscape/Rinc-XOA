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

#include "cube-universe-3d.h"


HoverRotateWindow::HoverRotateWindow()//Qt3DCore::QTransform* targetTransform)
  //: transform_(targetTransform)
{
 Qt3DCore::QEntity* rootEntity = new Qt3DCore::QEntity();

 // Light source
 Qt3DCore::QEntity* lightEntity = new Qt3DCore::QEntity(rootEntity);
 Qt3DRender::QPointLight* light = new Qt3DRender::QPointLight(lightEntity);
 light->setColor(Qt::white);
 light->setIntensity(1.5f);
 lightEntity->addComponent(light);

 Qt3DCore::QTransform* lightTransform = new Qt3DCore::QTransform(lightEntity);
 lightTransform->setTranslation(QVector3D(15.0f, 20.0f, 15.0f));
 lightEntity->addComponent(lightTransform);

 add_color_code(0); add_color_code(1); add_color_code(2); add_color_code(3);

 // Build 3x3x3 cube lattice centered at origin
 Qt3DCore::QEntity* latticeRoot = create_cube_universe_lattice(rootEntity, {2, 3, 1},
    color_codes_, {converges_color_, diverges_color_, cycles_color_, default_231_color_} //3, 2.5f, 1.0f
    );
 Qt3DCore::QTransform* latticeTransform = new Qt3DCore::QTransform(latticeRoot);
 latticeRoot->addComponent(latticeTransform);

 //HoverRotateWindow* view(latticeTransform);

 transform_ = latticeTransform;

 defaultFrameGraph()->setClearColor(QColor(QStringLiteral("#1e2229")));

 // Camera setup
 //Qt3DRender::QCamera* camera = view.camera();
 camera()->lens()->setPerspectiveProjection(45.0f, 16.0f / 9.0f, 0.1f, 1000.0f);
 camera()->setPosition(QVector3D(10.0f, 10.0f, 14.0f));
 camera()->setViewCenter(QVector3D(0.0f, 0.0f, 0.0f));

// // Orbit camera controls
// Qt3DExtras::QOrbitCameraController* camController = new Qt3DExtras::QOrbitCameraController(rootEntity);
// camController->setLinearSpeed(50.0f);
// camController->setLookSpeed(180.0f);
// camController->setCamera(camera);

 setRootEntity(rootEntity);
 resize(1024, 768);
 show();

 //return app.exec();
}


#include <Qt3DRender/QPaintedTextureImage>
#include <QPainter>
#include <QFont>

class TransparentTextTexture : public Qt3DRender::QPaintedTextureImage {
public:
    TransparentTextTexture(const QString &text, const QColor &textColor = Qt::white, Qt3DCore::QNode *parent = nullptr)
        : Qt3DRender::QPaintedTextureImage(parent), m_text(text), m_textColor(textColor) {
        setSize(QSize(256, 256));
        update();
    }

    void paint(QPainter *painter) override {
        painter->fillRect(0, 0, width(), height(), Qt::transparent);
        painter->setRenderHint(QPainter::Antialiasing);
        painter->setRenderHint(QPainter::TextAntialiasing);
        painter->setPen(m_textColor);
        painter->setFont(QFont("Arial", 48, QFont::Bold));
        painter->drawText(QRect(0, 0, width(), height()), Qt::AlignCenter, m_text);
    }

private:
    QString m_text;
    QColor m_textColor;
};

#include <Qt3DCore/QEntity>
#include <Qt3DCore/QTransform>
#include <Qt3DExtras/QPlaneMesh>
#include <Qt3DExtras/QTextureMaterial>
#include <Qt3DRender/QTexture>

void addLabelsToCube(Qt3DCore::QEntity *existingCubeEntity, const QString &text, float cubeSize = 1.0f, const QColor &textColor = Qt::white) {
    // Offset slightly beyond half the cube size to prevent z-fighting
    const float offset = (cubeSize * 0.5f) + 0.002f;

    struct FaceTransform {
        QVector3D pos;
        QQuaternion rot;
    };

    const QList<FaceTransform> faces = {
        { { 0.0f,    0.0f,  offset}, QQuaternion::fromEulerAngles( 90.0f,   0.0f, 0.0f) }, // Front (+Z)
        { { 0.0f,    0.0f, -offset}, QQuaternion::fromEulerAngles(-90.0f, 180.0f, 0.0f) }, // Back (-Z)
        { { offset,  0.0f,    0.0f}, QQuaternion::fromEulerAngles(  0.0f,   0.0f,-90.0f) }, // Right (+X)
        { {-offset,  0.0f,    0.0f}, QQuaternion::fromEulerAngles(  0.0f,   0.0f, 90.0f) }, // Left (-X)
        { { 0.0f,  offset,    0.0f}, QQuaternion::fromEulerAngles(  0.0f,   0.0f,  0.0f) }, // Top (+Y)
        { { 0.0f, -offset,    0.0f}, QQuaternion::fromEulerAngles(180.0f,   0.0f,  0.0f) }  // Bottom (-Y)
    };

    // Create ONE texture/material and share it across all 6 faces of this cube to save memory
    auto *texture = new Qt3DRender::QTexture2D(existingCubeEntity);
    texture->addTextureImage(new TransparentTextTexture(text, textColor, texture));

    auto *material = new Qt3DExtras::QTextureMaterial(existingCubeEntity);
    material->setTexture(texture);
    material->setAlphaBlendingEnabled(true);

    auto *planeMesh = new Qt3DExtras::QPlaneMesh(existingCubeEntity);
    planeMesh->setWidth(cubeSize);
    planeMesh->setHeight(cubeSize);

    for (const auto &face : faces) {
        auto *labelEntity = new Qt3DCore::QEntity(existingCubeEntity);

        auto *transform = new Qt3DCore::QTransform(labelEntity);
        transform->setTranslation(face.pos);
        transform->setRotation(face.rot);

        labelEntity->addComponent(planeMesh);
        labelEntity->addComponent(transform);
        labelEntity->addComponent(material);
    }
}



static Qt3DCore::QEntity* create_cube_universe_lattice(Qt3DCore::QEntity *rootEntity,
  QVector<int> starts, QVector<int> color_codes, QVector<QColor> colors, int gridSize_x, int gridSize_y, int gridSize_z,
  float spacing, float cubeSize)
{
 int x_start = starts.value(0, 2);
 int y_start = starts.value(1, 3);
 int z_start = starts.value(2, 1);

 Qt3DCore::QEntity* latticeRoot = new Qt3DCore::QEntity(rootEntity);

 // Share one mesh across all cubes for better performance
 Qt3DExtras::QCuboidMesh* cuboidMesh = new Qt3DExtras::QCuboidMesh(latticeRoot);
 cuboidMesh->setXExtent(cubeSize);
 cuboidMesh->setYExtent(cubeSize);
 cuboidMesh->setZExtent(cubeSize);

 const float x_offset = ((gridSize_x - 1) * spacing) * 0.5f;
 const float y_offset = ((gridSize_y - 1) * spacing) * 0.5f;
 const float z_offset = ((gridSize_z - 1) * spacing) * 0.5f;

 unsigned int count = 0, mask = 3;

 for (int x = 0; x < gridSize_x; ++x)
 {
  for (int y = 0; y < gridSize_y; ++y)
  {
   for (int z = 0; z < gridSize_z; ++z)
   {
    int color_code = color_codes.isEmpty()? 0 : (color_codes.last() & mask);
    ++count;

    if(count % 8) // not starting a new int
      mask <<= 2;
    else
    {
     mask = 3;
     if(!color_codes.isEmpty())
       color_codes.takeLast();
    }
    QColor cube_color = colors.value(color_code, Qt::white);

    Qt3DCore::QEntity* cubeEntity = new Qt3DCore::QEntity(latticeRoot);
    cubeEntity->addComponent(cuboidMesh);

    Qt3DExtras::QPhongMaterial* material = new Qt3DExtras::QPhongMaterial(cubeEntity);
    material->setDiffuse(cube_color);
//    material->setDiffuse(QColor::fromRgbF(
//                          static_cast<float>(x) / qMax(1, gridSize - 1),
//                          static_cast<float>(y) / qMax(1, gridSize - 1),
//                          static_cast<float>(z) / qMax(1, gridSize - 1)
//                          ));
    cubeEntity->addComponent(material);

    auto *transform = new Qt3DCore::QTransform(cubeEntity);
    transform->setTranslation(QVector3D(
                               x * spacing - x_offset,
                               y * spacing - y_offset,
                               z * spacing - z_offset
                               ));
    cubeEntity->addComponent(transform);

    QString label = QString("%1, %2, %3\n%4, %5, %6\n(%7)")
      .arg(x + x_start).arg(y + y_start).arg(z + z_start)
      .arg(x).arg(y).arg(z).arg(count);

    addLabelsToCube(cubeEntity, label, 1.0f, Qt::black);

   }
  }
 }

 return latticeRoot;
}
