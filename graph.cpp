#include "graph.h"

Graph::Graph(QCustomPlot *plot, QObject *parent) :
    QObject(parent), m_plot(plot), sampleCount(500)
{
    setupPlot(); // calling func
}

/* sets the graph up for plotting*/
void Graph::setupPlot() {
    if (m_plot) {
           qDebug() << "mplot";
        m_plot->addGraph();
        m_plot->graph(0)->setPen(QPen(Qt::blue));
        m_plot->xAxis->setLabel("Time (s)");
        m_plot->yAxis->setLabel("Microvolts (v)");
        m_plot->xAxis->setRange(0, 90); // 0 - 90 seconds
        m_plot->yAxis->setRange(-150, 150);
    }
}

/*for updating graph */
void Graph::updateGraph(double time, double freq) {
    x.append(time); // setting xaxis
    y.append(freq); //setting yaxis
    m_plot->graph(0)->setData(x, y); // Set the data
    m_plot->replot();
}
