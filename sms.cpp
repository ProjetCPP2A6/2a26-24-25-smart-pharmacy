#include <QtNetwork>
#include "sms.h"


QString twilio_phone_number = "+13212653837";


sms::sms(){

}
void sms::sendSMS(const QString &to, const QString &message) {
    QNetworkAccessManager *manager = new QNetworkAccessManager();

    QUrl url("https://api.twilio.com/2010-04-01/Accounts/AC89558ed91916716c25828b95231ed38f/Messages.json");
    QNetworkRequest request(url);

 /// ////////////////////////////////////////////////////////////////////// fi 3oth 1 t7ot SID w 2 t7ot Token
    QString credentials = "AC89558ed91916716c25828b95231ed38f:d2b1154b8c5970866f24f3cbacfb50d8";
    QByteArray base64Credentials = credentials.toUtf8().toBase64();
    request.setRawHeader("Authorization", "Basic " + base64Credentials);


    QByteArray postData;
    postData.append("From="+twilio_phone_number.toUtf8());
    postData.append("&To=" + to.toUtf8());
    postData.append("&Body=" + message.toUtf8());


    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

    // Make the request
    QNetworkReply *reply = manager->post(request, postData);


    QObject::connect(reply, &QNetworkReply::finished, [=]() {
        if (reply->error() == QNetworkReply::NoError) {
            qDebug() << "SMS sent successfully";
        } else {
            qDebug() << "Failed to send SMS:" << reply->errorString();
        }


        reply->deleteLater();
        manager->deleteLater();
    });
}
