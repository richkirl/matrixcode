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
  const static int W = 80;
  const static int H = 30;
  struct grid {
    //grid(char ach = ' ', int alive = 0) : x(0), y(0), ch(ach), live(alive) {}
    int x;
    int y;
    QString ch;
    //int live;
  };

    grid pp[800][600];
 // std::list<QString> p;
  grid scren[W][H];
  int i = 0;
  int second = 0;
  int timerID;
  int stringelement;
  QString s;
  std::map<int, QString> keytointmap;
  matrixcode();
  ~matrixcode();
  void setX(int);
  int X(int);
  void setY(int);
  int Y(int);
  int x1 = 0;
  int y1 = 0;
  QTime a;
  //QTimer *tmr;
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
