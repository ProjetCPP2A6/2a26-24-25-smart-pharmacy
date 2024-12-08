#include "arduino.h"

arduino::arduino()
{
    test="";
    arduino_port_name="";
    arduino_is_available=false;
    serial=new QSerialPort;
}

QString arduino::getarduino_port_name()
{
    return arduino_port_name;
}

QSerialPort *arduino::getserial()
{
    return serial;
}
int arduino::connect_arduino() {
    foreach (const QSerialPortInfo &serial_port_info, QSerialPortInfo::availablePorts()) {
        qDebug() << "Checking port:" << serial_port_info.portName();
        if (serial_port_info.hasVendorIdentifier() && serial_port_info.hasProductIdentifier()) {
            if (serial_port_info.vendorIdentifier() == arduino_uno_vendor_id &&
                serial_port_info.productIdentifier() == arduino_uno_producy_id) {
                arduino_is_available = true;
                arduino_port_name = serial_port_info.portName();
                break;
            }
        }
    }

    if (!arduino_is_available) {
        qDebug() << "Arduino not found!";
        return -1;
    }

    serial->setPortName(arduino_port_name);
    if (!serial->open(QSerialPort::ReadWrite)) {
        qDebug() << "Failed to open port:" << serial->errorString();
        return -1;
    }

    serial->setBaudRate(QSerialPort::Baud9600);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);

    qDebug() << "Connected to Arduino on port:" << arduino_port_name;
    return 0;
}

int arduino::close_arduino()

{

    if(serial->isOpen()){
        serial->close();
        return 0;
    }
    return 1;


}


QByteArray arduino::read_from_arduino()
{
    if (serial->isReadable()) {
        QByteArray data = serial->readAll(); // Read all available data
        if (!data.isEmpty()) {
            qDebug() << "Received data:" << data;
        } else {
            qDebug() << "Read buffer is empty!";
        }
        return data;
    } else {
        qDebug() << "Serial port not readable!";
        return QByteArray();
    }
}



int arduino::write_to_arduino( QByteArray d)

{

    if(serial->isWritable()){
        serial->write(d);  // envoyer des donnés vers Arduino
    }else{
        qDebug() << "Couldn't write to serial!";
    }


}
