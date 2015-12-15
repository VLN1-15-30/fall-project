/********************************************************************************
** Form generated from reading UI file 'discover_widget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DISCOVER_WIDGET_H
#define UI_DISCOVER_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_discover_widget
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QLabel *label;
    QLabel *label_info;
    QPushButton *pushButton_discover;
    QLabel *label_target;
    QHBoxLayout *horizontalLayout;
    QLabel *label_define_1;
    QLabel *label_target_1;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_define_2;
    QLabel *label_target_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_define_3;
    QLabel *label_target_3;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_define_4;
    QLabel *label_target_4;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_define_5;
    QLabel *label_target_5;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *discover_widget)
    {
        if (discover_widget->objectName().isEmpty())
            discover_widget->setObjectName(QStringLiteral("discover_widget"));
        discover_widget->resize(696, 474);
        verticalLayout = new QVBoxLayout(discover_widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalSpacer = new QSpacerItem(20, 35, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        label = new QLabel(discover_widget);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(70, 50));
        label->setMaximumSize(QSize(70, 50));
        label->setPixmap(QPixmap(QString::fromUtf8(":/hooper/prefix3/icon-eye.png")));
        label->setScaledContents(true);

        verticalLayout->addWidget(label, 0, Qt::AlignHCenter);

        label_info = new QLabel(discover_widget);
        label_info->setObjectName(QStringLiteral("label_info"));
        label_info->setMaximumSize(QSize(16777215, 20));
        label_info->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_info);

        pushButton_discover = new QPushButton(discover_widget);
        pushButton_discover->setObjectName(QStringLiteral("pushButton_discover"));
        pushButton_discover->setStyleSheet(QStringLiteral("background {rgb(131, 58, 255)}"));
        pushButton_discover->setAutoDefault(false);
        pushButton_discover->setFlat(false);

        verticalLayout->addWidget(pushButton_discover, 0, Qt::AlignHCenter);

        label_target = new QLabel(discover_widget);
        label_target->setObjectName(QStringLiteral("label_target"));
        QFont font;
        font.setPointSize(25);
        font.setBold(true);
        font.setUnderline(true);
        font.setWeight(75);
        label_target->setFont(font);

        verticalLayout->addWidget(label_target, 0, Qt::AlignHCenter|Qt::AlignVCenter);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_define_1 = new QLabel(discover_widget);
        label_define_1->setObjectName(QStringLiteral("label_define_1"));
        QFont font1;
        font1.setPointSize(18);
        font1.setBold(true);
        font1.setWeight(75);
        label_define_1->setFont(font1);

        horizontalLayout->addWidget(label_define_1, 0, Qt::AlignLeft);

        label_target_1 = new QLabel(discover_widget);
        label_target_1->setObjectName(QStringLiteral("label_target_1"));
        label_target_1->setMinimumSize(QSize(205, 0));
        label_target_1->setMaximumSize(QSize(16777215, 16777215));
        QFont font2;
        font2.setPointSize(18);
        label_target_1->setFont(font2);

        horizontalLayout->addWidget(label_target_1);

        horizontalSpacer_3 = new QSpacerItem(35, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        label_define_2 = new QLabel(discover_widget);
        label_define_2->setObjectName(QStringLiteral("label_define_2"));
        label_define_2->setFont(font1);

        horizontalLayout->addWidget(label_define_2, 0, Qt::AlignLeft);

        label_target_2 = new QLabel(discover_widget);
        label_target_2->setObjectName(QStringLiteral("label_target_2"));
        label_target_2->setMinimumSize(QSize(205, 0));
        label_target_2->setMaximumSize(QSize(16777215, 16777215));
        label_target_2->setFont(font2);

        horizontalLayout->addWidget(label_target_2);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_define_3 = new QLabel(discover_widget);
        label_define_3->setObjectName(QStringLiteral("label_define_3"));
        label_define_3->setFont(font1);

        horizontalLayout_2->addWidget(label_define_3, 0, Qt::AlignLeft);

        label_target_3 = new QLabel(discover_widget);
        label_target_3->setObjectName(QStringLiteral("label_target_3"));
        label_target_3->setFont(font2);

        horizontalLayout_2->addWidget(label_target_3);

        horizontalSpacer_5 = new QSpacerItem(100, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        label_define_4 = new QLabel(discover_widget);
        label_define_4->setObjectName(QStringLiteral("label_define_4"));
        label_define_4->setFont(font1);

        horizontalLayout_2->addWidget(label_define_4, 0, Qt::AlignLeft);

        label_target_4 = new QLabel(discover_widget);
        label_target_4->setObjectName(QStringLiteral("label_target_4"));
        label_target_4->setFont(font2);

        horizontalLayout_2->addWidget(label_target_4);

        horizontalSpacer_2 = new QSpacerItem(50, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_define_5 = new QLabel(discover_widget);
        label_define_5->setObjectName(QStringLiteral("label_define_5"));
        label_define_5->setFont(font1);

        horizontalLayout_3->addWidget(label_define_5);

        label_target_5 = new QLabel(discover_widget);
        label_target_5->setObjectName(QStringLiteral("label_target_5"));
        label_target_5->setFont(font2);

        horizontalLayout_3->addWidget(label_target_5);

        horizontalSpacer = new QSpacerItem(415, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_3);


        retranslateUi(discover_widget);

        pushButton_discover->setDefault(false);


        QMetaObject::connectSlotsByName(discover_widget);
    } // setupUi

    void retranslateUi(QWidget *discover_widget)
    {
        discover_widget->setWindowTitle(QApplication::translate("discover_widget", "Form", 0));
        label->setText(QString());
        label_info->setText(QApplication::translate("discover_widget", "Discover a pioneer, a computer or a connection", 0));
        pushButton_discover->setText(QApplication::translate("discover_widget", "Discover", 0));
        label_target->setText(QApplication::translate("discover_widget", "target", 0));
        label_define_1->setText(QApplication::translate("discover_widget", "First name:", 0));
        label_target_1->setText(QApplication::translate("discover_widget", "target", 0));
        label_define_2->setText(QApplication::translate("discover_widget", "Last name:", 0));
        label_target_2->setText(QApplication::translate("discover_widget", "target", 0));
        label_define_3->setText(QApplication::translate("discover_widget", "Gender:", 0));
        label_target_3->setText(QApplication::translate("discover_widget", "target", 0));
        label_define_4->setText(QApplication::translate("discover_widget", "Year born:", 0));
        label_target_4->setText(QApplication::translate("discover_widget", "target", 0));
        label_define_5->setText(QApplication::translate("discover_widget", "Year died:", 0));
        label_target_5->setText(QApplication::translate("discover_widget", "target", 0));
    } // retranslateUi

};

namespace Ui {
    class discover_widget: public Ui_discover_widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DISCOVER_WIDGET_H
