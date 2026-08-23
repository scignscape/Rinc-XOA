/********************************************************************************
** Form generated from reading UI file 'identityeditorwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IDENTITYEDITORWIDGET_H
#define UI_IDENTITYEDITORWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

#include <QPushButton>

#include <identityplugin/passwordwidget.h>
#include <identityplugin/themedgenderbutton.h>
#include <utils/widgets/languagecombobox.h>
#include <utils/widgets/moderndateeditor.h>
#include <zipcodesplugin/zipcodeswidget.h>

namespace Identity {
namespace Internal {

class Ui_IdentityWidget
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLabel *otherNamesLabel;

    //?Identity::Internal::ThemedGenderButton *photoButton;
    QPushButton* photo_button_;

    QLabel *genderLabel;

    QComboBox* cb_language_;
//?    Utils::LanguageComboBox *language;
    QLabel *firstnameLabel;
    QComboBox *titleCombo;
    QLineEdit *usualName;
    QLabel *languageLabel;
    QLabel *dobLabel;
    QLineEdit *firstname;
    QLineEdit *otherNames;
    Utils::ModernDateEditor *dob;
    QComboBox *genderCombo;
    Identity::Internal::PasswordWidget *passwordWidget;
    ZipCodes::ZipCodesWidget *zipcodesWidget;

    void setupUi(QWidget *Identity__Internal__IdentityWidget)
    {
        if (Identity__Internal__IdentityWidget->objectName().isEmpty())
            Identity__Internal__IdentityWidget->setObjectName(QString::fromUtf8("Identity__Internal__IdentityWidget"));
        Identity__Internal__IdentityWidget->resize(525, 478);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Identity__Internal__IdentityWidget->sizePolicy().hasHeightForWidth());
        Identity__Internal__IdentityWidget->setSizePolicy(sizePolicy);
        gridLayout_2 = new QGridLayout(Identity__Internal__IdentityWidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        otherNamesLabel = new QLabel(Identity__Internal__IdentityWidget);
        otherNamesLabel->setObjectName(QString::fromUtf8("otherNamesLabel"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(otherNamesLabel->sizePolicy().hasHeightForWidth());
        otherNamesLabel->setSizePolicy(sizePolicy1);
        otherNamesLabel->setMinimumSize(QSize(0, 20));

        gridLayout->addWidget(otherNamesLabel, 3, 1, 1, 1);

#ifdef HIDE
        photoButton = new Identity::Internal::ThemedGenderButton(Identity__Internal__IdentityWidget);
        photoButton->setObjectName(QString::fromUtf8("photoButton"));
        sizePolicy1.setHeightForWidth(photoButton->sizePolicy().hasHeightForWidth());
        photoButton->setSizePolicy(sizePolicy1);
        photoButton->setMinimumSize(QSize(64, 64));
        photoButton->setMaximumSize(QSize(64, 64));
        photoButton->setFocusPolicy(Qt::ClickFocus);
        photoButton->setIconSize(QSize(50, 50));
        photoButton->setPopupMode(QToolButton::InstantPopup);

        gridLayout->addWidget(photoButton, 0, 0, 3, 1);
#endif
        photo_button_ = new QPushButton("photo");
        gridLayout->addWidget(photo_button_, 0, 0, 3, 1);

        genderLabel = new QLabel(Identity__Internal__IdentityWidget);
        genderLabel->setObjectName(QString::fromUtf8("genderLabel"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(genderLabel->sizePolicy().hasHeightForWidth());
        genderLabel->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(genderLabel, 5, 1, 1, 1);

        cb_language_ = new QComboBox;
//?        language = new Utils::LanguageComboBox(Identity__Internal__IdentityWidget);
//?        language->setObjectName(QString::fromUtf8("language"));
//?        language->setMinimumSize(QSize(0, 20));
        cb_language_->setMinimumSize(QSize(0, 20));

//?        gridLayout->addWidget(language, 6, 2, 1, 2);
        gridLayout->addWidget(cb_language_, 6, 2, 1, 2);

        firstnameLabel = new QLabel(Identity__Internal__IdentityWidget);
        firstnameLabel->setObjectName(QString::fromUtf8("firstnameLabel"));
        sizePolicy1.setHeightForWidth(firstnameLabel->sizePolicy().hasHeightForWidth());
        firstnameLabel->setSizePolicy(sizePolicy1);
        firstnameLabel->setMinimumSize(QSize(0, 20));

        gridLayout->addWidget(firstnameLabel, 2, 1, 1, 1);

        titleCombo = new QComboBox(Identity__Internal__IdentityWidget);
        titleCombo->setObjectName(QString::fromUtf8("titleCombo"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(titleCombo->sizePolicy().hasHeightForWidth());
        titleCombo->setSizePolicy(sizePolicy3);
        titleCombo->setMinimumSize(QSize(0, 20));

        gridLayout->addWidget(titleCombo, 0, 1, 1, 3);

        usualName = new QLineEdit(Identity__Internal__IdentityWidget);
        usualName->setObjectName(QString::fromUtf8("usualName"));
        usualName->setMinimumSize(QSize(0, 20));

        gridLayout->addWidget(usualName, 1, 1, 1, 3);

        languageLabel = new QLabel(Identity__Internal__IdentityWidget);
        languageLabel->setObjectName(QString::fromUtf8("languageLabel"));
        sizePolicy1.setHeightForWidth(languageLabel->sizePolicy().hasHeightForWidth());
        languageLabel->setSizePolicy(sizePolicy1);
        languageLabel->setMinimumSize(QSize(0, 20));

        gridLayout->addWidget(languageLabel, 6, 1, 1, 1);

        dobLabel = new QLabel(Identity__Internal__IdentityWidget);
        dobLabel->setObjectName(QString::fromUtf8("dobLabel"));
        sizePolicy1.setHeightForWidth(dobLabel->sizePolicy().hasHeightForWidth());
        dobLabel->setSizePolicy(sizePolicy1);
        dobLabel->setMinimumSize(QSize(0, 20));

        gridLayout->addWidget(dobLabel, 4, 1, 1, 1);

        firstname = new QLineEdit(Identity__Internal__IdentityWidget);
        firstname->setObjectName(QString::fromUtf8("firstname"));
        firstname->setMinimumSize(QSize(0, 20));

        gridLayout->addWidget(firstname, 2, 2, 1, 2);

        otherNames = new QLineEdit(Identity__Internal__IdentityWidget);
        otherNames->setObjectName(QString::fromUtf8("otherNames"));
        otherNames->setMinimumSize(QSize(0, 20));

        gridLayout->addWidget(otherNames, 3, 2, 1, 2);

        dob = new Utils::ModernDateEditor(Identity__Internal__IdentityWidget);
        dob->setObjectName(QString::fromUtf8("dob"));
        dob->setMinimumSize(QSize(0, 20));

        gridLayout->addWidget(dob, 4, 2, 1, 2);

        genderCombo = new QComboBox(Identity__Internal__IdentityWidget);
        genderCombo->setObjectName(QString::fromUtf8("genderCombo"));
        sizePolicy3.setHeightForWidth(genderCombo->sizePolicy().hasHeightForWidth());
        genderCombo->setSizePolicy(sizePolicy3);
        genderCombo->setMinimumSize(QSize(0, 20));

        gridLayout->addWidget(genderCombo, 5, 2, 1, 2);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        passwordWidget = new Identity::Internal::PasswordWidget(Identity__Internal__IdentityWidget);
        passwordWidget->setObjectName(QString::fromUtf8("passwordWidget"));

        gridLayout_2->addWidget(passwordWidget, 2, 0, 1, 1);

        zipcodesWidget = new ZipCodes::ZipCodesWidget(Identity__Internal__IdentityWidget);
        zipcodesWidget->setObjectName(QString::fromUtf8("zipcodesWidget"));

        gridLayout_2->addWidget(zipcodesWidget, 1, 0, 1, 1);

#if QT_CONFIG(shortcut)
        otherNamesLabel->setBuddy(otherNames);
        firstnameLabel->setBuddy(firstname);
        dobLabel->setBuddy(dob);
#endif // QT_CONFIG(shortcut)
        QWidget::setTabOrder(titleCombo, usualName);
        QWidget::setTabOrder(usualName, firstname);
        QWidget::setTabOrder(firstname, otherNames);
        QWidget::setTabOrder(otherNames, dob);
        QWidget::setTabOrder(dob, genderCombo);
//?        QWidget::setTabOrder(genderCombo, language);
        QWidget::setTabOrder(genderCombo, cb_language_);

        retranslateUi(Identity__Internal__IdentityWidget);

        QMetaObject::connectSlotsByName(Identity__Internal__IdentityWidget);
    } // setupUi

    void retranslateUi(QWidget *Identity__Internal__IdentityWidget)
    {
        Identity__Internal__IdentityWidget->setWindowTitle(QCoreApplication::translate("Identity::Internal::IdentityWidget", "Form", nullptr));
        otherNamesLabel->setText(QCoreApplication::translate("Identity::Internal::IdentityWidget", "Other names:", nullptr));
#if QT_CONFIG(tooltip)
        //?photoButton->setToolTip(QCoreApplication::translate("Identity::Internal::IdentityWidget", "Click to add/change the photo", nullptr));
#endif // QT_CONFIG(tooltip)
        photo_button_->setText("photo");
//?        photoButton->setText(QString());
        genderLabel->setText(QCoreApplication::translate("Identity::Internal::IdentityWidget", "Gender:", nullptr));
        firstnameLabel->setText(QCoreApplication::translate("Identity::Internal::IdentityWidget", "First name:", nullptr));
        languageLabel->setText(QCoreApplication::translate("Identity::Internal::IdentityWidget", "Language:", nullptr));
        dobLabel->setText(QCoreApplication::translate("Identity::Internal::IdentityWidget", "Date of birth:", nullptr));
    } // retranslateUi

};

} // namespace Internal
} // namespace Identity

namespace Identity {
namespace Internal {
namespace Ui {
    class IdentityWidget: public Ui_IdentityWidget {};
} // namespace Ui
} // namespace Internal
} // namespace Identity

#endif // UI_IDENTITYEDITORWIDGET_H
