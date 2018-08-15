
//SamplerConnector: Copyright (c) 2016 A. Klumpp


// *  This program is free software; you can redistribute it and/or modify
// *  it under the terms of the GNU General Public License as published by
// *  the Free Software Foundation; either version 2 of the License, or
// *  (at your option) any later version.
// *
// *  This program is distributed in the hope that it will be useful,
// *  but WITHOUT ANY WARRANTY; without even the implied warranty of
// *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// *  GNU General Public License for more details.
// *
// *  You should have received a copy of the GNU General Public License
// *  along with this program; if not, write to the Free Software
// *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA



// Add SamplerConnector to the autostart programs (e.g. from usr/local/bin) in order to get a "screen free" LinuxSampler (e.g. raspberry pi) box.
// Please restart SamplerConnector after saving changes (e.g. changing the path of the qmidiarp file).



//install libasound2 and libasound2-dev

#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include "arecordmidi.c"
#include <QDebug>
#include <QProcess>
#include <QMessageBox>
#include <unistd.h>

#include <QDateTime>



#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <signal.h>
#include <getopt.h>
#include <sys/poll.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <signal.h>
#include <getopt.h>
#include <sys/poll.h>
#include <alsa/include/asoundlib.h>
//#include <alsa/include/aconfig.h>
#include <alsa/include/config.h.in>
#include <alsa/include/version.h>

//


#include <linux/soundcard.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int mrid;
int mrport;


QProcess process1;
QProcess process2;
QProcess process3;
//QProcess process4;
QProcess process5;
//QProcess process6;
QProcess process7;
QProcess process8;


static int queue;


QList<QString> nameAr;
QList<QString> clientAr;
QList<QString> portAr;
QList<QString> fullAr;

QList<QString> nameArIn;
QList<QString> clientArIn;
QList<QString> portArIn;
QList<QString> fullArIn;


QString lsampler;
QString jackdcom;



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //



    QFile hfile(".spjackdfile.txt");
    if (!hfile.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    QTextStream in(&hfile);
    while (!in.atEnd()) {
        QString hostr = in.readLine();
        //qDebug() << hostr;
        if(~(hostr.isEmpty())){
        ui->lineEditjackd->setText(hostr);}
                }


    QString jackdcom = ui->lineEditjackd->text();
    qDebug() << jackdcom;

    if(jackdcom.trimmed().isEmpty())
        {

    ui->statusBar->showMessage("Command missing");

    //while (n<1)                {
    QMessageBox msgBox;
    msgBox.setText("Please enter jackd command.");
    msgBox.exec();
            //n++;                }

           }

    else
        {
        QString ccccommand = "gnome-terminal -x bash -c \" " + jackdcom;

        //qsampler /home/debian9/test1.lscp
qDebug() <<  "jackd command:";
       qDebug() <<  ccccommand;

        process7.start(ccccommand);

         wait1();
          wait1();




    //getjack end
    //

    QFile h1file(".sppathhfile.txt");
    if (!h1file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    QTextStream in(&h1file);
    while (!in.atEnd()) {
        QString hostr1 = in.readLine();
        //qDebug() << hostr;
        if(~(hostr1.isEmpty())){
        ui->lineEditlscp->setText(hostr1);}
                }


    QString pathhost = ui->lineEditlscp->text();
    qDebug() << pathhost;

    if(pathhost.trimmed().isEmpty())
        {

    ui->statusBar->showMessage("Command missing");

    //while (n<1)                {
    QMessageBox msgBox;
    msgBox.setText("Please enter lscp command.");
    msgBox.exec();
            //n++;                }

           }

    else
        {
//lsamplercommand
        QFile h2file(".splscommandfile.txt");
        if (!h2file.open(QIODevice::ReadOnly | QIODevice::Text))
            return;
        QTextStream in(&h2file);
        while (!in.atEnd()) {
            QString hostr2 = in.readLine();
            //qDebug() << hostr;
            if(~(hostr2.isEmpty())){
            ui->lineEditlinuxsampler->setText(hostr2);}
                    }


        lsampler = ui->lineEditlinuxsampler->text();
        qDebug() << lsampler;

        if(lsampler.trimmed().isEmpty())
            {

        ui->statusBar->showMessage("Command missing");

        //while (n<1)                {
        QMessageBox msgBox;
        msgBox.setText("Please enter linuxsampler command.");
        msgBox.exec();
                //n++;                }

               }

        else

        {
            QString ccsommand = "gnome-terminal -x bash -c \" " + lsampler;

            //qsampler /home/debian9/test1.lscp
 qDebug() <<  "linuxsampler command:";
           qDebug() <<  ccsommand;

            process8.start(ccsommand);

           wait1();





        //lsamplercommand end

        wait1();

          qDebug() << "after linuxsampler";

          QString ccommand = "gnome-terminal -x bash -c \" " + pathhost;

          //qsampler /home/debian9/test1.lscp
 qDebug() <<  "cat command:";
         qDebug() <<  ccommand;

          process5.start(ccommand);




wait();

    }

}
}

}




void MainWindow::wait()
{

 //usleep(5000000);

    for(int i = 0; i <= 4; i++)
       {
           qDebug() << i;


           sleep(1);
       }

     qDebug() << "after sleep";



    // QString cccommand = "gnome-terminal -x bash -c \"a2jmidid -e";


           //   process6.start(cccommand);

     wait1();
output();
}

void MainWindow::wait1()
{


    for(int i = 0; i <= 1; i++)
       {
           qDebug() << i;


           sleep(1);
       }

     qDebug() << "after 1 sleep";


}


void MainWindow::output()
{



        //





#define perm_ok(pinfo,bits) ((snd_seq_port_info_get_capability(pinfo) & (bits)) == (bits))
snd_seq_t *seq;
snd_seq_open(&seq, "default", SND_SEQ_OPEN_DUPLEX, 0);
//

    mrid = snd_seq_client_id(seq);
    //qDebug() <<  mrid;

    mrport = snd_seq_set_client_name(seq, "spAlsaConnector");
    //qDebug() <<  mrport;

    //
    snd_seq_client_info_t *cinfo;
    snd_seq_port_info_t *pinfo;
    //



        snd_seq_port_info_alloca(&pinfo);


        snd_seq_port_info_set_capability(pinfo,
                         SND_SEQ_PORT_CAP_WRITE |
                         SND_SEQ_PORT_CAP_SUBS_WRITE);
        snd_seq_port_info_set_type(pinfo,
                       SND_SEQ_PORT_TYPE_MIDI_GENERIC |
                       SND_SEQ_PORT_TYPE_APPLICATION);
        snd_seq_port_info_set_midi_channels(pinfo, 16);


        snd_seq_port_info_set_timestamping(pinfo, 1);
        snd_seq_port_info_set_timestamp_queue(pinfo, queue);




//



    snd_seq_client_info_alloca(&cinfo);
    snd_seq_port_info_alloca(&pinfo);
    snd_seq_client_info_set_client(cinfo, -1);
    while (snd_seq_query_next_client(seq, cinfo) >= 0)

    {
            snd_seq_port_info_set_client(pinfo, snd_seq_client_info_get_client(cinfo));
            snd_seq_port_info_set_port(pinfo, -1);

            int seldd = 0;
             int iseldd = 0;

            while (snd_seq_query_next_port(seq, pinfo) >= 0)


                //output


                if (    perm_ok
                                       (pinfo, SND_SEQ_PORT_CAP_READ|SND_SEQ_PORT_CAP_SUBS_READ))
                                       //(pinfo, SND_SEQ_PORT_CAP_WRITE|SND_SEQ_PORT_CAP_SUBS_WRITE))
                                           {
                                               QString pname = snd_seq_port_info_get_name(pinfo);
                                              //qDebug() << pname;
                                               nameAr.append(pname);
                                               int icnum = snd_seq_client_info_get_client(cinfo);
                                               QString scnum = QString::number(icnum);
                                              // qDebug() << scnum;
                                               clientAr.append(scnum);
                                               //
                                               const char* fullname = snd_seq_client_info_get_name(cinfo);
                                              // qDebug() << "fullname";
                                                   // qDebug() << fullname;
                                                    fullAr.append(fullname + pname);
                                               //
                                               int ipnum = snd_seq_port_info_get_port(pinfo);
                                               QString spnum = QString::number(ipnum);
                                             // qDebug() << spnum;
                                               portAr.append(spnum);
                                              seldd++;
                                           }






     }


    //ui->comboBoxKeyOut->addItems(fullAr);
    loadselectioncomboBoxKeyOut();



    // ui->comboBoxArpOut->addItems(fullAr);
    //  ui->comboBoxClockOut->addItems(fullAr);
   // old:ui->comboBox2->addItems(nameArIn);

    input();
}





void MainWindow::input()

{

qDebug() << "input function";

#define perm_ok(pinfo,bits) ((snd_seq_port_info_get_capability(pinfo) & (bits)) == (bits))
snd_seq_t *seq;
snd_seq_open(&seq, "default", SND_SEQ_OPEN_DUPLEX, 0);
//

    mrid = snd_seq_client_id(seq);
    //qDebug() <<  mrid;

    mrport = snd_seq_set_client_name(seq, "spAlsaConnector");
    //qDebug() <<  mrport;

    //
    snd_seq_client_info_t *cinfo;
    snd_seq_port_info_t *pinfo;
    //



        snd_seq_port_info_alloca(&pinfo);


        snd_seq_port_info_set_capability(pinfo,
                         SND_SEQ_PORT_CAP_WRITE |
                         SND_SEQ_PORT_CAP_SUBS_WRITE);
        snd_seq_port_info_set_type(pinfo,
                       SND_SEQ_PORT_TYPE_MIDI_GENERIC |
                       SND_SEQ_PORT_TYPE_APPLICATION);
        snd_seq_port_info_set_midi_channels(pinfo, 16);


        snd_seq_port_info_set_timestamping(pinfo, 1);
        snd_seq_port_info_set_timestamp_queue(pinfo, queue);


//


//


snd_seq_client_info_alloca(&cinfo);
snd_seq_port_info_alloca(&pinfo);
snd_seq_client_info_set_client(cinfo, -1);
while (snd_seq_query_next_client(seq, cinfo) >= 0)

{
        snd_seq_port_info_set_client(pinfo, snd_seq_client_info_get_client(cinfo));
        snd_seq_port_info_set_port(pinfo, -1);

        int seldd = 0;
         int iseldd = 0;

        while (snd_seq_query_next_port(seq, pinfo) >= 0)



            //input (write)
            if (    perm_ok
                    //(pinfo, SND_SEQ_PORT_CAP_READ|SND_SEQ_PORT_CAP_SUBS_READ))
                    (pinfo, SND_SEQ_PORT_CAP_WRITE|SND_SEQ_PORT_CAP_SUBS_WRITE))
                        {
                            QString ipname = snd_seq_port_info_get_name(pinfo);
                            qDebug() << "ipname";
                           qDebug() << ipname;
                            nameArIn.append(ipname);
                            int iicnum = snd_seq_client_info_get_client(cinfo);
                            QString iscnum = QString::number(iicnum);
                            qDebug() << iscnum;
                            clientArIn.append(iscnum);
                            //
                            const char* ifullname = snd_seq_client_info_get_name(cinfo);
                            //qDebug() << "ifullname";
                                 qDebug() << ifullname;
                                 fullArIn.append(ifullname + ipname);
                            //
                            int iipnum = snd_seq_port_info_get_port(pinfo);
                            QString ispnum = QString::number(iipnum);
                          // qDebug() << ispnum;
                            portArIn.append(ispnum);

                            qDebug() << "iseldd";
                            qDebug() << iseldd;


                            //WIP


                            QString KeyboardName = "nanoKEY2";

                            if (ipname.contains(KeyboardName))
                               // if (String.contains(searchString, Qt::CaseSensitive))
                            {
                            qDebug() << "this ipname is " + ipname + " and iscnum is " + iscnum;


                              //s = ui->lineEdit->text();



                             }


                            //iseldd++;

                        }

            //input end





 }

loadselectioncomboBoxArpIn();

//
loadLS0();
loadLS1();
loadSP1();
loadSP2();


autoconnect();

//ui->comboBoxClients->addItems(nameAr);
 //ui->comboBoxArpIn->addItems(fullArIn);
 //ui->comboSynthIn->addItems(fullArIn);
 //ui->comboBoxClockIn->addItems(fullArIn);


}


//keep selection of combobox
//
void MainWindow::loadselectioncomboBoxKeyOut()

{
           ui->comboBoxKeyOut->clear();
          //colAr.append("-");
          ui->comboBoxKeyOut->addItems(fullAr);
           ui->comboBoxKeyOut->setCurrentIndex(0);

          QFile hfile(".spcomboBoxKeyOut");
          if (!hfile.open(QIODevice::ReadOnly | QIODevice::Text))
              return;
          QTextStream in(&hfile);
          while (!in.atEnd())

           {              QString keepselectID = in.readLine();
              //qDebug() << keepselectID;


              if(keepselectID=="")
                {
              ui->comboBoxKeyOut->setCurrentIndex(0);
                 }
              else
                 {
                  int indexID = ui->comboBoxKeyOut->findText(keepselectID);
                  ui->comboBoxKeyOut->setCurrentIndex(indexID);
                }

           }

}

//

 void MainWindow::loadLS0()

 {


     QFile hfile(".ls0file.txt");
     if (!hfile.open(QIODevice::ReadOnly | QIODevice::Text))
         return;
     QTextStream in(&hfile);
     while (!in.atEnd()) {
         QString hostr = in.readLine();
         //qDebug() << hostr;
         if(~(hostr.isEmpty())){
         ui->lineEditLS0->setText(hostr);}
                 }

                QString ls0 = ui->lineEditLS0->text();
               qDebug() << ls0;


               if(ls0.trimmed().isEmpty())
                 {
               ui->lineEditLS0->setText("LinuxSampler:0");
               ls0="LinuxSampler:0";
                  }


            }








 //



//

void MainWindow::loadLS1()
{


    QFile hfile(".ls1file.txt");
    if (!hfile.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    QTextStream in(&hfile);
    while (!in.atEnd()) {
        QString hostr = in.readLine();
        //qDebug() << hostr;
        if(~(hostr.isEmpty())){
        ui->lineEditLS1->setText(hostr);}
                }

               QString ls1 = ui->lineEditLS0->text();
              qDebug() << ls1;


              if(ls1.trimmed().isEmpty())
                {
              ui->lineEditLS1->setText("LinuxSampler:1");
              ls1="LinuxSampler:1";
                 }



}


//

void MainWindow::loadselectioncomboBoxArpIn()
{
           ui->comboBoxArpIn->clear();
          //colAr.append("-");
          ui->comboBoxArpIn->addItems(fullArIn);
           ui->comboBoxArpIn->setCurrentIndex(0);

          QFile hfile(".spcomboBoxArpIn");
          if (!hfile.open(QIODevice::ReadOnly | QIODevice::Text))
              return;
          QTextStream in(&hfile);
          while (!in.atEnd())

           {              QString keepselectID = in.readLine();
              //qDebug() << keepselectID;


              if(keepselectID=="")
                {
              ui->comboBoxArpIn->setCurrentIndex(0);
                 }
              else
                 {
                  int indexID = ui->comboBoxArpIn->findText(keepselectID);
                  ui->comboBoxArpIn->setCurrentIndex(indexID);
                }

           }

}

//

void MainWindow::loadSP1()
{
    QFile hfile(".sp1file.txt");
    if (!hfile.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    QTextStream in(&hfile);
    while (!in.atEnd()) {
        QString hostr = in.readLine();
        //qDebug() << hostr;
        if(~(hostr.isEmpty())){
        ui->lineEditSP1->setText(hostr);}
                }

               QString sp1 = ui->lineEditSP1->text();
              qDebug() << sp1;


              if(sp1.trimmed().isEmpty())
                {
              ui->lineEditSP1->setText("system:playback_1");
              sp1="system:playback_1";
                 }

}

//

void MainWindow::loadSP2()
{
    QFile hfile(".sp2file.txt");
    if (!hfile.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    QTextStream in(&hfile);
    while (!in.atEnd()) {
        QString hostr = in.readLine();
        //qDebug() << hostr;
        if(~(hostr.isEmpty())){
        ui->lineEditSP2->setText(hostr);}
                }

               QString sp2 = ui->lineEditSP2->text();
              qDebug() << sp2;


              if(sp2.trimmed().isEmpty())
                {
              ui->lineEditSP2->setText("system:playback_2");
              sp2="system:playback_2";
                 }


}
//if autoconnect is active

void MainWindow::autoconnect()

{

    QFile hfile(".autoconnect");
    if (!hfile.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    QTextStream in(&hfile);
    while (!in.atEnd())

     {              QString trueorfalse = in.readLine();
        //qDebug() << keepselectID;


        if(trueorfalse=="")
          {
            ui->labelStatus->setText("Autoconnect: OFF");

           }
          if(trueorfalse=="true")
           {
            ui->labelStatus->setText("Autoconnect: ON");
            slotrec();
          }

     }




}






//


void MainWindow::slotrec()

{
//connecting midi





      int getmididev = ui->comboBoxKeyOut->currentIndex();

            //qDebug() << getmididev;


      if (getmididev<0)
      {
          QMessageBox msgBox;
          msgBox.setText("Autoconnect I/O error.");
          msgBox.exec();
                       }


      else
      {

      QString getclient =  clientAr[getmididev];
      int igetclient = getclient.toInt();
      qDebug() << igetclient;

      QString getport =  portAr[getmididev];
      int igetport = getport.toInt();
      qDebug() << igetport;


      //


      int getmididev2 = ui->comboBoxArpIn->currentIndex();
      //qDebug() << getmididev;


      if (getmididev2<0)
      {
          QMessageBox msgBox;
          msgBox.setText("Autoconnect I/O error.");
          msgBox.exec();
                       }

      else

        {

      QString getclient2 =  clientArIn[getmididev2];
      int igetclient2 = getclient2.toInt();
      qDebug() << igetclient2;

      QString getport2 =  portArIn[getmididev2];
      int igetport2 = getport2.toInt();
      qDebug() << igetport2;





     //  QString acommand = "gnome-terminal -x bash -c \"arecordmidi -p " + getclient + ":" + getport + " " + filename;

     // aconnect [-options] sender receiver
      //    sender, receiver = client:port pair

    //  aconnect 28:0 32:0


      QString acommand = "gnome-terminal -x bash -c \"aconnect " + getclient + ":" + getport + " " + getclient2 + ":" + getport2;

     qDebug() <<  acommand;

      process1.start(acommand);


      //

      wait1();

      //






      QString getLS0ut = ui->lineEditLS0->text();
      QString getLS0 = getLS0ut.trimmed();
      //qDebug() << getmididev;

      if (getLS0.isEmpty())
      {
          QMessageBox msgBox;
          msgBox.setText("Autoconnect I/O error.");
          msgBox.exec();
                       }


      else

      {



      QString getSP1ut = ui->lineEditSP1->text();
      QString getSP1 = getSP1ut.trimmed();
      //qDebug() << getmididev;

      if (getSP1.isEmpty())
      {
          QMessageBox msgBox;
          msgBox.setText("Autoconnect I/O error.");
          msgBox.exec();
                       }


      else

      {



      QString acommand2 = "gnome-terminal -x bash -c \"jack_connect '" + getLS0 + "'" + " '" + getSP1 + "'";


     // jack_connect "LinuxSampler:0" "system:playback_1"


     qDebug() <<  acommand2;

      process2.start(acommand2);


      //
 qDebug() <<  "before new sleep";
      wait1();
       qDebug() <<  "after new sleep1";

      //

       QString getLS1ut = ui->lineEditLS1->text();
       QString getLS1 = getLS1ut.trimmed();
       //qDebug() << getmididev;

       if (getLS1.isEmpty())
       {
           QMessageBox msgBox;
           msgBox.setText("Autoconnect I/O error.");
           msgBox.exec();
                        }







          else
          {



           QString getSP2ut = ui->lineEditSP2->text();
           QString getSP2 = getSP2ut.trimmed();
           //qDebug() << getmididev;

           if (getSP2.isEmpty())
           {
               QMessageBox msgBox;
               msgBox.setText("Autoconnect I/O error.");
               msgBox.exec();
                            }
      else

      {



      QString acommand3 = "gnome-terminal -x bash -c \"jack_connect '" + getLS1 + "'" + " '" + getSP2 + "'";

     // jack_connect "LinuxSampler:1" "system:playback_2"


     qDebug() <<  acommand3;

      process3.start(acommand3);







 //qDebug() <<  mrid;




 ui->statusBar->showMessage("Connected");


}


}

}
}
}

}
}

void MainWindow::slotstop()

{
    int getmididev = ui->comboBoxKeyOut->currentIndex();
    //qDebug() << getmididev;

    QString getclient =  clientAr[getmididev];
    int igetclient = getclient.toInt();
    qDebug() << igetclient;

    QString getport =  portAr[getmididev];
    int igetport = getport.toInt();
    qDebug() << igetport;


    //


    int getmididev2 = ui->comboBoxArpIn->currentIndex();
    //qDebug() << getmididev;

    QString getclient2 =  clientArIn[getmididev2];
    int igetclient2 = getclient2.toInt();
    qDebug() << igetclient2;

    QString getport2 =  portArIn[getmididev2];
    int igetport2 = getport2.toInt();
    qDebug() << igetport2;




    //

 QString acommand = "gnome-terminal -x bash -c \"aconnect -d " + getclient + ":" + getport + " " + getclient2 + ":" + getport2;

qDebug() <<  acommand;

 process1.start(acommand);

 //
//
 //

 wait1();

 //







 //

 ui->statusBar->showMessage("");

 ui->labelStatus->setText("Autoconnect: OFF");



 //save ID settings
 QString cbID = "";
 //qDebug() << cbID;
 QFile cbIDfile(".autoconnect");
        if (!cbIDfile.open(QIODevice::WriteOnly | QIODevice::Text))
            return;

        QTextStream outg(&cbIDfile);
        outg << cbID;

           cbIDfile.close();








      //aconnect -i


//process1.terminate(SIGINT);
//process.close();
}





void MainWindow::on_pushButtonPath_pressed()
{

       QString pathhost = ui->lineEditlscp->text();



       if(pathhost.trimmed().isEmpty())
                   {
       QMessageBox msgBox;
       msgBox.setText("Please enter command.");
       msgBox.exec();
                    }


       else
       {

       QFile hfile(".sppathhfile.txt");
            if (!hfile.open(QIODevice::WriteOnly | QIODevice::Text))
                return;

            QTextStream outh(&hfile);
            outh << pathhost;

        }






}










void MainWindow::on_pushButtonKey_pressed()
{
    qDebug() <<  "keysavebutton works";



    //save ID settings
    QString cbID = ui->comboBoxKeyOut->currentText();
    //qDebug() << cbID;
    QFile cbIDfile(".spcomboBoxKeyOut");
           if (!cbIDfile.open(QIODevice::WriteOnly | QIODevice::Text))
               return;

           QTextStream outg(&cbIDfile);
           outg << cbID;

              cbIDfile.close();





}

void MainWindow::on_pushButtonArpIn_pressed()
{
    qDebug() <<  "pushButtonArpInbutton works";



    //save ID settings
    QString cbID = ui->comboBoxArpIn->currentText();
    //qDebug() << cbID;
    QFile cbIDfile(".spcomboBoxArpIn");
           if (!cbIDfile.open(QIODevice::WriteOnly | QIODevice::Text))
               return;

           QTextStream outg(&cbIDfile);
           outg << cbID;

              cbIDfile.close();

}

void MainWindow::on_pushButtonArpOut_pressed()

{
    QString pathhost = ui->lineEditLS0->text();



    if(pathhost.trimmed().isEmpty())
                {
    QMessageBox msgBox;
    msgBox.setText("Please enter jack_lsp data.");
    msgBox.exec();
                 }


    else
    {

    QFile hfile(".ls0file.txt");
         if (!hfile.open(QIODevice::WriteOnly | QIODevice::Text))
             return;

         QTextStream outh(&hfile);
         outh << pathhost;

     }



    //
    qDebug() <<  "pushButtonArpOutbutton works";



   }

void MainWindow::on_pushButtonSynthIn_pressed()
{
    qDebug() <<  "pushButtonSynthInbutton works";


    QString pathhost = ui->lineEditLS1->text();



    if(pathhost.trimmed().isEmpty())
                {
    QMessageBox msgBox;
    msgBox.setText("Please enter jack_lsp data.");
    msgBox.exec();
                 }


    else
    {

    QFile hfile(".ls1file.txt");
         if (!hfile.open(QIODevice::WriteOnly | QIODevice::Text))
             return;

         QTextStream outh(&hfile);
         outh << pathhost;

}
}

void MainWindow::on_pushButtonClockOut_pressed()
{
    qDebug() <<  "pushButtonClockOutbutton works";



    QString pathhost = ui->lineEditSP1->text();



    if(pathhost.trimmed().isEmpty())
                {
    QMessageBox msgBox;
    msgBox.setText("Please enter jack_lsp data.");
    msgBox.exec();
                 }


    else
    {

    QFile hfile(".sp1file.txt");
         if (!hfile.open(QIODevice::WriteOnly | QIODevice::Text))
             return;

         QTextStream outh(&hfile);
         outh << pathhost;

}
}

void MainWindow::on_pushButtonClockIn_pressed()
{
    qDebug() <<  "pushButtonClockInbutton works";

    QString pathhost = ui->lineEditSP2->text();



    if(pathhost.trimmed().isEmpty())
                {
    QMessageBox msgBox;
    msgBox.setText("Please enter jack_lsp data.");
    msgBox.exec();
                 }


    else
    {

    QFile hfile(".sp2file.txt");
         if (!hfile.open(QIODevice::WriteOnly | QIODevice::Text))
             return;

         QTextStream outh(&hfile);
         outh << pathhost;




}
}

void MainWindow::on_pushButtonAuto_pressed()
{
    qDebug() <<  "pushButtonAuto works";

    ui->labelStatus->setText("Autoconnect active");



    //save ID settings
    QString cbID = "true";
    //qDebug() << cbID;
    QFile cbIDfile(".autoconnect");
           if (!cbIDfile.open(QIODevice::WriteOnly | QIODevice::Text))
               return;

           QTextStream outg(&cbIDfile);
           outg << cbID;

              cbIDfile.close();

}



void MainWindow::on_pushButtonsampler_pressed()
{
    QString pathhost = ui->lineEditlinuxsampler->text();



    if(pathhost.trimmed().isEmpty())
                {
    QMessageBox msgBox;
    msgBox.setText("Please enter command.");
    msgBox.exec();
                 }


    else
    {

    QFile hfile(".splscommandfile.txt");
         if (!hfile.open(QIODevice::WriteOnly | QIODevice::Text))
             return;

         QTextStream outh(&hfile);
         outh << pathhost;

     }
}




void MainWindow::on_pushButtonjackd_pressed()
{
    QString pathhost = ui->lineEditjackd->text();



    if(pathhost.trimmed().isEmpty())
                {
    QMessageBox msgBox;
    msgBox.setText("Please enter command.");
    msgBox.exec();
                 }


    else
    {

    QFile hfile(".spjackdfile.txt");
         if (!hfile.open(QIODevice::WriteOnly | QIODevice::Text))
             return;

         QTextStream outh(&hfile);
         outh << pathhost;

     }
}



MainWindow::~MainWindow()
{
    delete ui;
}
