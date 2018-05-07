/*
 * This file is part of PoolViewer
 * Copyright (c) 2015 Ivor Hewitt
 *
 * PoolViewer is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * PoolViewer is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with PoolViewer.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef PODLIVE_H
#define PODLIVE_H

// New UsbLive interface
#include "podbase.h"
#include <QScopedPointer>

class PodLive : public PodBase
{
    Q_OBJECT
public:
    PodLive();

    void run();

    virtual void stop();
    virtual void getData(std::vector<ExerciseSet>& data);

signals:
    void info(QString msg);
    void error(QString msg);
    void progress(int progress);

private slots:
    void handleError(QSerialPort::SerialPortError error);

private:
    bool         init();

    QString      find();
    QScopedPointer<QSerialPort> serialPort;
    QString      serialPortName;
    QByteArray   readData;
    bool         download(const QScopedPointer<QSerialPort> & serialPort, const QByteArray &handshake, QByteArray& readData);

};

#endif //PODLIVE_H
