/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDial>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow {
 public:
  QFrame *Window;
  QPushButton *open;
  QWidget *verticalLayoutWidget;
  QVBoxLayout *Info_Pannel;
  QLabel *name_file;
  QLabel *vershins;
  QLabel *facets;
  QFrame *Size_Type;
  QFrame *Dot_Panel;
  QPushButton *dot_size_minus;
  QLabel *label_2;
  QDial *dial_dot_type;
  QLabel *label;
  QPushButton *dot_size_plus;
  QLabel *label_3;
  QSpinBox *dot_size_spinBox;
  QLabel *label_vertices;
  QLabel *label_size_type;
  QLabel *label_lines;
  QFrame *Line_Panel;
  QPushButton *line_size_minus;
  QLabel *label_4;
  QLabel *label_5;
  QDial *dial_line_type;
  QSpinBox *line_size_spinBox;
  QPushButton *line_size_plus;
  QFrame *Palette;
  QFrame *Colors_panel;
  QLabel *R_Label;
  QSlider *Slider_Green;
  QLabel *B_Label;
  QLabel *G_Label;
  QDial *dial_color;
  QSlider *Slider_Blue;
  QLabel *Label_2;
  QSlider *Slider_Red;
  QLabel *Label_1;
  QLabel *Label_0;
  QLabel *label_palette;
  QFrame *Movement;
  QFrame *Panel_of_Move;
  QLabel *Move_label;
  QPushButton *plus_rotation_button;
  QPushButton *zoom_plus;
  QPushButton *plus_move_button;
  QCheckBox *x_move_checkbox;
  QPushButton *minus_rotation_button;
  QCheckBox *y_rotate_checkbox;
  QLabel *y_label;
  QCheckBox *z_rotate_checkbox;
  QLabel *y_label_2;
  QCheckBox *z_move_checkbox;
  QDoubleSpinBox *move_spinBox;
  QPushButton *zoom_minus;
  QPushButton *minus_move_button;
  QLabel *x_label;
  QLabel *x_label_2;
  QLabel *Rotation_label;
  QCheckBox *y_move_checkbox;
  QCheckBox *x_rotate_checkbox;
  QLabel *z_label_2;
  QDoubleSpinBox *zoom_spinBox;
  QLabel *z_label;
  QLabel *ZOOM_Label;
  QDoubleSpinBox *rotation_spinBox;
  QLabel *Move_Label;
  QFrame *Type_Projection;
  QLabel *label_9;
  QFrame *Types;
  QRadioButton *central_radio_but;
  QRadioButton *parallel_radio_but;
  QFrame *line;
  QPushButton *reset_but;
  QFrame *Save_frames;
  QFrame *photo_frame;
  QCheckBox *checkBoxBMP;
  QPushButton *ImageButton;
  QCheckBox *checkBoxJPG;
  QPushButton *ButtonGif;
  QFrame *line_3;
  QFrame *line_2;
  QPushButton *pushButton;

  void setupUi(QWidget *MainWindow) {
    if (MainWindow->objectName().isEmpty())
      MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
    MainWindow->resize(1300, 900);
    MainWindow->setMinimumSize(QSize(1300, 900));
    MainWindow->setMaximumSize(QSize(1300, 900));
    MainWindow->setStyleSheet(QString::fromUtf8(""));
    Window = new QFrame(MainWindow);
    Window->setObjectName(QString::fromUtf8("Window"));
    Window->setGeometry(QRect(0, 0, 330, 900));
    Window->setStyleSheet(
        QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
                          "border-color: rgb(0, 0, 0);"));
    Window->setFrameShape(QFrame::StyledPanel);
    Window->setFrameShadow(QFrame::Raised);
    open = new QPushButton(Window);
    open->setObjectName(QString::fromUtf8("open"));
    open->setGeometry(QRect(10, 10, 151, 25));
    open->setStyleSheet(
        QString::fromUtf8("background-color: rgb(255, 255, 255);"));
    verticalLayoutWidget = new QWidget(Window);
    verticalLayoutWidget->setObjectName(
        QString::fromUtf8("verticalLayoutWidget"));
    verticalLayoutWidget->setGeometry(QRect(10, 50, 301, 91));
    Info_Pannel = new QVBoxLayout(verticalLayoutWidget);
    Info_Pannel->setObjectName(QString::fromUtf8("Info_Pannel"));
    Info_Pannel->setContentsMargins(0, 0, 0, 0);
    name_file = new QLabel(verticalLayoutWidget);
    name_file->setObjectName(QString::fromUtf8("name_file"));
    name_file->setMaximumSize(QSize(289, 20));
    name_file->setStyleSheet(
        QString::fromUtf8("background-color: rgb(255, 255, 255);"));

    Info_Pannel->addWidget(name_file);

    vershins = new QLabel(verticalLayoutWidget);
    vershins->setObjectName(QString::fromUtf8("vershins"));
    vershins->setStyleSheet(
        QString::fromUtf8("background-color: rgb(255, 255, 255);"));

    Info_Pannel->addWidget(vershins);

    facets = new QLabel(verticalLayoutWidget);
    facets->setObjectName(QString::fromUtf8("facets"));
    facets->setMaximumSize(QSize(16777215, 20));
    facets->setStyleSheet(
        QString::fromUtf8("background-color: rgb(255, 255, 255);"));

    Info_Pannel->addWidget(facets);

    Size_Type = new QFrame(Window);
    Size_Type->setObjectName(QString::fromUtf8("Size_Type"));
    Size_Type->setGeometry(QRect(1, 330, 328, 201));
    Size_Type->setFrameShape(QFrame::NoFrame);
    Size_Type->setFrameShadow(QFrame::Raised);
    Size_Type->setLineWidth(0);
    Dot_Panel = new QFrame(Size_Type);
    Dot_Panel->setObjectName(QString::fromUtf8("Dot_Panel"));
    Dot_Panel->setGeometry(QRect(9, 50, 156, 143));
    Dot_Panel->setFrameShape(QFrame::Box);
    Dot_Panel->setFrameShadow(QFrame::Plain);
    dot_size_minus = new QPushButton(Dot_Panel);
    dot_size_minus->setObjectName(QString::fromUtf8("dot_size_minus"));
    dot_size_minus->setGeometry(QRect(13, 111, 30, 30));
    dot_size_minus->setAutoDefault(false);
    label_2 = new QLabel(Dot_Panel);
    label_2->setObjectName(QString::fromUtf8("label_2"));
    label_2->setGeometry(QRect(54, 3, 51, 17));
    label_2->setAlignment(Qt::AlignCenter);
    dial_dot_type = new QDial(Dot_Panel);
    dial_dot_type->setObjectName(QString::fromUtf8("dial_dot_type"));
    dial_dot_type->setGeometry(QRect(44, 24, 71, 71));
    dial_dot_type->setMinimum(0);
    dial_dot_type->setMaximum(2);
    dial_dot_type->setPageStep(1);
    dial_dot_type->setValue(1);
    dial_dot_type->setSliderPosition(1);
    dial_dot_type->setOrientation(Qt::Horizontal);
    dial_dot_type->setInvertedAppearance(false);
    dial_dot_type->setInvertedControls(false);
    dial_dot_type->setWrapping(false);
    dial_dot_type->setNotchTarget(3.000000000000000);
    dial_dot_type->setNotchesVisible(true);
    label = new QLabel(Dot_Panel);
    label->setObjectName(QString::fromUtf8("label"));
    label->setGeometry(QRect(19, 90, 44, 17));
    dot_size_plus = new QPushButton(Dot_Panel);
    dot_size_plus->setObjectName(QString::fromUtf8("dot_size_plus"));
    dot_size_plus->setGeometry(QRect(116, 111, 30, 30));
    dot_size_plus->setText(QString::fromUtf8("+"));
    label_3 = new QLabel(Dot_Panel);
    label_3->setObjectName(QString::fromUtf8("label_3"));
    label_3->setGeometry(QRect(97, 90, 41, 17));
    dot_size_spinBox = new QSpinBox(Dot_Panel);
    dot_size_spinBox->setObjectName(QString::fromUtf8("dot_size_spinBox"));
    dot_size_spinBox->setGeometry(QRect(44, 110, 71, 32));
    dot_size_spinBox->setMinimum(1);
    dot_size_spinBox->setMaximum(360);
    label_vertices = new QLabel(Size_Type);
    label_vertices->setObjectName(QString::fromUtf8("label_vertices"));
    label_vertices->setGeometry(QRect(9, 26, 156, 25));
    label_vertices->setFrameShape(QFrame::Box);
    label_vertices->setFrameShadow(QFrame::Plain);
    label_vertices->setAlignment(Qt::AlignCenter);
    label_vertices->setWordWrap(false);
    label_size_type = new QLabel(Size_Type);
    label_size_type->setObjectName(QString::fromUtf8("label_size_type"));
    label_size_type->setGeometry(QRect(9, 0, 311, 27));
    label_size_type->setFrameShape(QFrame::Box);
    label_size_type->setFrameShadow(QFrame::Plain);
    label_size_type->setAlignment(Qt::AlignCenter);
    label_size_type->setWordWrap(false);
    label_lines = new QLabel(Size_Type);
    label_lines->setObjectName(QString::fromUtf8("label_lines"));
    label_lines->setGeometry(QRect(164, 26, 156, 25));
    label_lines->setFrameShape(QFrame::Box);
    label_lines->setFrameShadow(QFrame::Plain);
    label_lines->setAlignment(Qt::AlignCenter);
    label_lines->setWordWrap(false);
    Line_Panel = new QFrame(Size_Type);
    Line_Panel->setObjectName(QString::fromUtf8("Line_Panel"));
    Line_Panel->setGeometry(QRect(164, 50, 156, 143));
    Line_Panel->setFrameShape(QFrame::Box);
    Line_Panel->setFrameShadow(QFrame::Plain);
    Line_Panel->setLineWidth(1);
    Line_Panel->setMidLineWidth(0);
    line_size_minus = new QPushButton(Line_Panel);
    line_size_minus->setObjectName(QString::fromUtf8("line_size_minus"));
    line_size_minus->setGeometry(QRect(13, 111, 30, 30));
    line_size_minus->setAutoDefault(false);
    label_4 = new QLabel(Line_Panel);
    label_4->setObjectName(QString::fromUtf8("label_4"));
    label_4->setGeometry(QRect(17, 90, 41, 17));
    label_4->setAlignment(Qt::AlignCenter);
    label_5 = new QLabel(Line_Panel);
    label_5->setObjectName(QString::fromUtf8("label_5"));
    label_5->setGeometry(QRect(93, 90, 51, 17));
    label_5->setAlignment(Qt::AlignCenter);
    dial_line_type = new QDial(Line_Panel);
    dial_line_type->setObjectName(QString::fromUtf8("dial_line_type"));
    dial_line_type->setGeometry(QRect(44, 20, 71, 71));
    dial_line_type->setSizeIncrement(QSize(2, 0));
    dial_line_type->setBaseSize(QSize(0, 0));
    dial_line_type->setMaximum(1);
    dial_line_type->setOrientation(Qt::Horizontal);
    dial_line_type->setInvertedAppearance(false);
    dial_line_type->setInvertedControls(false);
    dial_line_type->setWrapping(false);
    dial_line_type->setNotchTarget(5.000000000000000);
    dial_line_type->setNotchesVisible(true);
    line_size_spinBox = new QSpinBox(Line_Panel);
    line_size_spinBox->setObjectName(QString::fromUtf8("line_size_spinBox"));
    line_size_spinBox->setGeometry(QRect(44, 110, 71, 32));
    line_size_spinBox->setMinimum(1);
    line_size_spinBox->setMaximum(99);
    line_size_plus = new QPushButton(Line_Panel);
    line_size_plus->setObjectName(QString::fromUtf8("line_size_plus"));
    line_size_plus->setGeometry(QRect(116, 111, 30, 30));
    line_size_plus->setText(QString::fromUtf8("+"));
    Palette = new QFrame(Window);
    Palette->setObjectName(QString::fromUtf8("Palette"));
    Palette->setGeometry(QRect(1, 530, 328, 171));
    Palette->setFrameShape(QFrame::NoFrame);
    Palette->setFrameShadow(QFrame::Raised);
    Palette->setLineWidth(0);
    Colors_panel = new QFrame(Palette);
    Colors_panel->setObjectName(QString::fromUtf8("Colors_panel"));
    Colors_panel->setGeometry(QRect(9, 30, 311, 131));
    Colors_panel->setFrameShape(QFrame::Box);
    Colors_panel->setFrameShadow(QFrame::Plain);
    R_Label = new QLabel(Colors_panel);
    R_Label->setObjectName(QString::fromUtf8("R_Label"));
    R_Label->setGeometry(QRect(2, 20, 25, 25));
    R_Label->setAlignment(Qt::AlignCenter);
    Slider_Green = new QSlider(Colors_panel);
    Slider_Green->setObjectName(QString::fromUtf8("Slider_Green"));
    Slider_Green->setGeometry(QRect(30, 63, 160, 16));
    Slider_Green->setMaximum(253);
    Slider_Green->setSingleStep(1);
    Slider_Green->setValue(253);
    Slider_Green->setOrientation(Qt::Horizontal);
    B_Label = new QLabel(Colors_panel);
    B_Label->setObjectName(QString::fromUtf8("B_Label"));
    B_Label->setGeometry(QRect(2, 97, 25, 25));
    B_Label->setAlignment(Qt::AlignCenter);
    G_Label = new QLabel(Colors_panel);
    G_Label->setObjectName(QString::fromUtf8("G_Label"));
    G_Label->setGeometry(QRect(2, 59, 25, 25));
    G_Label->setAlignment(Qt::AlignCenter);
    dial_color = new QDial(Colors_panel);
    dial_color->setObjectName(QString::fromUtf8("dial_color"));
    dial_color->setGeometry(QRect(220, 30, 61, 71));
    dial_color->setMinimum(0);
    dial_color->setMaximum(2);
    dial_color->setPageStep(1);
    dial_color->setValue(0);
    dial_color->setSliderPosition(0);
    dial_color->setOrientation(Qt::Horizontal);
    dial_color->setInvertedAppearance(false);
    dial_color->setInvertedControls(false);
    dial_color->setWrapping(false);
    dial_color->setNotchTarget(3.000000000000000);
    dial_color->setNotchesVisible(true);
    Slider_Blue = new QSlider(Colors_panel);
    Slider_Blue->setObjectName(QString::fromUtf8("Slider_Blue"));
    Slider_Blue->setGeometry(QRect(30, 101, 160, 16));
    Slider_Blue->setMaximum(253);
    Slider_Blue->setSingleStep(1);
    Slider_Blue->setValue(253);
    Slider_Blue->setOrientation(Qt::Horizontal);
    Label_2 = new QLabel(Colors_panel);
    Label_2->setObjectName(QString::fromUtf8("Label_2"));
    Label_2->setGeometry(QRect(250, 100, 57, 17));
    Slider_Red = new QSlider(Colors_panel);
    Slider_Red->setObjectName(QString::fromUtf8("Slider_Red"));
    Slider_Red->setGeometry(QRect(30, 24, 160, 16));
    Slider_Red->setMaximum(253);
    Slider_Red->setSingleStep(1);
    Slider_Red->setValue(253);
    Slider_Red->setOrientation(Qt::Horizontal);
    Label_1 = new QLabel(Colors_panel);
    Label_1->setObjectName(QString::fromUtf8("Label_1"));
    Label_1->setGeometry(QRect(210, 100, 31, 17));
    Label_0 = new QLabel(Colors_panel);
    Label_0->setObjectName(QString::fromUtf8("Label_0"));
    Label_0->setGeometry(QRect(230, 20, 41, 17));
    Label_0->setAlignment(Qt::AlignCenter);
    label_palette = new QLabel(Palette);
    label_palette->setObjectName(QString::fromUtf8("label_palette"));
    label_palette->setGeometry(QRect(9, 1, 311, 30));
    label_palette->setFrameShape(QFrame::Box);
    label_palette->setAlignment(Qt::AlignCenter);
    Movement = new QFrame(Window);
    Movement->setObjectName(QString::fromUtf8("Movement"));
    Movement->setGeometry(QRect(1, 698, 328, 199));
    Movement->setFrameShape(QFrame::NoFrame);
    Movement->setFrameShadow(QFrame::Raised);
    Movement->setLineWidth(0);
    Panel_of_Move = new QFrame(Movement);
    Panel_of_Move->setObjectName(QString::fromUtf8("Panel_of_Move"));
    Panel_of_Move->setGeometry(QRect(9, 30, 311, 168));
    Panel_of_Move->setFrameShape(QFrame::Box);
    Panel_of_Move->setFrameShadow(QFrame::Plain);
    Move_label = new QLabel(Panel_of_Move);
    Move_label->setObjectName(QString::fromUtf8("Move_label"));
    Move_label->setGeometry(QRect(210, 9, 65, 21));
    Move_label->setAlignment(Qt::AlignCenter);
    plus_rotation_button = new QPushButton(Panel_of_Move);
    plus_rotation_button->setObjectName(
        QString::fromUtf8("plus_rotation_button"));
    plus_rotation_button->setGeometry(QRect(101, 30, 30, 30));
    plus_rotation_button->setAutoDefault(false);
    zoom_plus = new QPushButton(Panel_of_Move);
    zoom_plus->setObjectName(QString::fromUtf8("zoom_plus"));
    zoom_plus->setGeometry(QRect(190, 135, 30, 30));
    zoom_plus->setText(QString::fromUtf8("+"));
    plus_move_button = new QPushButton(Panel_of_Move);
    plus_move_button->setObjectName(QString::fromUtf8("plus_move_button"));
    plus_move_button->setGeometry(QRect(277, 30, 30, 30));
    plus_move_button->setAutoDefault(false);
    x_move_checkbox = new QCheckBox(Panel_of_Move);
    x_move_checkbox->setObjectName(QString::fromUtf8("x_move_checkbox"));
    x_move_checkbox->setGeometry(QRect(197, 70, 21, 16));
    minus_rotation_button = new QPushButton(Panel_of_Move);
    minus_rotation_button->setObjectName(
        QString::fromUtf8("minus_rotation_button"));
    minus_rotation_button->setGeometry(QRect(2, 30, 30, 30));
    minus_rotation_button->setAutoDefault(false);
    y_rotate_checkbox = new QCheckBox(Panel_of_Move);
    y_rotate_checkbox->setObjectName(QString::fromUtf8("y_rotate_checkbox"));
    y_rotate_checkbox->setGeometry(QRect(59, 70, 21, 16));
    y_label = new QLabel(Panel_of_Move);
    y_label->setObjectName(QString::fromUtf8("y_label"));
    y_label->setGeometry(QRect(61, 87, 16, 17));
    y_label->setAlignment(Qt::AlignCenter);
    z_rotate_checkbox = new QCheckBox(Panel_of_Move);
    z_rotate_checkbox->setObjectName(QString::fromUtf8("z_rotate_checkbox"));
    z_rotate_checkbox->setGeometry(QRect(96, 70, 21, 16));
    y_label_2 = new QLabel(Panel_of_Move);
    y_label_2->setObjectName(QString::fromUtf8("y_label_2"));
    y_label_2->setGeometry(QRect(238, 87, 16, 17));
    y_label_2->setAlignment(Qt::AlignCenter);
    z_move_checkbox = new QCheckBox(Panel_of_Move);
    z_move_checkbox->setObjectName(QString::fromUtf8("z_move_checkbox"));
    z_move_checkbox->setGeometry(QRect(272, 70, 21, 16));
    move_spinBox = new QDoubleSpinBox(Panel_of_Move);
    move_spinBox->setObjectName(QString::fromUtf8("move_spinBox"));
    move_spinBox->setGeometry(QRect(210, 30, 65, 30));
    move_spinBox->setSingleStep(0.100000000000000);
    zoom_minus = new QPushButton(Panel_of_Move);
    zoom_minus->setObjectName(QString::fromUtf8("zoom_minus"));
    zoom_minus->setGeometry(QRect(91, 135, 30, 30));
    zoom_minus->setAutoDefault(false);
    minus_move_button = new QPushButton(Panel_of_Move);
    minus_move_button->setObjectName(QString::fromUtf8("minus_move_button"));
    minus_move_button->setGeometry(QRect(178, 30, 30, 30));
    x_label = new QLabel(Panel_of_Move);
    x_label->setObjectName(QString::fromUtf8("x_label"));
    x_label->setGeometry(QRect(21, 87, 16, 17));
    QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(x_label->sizePolicy().hasHeightForWidth());
    x_label->setSizePolicy(sizePolicy);
    x_label->setAlignment(Qt::AlignCenter);
    x_label_2 = new QLabel(Panel_of_Move);
    x_label_2->setObjectName(QString::fromUtf8("x_label_2"));
    x_label_2->setGeometry(QRect(197, 87, 16, 17));
    sizePolicy.setHeightForWidth(x_label_2->sizePolicy().hasHeightForWidth());
    x_label_2->setSizePolicy(sizePolicy);
    x_label_2->setAlignment(Qt::AlignCenter);
    Rotation_label = new QLabel(Panel_of_Move);
    Rotation_label->setObjectName(QString::fromUtf8("Rotation_label"));
    Rotation_label->setGeometry(QRect(34, 9, 65, 21));
    Rotation_label->setAlignment(Qt::AlignCenter);
    y_move_checkbox = new QCheckBox(Panel_of_Move);
    y_move_checkbox->setObjectName(QString::fromUtf8("y_move_checkbox"));
    y_move_checkbox->setGeometry(QRect(235, 70, 21, 16));
    x_rotate_checkbox = new QCheckBox(Panel_of_Move);
    x_rotate_checkbox->setObjectName(QString::fromUtf8("x_rotate_checkbox"));
    x_rotate_checkbox->setGeometry(QRect(21, 70, 21, 16));
    z_label_2 = new QLabel(Panel_of_Move);
    z_label_2->setObjectName(QString::fromUtf8("z_label_2"));
    z_label_2->setGeometry(QRect(275, 87, 16, 17));
    z_label_2->setAlignment(Qt::AlignCenter);
    zoom_spinBox = new QDoubleSpinBox(Panel_of_Move);
    zoom_spinBox->setObjectName(QString::fromUtf8("zoom_spinBox"));
    zoom_spinBox->setGeometry(QRect(123, 135, 65, 30));
    zoom_spinBox->setMinimum(0.100000000000000);
    zoom_spinBox->setSingleStep(0.100000000000000);
    zoom_spinBox->setStepType(QAbstractSpinBox::DefaultStepType);
    zoom_spinBox->setValue(1.000000000000000);
    z_label = new QLabel(Panel_of_Move);
    z_label->setObjectName(QString::fromUtf8("z_label"));
    z_label->setGeometry(QRect(99, 89, 16, 16));
    z_label->setAlignment(Qt::AlignCenter);
    ZOOM_Label = new QLabel(Panel_of_Move);
    ZOOM_Label->setObjectName(QString::fromUtf8("ZOOM_Label"));
    ZOOM_Label->setGeometry(QRect(123, 105, 65, 30));
    ZOOM_Label->setAlignment(Qt::AlignCenter);
    rotation_spinBox = new QDoubleSpinBox(Panel_of_Move);
    rotation_spinBox->setObjectName(QString::fromUtf8("rotation_spinBox"));
    rotation_spinBox->setGeometry(QRect(34, 30, 65, 30));
    rotation_spinBox->setMaximum(360.000000000000000);
    Move_Label = new QLabel(Movement);
    Move_Label->setObjectName(QString::fromUtf8("Move_Label"));
    Move_Label->setGeometry(QRect(9, 1, 311, 30));
    Move_Label->setFrameShape(QFrame::Box);
    Move_Label->setAlignment(Qt::AlignCenter);
    Type_Projection = new QFrame(Window);
    Type_Projection->setObjectName(QString::fromUtf8("Type_Projection"));
    Type_Projection->setGeometry(QRect(1, 269, 328, 61));
    Type_Projection->setFrameShape(QFrame::NoFrame);
    Type_Projection->setFrameShadow(QFrame::Plain);
    Type_Projection->setLineWidth(0);
    label_9 = new QLabel(Type_Projection);
    label_9->setObjectName(QString::fromUtf8("label_9"));
    label_9->setGeometry(QRect(9, 0, 311, 25));
    label_9->setFrameShape(QFrame::Box);
    label_9->setAlignment(Qt::AlignCenter);
    Types = new QFrame(Type_Projection);
    Types->setObjectName(QString::fromUtf8("Types"));
    Types->setGeometry(QRect(9, 24, 311, 27));
    Types->setFrameShape(QFrame::Box);
    Types->setFrameShadow(QFrame::Plain);
    Types->setLineWidth(1);
    central_radio_but = new QRadioButton(Types);
    central_radio_but->setObjectName(QString::fromUtf8("central_radio_but"));
    central_radio_but->setGeometry(QRect(191, 1, 81, 25));
    QFont font;
    font.setBold(false);
    font.setItalic(false);
    font.setWeight(50);
    font.setStyleStrategy(QFont::PreferDefault);
    central_radio_but->setFont(font);
    central_radio_but->setLayoutDirection(Qt::LeftToRight);
    central_radio_but->setStyleSheet(QString::fromUtf8(""));
    parallel_radio_but = new QRadioButton(Types);
    parallel_radio_but->setObjectName(QString::fromUtf8("parallel_radio_but"));
    parallel_radio_but->setGeometry(QRect(37, 1, 81, 25));
    parallel_radio_but->setFont(font);
    parallel_radio_but->setLayoutDirection(Qt::RightToLeft);
    parallel_radio_but->setAutoFillBackground(false);
    parallel_radio_but->setChecked(true);
    line = new QFrame(Types);
    line->setObjectName(QString::fromUtf8("line"));
    line->setWindowModality(Qt::ApplicationModal);
    line->setGeometry(QRect(154, 0, 1, 27));
    line->setAutoFillBackground(false);
    line->setStyleSheet(
        QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
    line->setFrameShadow(QFrame::Plain);
    line->setFrameShape(QFrame::VLine);
    line->raise();
    central_radio_but->raise();
    parallel_radio_but->raise();
    reset_but = new QPushButton(Window);
    reset_but->setObjectName(QString::fromUtf8("reset_but"));
    reset_but->setGeometry(QRect(170, 10, 151, 25));
    Save_frames = new QFrame(Window);
    Save_frames->setObjectName(QString::fromUtf8("Save_frames"));
    Save_frames->setGeometry(QRect(1, 180, 328, 80));
    Save_frames->setFrameShape(QFrame::NoFrame);
    Save_frames->setFrameShadow(QFrame::Plain);
    photo_frame = new QFrame(Save_frames);
    photo_frame->setObjectName(QString::fromUtf8("photo_frame"));
    photo_frame->setGeometry(QRect(9, 0, 311, 80));
    photo_frame->setFrameShape(QFrame::Box);
    photo_frame->setFrameShadow(QFrame::Plain);
    checkBoxBMP = new QCheckBox(photo_frame);
    checkBoxBMP->setObjectName(QString::fromUtf8("checkBoxBMP"));
    checkBoxBMP->setGeometry(QRect(28, 50, 61, 22));
    ImageButton = new QPushButton(photo_frame);
    ImageButton->setObjectName(QString::fromUtf8("ImageButton"));
    ImageButton->setGeometry(QRect(2, 2, 227, 40));
    checkBoxJPG = new QCheckBox(photo_frame);
    checkBoxJPG->setObjectName(QString::fromUtf8("checkBoxJPG"));
    checkBoxJPG->setGeometry(QRect(145, 50, 61, 22));
    ButtonGif = new QPushButton(photo_frame);
    ButtonGif->setObjectName(QString::fromUtf8("ButtonGif"));
    ButtonGif->setGeometry(QRect(233, 2, 75, 75));
    ButtonGif->setLayoutDirection(Qt::LeftToRight);
    line_3 = new QFrame(photo_frame);
    line_3->setObjectName(QString::fromUtf8("line_3"));
    line_3->setWindowModality(Qt::ApplicationModal);
    line_3->setGeometry(QRect(220, 0, 20, 81));
    line_3->setAutoFillBackground(false);
    line_3->setStyleSheet(
        QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
    line_3->setFrameShadow(QFrame::Plain);
    line_3->setFrameShape(QFrame::VLine);
    line_2 = new QFrame(photo_frame);
    line_2->setObjectName(QString::fromUtf8("line_2"));
    line_2->setWindowModality(Qt::ApplicationModal);
    line_2->setGeometry(QRect(117, 42, 1, 39));
    line_2->setAutoFillBackground(false);
    line_2->setStyleSheet(
        QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
    line_2->setFrameShadow(QFrame::Plain);
    line_2->setFrameShape(QFrame::VLine);
    pushButton = new QPushButton(Window);
    pushButton->setObjectName(QString::fromUtf8("pushButton"));
    pushButton->setGeometry(QRect(10, 145, 311, 31));
    Save_frames->raise();
    open->raise();
    verticalLayoutWidget->raise();
    Size_Type->raise();
    Palette->raise();
    Movement->raise();
    Type_Projection->raise();
    reset_but->raise();
    pushButton->raise();

    retranslateUi(MainWindow);

    QMetaObject::connectSlotsByName(MainWindow);
  }  // setupUi

  void retranslateUi(QWidget *MainWindow) {
    MainWindow->setWindowTitle(
        QCoreApplication::translate("MainWindow", "3D Viewer", nullptr));
    open->setText(
        QCoreApplication::translate("MainWindow", "Open file", nullptr));
    name_file->setText(
        QCoreApplication::translate("MainWindow", "Name:", nullptr));
    vershins->setText(QCoreApplication::translate(
        "MainWindow", "Number of vertices:", nullptr));
    facets->setText(QCoreApplication::translate("MainWindow",
                                                "Number of facets:", nullptr));
    dot_size_minus->setText(
        QCoreApplication::translate("MainWindow", "-", nullptr));
    label_2->setText(
        QCoreApplication::translate("MainWindow", "Square", nullptr));
    label->setText(QCoreApplication::translate("MainWindow", "Empty", nullptr));
    label_3->setText(
        QCoreApplication::translate("MainWindow", "Circle", nullptr));
    label_vertices->setText(
        QCoreApplication::translate("MainWindow", "Vertices", nullptr));
    label_size_type->setText(
        QCoreApplication::translate("MainWindow", "Size & Type", nullptr));
    label_lines->setText(
        QCoreApplication::translate("MainWindow", "Lines", nullptr));
    line_size_minus->setText(
        QCoreApplication::translate("MainWindow", "-", nullptr));
    label_4->setText(
        QCoreApplication::translate("MainWindow", "Solid", nullptr));
    label_5->setText(
        QCoreApplication::translate("MainWindow", "Dashed", nullptr));
    R_Label->setText(QCoreApplication::translate("MainWindow", "R", nullptr));
    B_Label->setText(QCoreApplication::translate("MainWindow", "B", nullptr));
    G_Label->setText(QCoreApplication::translate("MainWindow", "G", nullptr));
    Label_2->setText(
        QCoreApplication::translate("MainWindow", "Vertices", nullptr));
    Label_1->setText(QCoreApplication::translate("MainWindow", "BG", nullptr));
    Label_0->setText(
        QCoreApplication::translate("MainWindow", "Edge", nullptr));
    label_palette->setText(QCoreApplication::translate(
        "MainWindow", "Palette for objects", nullptr));
    Move_label->setText(
        QCoreApplication::translate("MainWindow", "Move", nullptr));
    plus_rotation_button->setText(
        QCoreApplication::translate("MainWindow", "+", nullptr));
    plus_move_button->setText(
        QCoreApplication::translate("MainWindow", "+", nullptr));
    x_move_checkbox->setText(QString());
    minus_rotation_button->setText(
        QCoreApplication::translate("MainWindow", "-", nullptr));
    y_rotate_checkbox->setText(
        QCoreApplication::translate("MainWindow", "CheckBox", nullptr));
    y_label->setText(QCoreApplication::translate("MainWindow", "y", nullptr));
    z_rotate_checkbox->setText(
        QCoreApplication::translate("MainWindow", "CheckBox", nullptr));
    y_label_2->setText(QCoreApplication::translate("MainWindow", "y", nullptr));
    z_move_checkbox->setText(QString());
    zoom_minus->setText(
        QCoreApplication::translate("MainWindow", "-", nullptr));
    minus_move_button->setText(
        QCoreApplication::translate("MainWindow", "-", nullptr));
    x_label->setText(QCoreApplication::translate("MainWindow", "x", nullptr));
    x_label_2->setText(QCoreApplication::translate("MainWindow", "x", nullptr));
    Rotation_label->setText(
        QCoreApplication::translate("MainWindow", "Rotation", nullptr));
    y_move_checkbox->setText(QString());
    x_rotate_checkbox->setText(
        QCoreApplication::translate("MainWindow", "CheckBox", nullptr));
    z_label_2->setText(QCoreApplication::translate("MainWindow", "z", nullptr));
    z_label->setText(QCoreApplication::translate("MainWindow", "z", nullptr));
    ZOOM_Label->setText(
        QCoreApplication::translate("MainWindow", "ZOOM", nullptr));
    Move_Label->setText(QCoreApplication::translate(
        "MainWindow", "Movement/Zoom Pannel", nullptr));
    label_9->setText(QCoreApplication::translate(
        "MainWindow", "Type of Projection", nullptr));
    central_radio_but->setText(
        QCoreApplication::translate("MainWindow", "Central", nullptr));
    parallel_radio_but->setText(
        QCoreApplication::translate("MainWindow", "Parallel", nullptr));
    reset_but->setText(
        QCoreApplication::translate("MainWindow", "Reload file", nullptr));
    checkBoxBMP->setText(
        QCoreApplication::translate("MainWindow", "BMP", nullptr));
    ImageButton->setText(
        QCoreApplication::translate("MainWindow", "Save image as", nullptr));
    checkBoxJPG->setText(
        QCoreApplication::translate("MainWindow", "JPG", nullptr));
    ButtonGif->setText(QCoreApplication::translate("MainWindow",
                                                   "Record\n"
                                                   " as\n"
                                                   " GIF",
                                                   nullptr));
    pushButton->setText(
        QCoreApplication::translate("MainWindow", "Restore state", nullptr));
  }  // retranslateUi
};

namespace Ui {
class MainWindow : public Ui_MainWindow {};
}  // namespace Ui

QT_END_NAMESPACE

#endif  // UI_MAINWINDOW_H
