#include "calendardialog.h"
#include <QStandardPaths>
#include <QFileInfo>
#include <QDir>

CalendarDialog::CalendarDialog(QWidget *parent)
    : QDialog(parent) {
    calendar = new QCalendarWidget(this);
    noteEditor = new QTextEdit(this);
    saveButton = new QPushButton("Enregistrer la note", this);
    addReminderButton = new QPushButton("Ajouter un rappel", this);
    reminderTimeEdit = new QDateTimeEdit(this);

    reminderTimeEdit->setDate(calendar->selectedDate());
    reminderTimeEdit->setTime(QTime::currentTime());

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(calendar);
    mainLayout->addWidget(noteEditor);
    mainLayout->addWidget(saveButton);
    mainLayout->addWidget(reminderTimeEdit);
    mainLayout->addWidget(addReminderButton);

    setLayout(mainLayout);
    setWindowTitle("Calendrier avec notes et rappels");

    connect(calendar, &QCalendarWidget::clicked, this, &CalendarDialog::onDateChanged);
    connect(saveButton, &QPushButton::clicked, this, &CalendarDialog::saveNote);
    connect(addReminderButton, &QPushButton::clicked, this, &CalendarDialog::addReminder);

    reminderTimer = new QTimer(this);
    connect(reminderTimer, &QTimer::timeout, this, &CalendarDialog::checkReminders);
    reminderTimer->start(60000);

    loadData();

    onDateChanged(calendar->selectedDate());
}

CalendarDialog::~CalendarDialog() {
    saveData();
}

void CalendarDialog::onDateChanged(const QDate &date) {
    if (notes.contains(date)) {
        noteEditor->setText(notes[date]);
    } else {
        noteEditor->clear();
    }

    reminderTimeEdit->setDate(date);
}

void CalendarDialog::saveNote() {
    QDate selectedDate = calendar->selectedDate();
    QString note = noteEditor->toPlainText();

    if (!note.isEmpty()) {
        notes[selectedDate] = note;
        QMessageBox::information(this, "Note Enregistrée", "Votre note a été enregistrée.");
    } else {
        notes.remove(selectedDate);
        QMessageBox::information(this, "Note Effacée", "La note pour cette date a été effacée.");
    }
}

void CalendarDialog::addReminder() {
    QDateTime reminderTime = reminderTimeEdit->dateTime();
    QString note = noteEditor->toPlainText();

    if (!note.isEmpty()) {
        reminders[reminderTime] = note;
        QMessageBox::information(this, "Rappel Ajouté", "Votre rappel a été défini.");
    } else {
        QMessageBox::warning(this, "Pas de Note", "Veuillez ajouter une note avant de définir un rappel.");
    }
}

void CalendarDialog::checkReminders() {
    QDateTime currentDateTime = QDateTime::currentDateTime();

    for (auto it = reminders.begin(); it != reminders.end();) {
        if (it.key() <= currentDateTime) {
            QMessageBox::information(this, "Rappel", QString("Rappel pour %1:\n%2")
                                         .arg(it.key().toString())
                                         .arg(it.value()));
            it = reminders.erase(it);
        } else {
            ++it;
        }
    }
}

void CalendarDialog::saveData() {
    QJsonObject json;

    QJsonObject notesJson;
    for (auto it = notes.begin(); it != notes.end(); ++it) {
        notesJson[it.key().toString()] = it.value();
    }
    json["notes"] = notesJson;

    QJsonArray remindersJson;
    for (auto it = reminders.begin(); it != reminders.end(); ++it) {
        QJsonObject reminder;
        reminder["datetime"] = it.key().toString(Qt::ISODate);
        reminder["note"] = it.value();
        remindersJson.append(reminder);
    }
    json["reminders"] = remindersJson;

    QString projectDir = QDir::currentPath();
    QString filePath = projectDir + "/calendar_data.json";

    QDir dir = QFileInfo(filePath).absoluteDir();
    if (!dir.exists()) {
        if (!dir.mkpath(".")) {
            qDebug() << "Échec de la création du répertoire:" << dir.absolutePath();
            return;
        }
    }

    QFile file(filePath);
    if (file.open(QIODevice::WriteOnly)) {
        file.write(QJsonDocument(json).toJson());
        file.close();
        qDebug() << "Données enregistrées dans:" << filePath;
    } else {
        qDebug() << "Échec de l'enregistrement des données:" << file.errorString();
    }
}

void CalendarDialog::loadData() {

    QString projectDir = QDir::currentPath();
    QString filePath = projectDir + "/calendar_data.json";

    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "Aucune donnée enregistrée. Erreur du fichier:" << file.errorString();
        return;
    }

    QByteArray data = file.readAll();
    file.close();

    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject json = doc.object();

    QJsonObject notesJson = json["notes"].toObject();
    for (auto it = notesJson.begin(); it != notesJson.end(); ++it) {
        QDate date = QDate::fromString(it.key(), Qt::ISODate);
        if (date.isValid()) {
            notes[date] = it.value().toString();
        }
    }

    QJsonArray remindersJson = json["reminders"].toArray();
    for (const QJsonValue &value : remindersJson) {
        QJsonObject reminder = value.toObject();
        QDateTime dateTime = QDateTime::fromString(reminder["datetime"].toString(), Qt::ISODate);
        if (dateTime.isValid()) {
            reminders[dateTime] = reminder["note"].toString();
        }
    }

    qDebug() << "Données chargées depuis:" << filePath;
}
