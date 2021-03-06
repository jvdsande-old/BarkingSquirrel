#ifndef FILEVIEWER_H
#define FILEVIEWER_H

#include <QWidget>
#include <QVector>
#include "qzoomplot.h"


typedef struct {
    QCPItemLine *hLine;
    QCPItemLine *vLine;
} QCPCursor;


namespace Ui {
class FileViewer;
}

class FileViewer : public QWidget
{
    Q_OBJECT

public:
    explicit FileViewer(QWidget *parent = 0);
    ~FileViewer();
    void showEvent(QShowEvent *);
    void ManageCursor(QCustomPlot *customPlot, QCPCursor *cursor, double px, double py, QPen pen);

public slots:
    void mouseRelease(QMouseEvent* event);
    void show_dialog(QString dir);

private:
    Ui::FileViewer *ui;


    QZoomPlot * graph[20];
    QString dir;

    QVector<double> *x[20], *y[20];
};

#endif // FILEVIEWER_H
