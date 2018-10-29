#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "centerframe.h"
#include <QMainWindow>


class QLabel;//文本或图像显示
class QComboBox;//组合按钮和弹出列表
class QSpinBox;//旋转框控件
class QToolButton;//命令或选项的快速访问按钮

//QMainWindow:主应用程序窗口

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);

    ~MainWindow();

    void createToolBar();
public slots:
    void penStyleChangged(int index=0);

    void penColorChangged();

private:
    CenterFrame *centerFrame;
    QLabel *styleLabel;
    QComboBox *styleComboBox;
    QLabel *widthLabel;
    QSpinBox *widthSpinBox;
    QToolButton *colorBtn;
    QToolButton *clearBtn;
    QToolButton *imgBtn;

protected:
    void on_picture();

};
#endif // MAINWINDOW_H
