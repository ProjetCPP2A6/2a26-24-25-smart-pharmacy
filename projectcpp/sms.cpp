#include <QtNetwork>
#include "sms.h"
<<<<<<< HEAD
<<<<<<< HEAD
#include <QProcessEnvironment>  // Include this to work with environment variables

QString twilio_phone_number = "+13212653837";

sms::sms() {
}

=======

=======
#include <QProcessEnvironment>  // Include this to work with environment variables
>>>>>>> 5d60f4b (Added code to fournisseur.h)

QString twilio_phone_number = "+13212653837";

sms::sms() {
}
<<<<<<< HEAD
/*/>>>>>>> ed90b17 (Created sms.cpp and sms.h)
=======

>>>>>>> 5d60f4b (Added code to fournisseur.h)
void sms::sendSMS(const QString &to, const QString &message) {
    QNetworkAccessManager *manager = new QNetworkAccessManager();

    QUrl url("https://api.twilio.com/2010-04-01/Accounts/AC89558ed91916716c25828b95231ed38f/Messages.json");
    QNetworkRequest request(url);

<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 5d60f4b (Added code to fournisseur.h)
    // Retrieve the Auth Token from the environment variable
    QString authToken = QProcessEnvironment::systemEnvironment().value("TWILIO_AUTH_TOKEN");

    // Check if the Auth Token is found in the environment variable
    if (authToken.isEmpty()) {
        qDebug() << "Error: Twilio Auth Token not found in environment variables.";
        return;
    }

    // Construct credentials using the SID and Auth Token
    QString credentials = "AC89558ed91916716c25828b95231ed38f:" + authToken;
<<<<<<< HEAD
    QByteArray base64Credentials = credentials.toUtf8().toBase64();
    request.setRawHeader("Authorization", "Basic " + base64Credentials);

    QByteArray postData;
    postData.append("From=" + twilio_phone_number.toUtf8());
    postData.append("&To=" + to.toUtf8());
    postData.append("&Body=" + message.toUtf8());

=======
 /// ////////////////////////////////////////////////////////////////////// fi 3oth 1 t7ot SID w 2 t7ot Token
    QString credentials = "AC89558ed91916716c25828b95231ed38f:d2b1154b8c5970866f24f3cbacfb50d8";
=======
>>>>>>> 5d60f4b (Added code to fournisseur.h)
    QByteArray base64Credentials = credentials.toUtf8().toBase64();
    request.setRawHeader("Authorization", "Basic " + base64Credentials);

    QByteArray postData;
    postData.append("From=" + twilio_phone_number.toUtf8());
    postData.append("&To=" + to.toUtf8());
    postData.append("&Body=" + message.toUtf8());

<<<<<<< HEAD

>>>>>>> ed90b17 (Created sms.cpp and sms.h)
=======
>>>>>>> 5d60f4b (Added code to fournisseur.h)
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

    // Make the request
    QNetworkReply *reply = manager->post(request, postData);

<<<<<<< HEAD
<<<<<<< HEAD
=======

>>>>>>> ed90b17 (Created sms.cpp and sms.h)
=======
>>>>>>> 5d60f4b (Added code to fournisseur.h)
    QObject::connect(reply, &QNetworkReply::finished, [=]() {
        if (reply->error() == QNetworkReply::NoError) {
            qDebug() << "SMS sent successfully";
        } else {
            qDebug() << "Failed to send SMS:" << reply->errorString();
        }

<<<<<<< HEAD
<<<<<<< HEAD
=======

>>>>>>> ed90b17 (Created sms.cpp and sms.h)
=======
>>>>>>> 5d60f4b (Added code to fournisseur.h)
        reply->deleteLater();
        manager->deleteLater();
    });
}
<<<<<<< HEAD
<<<<<<< HEAD
s
=======
>>>>>>> ed90b17 (Created sms.cpp and sms.h)*/
=======
s
>>>>>>> 5d60f4b (Added code to fournisseur.h)
