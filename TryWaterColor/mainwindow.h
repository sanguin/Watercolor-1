#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <splat_scene.h>
#include <QGraphicsEllipseItem>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
protected:
    virtual void mouseMoveEvent(QMouseEvent *);

private slots:
    void on_colorPicker_clicked();

    void on_simpleChoice_clicked();

    void on_wetOnDryCoice_clicked();

    void on_cruncyChoice_clicked();

    void on_wetOnWetChoice_clicked();

    void on_blobbChoice_clicked();

    void on_checkBox_clicked(bool checked);

    void on_pushButton_4_clicked();

    void on_c_D54A9E_clicked();

    void on_c_D54A63_clicked();

    void on_c_D5A74A_clicked();

    void on_c_B6D54A_clicked();

    void on_c_4AD57A_clicked();

    void on_c_4AB6D5_clicked();

    void on_c_6C4AD5_clicked();

    void on_c_954AD5_clicked();

    void on_c_D2CB6B_clicked();

private:
    SplatScene *m_scene;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
