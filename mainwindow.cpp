#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QAction>
#include <QApplication>
#include <QClipboard>
#include <QColorDialog>
#include <QComboBox>
#include <QFontComboBox>
#include <QFile>
#include <QFileDialog>
#include <QFileInfo>
#include <QFontDatabase>
#include <QMenu>
#include <QMenuBar>
#include <QTextCodec>
#include <QTextEdit>
#include <QToolBar>
#include <QTextCursor>
#include <QTextDocumentWriter>
#include <QTextList>
#include <QtDebug>
#include <QCloseEvent>
#include <QMessageBox>
#include <QMimeData>
#ifndef QT_NO_PRINTER
#include <QPrintDialog>
#include <QPrinter>
#include <QPrintPreviewDialog>
#endif
#include <QDebug>

#include <QPainter>
#include <QDate>
#include <QTime>
#include <QTextStream>






MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete ui;
}

QString textAt(int h,int i,QString str) {

    QString s;

    switch ( h )
    {
    case  0:
      s="<h1>";
      break;
    case  1:
      s="<h2>";
      break;
    case  2:
      s="<h3>";
      break;
    case  3:
      s="<h4>";
      break;
    case  4:
      s="<h5>";
      break;
    case  5:
      s="<h6>";
      break;
    }



    for (int x=0; x<i ;x++){
        s = s+"&nbsp;";
    }

    s=s+str;


    switch ( h )
    {
    case 0:
      s=s+"</h1>";
      break;
    case 1:
      s=s+"</h2>";
      break;
    case 2:
      s=s+"</h3>";
      break;
    case 3:
      s=s+"</h4>";
      break;
    case 4:
      s=s+"</h5>";
      break;
    case 5:
      s=s+"</h6>";
      break;
    }


qDebug() << s;
    return s;
}

QString nbsp(int i) {

    QString s;
    s="";

    for (int x=0; x<i ;x++){
        s = s+"&nbsp;";
    }

    return s;
}

void MainWindow::on_pushButton_clicked()

{

   //ui->lineEdit->setText("Hello World");
    QString s = "Hello";\
    qDebug().nospace() << "abc" << qPrintable(s) << "def";
    qDebug() << "abc" << s << "def";
    qDebug("abc" + s.toLatin1() + "def");
    QTextDocument doc;
    //doc.setHtml("<h1>hello, I'm an head</h1>");
    doc.setPlainText("Hello World");

    #if !defined(QT_NO_PRINTER) && !defined(QT_NO_PRINTDIALOG)
        QPrinter printer(QPrinter::HighResolution);
        QPrintDialog *dlg = new QPrintDialog(&printer, this);
        dlg->addEnabledOption(QAbstractPrintDialog::PrintSelection);
        dlg->setWindowTitle(tr("Print Document"));
        if (dlg->exec() == QDialog::Accepted)
           // QPainter painter(&printer); // create a painter which will paint 'on printer'.
            //painter.setFont(QFont("Tahoma",8));
           // painter.drawText(200,200,"Test");
           // painter.end();

            QPrinter printer;
            printer.setOutputFileName("c:\\temp\\file.txt");
            printer.setOutputFormat(QPrinter::NativeFormat);
            doc.print(&printer);
            printer.newPage();


        delete dlg;
    #endif


}

void MainWindow::on_pushButton_2_clicked()
{


#if !defined(QT_NO_PRINTER) && !defined(QT_NO_PRINTDIALOG)
    QPrinter printer(QPrinter::HighResolution);
    QPrintDialog *dlg = new QPrintDialog(&printer, this);
    dlg->addEnabledOption(QAbstractPrintDialog::PrintSelection);
    dlg->setWindowTitle(tr("Print Document"));
    if (dlg->exec() == QDialog::Accepted) {
        QPrinter printer;
        ui->textEdit->print(&printer);
        printer.newPage();
    }


    delete dlg;
#endif
}

void MainWindow::on_pushButton_3_clicked()
{


    //ui->textEdit->append(ui->lineEdit->text());
    //ui->textEdit->append("Hello World");
    //ui->textEdit->setHtml("<h1> Hello there "+ui->lineEdit->text());
    //ui->textEdit->append("<h1> nice work! </h1>");
    //ui->textEdit->setHtml("<h3>11111111112222222222333333333344444444445555555555666666666677777777778888888888999999999900000000</h3>");

    ui->textEdit->setHtml(::textAt(h3,65,"ASAP Film Order"));
    ui->textEdit->append(::textAt(h3,40,"From C&C Special Products Co. 952-881-0073"));
    ui->textEdit->append(::textAt(h3,67,"Mark &nbsp;Robin"));
    ui->textEdit->append(::textAt(h3,6,"Attn: Customer Service"+::nbsp(63)+"Rip Settings:"));
    ui->textEdit->append(::textAt(h3,103,"1) Film Positives"));
    ui->textEdit->append(::textAt(h3,103,"2) DO NOT TRAP"));
    ui->textEdit->append(::textAt(h3,103,"3) Send Pre Separated"));
    ui->textEdit->append(::textAt(h3,6,QDate::currentDate().toString()));




}


