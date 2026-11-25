
#include <QApplication>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QVector2D>
#include <QLineEdit>

#include <QDebug>

#include <QtMath>

#include "cube-9-grid.h"

static const QString ENDL = QStringLiteral("\n");
static const QString PIPE = QStringLiteral("|");

Cube_9_Grid_Window::Cube_9_Grid_Window(QWidget* parent) : QMainWindow(parent),
  cell_width_(0), current_ndcs_run_(nullptr)
{
 even_color_ = QColor(52, 211, 153);
 odd_color_ = QColor(251, 146, 60);
 border_color_ = QColor(71, 36, 42);
 empty_border_color_ = QColor(64, 128, 143);


 scene_ = new QGraphicsScene(this);
 scene_->setSceneRect(0, 0, 800, 600);

 view_ = new QGraphicsView(scene_, this);
 view_->setRenderHint(QPainter::Antialiasing);

 main_layout_ = new QVBoxLayout;
 bottom_layout_ = new QHBoxLayout;
 far_bottom_layout_ = new QHBoxLayout;

 main_layout_->addWidget(view_);

 qsb_n_ = new QSpinBox(this);
 qsb_n_->setRange(2, 99);
 qsb_n_->setValue(19);
 qsb_d_ = new QSpinBox(this);
 qsb_d_->setRange(2, 99);
 qsb_d_->setValue(2);
 qsb_c_ = new QSpinBox(this);
 qsb_c_->setRange(2, 99);
 qsb_c_->setValue(3);
 qsb_s_ = new QSpinBox(this);
 qsb_s_->setRange(1, 99);
 qsb_s_->setValue(1);

 qsb_n_->setFixedWidth(120);
 qsb_d_->setFixedWidth(120);
 qsb_c_->setFixedWidth(120);
 qsb_s_->setFixedWidth(120);

 bottom_layout_->addWidget(qsb_n_, 1);
 bottom_layout_->addWidget(qsb_d_, 1);
 bottom_layout_->addWidget(qsb_c_, 1);
 bottom_layout_->addWidget(qsb_s_, 1);

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

 color_selector_layout_ = new QHBoxLayout;

 even_color_selector_ = new ColorSelector(this);
 even_color_selector_->setColor(even_color_);
 odd_color_selector_ = new ColorSelector(this);
 odd_color_selector_->setColor(odd_color_);
 even_color_selector_->setMaximumWidth(30);
 odd_color_selector_->setMaximumWidth(30);

 even_color_selector_->setUpdateMode(color_widgets::ColorSelector::Confirm);
 odd_color_selector_->setUpdateMode(color_widgets::ColorSelector::Confirm);

 connect(even_color_selector_, &color_widgets::ColorSelector::colorChanged, this,
   [this](const QColor& color) { even_color_ = color; });

 connect(odd_color_selector_, &color_widgets::ColorSelector::colorChanged, this,
   [this](const QColor& color) { odd_color_ = color; });

 qlb_even_select_ = new QLabel("Even (descending) color:", this);
 qlb_odd_select_ = new QLabel("Odd (ascending) color:", this);

 qlb_even_select_->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
 qlb_odd_select_->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);

 color_selector_layout_->setContentsMargins(0, 0, 0, 0);

 color_selector_layout_->addWidget(qlb_even_select_);
 color_selector_layout_->addWidget(even_color_selector_);
 color_selector_layout_->addSpacing(20);
 color_selector_layout_->addWidget(qlb_odd_select_);
 color_selector_layout_->addWidget(odd_color_selector_);
 color_selector_layout_->addSpacing(50);

 qlb_color_select_explanation_ = new QLabel("(Click on the color swatch to edit)", this);
 color_selector_layout_->addWidget(qlb_color_select_explanation_);


 main_layout_->addLayout(color_selector_layout_);
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
 u4 n = qsb_n_->text().toInt();
 u4 d = qsb_d_->text().toInt();
 u4 c = qsb_c_->text().toInt();
 u4 s = qsb_s_->text().toInt();

 current_ndcs_run_ = new NDCS_Run(n, d, c, s);

 u4 current = n;

 current_ndcs_run_->steps().push_back(current);

 u4 count = 0;

 u4 odd_count = 0;
 u4 even_count = 0;

 // ln(2) / ln(3) ≈ 0.6309297535714574
 static constexpr r8 ln2_over_ln3 = 0.6309297535714574371;

 while(current > 1)
 {
  cells_[count % 54].value_ = current;
  if(current % d)  // //  odd (for d = 2)
  {
   cell_to_odd_color(cells_[count % 54]);
   current = current * c + s;
   ++odd_count;
  }
  else
  {
   cell_to_even_color(cells_[count % 54]);
   current /= d;
   ++even_count;

   if(current_ndcs_run_->coefficient_stopping_time() == 0)
   {
 //   r8 div = ((r8) (qPow(c, odd_count))) / qPow(d, even_count);

   r8 product = even_count * ln2_over_ln3;
   if(odd_count < product)
      current_ndcs_run_->set_coefficient_stopping_time(even_count);
   }

  }
  current_ndcs_run_->steps().push_back(current);

  if(current < n && current_ndcs_run_->stopping_time() == 0)
    current_ndcs_run_->set_stopping_time(count + 1);

  ++count;

 }

 current_ndcs_run_->reset_range();

 count %= 54;
 cell_to_odd_color(cells_[count]);
 cells_[count].value_ = current;


 while(++count < 54)
   cells_[count].value_ = 0;


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
   cc.graphics_item_->setPen(border_color_);
   scene_->addItem(cc.graphics_item_);
  }
 }
}

void Cube_9_Grid_Window::show_cells()
{
 for(Cube_Cell& cc : cells_)
 {
  if(cc.value_)
  {
   cc.graphics_item_->setPen(border_color_);
   cc.text_ = QString::number(cc.value_);
  }
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
 summary_text_["Avg"] = QString::number(current_ndcs_run_->get_average());
 summary_text_["Steps"] = QString::number(current_ndcs_run_->get_steps_count());
 summary_text_["Run"] = "N=%1, D=%2, C=%3, S=%4"_qt
   .arg(current_ndcs_run_->n()).arg(current_ndcs_run_->d())
   .arg(current_ndcs_run_->c()).arg(current_ndcs_run_->s());

 summary_text_["Type"] = current_ndcs_run_->get_type_string();
 summary_text_["Stopping Time"] = QString::number(current_ndcs_run_->stopping_time());
 summary_text_["Coefficient Stopping Time"] = QString::number(current_ndcs_run_->coefficient_stopping_time());

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
 write("Stopping Time") << ENDL;
 write("Coefficient Stopping Time") << ENDL;

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
 cc.graphics_item_->setPen(empty_border_color_);
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


