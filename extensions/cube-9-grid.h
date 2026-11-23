

#include <QApplication>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>

#include <QVBoxLayout>
#include <QHBoxLayout>

#include <QLineEdit>
#include <QPushButton>

struct Cube_Cell {

 QGraphicsRectItem* graphics_item_;

 QPoint tl_;
 int grid_row_;
 int grid_col_;
 int rank_;
 int value_;
 QString text_;


};

class Cube_9_Grid_Window : public QMainWindow
{
 QVBoxLayout* main_layout_;
 QHBoxLayout* bottom_layout_;
 QHBoxLayout* far_bottom_layout_;

 QLineEdit* qle_d_;
 QLineEdit* qle_c_;
 QLineEdit* qle_s_;
 QLineEdit* qle_n_;

 QPushButton* go_button_;

 QWidget* central_widget_;

 QGraphicsScene* scene_;
 QGraphicsView* view_;

 QVector<Cube_Cell> cells_;

 int cell_width_;

 QColor odd_color_;
 QColor even_color_;

 void complete_cells();
 void reposition_cells();

 void show_cells();

 void cell_to_even_color(Cube_Cell& cc);
 void cell_to_odd_color(Cube_Cell& cc);

 static void cell_to_no_background(Cube_Cell& cc);

 static void center_text(Cube_Cell& cc);
 static void center_text(Cube_Cell& cc, QGraphicsSimpleTextItem* sti);

 void recalculate();

public:
 Cube_9_Grid_Window(QWidget* parent = nullptr);

};
