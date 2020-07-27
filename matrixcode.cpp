#include "matrixcode.hpp"
#include <GL/gl.h>
#include <QDebug>
#include <QFont>
#include <QString>
#include <QTimer>
#include <QTimerEvent>
#include <iostream>
#include <list>
#include <map>
#include <random>
#include <sstream>
#include <vector>
matrixcode::matrixcode() { matrixcode::inithisprogram(); }
matrixcode::~matrixcode() {}
void matrixcode::initializeGL() {
  glViewport(0, 0, 800, 600);
  glLoadIdentity();
  glOrtho(0, 800, 0, 600, 0, 1);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  glDisable(GL_DEPTH);
  glEnable(GL_MULTISAMPLE);
  glEnable(GL_BLEND);
  glEnable(GL_LINE_SMOOTH);
  glEnable(GL_POINT_SMOOTH);
  glEnable(GL_SMOOTH);
  glEnable(GL_COLOR_MATERIAL);
}
void matrixcode::resizeGL(int aw, int ah) {
  glViewport(0, 0, (GLint)aw, (GLint)ah);
  glLoadIdentity();
  glOrtho(0, aw, ah, 0, 0, 1);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}
void matrixcode::paintGL() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  qglClearColor(Qt::black);
  _processing();
  _draw();
  _rain();
}
void matrixcode::resizeEvent(QResizeEvent *e) {}
void matrixcode::_processing() {this->y1++;}
void matrixcode::_draw() {
  auto aw = this->width();
  auto ah = this->height();
  int u = ah / 20;
  int h = aw / 20;
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  for (int g = 0; g < h; ++g) {
    for (int i = 1; i < u; ++i) {
      matrixcode::pp[i].x = 20 * g;
      matrixcode::pp[i].y = 20 * i;
      matrixcode::pp[i].ch = (QString)(rand() % 25 + 97);
    }
    static auto font = QFont("Terminus", 18);
    font.setStyleName("Terminus");
    for (int i = 1; i < u; ++i) {
      //glClear(GL_COLOR_BUFFER_BIT );
      glRasterPos2i(h * 20, u * 20);
      glColor3f(0, 0.5, 0);
      //glColor4i(1, 1, 1,1);
      renderText(matrixcode::pp[i].x, matrixcode::pp[i].y, matrixcode::pp[i].ch,
                 font);
    }
  }
  int k = rand() % aw / 20;

  for (int i = 0; i < u; ++i) {
  }
}
void matrixcode::_rain() {
  // auto aw = this->width() / 20;
  // auto ah = this->height() / 20;
  // int k = rand() % aw / 20;
  // int i=0;
  // while (i<k) {
  //   i++;
  //   if (i==k) {
  //     for(int g=0;g<ah;++g){
  //     glColor3f(1, 1, 1);
  //     glRasterPos2i(i * 20, ah * 20);
  //     QString s=(QString)(rand()%25+97);
  //     static auto font = QFont("Terminus", 18);
  //           renderText(this->x1, this->y1,s,
  //                font);
     
  //     }
  //   }
  // }

}
void matrixcode::generate(int l) {}
void matrixcode::keyReleaseEvent(QKeyEvent *e) {
  if (e->key() == Qt::Key_Escape)
    close();
}
void matrixcode::inithisprogram() {
  this->i = 1;
  this->a.setHMS(0, 0, 0);
  this->x1=20;
  this->y1=20;
  QTimer *tmr = new QTimer;
  connect(tmr, SIGNAL(timeout()), this, SLOT(updateGL()));
  tmr->start(32);
  timerID = startTimer(32);
}
void matrixcode::updatetime() { this->a = this->a.addSecs(1); }
void matrixcode::timerEvent(QTimerEvent *e) {
  this->second++;
  updatetime();
  if (this->second % 15 == 0) {
   // this->stringelement = rand() % 25 + 97;
    //matrixcode::_rain();
  }
}
