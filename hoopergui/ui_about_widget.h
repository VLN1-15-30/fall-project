/********************************************************************************
** Form generated from reading UI file 'about_widget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUT_WIDGET_H
#define UI_ABOUT_WIDGET_H

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

class Ui_about_widget
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_logo;
    QLabel *label_about;
    QLabel *label_authors;
    QLabel *label_version;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *about_widget)
    {
        if (about_widget->objectName().isEmpty())
            about_widget->setObjectName(QStringLiteral("about_widget"));
        about_widget->resize(400, 300);
        verticalLayout = new QVBoxLayout(about_widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        label_logo = new QLabel(about_widget);
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
        label_logo->setScaledContents(true);
        label_logo->setAlignment(Qt::AlignCenter);
        label_logo->setWordWrap(false);

        verticalLayout->addWidget(label_logo, 0, Qt::AlignHCenter);

        label_about = new QLabel(about_widget);
        label_about->setObjectName(QStringLiteral("label_about"));
        label_about->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_about);

        label_authors = new QLabel(about_widget);
        label_authors->setObjectName(QStringLiteral("label_authors"));
        label_authors->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_authors);

        label_version = new QLabel(about_widget);
        label_version->setObjectName(QStringLiteral("label_version"));

        verticalLayout->addWidget(label_version, 0, Qt::AlignHCenter);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(about_widget);

        QMetaObject::connectSlotsByName(about_widget);
    } // setupUi

    void retranslateUi(QWidget *about_widget)
    {
        about_widget->setWindowTitle(QApplication::translate("about_widget", "Form", 0));
        label_logo->setText(QString());
        label_about->setText(QApplication::translate("about_widget", "Hooper was created by:", 0));
        label_authors->setText(QApplication::translate("about_widget", "Emil, Gunnar, Rakel and Sverrir in VLN-1", 0));
        label_version->setText(QApplication::translate("about_widget", "Version: 1.0 <3", 0));
    } // retranslateUi

};

namespace Ui {
    class about_widget: public Ui_about_widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUT_WIDGET_H
