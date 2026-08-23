/********************************************************************************
** Form generated from reading UI file 'passwordwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PASSWORDWIDGET_H
#define UI_PASSWORDWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

#include <QLineEdit>

//?#include <utils/widgets/lineeditechoswitcher.h>

namespace Identity {
namespace Internal {

class Ui_PasswordWidget
{
public:
    QGridLayout *gridLayout;
//?    Utils::LineEditEchoSwitcher *login;

    QLineEdit* login_;

    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QLabel *passwordStatus;
    QPushButton *changePassword;
    QLabel *label_3;
    QLabel *info;

    void setupUi(QWidget *Identity__Internal__PasswordWidget)
    {
        if (Identity__Internal__PasswordWidget->objectName().isEmpty())
            Identity__Internal__PasswordWidget->setObjectName(QString::fromUtf8("Identity__Internal__PasswordWidget"));
        Identity__Internal__PasswordWidget->resize(563, 113);
        gridLayout = new QGridLayout(Identity__Internal__PasswordWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));

        login_ = new QLineEdit("<login>");
//?        login = new Utils::LineEditEchoSwitcher(Identity__Internal__PasswordWidget);
//?        login->setObjectName(QString::fromUtf8("login"));

        gridLayout->addWidget(login_, 0, 1, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(238, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        passwordStatus = new QLabel(Identity__Internal__PasswordWidget);
        passwordStatus->setObjectName(QString::fromUtf8("passwordStatus"));

        horizontalLayout_2->addWidget(passwordStatus);

        changePassword = new QPushButton(Identity__Internal__PasswordWidget);
        changePassword->setObjectName(QString::fromUtf8("changePassword"));

        horizontalLayout_2->addWidget(changePassword);


        gridLayout->addLayout(horizontalLayout_2, 2, 1, 1, 1);

        label_3 = new QLabel(Identity__Internal__PasswordWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        info = new QLabel(Identity__Internal__PasswordWidget);
        info->setObjectName(QString::fromUtf8("info"));
        info->setText(QString::fromUtf8(""));

        gridLayout->addWidget(info, 1, 1, 1, 1);


        retranslateUi(Identity__Internal__PasswordWidget);

        QMetaObject::connectSlotsByName(Identity__Internal__PasswordWidget);
    } // setupUi

    void retranslateUi(QWidget *Identity__Internal__PasswordWidget)
    {
        Identity__Internal__PasswordWidget->setWindowTitle(QCoreApplication::translate("Identity::Internal::PasswordWidget", "Form", nullptr));
        changePassword->setText(QCoreApplication::translate("Identity::Internal::PasswordWidget", "Set password", nullptr));
        label_3->setText(QCoreApplication::translate("Identity::Internal::PasswordWidget", "Login", nullptr));
    } // retranslateUi

};

} // namespace Internal
} // namespace Identity

namespace Identity {
namespace Internal {
namespace Ui {
    class PasswordWidget: public Ui_PasswordWidget {};
} // namespace Ui
} // namespace Internal
} // namespace Identity

#endif // UI_PASSWORDWIDGET_H
