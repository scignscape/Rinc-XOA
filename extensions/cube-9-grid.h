

#include <QApplication>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>

#include <QVBoxLayout>
#include <QHBoxLayout>

#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QSpinBox>

#include "global-types.h"
#include "accessors.h"

#include "tsl/ordered_map.h"

#include "color_selector.hpp"

using namespace  color_widgets;



struct Cube_Cell {
 QGraphicsRectItem* graphics_item_;

 QPoint tl_;
 u4 grid_row_;
 u4 grid_col_;
 u4 rank_;
 u4 value_;
 QString text_;
};

class NDCS_Run
{
 u4 n_;
 u4 d_;
 u4 c_;
 u4 s_;
 u4 min_;
 u4 max_;

 u2 stopping_time_;
 u2 coefficient_stopping_time_;

 QVector<u4> steps_;

public:

 ACCESSORS(u4 ,n)
 ACCESSORS(u4 ,d)
 ACCESSORS(u4 ,c)
 ACCESSORS(u4 ,s)

 ACCESSORS(u2 ,stopping_time)
 ACCESSORS(u2 ,coefficient_stopping_time)


 ACCESSORS(u4 ,min)
 ACCESSORS(u4 ,max)
 ACCESSORS__RGET(QVector<u4> ,steps)

 NDCS_Run(u4 n, u4 d, u4 c, u4 s): n_(n), d_(d), c_(c), s_(s),
   min_(n), max_(n), stopping_time_(0), coefficient_stopping_time_(0) {}

 void reset_range()
 {
  min_ = *std::min_element(steps_.constBegin(), steps_.constEnd());
  max_ = *std::max_element(steps_.constBegin(), steps_.constEnd());
 }

 u2 get_steps_count()
 {
  return steps_.size() - 1;
 }

 r4 get_average()
 {
  if(steps_.isEmpty())
    return 0.;
  r8 sum = std::accumulate(steps_.begin(), steps_.end(), 0.);
  return sum / steps_.size();
 }

 QString get_type_string()
 {
  if(min_ == 0)
    return "Unknown";
  if(min_ < n_)
    return "Converges to %1"_qt.arg(min_);
  return "Diverges";
 }

};

//typedef QPair<QString, QString> QStringPair;
//typedef QVector<QStringPair> QStringPairVector;


class Cube_9_Grid_Window : public QMainWindow
{
 QVBoxLayout* main_layout_;
 QHBoxLayout* bottom_layout_;
 QHBoxLayout* far_bottom_layout_;
 QHBoxLayout* color_selector_layout_;

 ColorSelector* even_color_selector_;
 ColorSelector* odd_color_selector_;

 QLabel* qlb_even_select_;
 QLabel* qlb_odd_select_;
 QLabel* qlb_color_select_explanation_;

 QSpinBox* qsb_d_;
 QSpinBox* qsb_c_;
 QSpinBox* qsb_s_;
 QSpinBox* qsb_n_;

 QPushButton* go_button_;

 QTextEdit* qte_summary_;

 tsl::ordered_map<QString, QString> summary_text_;


 QWidget* central_widget_;

 QGraphicsScene* scene_;
 QGraphicsView* view_;

 QVector<Cube_Cell> cells_;

 u4 cell_width_;

 QColor odd_color_;
 QColor even_color_;
 QColor border_color_;
 QColor empty_border_color_;

 NDCS_Run* current_ndcs_run_;

 void complete_cells();
 void reposition_cells();

 void show_cells();

 void cell_to_even_color(Cube_Cell& cc);
 void cell_to_odd_color(Cube_Cell& cc);
 void cell_to_no_background(Cube_Cell& cc);

 static void center_text(Cube_Cell& cc);
 static void center_text(Cube_Cell& cc, QGraphicsSimpleTextItem* sti);

 void recalculate();
 void reset_summary();

public:
 Cube_9_Grid_Window(QWidget* parent = nullptr);

};
