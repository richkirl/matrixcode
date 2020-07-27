#ifndef __MATRIXCODE_H_
#define __MATRIXCODE_H_
// Copyright 2020 <kaje>
#include <QGLWidget>
#include <QKeyEvent>
#include <QResizeEvent>
#include <QString>
#include <QTime>
#include <QTimerEvent>

class matrixcode : public QGLWidget {
  Q_OBJECT
public:
  struct grid {
    int x;
    int y;
    QString ch;
    // int live;
  };
  grid pp[600];
  int i = 0;
  int second = 0;
  int timerID;
  int stringelement;
  matrixcode();
  ~matrixcode();
  QTime a;
  // QTimer *tmr;
  void generate(int);

private slots:
  void updatetime();

private:
  void initializeGL() override;
  void resizeGL(int, int) override;
  void paintGL() override;
  void keyReleaseEvent(QKeyEvent *) override;
  virtual void resizeEvent(QResizeEvent *) override;
  virtual void timerEvent(QTimerEvent *) override;

  void inithisprogram();

private:
  void _processing();
  void _draw();

private:
};
#endif // __MATRIXCODE_H_
