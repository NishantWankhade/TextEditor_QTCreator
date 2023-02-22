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
    mFilename = "";
    ui->textEdit->setPlainText("");

}




void MainWindow::on_actionOpen_triggered()
{

}


void MainWindow::on_actionSave_triggered()
{

}


void MainWindow::on_actionSave_As_triggered()
{

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

        QTextCharFormat format;
        format.setFontWeight(QFont::Bold);
        ui->textEdit->textCursor().mergeCharFormat(format);
    }
    // If it is equal
    else{
        // If it is equal then set text to normal {UnBold feature}
        QTextCharFormat format;
        format.setFontWeight(QFont::Normal);
        ui->textEdit->textCursor().mergeCharFormat(format);
    }
}


void MainWindow::on_actionBold_changed()
{

}

