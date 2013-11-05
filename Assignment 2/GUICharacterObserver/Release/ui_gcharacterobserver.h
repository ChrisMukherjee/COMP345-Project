/********************************************************************************
** Form generated from reading UI file 'gcharacterobserver.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GCHARACTEROBSERVER_H
#define UI_GCHARACTEROBSERVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GCharacterObserver
{
public:
    QAction *actionSave;
    QAction *actionLoad;
    QWidget *centralWidget;
    QGroupBox *infoBox;
    QLabel *nameLabel;
    QLineEdit *nameField;
    QLabel *levelLabel;
    QLineEdit *levelField;
    QGroupBox *attributesGroup;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *attLabelVBox;
    QLabel *strLabel;
    QLabel *dexLabel;
    QLabel *conLabel;
    QLabel *intLabel;
    QLabel *wisLabel;
    QLabel *chaLabel;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *attScoreVBox;
    QLineEdit *strField;
    QLineEdit *dexField;
    QLineEdit *conField;
    QLineEdit *intField;
    QLineEdit *wisField;
    QLineEdit *chaField;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *attModVBox;
    QLineEdit *modStrField;
    QLineEdit *modDexField;
    QLineEdit *modConField;
    QLineEdit *modIntField;
    QLineEdit *modWisField;
    QLineEdit *modChaField;
    QLabel *scoreLabel;
    QLabel *modLabel;
    QGroupBox *invBox;
    QTextBrowser *invField;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *GCharacterObserver)
    {
        if (GCharacterObserver->objectName().isEmpty())
            GCharacterObserver->setObjectName(QStringLiteral("GCharacterObserver"));
        GCharacterObserver->resize(602, 395);
        actionSave = new QAction(GCharacterObserver);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionLoad = new QAction(GCharacterObserver);
        actionLoad->setObjectName(QStringLiteral("actionLoad"));
        centralWidget = new QWidget(GCharacterObserver);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        infoBox = new QGroupBox(centralWidget);
        infoBox->setObjectName(QStringLiteral("infoBox"));
        infoBox->setGeometry(QRect(20, 10, 191, 81));
        nameLabel = new QLabel(infoBox);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));
        nameLabel->setGeometry(QRect(10, 20, 31, 16));
        nameField = new QLineEdit(infoBox);
        nameField->setObjectName(QStringLiteral("nameField"));
        nameField->setGeometry(QRect(50, 20, 131, 20));
        nameField->setReadOnly(true);
        levelLabel = new QLabel(infoBox);
        levelLabel->setObjectName(QStringLiteral("levelLabel"));
        levelLabel->setGeometry(QRect(10, 50, 31, 16));
        levelField = new QLineEdit(infoBox);
        levelField->setObjectName(QStringLiteral("levelField"));
        levelField->setGeometry(QRect(50, 50, 131, 20));
        levelField->setReadOnly(true);
        attributesGroup = new QGroupBox(centralWidget);
        attributesGroup->setObjectName(QStringLiteral("attributesGroup"));
        attributesGroup->setGeometry(QRect(20, 100, 191, 251));
        verticalLayoutWidget = new QWidget(attributesGroup);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 40, 71, 201));
        attLabelVBox = new QVBoxLayout(verticalLayoutWidget);
        attLabelVBox->setSpacing(6);
        attLabelVBox->setContentsMargins(11, 11, 11, 11);
        attLabelVBox->setObjectName(QStringLiteral("attLabelVBox"));
        attLabelVBox->setContentsMargins(0, 0, 0, 0);
        strLabel = new QLabel(verticalLayoutWidget);
        strLabel->setObjectName(QStringLiteral("strLabel"));

        attLabelVBox->addWidget(strLabel);

        dexLabel = new QLabel(verticalLayoutWidget);
        dexLabel->setObjectName(QStringLiteral("dexLabel"));

        attLabelVBox->addWidget(dexLabel);

        conLabel = new QLabel(verticalLayoutWidget);
        conLabel->setObjectName(QStringLiteral("conLabel"));

        attLabelVBox->addWidget(conLabel);

        intLabel = new QLabel(verticalLayoutWidget);
        intLabel->setObjectName(QStringLiteral("intLabel"));

        attLabelVBox->addWidget(intLabel);

        wisLabel = new QLabel(verticalLayoutWidget);
        wisLabel->setObjectName(QStringLiteral("wisLabel"));

        attLabelVBox->addWidget(wisLabel);

        chaLabel = new QLabel(verticalLayoutWidget);
        chaLabel->setObjectName(QStringLiteral("chaLabel"));

        attLabelVBox->addWidget(chaLabel);

        verticalLayoutWidget_2 = new QWidget(attributesGroup);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(80, 40, 52, 201));
        attScoreVBox = new QVBoxLayout(verticalLayoutWidget_2);
        attScoreVBox->setSpacing(6);
        attScoreVBox->setContentsMargins(11, 11, 11, 11);
        attScoreVBox->setObjectName(QStringLiteral("attScoreVBox"));
        attScoreVBox->setContentsMargins(0, 0, 0, 0);
        strField = new QLineEdit(verticalLayoutWidget_2);
        strField->setObjectName(QStringLiteral("strField"));
        strField->setReadOnly(true);

        attScoreVBox->addWidget(strField);

        dexField = new QLineEdit(verticalLayoutWidget_2);
        dexField->setObjectName(QStringLiteral("dexField"));
        dexField->setReadOnly(true);

        attScoreVBox->addWidget(dexField);

        conField = new QLineEdit(verticalLayoutWidget_2);
        conField->setObjectName(QStringLiteral("conField"));
        conField->setReadOnly(true);

        attScoreVBox->addWidget(conField);

        intField = new QLineEdit(verticalLayoutWidget_2);
        intField->setObjectName(QStringLiteral("intField"));
        intField->setReadOnly(true);

        attScoreVBox->addWidget(intField);

        wisField = new QLineEdit(verticalLayoutWidget_2);
        wisField->setObjectName(QStringLiteral("wisField"));
        wisField->setReadOnly(true);

        attScoreVBox->addWidget(wisField);

        chaField = new QLineEdit(verticalLayoutWidget_2);
        chaField->setObjectName(QStringLiteral("chaField"));
        chaField->setReadOnly(true);

        attScoreVBox->addWidget(chaField);

        verticalLayoutWidget_3 = new QWidget(attributesGroup);
        verticalLayoutWidget_3->setObjectName(QStringLiteral("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(150, 40, 31, 201));
        attModVBox = new QVBoxLayout(verticalLayoutWidget_3);
        attModVBox->setSpacing(6);
        attModVBox->setContentsMargins(11, 11, 11, 11);
        attModVBox->setObjectName(QStringLiteral("attModVBox"));
        attModVBox->setContentsMargins(0, 0, 0, 0);
        modStrField = new QLineEdit(verticalLayoutWidget_3);
        modStrField->setObjectName(QStringLiteral("modStrField"));
        modStrField->setReadOnly(true);

        attModVBox->addWidget(modStrField);

        modDexField = new QLineEdit(verticalLayoutWidget_3);
        modDexField->setObjectName(QStringLiteral("modDexField"));
        modDexField->setReadOnly(true);

        attModVBox->addWidget(modDexField);

        modConField = new QLineEdit(verticalLayoutWidget_3);
        modConField->setObjectName(QStringLiteral("modConField"));
        modConField->setReadOnly(true);

        attModVBox->addWidget(modConField);

        modIntField = new QLineEdit(verticalLayoutWidget_3);
        modIntField->setObjectName(QStringLiteral("modIntField"));
        modIntField->setReadOnly(true);

        attModVBox->addWidget(modIntField);

        modWisField = new QLineEdit(verticalLayoutWidget_3);
        modWisField->setObjectName(QStringLiteral("modWisField"));
        modWisField->setReadOnly(true);

        attModVBox->addWidget(modWisField);

        modChaField = new QLineEdit(verticalLayoutWidget_3);
        modChaField->setObjectName(QStringLiteral("modChaField"));
        modChaField->setReadOnly(true);

        attModVBox->addWidget(modChaField);

        scoreLabel = new QLabel(attributesGroup);
        scoreLabel->setObjectName(QStringLiteral("scoreLabel"));
        scoreLabel->setGeometry(QRect(80, 20, 31, 16));
        modLabel = new QLabel(attributesGroup);
        modLabel->setObjectName(QStringLiteral("modLabel"));
        modLabel->setGeometry(QRect(150, 20, 21, 16));
        invBox = new QGroupBox(centralWidget);
        invBox->setObjectName(QStringLiteral("invBox"));
        invBox->setGeometry(QRect(230, 10, 351, 341));
        invField = new QTextBrowser(invBox);
        invField->setObjectName(QStringLiteral("invField"));
        invField->setGeometry(QRect(10, 20, 331, 311));
        GCharacterObserver->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(GCharacterObserver);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 602, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        GCharacterObserver->setMenuBar(menuBar);
        statusBar = new QStatusBar(GCharacterObserver);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        GCharacterObserver->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionSave);
        menuFile->addAction(actionLoad);

        retranslateUi(GCharacterObserver);

        QMetaObject::connectSlotsByName(GCharacterObserver);
    } // setupUi

    void retranslateUi(QMainWindow *GCharacterObserver)
    {
        GCharacterObserver->setWindowTitle(QApplication::translate("GCharacterObserver", "GCharacterObserver", 0));
        actionSave->setText(QApplication::translate("GCharacterObserver", "Save", 0));
        actionLoad->setText(QApplication::translate("GCharacterObserver", "Load", 0));
        infoBox->setTitle(QApplication::translate("GCharacterObserver", "Info", 0));
        nameLabel->setText(QApplication::translate("GCharacterObserver", "Name:", 0));
        levelLabel->setText(QApplication::translate("GCharacterObserver", "Level:", 0));
        attributesGroup->setTitle(QApplication::translate("GCharacterObserver", "Attributes", 0));
        strLabel->setText(QApplication::translate("GCharacterObserver", "Strength:", 0));
        dexLabel->setText(QApplication::translate("GCharacterObserver", "Dexterity:", 0));
        conLabel->setText(QApplication::translate("GCharacterObserver", "Constitution:", 0));
        intLabel->setText(QApplication::translate("GCharacterObserver", "Intelligence:", 0));
        wisLabel->setText(QApplication::translate("GCharacterObserver", "Wisdom:", 0));
        chaLabel->setText(QApplication::translate("GCharacterObserver", "Charisma:", 0));
        scoreLabel->setText(QApplication::translate("GCharacterObserver", "Score", 0));
        modLabel->setText(QApplication::translate("GCharacterObserver", "Mod", 0));
        invBox->setTitle(QApplication::translate("GCharacterObserver", "Inventory", 0));
        menuFile->setTitle(QApplication::translate("GCharacterObserver", "File", 0));
    } // retranslateUi

};

namespace Ui {
    class GCharacterObserver: public Ui_GCharacterObserver {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GCHARACTEROBSERVER_H
