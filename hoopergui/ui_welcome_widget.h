/********************************************************************************
** Form generated from reading UI file 'welcome_widget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WELCOME_WIDGET_H
#define UI_WELCOME_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_welcome_widget
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_logo;
    QLabel *label_welcome;
    QLabel *label_info;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *welcome_widget)
    {
        if (welcome_widget->objectName().isEmpty())
            welcome_widget->setObjectName(QStringLiteral("welcome_widget"));
        welcome_widget->resize(552, 213);
        verticalLayout = new QVBoxLayout(welcome_widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalSpacer_2 = new QSpacerItem(20, 80, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        label_logo = new QLabel(welcome_widget);
        label_logo->setObjectName(QStringLiteral("label_logo"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(100);
        sizePolicy.setVerticalStretch(100);
        sizePolicy.setHeightForWidth(label_logo->sizePolicy().hasHeightForWidth());
        label_logo->setSizePolicy(sizePolicy);
        label_logo->setMinimumSize(QSize(100, 100));
        label_logo->setMaximumSize(QSize(100, 100));
        label_logo->setLayoutDirection(Qt::LeftToRight);
        label_logo->setPixmap(QPixmap(QString::fromUtf8(":/hooper/prefix1/hooper.png")));
        label_logo->setScaledContents(false);
        label_logo->setAlignment(Qt::AlignCenter);
        label_logo->setWordWrap(false);

        verticalLayout->addWidget(label_logo, 0, Qt::AlignHCenter);

        label_welcome = new QLabel(welcome_widget);
        label_welcome->setObjectName(QStringLiteral("label_welcome"));
        label_welcome->setAlignment(Qt::AlignCenter);
        label_welcome->setWordWrap(true);

        verticalLayout->addWidget(label_welcome);

        label_info = new QLabel(welcome_widget);
        label_info->setObjectName(QStringLiteral("label_info"));
        label_info->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_info);

        verticalSpacer = new QSpacerItem(20, 100, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(welcome_widget);

        QMetaObject::connectSlotsByName(welcome_widget);
    } // setupUi

    void retranslateUi(QWidget *welcome_widget)
    {
        welcome_widget->setWindowTitle(QApplication::translate("welcome_widget", "Form", 0));
        label_logo->setText(QString());
        label_welcome->setText(QApplication::translate("welcome_widget", "Welcome to Hooper.", 0));
        label_info->setText(QApplication::translate("welcome_widget", "Hooper contains information about pioneers and computers in computer science.", 0));
    } // retranslateUi

};

namespace Ui {
    class welcome_widget: public Ui_welcome_widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WELCOME_WIDGET_H
