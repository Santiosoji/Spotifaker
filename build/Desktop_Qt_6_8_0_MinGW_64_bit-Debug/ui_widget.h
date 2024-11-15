/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QSlider *progressSlider;
    QLabel *label_time;
    QPushButton *pushButton_play;
    QPushButton *pushButton_pause;
    QPushButton *pushButton_stop;
    QPushButton *pushButton_seekback;
    QPushButton *pushButton_mute;
    QPushButton *pushButton_seek;
    QSlider *vol;
    QWidget *screen;
    QFrame *line;
    QFrame *line_2;
    QFrame *line_3;
    QListView *listView;
    QPushButton *open;
    QLabel *label_file_name;
    QLabel *label_2;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(1076, 613);
        Widget->setStyleSheet(QString::fromUtf8("QWidget\n"
"{\n"
"    background-color:rgb(173,216,230);\n"
"}"));
        progressSlider = new QSlider(Widget);
        progressSlider->setObjectName("progressSlider");
        progressSlider->setGeometry(QRect(0, 460, 811, 22));
        progressSlider->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal\n"
"{\n"
"   height:7px; \n"
"   width:785px;\n"
"   background:gray; \n"
"   border-radius:2px;\n"
"}\n"
"QSlider::handle:horizontal\n"
"{\n"
"   background:rgb(52,50,64);\n"
"   width:10px;\n"
"   height:10px;\n"
"   margin:-7px -7px;\n"
"   border-radius:5px;\n"
"}"));
        progressSlider->setMaximum(1000);
        progressSlider->setOrientation(Qt::Orientation::Horizontal);
        label_time = new QLabel(Widget);
        label_time->setObjectName("label_time");
        label_time->setGeometry(QRect(750, 480, 51, 21));
        pushButton_play = new QPushButton(Widget);
        pushButton_play->setObjectName("pushButton_play");
        pushButton_play->setGeometry(QRect(250, 520, 100, 80));
        pushButton_play->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"   border:none;\n"
"   border-radius:20px;\n"
"   background-color:rgb(255,255,255);\n"
"   color:rgb(52,51,64);\n"
"   min-width:100px;\n"
"   max-width:100px;\n"
"   min-height:80px;\n"
"   max-height:80px;\n"
"   padding:0px;\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("reproducir.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_play->setIcon(icon);
        pushButton_play->setIconSize(QSize(40, 40));
        pushButton_pause = new QPushButton(Widget);
        pushButton_pause->setObjectName("pushButton_pause");
        pushButton_pause->setGeometry(QRect(140, 530, 80, 60));
        pushButton_pause->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"   border:none;\n"
"   border-radius:15px;\n"
"   background-color:rgb(255,255,255);\n"
"   color:rgb(52,51,64);\n"
"   min-width:80px;\n"
"   max-width:80px;\n"
"   min-height:60px;\n"
"   max-height:60px;\n"
"   padding:0px;\n"
"}"));
        pushButton_pause->setIconSize(QSize(30, 30));
        pushButton_stop = new QPushButton(Widget);
        pushButton_stop->setObjectName("pushButton_stop");
        pushButton_stop->setGeometry(QRect(380, 530, 80, 60));
        pushButton_stop->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"   border:none;\n"
"   border-radius:15px;\n"
"   background-color:rgb(255,255,255);\n"
"   color:rgb(52,51,64);\n"
"   min-width:80px;\n"
"   max-width:80px;\n"
"   min-height:60px;\n"
"   max-height:60px;\n"
"   padding:0px;\n"
"}"));
        pushButton_stop->setIconSize(QSize(30, 30));
        pushButton_seekback = new QPushButton(Widget);
        pushButton_seekback->setObjectName("pushButton_seekback");
        pushButton_seekback->setGeometry(QRect(30, 530, 80, 60));
        pushButton_seekback->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"   border:none;\n"
"   border-radius:15px;\n"
"   background-color:rgb(255,255,255);\n"
"   color:rgb(52,51,64);\n"
"   min-width:80px;\n"
"   max-width:80px;\n"
"   min-height:60px;\n"
"   max-height:60px;\n"
"   padding:0px;\n"
"}"));
        pushButton_seekback->setIconSize(QSize(25, 25));
        pushButton_mute = new QPushButton(Widget);
        pushButton_mute->setObjectName("pushButton_mute");
        pushButton_mute->setGeometry(QRect(620, 530, 60, 60));
        pushButton_mute->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"   border:none;\n"
"   border-radius:15px;\n"
"   background-color:rgb(255,255,255);\n"
"   color:rgb(52,51,64);\n"
"   min-width:60px;\n"
"   max-width:60px;\n"
"   min-height:60px;\n"
"   max-height:60px;\n"
"   padding:0px;\n"
"}"));
        pushButton_mute->setIconSize(QSize(20, 20));
        pushButton_seek = new QPushButton(Widget);
        pushButton_seek->setObjectName("pushButton_seek");
        pushButton_seek->setGeometry(QRect(490, 530, 80, 60));
        pushButton_seek->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"   border:none;\n"
"   border-radius:15px;\n"
"   background-color:rgb(255,255,255);\n"
"   color:rgb(52,51,64);\n"
"   min-width:80px;\n"
"   max-width:80px;\n"
"   min-height:60px;\n"
"   max-height:60px;\n"
"   padding:0px;\n"
"}"));
        pushButton_seek->setIconSize(QSize(25, 25));
        vol = new QSlider(Widget);
        vol->setObjectName("vol");
        vol->setGeometry(QRect(710, 550, 81, 22));
        vol->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal\n"
"{\n"
"   height:7px; \n"
"   width:60px;\n"
"   background:gray; \n"
"   border-radius:2px;\n"
"}\n"
"QSlider::handle:horizontal\n"
"{\n"
"   background:rgb(52,50,64);\n"
"   width:10px;\n"
"   height:10px;\n"
"   margin:-7px -7px;\n"
"   border-radius:5px;\n"
"}"));
        vol->setOrientation(Qt::Orientation::Horizontal);
        screen = new QWidget(Widget);
        screen->setObjectName("screen");
        screen->setGeometry(QRect(5, 14, 790, 441));
        line = new QFrame(Widget);
        line->setObjectName("line");
        line->setGeometry(QRect(0, 500, 811, 20));
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);
        line_2 = new QFrame(Widget);
        line_2->setObjectName("line_2");
        line_2->setGeometry(QRect(590, 510, 20, 101));
        line_2->setFrameShape(QFrame::Shape::VLine);
        line_2->setFrameShadow(QFrame::Shadow::Sunken);
        line_3 = new QFrame(Widget);
        line_3->setObjectName("line_3");
        line_3->setGeometry(QRect(800, 0, 20, 611));
        line_3->setFrameShape(QFrame::Shape::VLine);
        line_3->setFrameShadow(QFrame::Shadow::Sunken);
        listView = new QListView(Widget);
        listView->setObjectName("listView");
        listView->setGeometry(QRect(820, 60, 251, 471));
        open = new QPushButton(Widget);
        open->setObjectName("open");
        open->setGeometry(QRect(1030, 10, 30, 30));
        open->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"   border:none;\n"
"   border-radius:15px;\n"
"   background-color:rgb(255,255,255);\n"
"   color:rgb(52,51,64);\n"
"   min-width:30px;\n"
"   max-width:30px;\n"
"   min-height:30px;\n"
"   max-height:30px;\n"
"   padding:0px;\n"
"}"));
        QIcon icon1(QIcon::fromTheme(QIcon::ThemeIcon::DocumentOpen));
        open->setIcon(icon1);
        label_file_name = new QLabel(Widget);
        label_file_name->setObjectName("label_file_name");
        label_file_name->setGeometry(QRect(820, 5, 251, 41));
        label_file_name->setFrameShape(QFrame::Shape::Panel);
        label_file_name->setLineWidth(2);
        label_2 = new QLabel(Widget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(870, 550, 151, 41));
        QFont font;
        font.setFamilies({QString::fromUtf8("Comic Sans MS")});
        font.setPointSize(16);
        font.setBold(true);
        font.setItalic(true);
        label_2->setFont(font);
        label_2->setFrameShape(QFrame::Shape::Panel);
        label_2->setLineWidth(2);
        label_file_name->raise();
        progressSlider->raise();
        label_time->raise();
        pushButton_play->raise();
        pushButton_pause->raise();
        pushButton_stop->raise();
        pushButton_seekback->raise();
        pushButton_mute->raise();
        pushButton_seek->raise();
        vol->raise();
        screen->raise();
        line->raise();
        line_3->raise();
        line_2->raise();
        listView->raise();
        open->raise();
        label_2->raise();

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Form", nullptr));
        label_time->setText(QCoreApplication::translate("Widget", "00:00:00", nullptr));
        pushButton_play->setText(QString());
        pushButton_pause->setText(QString());
        pushButton_stop->setText(QString());
        pushButton_seekback->setText(QString());
        pushButton_mute->setText(QString());
        pushButton_seek->setText(QString());
        open->setText(QString());
        label_file_name->setText(QString());
        label_2->setText(QCoreApplication::translate("Widget", "SPOTIFAKER", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
