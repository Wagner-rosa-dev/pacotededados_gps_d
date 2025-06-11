#ifndef GPS_DATA_H
#define GPS_DATA_H

#include <QString>
#include <QTime>
#include <QDate>

struct GpsData
{
    double latitude = 0.0;
    double longitude = 0.0;
    double altitude = 0.0;
    int satelites = 0;
    QTime fixTime;
    QDate fixDate;
};




#endif // GPS_DATA_H
