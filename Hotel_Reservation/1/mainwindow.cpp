//main window
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("G:/final3/1/1.db");
    qDebug()<<db.open();

}

MainWindow::~MainWindow()
{
    db.close();
    delete ui;
}


//page 1 login
void MainWindow::on_login_2_clicked()
{

    login_email=ui->login_email_input->text();
    login_password=ui->login_password_input->text();

    pname="   ",pemail="   ",pmobile="   ";
    QSqlQuery query;
    query.exec("SELECT * FROM user1 WHERE email = '"+login_email+"' AND password = '"+login_password+"'");

    if(query.next())
    {
       ui->stackedWidget->setCurrentIndex(1);
       pname+=(query.value(0).toString());
       pemail+=(query.value(1).toString());
       pmobile+=(query.value(3).toString());
       ui->name_level->setText(pname);
       ui->email_level->setText(pemail);
       ui->contact_level->setText(pmobile);
    }
    else
    {

        QMessageBox::warning(this,"login","wrong password");
    }
    ui->login_email_input->clear();
    ui->login_password_input->clear();
}


void MainWindow::on_singup_clicked()
{

    signup_name=ui->signup_name_input->text();
    signup_email=ui->signup_email_input->text();
    signup_contact=ui->signup_contect_input->text();
    signup_password=ui->signup_password_input->text();

    QSqlQuery query;
    query.exec("INSERT INTO user1(Name,Email,Password,Mobile)VALUES('"+signup_name+"','"+signup_email+"','"+signup_password+"','"+signup_contact+"')");
    QMessageBox::information(this,"signup","sign up succesful");

    ui->signup_name_input->clear();
    ui->signup_email_input->clear();
    ui->signup_contect_input->clear();
    ui->signup_password_input->clear();

}




//page 2
void MainWindow::on_profilebutton_p2_clicked()
{
     ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_backbutton_p2_clicked()
{
     ui->stackedWidget->setCurrentIndex(0);

}



void MainWindow::on_searchbutton_p2_clicked()
{


     divisiontext= ui->division_p2->currentText();
     roomtext=ui->room_p2->currentText();
     //qDebug()<<dt;

     if(divisiontext=="CTG"){
     ui->stackedWidget->setCurrentIndex(2);


     QSqlQueryModel *model=new QSqlQueryModel();//hotel name
     QSqlQueryModel *model1=new QSqlQueryModel();//hotel adress


     QSqlQuery *qry = new QSqlQuery(db);
     QSqlQuery *qry1 = new QSqlQuery(db);


     qry->prepare("SELECT Hotel_Name FROM Hotel WHERE division = '"+divisiontext+"' ");
     qry1->prepare("SELECT Adress FROM Hotel WHERE division = '"+divisiontext+"' ");

     qDebug()<<qry->exec();
     qDebug()<<qry1->exec();

     model->setQuery(*qry);
     model1->setQuery(*qry1);

     QVBoxLayout *lay=new QVBoxLayout(this);


     QPushButton *name[100];

     for(int j=0;j<=model->rowCount()-1;j++)
     {
        QString str=model->record(j).value(0).toString();
        QString str1=model1->record(j).value(0).toString();

        name[j]=new QPushButton(str);
        QLabel *lab=new QLabel("Adress: "+str1+"");

        QFrame *line;

        line=new QFrame();
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line->setStyleSheet("background:White");

        name[j]->setObjectName("btnName_1");//push button obj name
        name[j]->setStyleSheet(
            "   QPushButton#btnName_1 {"
            "     background:transparent; Text-align:left;font-family:century gothic;font-size:18px; color:orange;"
            " }"
            " QPushButton#btnName_1:hover {"
            "     color: yellow;font-size:25px;"
            " }");                                  //Setting up the pushbutton with the on-hover changes...



        lab->setStyleSheet("background:transparent; Text-align:left;font-family:century gothic;font-size:18px; color:white");

         //adding all the widgets to the previously cretaed grid layout...
        lay->addWidget(name[j]);
        lay->addWidget(lab);
        lay->addWidget(line);  //adding all the widgets to the previously cretaed grid layout...

        connect(name[j],SIGNAL(clicked()),this,SLOT(onnameclicked()));//like push buuton



     }
        ui->scrollAreaWidgetContents->setLayout(lay);

      //connClose();
     }
     else
     {
         ui->stackedWidget->setCurrentIndex(3);


         QSqlQueryModel *model2=new QSqlQueryModel();
         QSqlQueryModel *model3=new QSqlQueryModel();

         //model->record.clear();
        // model1->record.clear();

         QSqlQuery *qry2 = new QSqlQuery(db);
         QSqlQuery *qry3 = new QSqlQuery(db);


         qry2->prepare("SELECT Hotel_Name FROM Hotel WHERE division = '"+divisiontext+"' ");
         qry3->prepare("SELECT Adress FROM Hotel WHERE division = '"+divisiontext+"' ");

         qDebug()<<qry2->exec();
         qDebug()<<qry3->exec();

         model2->setQuery(*qry2);
         model3->setQuery(*qry3);

         QVBoxLayout *lay2=new QVBoxLayout(this);


         QPushButton *name2[100];

         for(int j=0;j<=model2->rowCount()-1;j++)
         {
            QString str=model2->record(j).value(0).toString();
            QString str1=model3->record(j).value(0).toString();

            name2[j]=new QPushButton(str);
            QLabel *lab2=new QLabel("Adress: "+str1+"");

            QFrame *line;

            line=new QFrame();
            line->setFrameShape(QFrame::HLine);
            line->setFrameShadow(QFrame::Sunken);
            line->setStyleSheet("background:White");

            name2[j]->setObjectName("btnName_1");
            name2[j]->setStyleSheet(
                "   QPushButton#btnName_1 {"
                "     background:transparent; Text-align:left;font-family:century gothic;font-size:18px; color:orange;"
                " }"
                " QPushButton#btnName_1:hover {"
                "     color: yellow;font-size:25px;"
                " }");                                  //Setting up the pushbutton with the on-hover changes...



            lab2->setStyleSheet("background:transparent; Text-align:left;font-family:century gothic;font-size:18px; color:white");

             //adding all the widgets to the previously cretaed grid layout...
            lay2->addWidget(name2[j]);
            lay2->addWidget(lab2);
            lay2->addWidget(line);  //adding all the widgets to the previously cretaed grid layout...

            connect(name2[j],SIGNAL(clicked()),this,SLOT(onnameclicked()));
            ui->scrollAreaWidgetContents_2->setLayout(lay2);

         }



          //connClose();
         }

}



//page 3

QString buttonText;

//assigning zero to the static int created in header...
int MainWindow::x=0;
//creating an array of button, vector can be used as well...
QPushButton *pButton[100];


void MainWindow::onnameclicked()
{
        bname="   ";
        bemail="   ";
        badress="   ";
        bmobile= "   ";


    //initializing the previously created button...
        pButton[x]=new QPushButton;//button crick

    //recieving the button (name) clicked and assigning it to the pButton[x]...
        pButton[x] = qobject_cast<QPushButton*>(sender());

     /*//we have increased the value of x by 1 each time. so if the next name is clicked the previous name will go back to the default stylesheet in the codes below...
            if(x>0)
            {

                pButton[x-1]->setObjectName("btnName_1");
                pButton[x-1]->setStyleSheet("   QPushButton#btnName_1 {"
                                            "     background:transparent; Text-align:left;font-family:century gothic;font-size:18px; color:orange;"
                                            " }"
                                            " QPushButton#btnName_1:hover {"
                                            "     color: yellow;font-size:25px;"
                                            " }");
            }


        //style sheet for the clicked button...
            pButton[x]->setStyleSheet("color: yellow;font-size:25px;Text-align:left;font-family:century gothic");*/

        //assigning the text of the button to the string "buttonText"..
            bname += pButton[x]->text();//hotel name with space
            btxt= pButton[x]->text();//hotel name
            qDebug()<<btxt;
            ui->stackedWidget->setCurrentIndex(4);
            ui->hotelnamelevel_p4->setText(bname);
            QSqlQuery query;
            qDebug()<<query.exec("SELECT * FROM Hotel WHERE Hotel_Name = '"+btxt+"'");

            if(query.next())
            {
               badress+=(query.value(1).toString());
               bemail+=(query.value(3).toString());
               bmobile+=(query.value(2).toString());
               b_pic=(query.value(4).toString());

               ui->hotelemaillevel_p4->setText(bemail);
               ui->hoteladresslevel_p4->setText(badress);
               ui->hotelmobilelevel_p4->setText(bmobile);



               QPixmap pix(b_pic);
               int w=ui->hotelpic_p4->width();
               int h=ui->hotelpic_p4->height();
               ui->hotelpic_p4->setPixmap(pix.scaled(w,h));


               QSqlQuery query;

               query.next();

               qDebug()<<query.exec("SELECT * FROM price WHERE hotel_name = '"+btxt+"'" );

               if(query.next())
               {


                   if(roomtext=="Single"){
                   price1=(query.value(1).toString());
                   price2=(query.value(2).toString());
                   price3=(query.value(3).toString());

                   ui->price1_p4->setText(price1);
                   ui->price2_p4->setText(price2);
                   ui->price3_p4->setText(price3);

                   }
                   else
                   {
                      price1=(query.value(4).toString());
                        qDebug()<<price1;
                      price2=(query.value(5).toString());
                        qDebug()<<price2;
                      price3=(query.value(6).toString());
                       qDebug()<<price3;


                       ui->price1_p4->setText(price1);
                       ui->price2_p4->setText(price2);
                       ui->price3_p4->setText(price3);
                   }


               }



            }




}



//page 4

void MainWindow::on_singelbook_p4_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
    c_room="Standard";


}
void MainWindow::on_doublebook_p4_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
    c_room="Superior";
}

void MainWindow::on_doublebook_p4_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
    c_room="Deluxe";
}

//page 5
void MainWindow::on_confirm_button_p5_clicked()
{
    c_name=ui->name_input_p5->text();
    c_email=ui->email_input_p5->text();
    c_mobile=ui->mobile_input_p5->text();
    c_cardname=ui->cardholder_name_p5->text();
    c_cardtype=ui->card_type_p5->text();
    c_cardnumber=ui->card_number_p5->text();

    QSqlQuery query;

    query.exec("INSERT INTO costomer(c_name,c_email,c_mobile,c_cardname,c_cardtype,c_cardnumber,c_room,c_hotelname)VALUES('"+c_name+"','"+c_email+"','"+c_mobile+"','"+c_cardname+"','"+c_cardtype+"','"+c_cardnumber+"','"+c_room+"','"+btxt+"')");
    QMessageBox::information(this,"Confirmation","Cheak Your Email For Confirmation");

    ui->name_input_p5->clear();
    ui->email_input_p5->clear();
    ui->mobile_input_p5->clear();
    ui->cardholder_name_p5->clear();
    ui->card_type_p5->clear();
    ui->card_number_p5->clear();



    ui->stackedWidget->setCurrentIndex(6);

}


//page 6
void MainWindow::on_profile2_logout_clicked()
{
     ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_4_clicked()
{
    this->close();
}

void MainWindow::on_profiel2_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_back_button_p4_clicked()
{
    if(divisiontext=="CTG")
     ui->stackedWidget->setCurrentIndex(2);
    else
       ui->stackedWidget->setCurrentIndex(3);
}



void MainWindow::on_back_Button_p3_clicked()
{
   ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_back_Button_p3_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_2_clicked()
{
     ui->stackedWidget->setCurrentIndex(7);
}


//page 7
void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);

}


