
#include <QApplication>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QVector2D>
#include <QLineEdit>

#include <QDebug>

#include "cube-9-grid.h"

static const QString ENDL = QStringLiteral("\n");
static const QString PIPE = QStringLiteral("|");

Cube_9_Grid_Window::Cube_9_Grid_Window(QWidget* parent) : QMainWindow(parent),
  cell_width_(0), current_ndcs_run_(nullptr)
{
 even_color_ = QColor(120, 180, 240);
 odd_color_ = QColor(180, 240, 120);

 scene_ = new QGraphicsScene(this);
 scene_->setSceneRect(0, 0, 800, 600);

 view_ = new QGraphicsView(scene_, this);
 view_->setRenderHint(QPainter::Antialiasing);

 main_layout_ = new QVBoxLayout;
 bottom_layout_ = new QHBoxLayout;
 far_bottom_layout_ = new QHBoxLayout;

 main_layout_->addWidget(view_);

 qle_n_ = new QLineEdit("10", this);
 qle_d_ = new QLineEdit("2", this);
 qle_c_ = new QLineEdit("3", this);
 qle_s_ = new QLineEdit("1", this);

 qle_n_->setFixedWidth(120);
 qle_d_->setFixedWidth(120);
 qle_c_->setFixedWidth(120);
 qle_s_->setFixedWidth(120);

 bottom_layout_->addWidget(qle_n_, 1);
 bottom_layout_->addWidget(qle_d_, 1);
 bottom_layout_->addWidget(qle_c_, 1);
 bottom_layout_->addWidget(qle_s_, 1);

 bottom_layout_->setSpacing(10);

 go_button_ = new QPushButton("go", this);
 go_button_->setFixedWidth(40);

 connect(go_button_, &QPushButton::clicked, [this]()
 {
  recalculate(); show_cells(); reset_summary();
 });

 far_bottom_layout_->addStretch();
 far_bottom_layout_->addWidget(go_button_);
 far_bottom_layout_->addStretch();

 main_layout_->addLayout(bottom_layout_);
 main_layout_->addLayout(far_bottom_layout_);

 qte_summary_ = new QTextEdit(this);
 qte_summary_->setPlaceholderText("Run summary ...");
 main_layout_->addWidget(qte_summary_);

 central_widget_ = new QWidget(this);

 central_widget_->setLayout(main_layout_);

 setCentralWidget(central_widget_);

 resize(820, 620);

 cells_.resize(54);

 for(u4 i = 0; i < 54; ++i)
 {
  Cube_Cell& cc = cells_[i];
  cc.rank_ = i;
  cc.value_ = 0;

  cc.graphics_item_ = nullptr;

  if(i < 9)
  {
   cc.grid_row_ = i / 3;
   cc.grid_col_ = 3 + (i % 3);
  }
  else if(i >= 45)
  {
   cc.grid_row_ = 6 + ((i - 45) / 3);
   cc.grid_col_ = 3 + ((i - 45) % 3);
  }
  else //if(i < 27)
  {
   cc.grid_row_ = 3 + (((i - 9) / 3) % 3);
   cc.grid_col_ = (3 * ((i - 9) / 9)) + (i - 9) % 3;
  }
//  else
//  {
//   cc.grid_row_ = 0;
//   cc.grid_col_ = 0;
//  }
//  else
//  {
//   cc.grid_row_ = (i - 9) / 12;
//   cc.grid_col_ = (i - 9) % 12;
//  }
 }

 cell_width_ = 40;

 reposition_cells();
 complete_cells();
}

void Cube_9_Grid_Window::recalculate()
{
 u4 n = qle_n_->text().toInt();
 u4 d = qle_d_->text().toInt();
 u4 c = qle_c_->text().toInt();
 u4 s = qle_s_->text().toInt();

 current_ndcs_run_ = new NDCS_Run(n, d, c, s);

 u4 current = n;

 u4 count = 0;

 while(current > 1)
 {
  cells_[count % 54].value_ = current;
  if(current % d)  // //  odd (for d = 2)
  {
   cell_to_odd_color(cells_[count % 54]);
   current = current * c + s;
  }
  else
  {
   cell_to_even_color(cells_[count % 54]);
   current /= d;
  }
  current_ndcs_run_->steps().push_back(current);
  ++count;
 }
 cell_to_odd_color(cells_[count % 54]);
 cells_[count % 54].value_ = current;

}


void Cube_9_Grid_Window::reposition_cells()
{
 QVector2D offset {100, 100};
 for(Cube_Cell& cc : cells_)
 {
  cc.tl_ = offset.toPoint() + QPoint {cc.grid_col_ * cell_width_, cc.grid_row_ * cell_width_};

  if(cc.graphics_item_)
    cc.graphics_item_->setPos(cc.tl_);
  else
  {
   cc.graphics_item_ = new QGraphicsRectItem(cc.tl_.x(), cc.tl_.y(), cell_width_, cell_width_);
   cc.graphics_item_->setPen(QColor(30, 144, 255));
   scene_->addItem(cc.graphics_item_);
  }
 }
}

void Cube_9_Grid_Window::show_cells()
{
 for(Cube_Cell& cc : cells_)
 {
  if(cc.value_)
    cc.text_ = QString::number(cc.value_);
  else
  {
   cc.text_.clear();
   cell_to_no_background(cc);
  }
 }

 for(Cube_Cell& cc : cells_)
 {
  QGraphicsSimpleTextItem* sti = qgraphicsitem_cast<QGraphicsSimpleTextItem*>(cc.graphics_item_->childItems()[0]);
  sti->setText(cc.text_);
  center_text(cc, sti);
 }
}

void Cube_9_Grid_Window::reset_summary()
{
 summary_text_["Range"] = "[%1 to %2]"_qt.arg(current_ndcs_run_->min()).arg(current_ndcs_run_->max());
 summary_text_["Average"] = QString::number(current_ndcs_run_->get_average());
 summary_text_["Steps"] = QString::number(current_ndcs_run_->get_steps_count());
 summary_text_["Run"] = "N=%1, D=%2, C=%3, S=%4]"_qt
   .arg(current_ndcs_run_->n()).arg(current_ndcs_run_->d())
   .arg(current_ndcs_run_->c()).arg(current_ndcs_run_->s());

 summary_text_["Type"] = current_ndcs_run_->get_type_string();

 QString text;
 QTextStream qts(&text);

 auto write = [&qts, this](QString key) -> QTextStream&
 {
  qts << key << ": " << summary_text_[key];
  return qts;
 };

 write("Run") << ENDL;
 write("Steps") << PIPE;
 write("Type") << ENDL;
 write("Range") << PIPE;
 write("Avg") << ENDL;

 qte_summary_->setText(text);

 //qte_summary_->setT
}

void Cube_9_Grid_Window::cell_to_even_color(Cube_Cell& cc)
{
 cc.graphics_item_->setBrush(even_color_);
}

void Cube_9_Grid_Window::cell_to_odd_color(Cube_Cell& cc)
{
 cc.graphics_item_->setBrush(odd_color_);
}

void Cube_9_Grid_Window::cell_to_no_background(Cube_Cell& cc)
{
 cc.graphics_item_->setBrush(Qt::NoBrush);
}


void Cube_9_Grid_Window::center_text(Cube_Cell& cc, QGraphicsSimpleTextItem* sti)
{
 QRectF rect = cc.graphics_item_->rect();
 QRectF text_rect = sti->boundingRect();

 sti->setPos(rect.center().x() - text_rect.width() / 2.0,
   rect.center().y() - text_rect.height() / 2.0);

}

void Cube_9_Grid_Window::center_text(Cube_Cell& cc)
{
 QGraphicsSimpleTextItem* sti = qgraphicsitem_cast<QGraphicsSimpleTextItem*>(cc.graphics_item_->childItems()[0]);
 center_text(cc, sti);
}

void Cube_9_Grid_Window::complete_cells()
{
 for(Cube_Cell& cc : cells_)
 {
  cc.text_ = QString::number(cc.rank_);
  QGraphicsSimpleTextItem* sti = scene_->addSimpleText(cc.text_);
  sti->setParentItem(cc.graphics_item_);
  center_text(cc, sti);
 }
}


