/********************************************************************************
** Form generated from reading UI file 'add_widget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADD_WIDGET_H
#define UI_ADD_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_add_widget
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tab_add;
    QWidget *tab;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QLineEdit *input_firstname;
    QLineEdit *input_lastname;
    QLineEdit *input_gender;
    QLineEdit *input__yearOfBirth;
    QLineEdit *input_yearOfDeath;
    QPushButton *pushButton_add_pioneer;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QLineEdit *input_computer_name;
    QLineEdit *input_type;
    QLineEdit *input_yearBuilt;
    QLineEdit *input_ifMade;
    QPushButton *pushButton_add_computer;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout_4;
    QLabel *label;
    QLineEdit *input_connect_lastname;
    QLineEdit *input_connect_firstname;
    QLineEdit *Input_connect_computer_name;
    QPushButton *pushButton_add_connection;

    void setupUi(QWidget *add_widget)
    {
        if (add_widget->objectName().isEmpty())
            add_widget->setObjectName(QStringLiteral("add_widget"));
        add_widget->resize(438, 362);
        verticalLayout = new QVBoxLayout(add_widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tab_add = new QTabWidget(add_widget);
        tab_add->setObjectName(QStringLiteral("tab_add"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        verticalLayout_3 = new QVBoxLayout(tab);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_3 = new QLabel(tab);
        label_3->setObjectName(QStringLiteral("label_3"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setMinimumSize(QSize(100, 100));
        label_3->setMaximumSize(QSize(100, 100));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/hooper/prefix2/peopleIcon.png")));
        label_3->setScaledContents(true);

        verticalLayout_3->addWidget(label_3, 0, Qt::AlignHCenter);

        input_firstname = new QLineEdit(tab);
        input_firstname->setObjectName(QStringLiteral("input_firstname"));

        verticalLayout_3->addWidget(input_firstname);

        input_lastname = new QLineEdit(tab);
        input_lastname->setObjectName(QStringLiteral("input_lastname"));

        verticalLayout_3->addWidget(input_lastname);

        input_gender = new QLineEdit(tab);
        input_gender->setObjectName(QStringLiteral("input_gender"));

        verticalLayout_3->addWidget(input_gender);

        input__yearOfBirth = new QLineEdit(tab);
        input__yearOfBirth->setObjectName(QStringLiteral("input__yearOfBirth"));

        verticalLayout_3->addWidget(input__yearOfBirth);

        input_yearOfDeath = new QLineEdit(tab);
        input_yearOfDeath->setObjectName(QStringLiteral("input_yearOfDeath"));

        verticalLayout_3->addWidget(input_yearOfDeath);

        pushButton_add_pioneer = new QPushButton(tab);
        pushButton_add_pioneer->setObjectName(QStringLiteral("pushButton_add_pioneer"));

        verticalLayout_3->addWidget(pushButton_add_pioneer);

        tab_add->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        verticalLayout_2 = new QVBoxLayout(tab_2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_2 = new QLabel(tab_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(100, 100));
        label_2->setMaximumSize(QSize(100, 100));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/hooper/prefix2/computer-xxl.png")));
        label_2->setScaledContents(true);

        verticalLayout_2->addWidget(label_2, 0, Qt::AlignHCenter);

        input_computer_name = new QLineEdit(tab_2);
        input_computer_name->setObjectName(QStringLiteral("input_computer_name"));

        verticalLayout_2->addWidget(input_computer_name);

        input_type = new QLineEdit(tab_2);
        input_type->setObjectName(QStringLiteral("input_type"));

        verticalLayout_2->addWidget(input_type);

        input_yearBuilt = new QLineEdit(tab_2);
        input_yearBuilt->setObjectName(QStringLiteral("input_yearBuilt"));

        verticalLayout_2->addWidget(input_yearBuilt);

        input_ifMade = new QLineEdit(tab_2);
        input_ifMade->setObjectName(QStringLiteral("input_ifMade"));

        verticalLayout_2->addWidget(input_ifMade);

        pushButton_add_computer = new QPushButton(tab_2);
        pushButton_add_computer->setObjectName(QStringLiteral("pushButton_add_computer"));

        verticalLayout_2->addWidget(pushButton_add_computer);

        tab_add->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        verticalLayout_4 = new QVBoxLayout(tab_3);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label = new QLabel(tab_3);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(100, 100));
        label->setMaximumSize(QSize(100, 100));
        label->setPixmap(QPixmap(QString::fromUtf8(":/hooper/prefix2/connected-256.png")));
        label->setScaledContents(true);

        verticalLayout_4->addWidget(label, 0, Qt::AlignHCenter);

        input_connect_lastname = new QLineEdit(tab_3);
        input_connect_lastname->setObjectName(QStringLiteral("input_connect_lastname"));

        verticalLayout_4->addWidget(input_connect_lastname);

        input_connect_firstname = new QLineEdit(tab_3);
        input_connect_firstname->setObjectName(QStringLiteral("input_connect_firstname"));

        verticalLayout_4->addWidget(input_connect_firstname);

        Input_connect_computer_name = new QLineEdit(tab_3);
        Input_connect_computer_name->setObjectName(QStringLiteral("Input_connect_computer_name"));

        verticalLayout_4->addWidget(Input_connect_computer_name);

        pushButton_add_connection = new QPushButton(tab_3);
        pushButton_add_connection->setObjectName(QStringLiteral("pushButton_add_connection"));

        verticalLayout_4->addWidget(pushButton_add_connection);

        tab_add->addTab(tab_3, QString());

        verticalLayout->addWidget(tab_add);


        retranslateUi(add_widget);

        tab_add->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(add_widget);
    } // setupUi

    void retranslateUi(QWidget *add_widget)
    {
        add_widget->setWindowTitle(QApplication::translate("add_widget", "Form", 0));
        label_3->setText(QString());
        input_firstname->setPlaceholderText(QApplication::translate("add_widget", "Firstname", 0));
        input_lastname->setPlaceholderText(QApplication::translate("add_widget", "Lastname", 0));
        input_gender->setPlaceholderText(QApplication::translate("add_widget", "Gender", 0));
        input__yearOfBirth->setPlaceholderText(QApplication::translate("add_widget", "Year of birth", 0));
        input_yearOfDeath->setPlaceholderText(QApplication::translate("add_widget", "Year of death", 0));
        pushButton_add_pioneer->setText(QApplication::translate("add_widget", "Submit", 0));
        tab_add->setTabText(tab_add->indexOf(tab), QApplication::translate("add_widget", "Pioneer", 0));
        label_2->setText(QString());
        input_computer_name->setPlaceholderText(QApplication::translate("add_widget", "Name", 0));
        input_type->setPlaceholderText(QApplication::translate("add_widget", "type", 0));
        input_yearBuilt->setPlaceholderText(QApplication::translate("add_widget", "Built(0 if not built", 0));
        input_ifMade->setPlaceholderText(QApplication::translate("add_widget", "made(0 if made, else 1)", 0));
        pushButton_add_computer->setText(QApplication::translate("add_widget", "Submit", 0));
        tab_add->setTabText(tab_add->indexOf(tab_2), QApplication::translate("add_widget", "Computer", 0));
        label->setText(QString());
        input_connect_lastname->setPlaceholderText(QApplication::translate("add_widget", "Lastname", 0));
        input_connect_firstname->setPlaceholderText(QApplication::translate("add_widget", "Firstname", 0));
        Input_connect_computer_name->setPlaceholderText(QApplication::translate("add_widget", "Name of computer", 0));
        pushButton_add_connection->setText(QApplication::translate("add_widget", "Submit", 0));
        tab_add->setTabText(tab_add->indexOf(tab_3), QApplication::translate("add_widget", "Connection", 0));
    } // retranslateUi

};

namespace Ui {
    class add_widget: public Ui_add_widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADD_WIDGET_H
