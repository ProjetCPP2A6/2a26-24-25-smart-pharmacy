#include "statranim.h"
#include "ui_statranim.h"
#include <QSqlQuery>            // Requêtes SQL
#include <QSqlError>            // Gestion des erreurs SQL
#include <QMap>                 // Conteneur pour stocker les données (nom, quantité)
#include <QMessageBox>          // Affichage des messages d'erreur
#include <QGraphicsScene>       // Scène pour dessiner les graphiques
#include <QGraphicsView>        // Vue pour afficher la scène
#include <QGraphicsRectItem>    // Dessin des rectangles pour les barres
#include <QGraphicsTextItem>    // Ajout de texte à la scène
#include <QBrush>               // Remplissage des rectangles (barres)
#include <QPen>                 // Définition des bordures des éléments graphiques
#include <QColor>               // Couleurs des barres
#include <QFont>                // Gestion des polices pour les textes
#include <QVBoxLayout>          // Mise en page pour afficher la vue graphique
#include <QWidget>              // Gestion des widgets
#include <QDebug>
statranim::statranim(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::statranim)
{
    ui->setupUi(this);
}

statranim::~statranim()
{
    delete ui;
}

void statranim::on_pushButton_stat_clicked()
{
    // Création de la scène graphique
        QGraphicsScene *scene = new QGraphicsScene(this);

        // Préparation des données pour le graphique
        QMap<QString, int> supplierData;
        QSqlQuery query;
        query.prepare("SELECT nom, quantite FROM fournisseur"); // Requête pour récupérer les données
        if (query.exec()) {
            while (query.next()) {
                QString supplierName = query.value(0).toString();
                int quantity = query.value(1).toInt();

                // Ajout au QMap uniquement si la quantité est valide (> 0)
                if (quantity > 0) {
                    supplierData[supplierName] = quantity;
                }
            }
        } else {
            QMessageBox::critical(this, "Erreur", "Impossible de récupérer les données : " + query.lastError().text());
            return;
        }

        // Vérification des données récupérées
        if (supplierData.isEmpty()) {
            QMessageBox::warning(this, "Aucune donnée", "Aucun fournisseur avec des données valides.");
            return;
        }

        // Définition des dimensions et des paramètres du graphique
        int maxBarHeight = 250;  // Hauteur maximale des barres
        int barWidth = 40;       // Largeur de chaque barre
        int spacing = 20;        // Espacement entre les barres
        int xPosition = 80;      // Position initiale pour la première barre
        int maxValue = 0;

        // Trouver la valeur maximale pour ajuster l'échelle des barres
        for (auto value : supplierData) {
            if (value > maxValue) {
                maxValue = value;
            }
        }

        // Vérification pour éviter une division par zéro
        if (maxValue == 0) {
            QMessageBox::warning(this, "Erreur", "Toutes les quantités sont nulles. Vérifiez vos données.");
            return;
        }

        // Définition des polices et des couleurs
        QFont titleFont("Arial", 16, QFont::Bold);
        QFont axisFont("Arial", 10, QFont::Bold);
        QFont labelFont("Arial", 8);
        QColor barColors[] = {Qt::blue, Qt::green, Qt::red, Qt::cyan, Qt::magenta, Qt::yellow};

        // Ajout du titre
        QString title = "Statistiques des Quantités Fournies";
        QGraphicsTextItem *titleItem = new QGraphicsTextItem(title);
        titleItem->setFont(titleFont);
        titleItem->setDefaultTextColor(Qt::black);
        titleItem->setPos(50, -50); // Positionnement du titre au-dessus du graphique
        scene->addItem(titleItem);

        // Ajout des barres et des étiquettes
        int colorIndex = 0;
        for (auto it = supplierData.begin(); it != supplierData.end(); ++it) {
            // Calcul de la hauteur de la barre en fonction de la valeur
            int barHeight = static_cast<int>((it.value() / static_cast<double>(maxValue)) * maxBarHeight);

            // Création de la barre
            QGraphicsRectItem *bar = new QGraphicsRectItem(xPosition, maxBarHeight - barHeight, barWidth, barHeight);
            bar->setBrush(QBrush(barColors[colorIndex % 6]));  // Couleur cyclique pour chaque barre
            bar->setPen(Qt::NoPen);
            scene->addItem(bar);

            // Ajout de l'étiquette de la valeur au-dessus de la barre
            QGraphicsTextItem *valueLabel = new QGraphicsTextItem(QString::number(it.value()));
            valueLabel->setFont(labelFont);
            valueLabel->setDefaultTextColor(Qt::black);
            valueLabel->setPos(xPosition + barWidth / 4, maxBarHeight - barHeight - 20);
            scene->addItem(valueLabel);

            // Ajout du nom du fournisseur sous la barre
            QGraphicsTextItem *nameLabel = new QGraphicsTextItem(it.key());
            nameLabel->setFont(labelFont);
            nameLabel->setTextWidth(barWidth + 20);
            nameLabel->setDefaultTextColor(Qt::black);
            nameLabel->setPos(xPosition - 10, maxBarHeight + 10);
            scene->addItem(nameLabel);

            // Mise à jour de la position pour la prochaine barre
            xPosition += barWidth + spacing;
            colorIndex++;
        }

        // Dessin des axes X et Y
        QPen axisPen(Qt::black, 2);
        scene->addLine(50, maxBarHeight, xPosition, maxBarHeight, axisPen);  // Axe X
        scene->addLine(50, 0, 50, maxBarHeight, axisPen);                   // Axe Y

        // Ajout des étiquettes des axes
        QGraphicsTextItem *xLabel = new QGraphicsTextItem("Fournisseurs");
        xLabel->setFont(axisFont);
        xLabel->setDefaultTextColor(Qt::black);
        xLabel->setPos((xPosition - 80) / 2, maxBarHeight + 40);  // Centrage sur l'axe X
        scene->addItem(xLabel);

        QGraphicsTextItem *yLabel = new QGraphicsTextItem("Quantité");
        yLabel->setFont(axisFont);
        yLabel->setDefaultTextColor(Qt::black);
        yLabel->setRotation(-90);  // Rotation pour alignement vertical
        yLabel->setPos(10, maxBarHeight / 2);  // Centrage sur l'axe Y
        scene->addItem(yLabel);

        // Création de la vue graphique et ajout à la stackedWidget
        QGraphicsView *view = new QGraphicsView(scene);
        view->setRenderHint(QPainter::Antialiasing);

        QWidget *statPage = new QWidget();
        QVBoxLayout *layout = new QVBoxLayout(statPage);
        layout->addWidget(view);

        ui->stackedWidgetStat->addWidget(statPage);
        ui->stackedWidgetStat->setCurrentWidget(statPage);
}

