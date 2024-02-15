#ifndef CINEMA_H
#define CINEMA_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Cinema; }
QT_END_NAMESPACE

class Cinema : public QMainWindow
{
    Q_OBJECT

public:
    Cinema(QWidget *parent = nullptr);
    ~Cinema();

private slots:
    void on_pushButton_clicked();
    void buttonClickedSlot();
    void on_pushButton_2_clicked();
    void onReserveClicked();
    void onBuyClicked();
    void onSeePriceClicked();

    void on_ButtonTrailerOPP_clicked();

    void on_ButtonTrailerNAP_clicked();

    void on_ButtonTrailerSPI_clicked();

    void on_pushButton_SignUP_clicked();

    void on_pushButton_SignIN_clicked();

    void on_pushButtonUP_clicked();
    void on_pushButtonIN_clicked();

    void Menu();

    void on_NoAccount_clicked();

    void on_ShowPass_pressed();

    void on_ShowPass_released();

    void on_ShowPass_2_pressed();

    void on_ShowPass_2_released();


    void on_pushButtonOPP_clicked();

private:
    Ui::Cinema *ui;
};
#endif // CINEMA_H
