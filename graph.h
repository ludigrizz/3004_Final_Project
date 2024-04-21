#ifndef GRAPH_H
#define GRAPH_H

#include <QObject>
#include <QVector>
#include "qcustomplot.h"
#include "electrode.h"

class Graph : public QObject
{
    Q_OBJECT
public:
    explicit Graph(QCustomPlot *plot, QObject *parent = nullptr);
    void setupPlot();
    void updateGraph(double frequency, double amplitude);
    void clearGraph();

private:
    QCustomPlot *m_plot;
    QVector<double> x, y;
    int sampleCount;
};

#endif // GRAPH_H
