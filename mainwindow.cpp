#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionNew_triggered()
{
    //Giving a file name to empty string
    mFilename = "";

    //Setting the text to empty string
    ui->textEdit->setPlainText("");
}




void MainWindow::on_actionOpen_triggered()
{
    //Taking input from user via a dialog box and store that file name
    QString file = QFileDialog::getOpenFileName(this,"Open a file");

    // If that file is given as a input
    if(!file.isEmpty()){

        QFile sFile(file);

        if(sFile.open(QFile::ReadOnly | QFile::Text)){

            mFilename = file;
            QTextStream in(&sFile);
            QString text = in.readAll();
            sFile.close();

            ui->textEdit->setPlainText(text);
        }
    }
}


void MainWindow::on_actionSave_triggered()
{
    QFile sFile(mFilename);

    if(sFile.open(QFile::WriteOnly | QFile::Text)){

        QTextStream out(&sFile);

        out << ui->textEdit->toPlainText();

        sFile.flush();
        sFile.close();
    }

}


void MainWindow::on_actionSave_As_triggered()
{
    QString file = QFileDialog::getSaveFileName(this,"Open a file");

    // If that file is given as a input
    if(!file.isEmpty()){

        mFilename = file;
        on_actionSave_triggered();
    }
}


void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}


void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();
}


void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}


void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}


void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}




void MainWindow::on_actionBold_triggered()
{
    // Saving font weight in a local varaible
    int font = ui->textEdit->fontWeight();

    //First check if the font weight is not equal to the weight of BOLD
    if(font != QFont::Bold){
        // Then set the selected text to bold

        ui->textEdit->setFontWeight(QFont::Bold);
    }
    // If it is equal
    else{
        // If it is equal then set text to normal {UnBold feature}
        ui->textEdit->setFontWeight(QFont::Normal);
    }
}



void MainWindow::on_actionSubScript_triggered()
{
    ui->textEdit->setVerticalAlignment(QTextCharFormat::AlignSubScript);
}


void MainWindow::on_actionSuperScript_triggered()
{

}

