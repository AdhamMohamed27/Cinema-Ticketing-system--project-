#include "cinema.h"
#include "ui_cinema.h"
#include <QUrl>
#include <QDesktopServices>
#include <QCoreApplication>
#include "Credentials.h"
#include <QProcess>
int usersCount = 0;
QVector<Credentials> users; // Change type to store QPushButton pointers


QVector<QPushButton*> OPPbuttons; // Change type to store QPushButton pointers
Cinema::Cinema(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Cinema)
{
    ui->setupUi(this);
    QPixmap pix("/Users/alyalaswad/Desktop/Spring 2023/CS2 LAB/Cinema/Desktop.jpeg");
    ui->label->setPixmap(pix);
//    QLabel *label2 = new QLabel(this);
//    label2->setFrameStyle(QFrame::Panel | QFrame::Sunken);
//    label2->setText("first line\nsecond line");
//    label2->setAlignment(Qt::AlignBottom | Qt::AlignRight);
//    label2->setGeometry(10,10,30,80);

    QPixmap pixmap2("/Users/alyalaswad/Downloads/89269308b6cd0f754dfae79ea07f5eec.jpeg");
    QIcon ButtonIcon(pixmap2);
    ui->pushButton->setIcon(ButtonIcon);
    ui->pushButton->setIconSize(ui->pushButton->size());
    ui->pushButton_2->setIcon(ButtonIcon);
    ui->pushButton_2->setIconSize(ui->pushButton_2->size());

    ui->label_2->setText("<font color='white'>Cinema</font>");


    //HIDE SIGN IN OPTIONS
    ui->groupBoxHello->hide();
    ui->groupBoxSignUP->hide();
    ui->groupBoxSignIN->hide();


    //HIDE MENU OPTIONS
    ui->labelContrib->hide();
    ui->Spider->hide();
    ui->Napolean->hide();
    ui->Oppenheimer->hide();
    ui->pushButtonSPI->hide();
    ui->pushButtonNAP->hide();
    ui->pushButtonOPP->hide();
    ui->ReserveSpider->hide();
    ui->ReserveNapolean->hide();
    ui->ReserveOppenhemier->hide();
    ui->ButtonTrailerNAP->hide();
    ui->ButtonTrailerOPP->hide();
    ui->ButtonTrailerSPI->hide();



}

Cinema::~Cinema()
{
    delete ui;
}


void Cinema::on_pushButton_clicked()
{
    ui->lineEdit_Password->setEchoMode(QLineEdit::Password);
    ui->lineEdit_Password_2->setEchoMode(QLineEdit::Password);

    ui->groupBoxHello->show();

}

void Cinema::buttonClickedSlot()
{
    QPushButton* clickedButton = qobject_cast<QPushButton*>(sender());

    // Calculate the button index
    int ButtonIndex = OPPbuttons.indexOf(clickedButton);

    // Create a QGroupBox with the button index displayed on its label
    QGroupBox* groupBox = new QGroupBox(QString::number(ButtonIndex + 1), this);
    groupBox->setGeometry(250, 250, 250, 250);
    groupBox->setAlignment(Qt::AlignCenter);
    groupBox->setStyleSheet("QGroupBox { background-color: purple; color: white; }");

    // Create buttons for each action within the QGroupBox
    QPushButton* reserveButton = new QPushButton("Reserve", groupBox);
    reserveButton->setGeometry(50, 100, 150, 30);
    connect(reserveButton, &QPushButton::clicked, this, &Cinema::onReserveClicked);

    QPushButton* buyButton = new QPushButton("Buy", groupBox);
    buyButton->setGeometry(50, 150, 150, 30);
    connect(buyButton, &QPushButton::clicked, this, &Cinema::onBuyClicked);

    QPushButton* seePriceButton = new QPushButton("See Price", groupBox);
    seePriceButton->setGeometry(50, 200, 150, 30);
    connect(seePriceButton, &QPushButton::clicked, this, &Cinema::onSeePriceClicked);

    groupBox->show();
/*

*/





//     QLabel* label = new QLabel(QString::number(ButtonIndex + 1), this);
//    label->setGeometry(250,250,250,250);
//    label->setAlignment(Qt::AlignCenter);
//    label->setStyleSheet("QLabel { background-color: purple; color: white; }");
//    label->show();




    // Use the button index to access the button properties (optional)
    // QPushButton* clickedButton = buttons[buttonIndex];
    // ...

    // Could also emit a signal with the button index for further processing
    // emit buttonClicked(buttonIndex);


//    QPushButton* OUTbutton = new QPushButton(); // Use QPushButton instead of QLabel
//    OUTbutton->setGeometry(200,200,200,200);
//        if (OUTbutton->isDown()) { // Checks if the button is currently pressed
//            label->hide();
//        }

//    connect(OUTbutton, &QPushButton::clicked, this, &onOUTbuttonClicked);
}
void Cinema::onReserveClicked()
{

}
void Cinema::onBuyClicked()
{

}
void Cinema::onSeePriceClicked()
{

}

void Cinema::on_pushButton_2_clicked()
{
    on_pushButton_clicked();
    /*
    ui->label_2->hide();
    ui->pushButton->hide();
    ui->pushButton_2->hide();
    QPixmap pixIN("/Users/alyalaswad/Downloads/OPPBACK.png");
    ui->label->setPixmap(pixIN);




    for (int i = 0; i < 100; ++i) {
        QPushButton* button = new QPushButton(QString::number(i + 1), this); // Use QPushButton instead of QLabel
        button->setGeometry(i % 20 * 40, (i / 20 * 40) + 400, 40, 40);
        button->setStyleSheet("QPushButton { background-color: purple; color: white; }"); // Style the button
        buttons.push_back(button); // Add button to the vector
        button->show();
    }

    // Hide button at index 1 (accessing by index like labels)

    // Connect a click signal to each button (optional)
    for (int i = 0; i < buttons.size(); ++i) {
        connect(buttons[i], &QPushButton::clicked, this, [this] { buttonClickedSlot(); });
    }
=====================================================================================
SLOTS

    */
}


void Cinema::on_ButtonTrailerOPP_clicked()
{
    QDesktopServices::openUrl(QUrl("https://www.youtube.com/watch?v=uYPbbksJxIg&ab_channel=UniversalPictures"));
}


void Cinema::on_ButtonTrailerNAP_clicked()
{
    QDesktopServices::openUrl(QUrl("https://www.youtube.com/watch?v=LIsfMO5Jd_w&ab_channel=SonyPicturesEntertainment"));
}


void Cinema::on_ButtonTrailerSPI_clicked()
{
    QDesktopServices::openUrl(QUrl("https://www.youtube.com/watch?v=JfVOs4VSpmA&ab_channel=SonyPicturesEntertainment"));

}


void Cinema::on_pushButton_SignUP_clicked()
{
   QString tempUser  = ui->lineEdit_UserName->text();
   QString tempPass  = ui->lineEdit_Password->text();
   Credentials temp;
   temp.password =tempPass;
   temp.username =tempUser;
  if(tempUser.length()<4 || tempPass.length()<8)
  {
  }
  else{
   users.push_back(temp);
   ui->groupBoxSignUP->hide();
   Menu();
   }

}


void Cinema::on_pushButton_SignIN_clicked()
{
   ui->NoAccount->hide();
   QString tempUser  = ui->lineEdit_UserName->text();
   QString tempPass  = ui->lineEdit_Password->text();
   Credentials temp;
   temp.password =tempPass;
   temp.username =tempUser;

   for (int i = 0;  i< users.size(); i++)
   {
      Credentials tempCredential2 = users.at(i);
      if(tempCredential2.password == temp.password && tempCredential2.username==temp.username)
      {
          ui->groupBoxSignIN->hide();
          on_pushButton_clicked();
          break;
      }
   }
   ui->VerifyLabel->setText("Hmm... It looks like the username or the passwords are incorrect.");
   ui->NoAccount->show();



}

void Cinema::Menu()
{

   ui->label_2->hide();
   ui->pushButton->hide();
   ui->pushButton_2->hide();
   QPixmap pix2back("/Users/alyalaswad/Downloads/IMAGESBACK.jpg");
   ui->label->setPixmap(pix2back);

   QPixmap pixOPP("/Users/alyalaswad/Downloads/OppenheimerCover.jpg");
   ui->Oppenheimer->setPixmap(pixOPP);

   QPixmap pixNAP("/Users/alyalaswad/Downloads/NapoleanCover.jpg");
   ui->Napolean->setPixmap(pixNAP);

   QPixmap pixSPI("/Users/alyalaswad/Downloads/SpiderCover.jpg");


   ui->Spider->setPixmap(pixSPI);
   ui->labelContrib->show();
   ui->Spider->show();
   ui->Napolean->show();
   ui->Oppenheimer->show();
   ui->pushButtonSPI->show();
   ui->pushButtonNAP->show();
   ui->pushButtonOPP->show();
   ui->ReserveSpider->show();
   ui->ReserveNapolean->show();
   ui->ReserveOppenhemier->show();
   ui->ButtonTrailerNAP->show();
   ui->ButtonTrailerOPP->show();
   ui->ButtonTrailerSPI->show();
}



void Cinema::on_pushButtonUP_clicked()
{
   ui->groupBoxHello->hide();
   ui->groupBoxSignUP->show();

}
void Cinema::on_pushButtonIN_clicked()
{
   ui->groupBoxHello->hide();
   ui->groupBoxSignIN->show();
}



void Cinema::on_NoAccount_clicked()
{
   ui->groupBoxSignIN->hide();
   ui->groupBoxSignUP->show();
}


void Cinema::on_ShowPass_pressed()
{
     ui->lineEdit_Password->setEchoMode(QLineEdit::Normal);
}


void Cinema::on_ShowPass_released()
{
     ui->lineEdit_Password->setEchoMode(QLineEdit::Password);

}


void Cinema::on_ShowPass_2_pressed()
{
      ui->lineEdit_Password_2->setEchoMode(QLineEdit::Password);
}
void Cinema::on_ShowPass_2_released()
{
      ui->lineEdit_Password->setEchoMode(QLineEdit::Normal);

}

void Cinema::on_pushButtonOPP_clicked()
{
      ui->labelContrib->hide();
      ui->Spider->hide();
      ui->Napolean->hide();
      ui->Oppenheimer->hide();
      ui->pushButtonSPI->hide();
      ui->pushButtonNAP->hide();
      ui->pushButtonOPP->hide();
      ui->ReserveSpider->hide();
      ui->ReserveNapolean->hide();
      ui->ReserveOppenhemier->hide();
      ui->ButtonTrailerNAP->hide();
      ui->ButtonTrailerOPP->hide();
      ui->ButtonTrailerSPI->hide();
      QPixmap pixIN("/Users/alyalaswad/Downloads/OPPBACK.png");
      ui->label->setPixmap(pixIN);

      QString filePath = "/Users/alyalaswad/Downloads/Can You Hear The Music.wav";
      QProcess *process = new QProcess(this);
      process->startDetached("open", QStringList() << filePath);


      for (int i = 0; i < 100; ++i) {
      QPushButton* button = new QPushButton(QString::number(i + 1), this); // Use QPushButton instead of QLabel
      button->setGeometry(30+(i % 20 * 40), (i / 20 * 40) + 400, 40, 40);
      button->setStyleSheet("QPushButton { background-color: purple; color: white; }"); // Style the button
      OPPbuttons.push_back(button); // Add button to the vector
      button->show();
      }


      for (int i = 0; i < OPPbuttons.size(); ++i) {
      connect(OPPbuttons[i], &QPushButton::clicked, this, [this] { buttonClickedSlot(); });
      }
}

