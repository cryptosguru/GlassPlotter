#include "qcputil.h"

QCPUtil::QCPUtil()
{

}

QColor QCPUtil::getColorFromIndex(int index, int maxIndex)
{
    QCPColorGradient colorgrad;
    colorgrad.loadPreset(QCPColorGradient::gpHues);
    QColor color = colorgrad.color(index, QCPRange(0, maxIndex));

    return color;
}

QVector<double> QCPUtil::scaleVector(QVector<double> v, double scale)
{
    QVector<double> vv;
    vv = v;

    for(int i = 0; i < v.size(); i++){
        vv[i] = v[i]*scale;
    }
    return vv;
}

QVector<double> QCPUtil::getVectorFromRange(QCPRange range, double step)
{
    QVector<double> xdata;
    double xmin = range.lower;
    double xmax = range.upper;
    double x = xmin;
    while(x < xmax)
    {
        xdata.append(x);
        x += step;
    }
    return xdata;
}

void QCPUtil::setColorToGraph(QCPGraph *graph, QColor color)
{
    QPen pen = graph->pen();
    pen.setWidth(2);
    pen.setColor(color);
    graph->setPen(pen);
}
