#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QAudioInput>
#include <QAudioDecoder>
#include <QAudioFormat>
#include <math.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , audioPlayer(this)

{
    ui->setupUi(this);
    initializeAudio();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::initializeAudio(){
    on_gainSlider_valueChanged(ui->gainSlider->value());
    on_dialAttack_valueChanged(ui->dialAttack->value());
    ui->labelAttack->setNum(ui->dialAttack->value());
    on_dialDecay_valueChanged(ui->dialDecay->value());
    ui->labelDecay->setNum(ui->dialDecay->value());
    on_dialSustain_valueChanged(ui->dialSustain->value());
    ui->labelSustain->setNum(ui->dialSustain->value());
    on_dialRelease_valueChanged(ui->dialRelease->value());
    ui->labelRelease->setNum(ui->dialRelease->value());

    audioPlayer.setAudioSource(&oscillatorSource);
    audioPlayer.start();
}





void MainWindow::on_waveformCombobox_activated(int index)
{
    oscillatorSource.setSelectedOscillator(index);
}

void MainWindow::on_gainSlider_valueChanged(int value)
{
    oscillatorSource.setGain(value);
}


void MainWindow::on_note_1_clicked(bool checked)
{
    qDebug() << "note 1";

    if (checked){
        oscillatorSource.noteOn(60);
    }
    else{
        oscillatorSource.noteOff();
    }
}
void MainWindow::on_note_2_clicked(bool checked)
{
    if (checked){
        oscillatorSource.noteOn(61);
    }
    else{
        oscillatorSource.noteOff();
    }
}
void MainWindow::on_note_3_clicked(bool checked)
{
    if (checked){
        oscillatorSource.noteOn(62);
    }
    else{
        oscillatorSource.noteOff();
    }
}
void MainWindow::on_note_4_clicked(bool checked)
{
    if (checked){
        oscillatorSource.noteOn(63);
    }
    else{
        oscillatorSource.noteOff();
    }
}
void MainWindow::on_note_5_clicked(bool checked)
{
    if (checked){
        oscillatorSource.noteOn(64);
    }
    else{
        oscillatorSource.noteOff();
    }
}
void MainWindow::on_note_6_clicked(bool checked)
{
    if (checked){
        oscillatorSource.noteOn(65);
    }
    else{
        oscillatorSource.noteOff();
    }
}
void MainWindow::on_note_7_clicked(bool checked)
{
    if (checked){
        oscillatorSource.noteOn(66);
    }
    else{
        oscillatorSource.noteOff();
    }
}
void MainWindow::on_note_8_clicked(bool checked)
{
    if (checked){
        oscillatorSource.noteOn(67);
    }
    else{
        oscillatorSource.noteOff();
    }
}
void MainWindow::on_note_9_clicked(bool checked)
{
    if (checked){
        oscillatorSource.noteOn(68);
    }
    else{
        oscillatorSource.noteOff();
    }
}
void MainWindow::on_note_10_clicked(bool checked)
{
    if (checked){
        oscillatorSource.noteOn(69);
    }
    else{
        oscillatorSource.noteOff();
    }
}
void MainWindow::on_note_11_clicked(bool checked)
{
    if (checked){
        oscillatorSource.noteOn(70);
    }
    else{
        oscillatorSource.noteOff();
    }
}
void MainWindow::on_note_12_clicked(bool checked)
{
    if (checked){
        oscillatorSource.noteOn(71);
    }
    else{
        oscillatorSource.noteOff();
    }
}

void MainWindow::on_dialAttack_valueChanged(int value)
{
    oscillatorSource.setAttackSeconds(value/100.f);
}

void MainWindow::on_dialDecay_valueChanged(int value)
{
    oscillatorSource.setDecaySeconds(value/100.f);
}

void MainWindow::on_dialSustain_valueChanged(int value)
{
    oscillatorSource.setSustain_dB(value - 100);
}

void MainWindow::on_dialRelease_valueChanged(int value)
{
    oscillatorSource.setReleaseSeconds(value/100.f);
}
