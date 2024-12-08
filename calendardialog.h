#ifndef CALENDARDIALOG_H
#define CALENDARDIALOG_H

#include <QDialog>
#include <QCalendarWidget>
#include <QTextEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDateTimeEdit>
#include <QMap>
#include <QDate>
#include <QTimer>
#include <QMessageBox>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

class CalendarDialog : public QDialog {
    Q_OBJECT

public:
    explicit CalendarDialog(QWidget *parent = nullptr);
    ~CalendarDialog();

private slots:
    void onDateChanged(const QDate &date);
    void saveNote();
    void addReminder();
    void checkReminders();

private:
    QCalendarWidget *calendar;
    QTextEdit *noteEditor;
    QPushButton *saveButton;
    QPushButton *addReminderButton;
    QDateTimeEdit *reminderTimeEdit;

    QMap<QDate, QString> notes;
    QMap<QDateTime, QString> reminders;

    QTimer *reminderTimer;

    void saveData();
    void loadData();
};

#endif // CALENDARDIALOG_H
