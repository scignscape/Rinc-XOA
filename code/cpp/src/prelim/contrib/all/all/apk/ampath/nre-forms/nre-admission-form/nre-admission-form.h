
//           Copyright Nathaniel Christen 2026.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef NRE_ADMISSION_FORM__H
#define NRE_ADMISSION_FORM__H



#include <QMainWindow>

#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>

#include <QTabWidget>
#include <QFrame>
#include <QScrollArea>
#include <QPlainTextEdit>
#include <QLineEdit>
#include <QDateEdit>
#include <QDateTimeEdit>

#include "kans.h"

KANS_(AMPATH_Forms)

class NRE_Accordion_List;
class NRE_Combo_With_Label_Bar;
class NRE_Radio_Button_Group_Box;
class NRE_Workspace_Launcher_Button;

class NRE_Admission_Form : public QMainWindow
{
// //--> ctor
public:
 NRE_Admission_Form();

private:
 QTabWidget* pages_tab_widget_;


 // //  Page: Admission
 QScrollArea* S_100_; // Admission
 QFrame* F_100_; // Admission
 QVBoxLayout* F_100_vbl_ ;

  // // Section: Admission_data -- ctor
 NRE_Accordion_List* Admission_data_F100_;

 // //  Page: Anamnesis at admission
 QScrollArea* S_101_; // Anamnesis at admission
 QFrame* F_101_; // Anamnesis at admission
 QVBoxLayout* F_101_vbl_ ;

  // // Section: History_of_the_illness -- ctor
 NRE_Accordion_List* History_of_the_illness_F101_;

  // // Section: Feeding_history -- ctor
 NRE_Accordion_List* Feeding_history_F101_;

  // // Section: Family_history -- ctor
 NRE_Accordion_List* Family_history_F101_;

 // //  Page: Physical exam at admission
 QScrollArea* S_102_; // Physical exam at admission
 QFrame* F_102_; // Physical exam at admission
 QVBoxLayout* F_102_vbl_ ;

  // // Section: Physical_exam -- ctor
 NRE_Accordion_List* Physical_exam_F102_;

 // //  Page: Evaluation
 QScrollArea* S_103_; // Evaluation
 QFrame* F_103_; // Evaluation
 QVBoxLayout* F_103_vbl_ ;

  // // Section: Target -- ctor
 NRE_Accordion_List* Target_F103_;

  // // Section: Malaria_test -- ctor
 NRE_Accordion_List* Malaria_test_F103_;

  // // Section: TB_evaluation -- ctor
 NRE_Accordion_List* TB_evaluation_F103_;

 // //  Page: Observations
 QScrollArea* S_104_; // Observations
 QFrame* F_104_; // Observations
 QVBoxLayout* F_104_vbl_ ;

  // // Section: Observations -- ctor
 NRE_Accordion_List* Observations_F104_;

 // //  Page: Diagnosis
 QScrollArea* S_105_; // Diagnosis
 QFrame* F_105_; // Diagnosis
 QVBoxLayout* F_105_vbl_ ;

  // // Section: Diagnosis -- ctor
 NRE_Accordion_List* Diagnosis_F105_;

 // //  Page: Prescription
 QScrollArea* S_106_; // Prescription
 QFrame* F_106_; // Prescription
 QVBoxLayout* F_106_vbl_ ;

  // // Section: Prescription -- ctor
 NRE_Accordion_List* Prescription_F106_;
// //<-- ctor
// //--> init
 void init();

 // //  Page: Admission

  // // Section: Admission_data -- init

 // //  Page: Anamnesis at admission

  // // Section: History_of_the_illness -- init

  // // Section: Feeding_history -- init

  // // Section: Family_history -- init

 // //  Page: Physical exam at admission

  // // Section: Physical_exam -- init

 // //  Page: Evaluation

  // // Section: Target -- init

  // // Section: Malaria_test -- init

  // // Section: TB_evaluation -- init

 // //  Page: Observations

  // // Section: Observations -- init

 // //  Page: Diagnosis

  // // Section: Diagnosis -- init

 // //  Page: Prescription

  // // Section: Prescription -- init
// //<-- init
// //--> methods

 // //  Page: Admission

  // // Section: Admission_data -- methods
 QString L_caretakersName_;
 QLineEdit* caretakersName_;
 QString L_admissionDateAndTime_;
 QDateTimeEdit* admissionDateAndTime_;
 QString L_admissionType_;
 NRE_Radio_Button_Group_Box* admissionType_;
 QString L_spontaneousAdmission_;
 NRE_Radio_Button_Group_Box* spontaneousAdmission_;
 QString L_ifReferredByWhomOrFromWhere_;
 NRE_Radio_Button_Group_Box* ifReferredByWhomOrFromWhere_;
 QString L_ifReferredByWhomOrFromWhere_ifOtherSpecify_;
 QLineEdit* ifReferredByWhomOrFromWhere_ifOtherSpecify_;

 // //  Page: Anamnesis at admission

  // // Section: History_of_the_illness -- methods
 QString L_howLongHasTheChildBeenSick_;
 QLineEdit* howLongHasTheChildBeenSick_;
 QString L_whatAreTheProblemsReportedByTheCaretaker_;
 QPlainTextEdit* whatAreTheProblemsReportedByTheCaretaker_;
 QString L_isThereSomeoneInTheFamilyCoughingForMoreThanOneMonth_;
 NRE_Radio_Button_Group_Box* isThereSomeoneInTheFamilyCoughingForMoreThanOneMonth_;
 QString L_isThereSomeoneInTheFamilyCoughingForMoreThanOneMonth_specifyWho_;
 QLineEdit* isThereSomeoneInTheFamilyCoughingForMoreThanOneMonth_specifyWho_;
 QString L_isThereSomeoneTreatedForTbSinceTheBirthOfTheChild_;
 NRE_Radio_Button_Group_Box* isThereSomeoneTreatedForTbSinceTheBirthOfTheChild_;
 QString L_isThereSomeoneTreatedForTbSinceTheBirthOfTheChild_specifyWho_;
 QLineEdit* isThereSomeoneTreatedForTbSinceTheBirthOfTheChild_specifyWho_;

  // // Section: Feeding_history -- methods
 QString L_hasTheChildEverBeenBreastfed_;
 NRE_Radio_Button_Group_Box* hasTheChildEverBeenBreastfed_;
 QString L_isTheChildCurrentlyBeingBreastfed_;
 NRE_Radio_Button_Group_Box* isTheChildCurrentlyBeingBreastfed_;
 QString L_atWhatAgeDidYouIntroduceSolidFood_;
 QLineEdit* atWhatAgeDidYouIntroduceSolidFood_;
 QString L_typeOfMealsBeforeIllness_;
 QLineEdit* typeOfMealsBeforeIllness_;
 QString L_numberOfMealsPerDayBeforeIllness_;
 QLineEdit* numberOfMealsPerDayBeforeIllness_;
 QString L_numberOfMealsDuringTheLast24Hours_;
 QLineEdit* numberOfMealsDuringTheLast24Hours_;

  // // Section: Family_history -- methods
 QString L_whoIsTheHeadOfFamily_;
 NRE_Radio_Button_Group_Box* whoIsTheHeadOfFamily_;
 QString L_whoIsTheHeadOfFamily_ifOtherSpecify_;
 QLineEdit* whoIsTheHeadOfFamily_ifOtherSpecify_;
 QString L_isTheMotherAlive_;
 NRE_Radio_Button_Group_Box* isTheMotherAlive_;
 QString L_whoIsTakingCareOfTheChild_;
 QLineEdit* whoIsTakingCareOfTheChild_;
 QString L_numberOfBirthsForTheMother_;
 QLineEdit* numberOfBirthsForTheMother_;
 QString L_numberOfMothersChildrenAlive_;
 QLineEdit* numberOfMothersChildrenAlive_;
 QString L_rankInTheBirthOrder_;
 QLineEdit* rankInTheBirthOrder_;
 QString L_theChildIs_;
 NRE_Combo_With_Label_Bar* theChildIs_;
 QString L_nbOfPersonsSharingTheFamilyMeal_;
 QLineEdit* nbOfPersonsSharingTheFamilyMeal_;

 // //  Page: Physical exam at admission

  // // Section: Physical_exam -- methods
 QString L_pleaseCheckInvitalsBiometricsFortemperaturerRateweightheightAndmuacAndAddTodaysMeasurements_;
 QPlainTextEdit* pleaseCheckInvitalsBiometricsFortemperaturerRateweightheightAndmuacAndAddTodaysMeasurements_;
 QString L_capturePatientVitals_;
 NRE_Workspace_Launcher_Button* capturePatientVitals_;
 QString L_whz_;
 NRE_Radio_Button_Group_Box* whz_;
 QString L_oedema_;
 NRE_Radio_Button_Group_Box* oedema_;

 // //  Page: Evaluation

  // // Section: Target -- methods
 QString L_targetWeightOrMuac_;
 QLineEdit* targetWeightOrMuac_;

  // // Section: Malaria_test -- methods
 QString L_malariaTestResult_;
 NRE_Radio_Button_Group_Box* malariaTestResult_;

  // // Section: TB_evaluation -- methods
 QString L_tbEvaluation_;
 NRE_Radio_Button_Group_Box* tbEvaluation_;
 QString L_firstResultScore_;
 NRE_Radio_Button_Group_Box* firstResultScore_;
 QString L_firstResultDate_;
 QDateEdit* firstResultDate_;
 QString L_secondResultScore_;
 NRE_Radio_Button_Group_Box* secondResultScore_;
 QString L_secondResultDate_;
 QDateEdit* secondResultDate_;

 // //  Page: Observations

  // // Section: Observations -- methods
 QString L_observations_;
 QPlainTextEdit* observations_;

 // //  Page: Diagnosis

  // // Section: Diagnosis -- methods
 QString L_mainDiagnosisAtAdmission_;
 NRE_Combo_With_Label_Bar* mainDiagnosisAtAdmission_;
 QString L_mainDiagnosisAtAdmission_ifOtherSpecify_;
 QLineEdit* mainDiagnosisAtAdmission_ifOtherSpecify_;
 QString L_diagnosisAtAdmissionSecondary1_;
 NRE_Combo_With_Label_Bar* diagnosisAtAdmissionSecondary1_;
 QString L_diagnosisAtAdmissionSecondary1_ifOtherSpecify_;
 QLineEdit* diagnosisAtAdmissionSecondary1_ifOtherSpecify_;
 QString L_diagnosisAtAdmissionSecondary2_;
 NRE_Combo_With_Label_Bar* diagnosisAtAdmissionSecondary2_;
 QString L_diagnosisAtAdmissionSecondary2_ifOtherSpecify_;
 QLineEdit* diagnosisAtAdmissionSecondary2_ifOtherSpecify_;
 QString L_diagnosisAtAdmissionSecondary3_;
 NRE_Combo_With_Label_Bar* diagnosisAtAdmissionSecondary3_;
 QString L_diagnosisAtAdmissionSecondary3_ifOtherSpecify_;
 QLineEdit* diagnosisAtAdmissionSecondary3_ifOtherSpecify_;

 // //  Page: Prescription

  // // Section: Prescription -- methods
 QString L_pleaseStartTheFeedingForm_;
 QPlainTextEdit* pleaseStartTheFeedingForm_;
 QString L_pleaseCheckInImmunizations_;
 QPlainTextEdit* pleaseCheckInImmunizations_;
 QString L_capturePatientImmunizations_;
 NRE_Workspace_Launcher_Button* capturePatientImmunizations_;
 QString L_pleaseCheckInMedications_;
 QPlainTextEdit* pleaseCheckInMedications_;
 QString L_activeMedications_;
 NRE_Workspace_Launcher_Button* activeMedications_;
 QString L_prescribeNewExamsAndMedicationWithTheOrderBasketIfNecessary_;
 QPlainTextEdit* prescribeNewExamsAndMedicationWithTheOrderBasketIfNecessary_;
 QString L_orderMedications_;
 NRE_Workspace_Launcher_Button* orderMedications_;
// //<-- methods
// //--> labels
 void init_labels();

 // //  Page: Admission

  // // Section: Admission_data -> labels

 // //  Page: Anamnesis at admission

  // // Section: History_of_the_illness -> labels

  // // Section: Feeding_history -> labels

  // // Section: Family_history -> labels

 // //  Page: Physical exam at admission

  // // Section: Physical_exam -> labels

 // //  Page: Evaluation

  // // Section: Target -> labels

  // // Section: Malaria_test -> labels

  // // Section: TB_evaluation -> labels

 // //  Page: Observations

  // // Section: Observations -> labels

 // //  Page: Diagnosis

  // // Section: Diagnosis -> labels

 // //  Page: Prescription

  // // Section: Prescription -> labels
// //<-- labels
// //--> concepts
 void init_concepts();

 // //  Page: Admission

  // // Section: Admission_data -> concepts

 // //  Page: Anamnesis at admission

  // // Section: History_of_the_illness -> concepts

  // // Section: Feeding_history -> concepts

  // // Section: Family_history -> concepts

 // //  Page: Physical exam at admission

  // // Section: Physical_exam -> concepts

 // //  Page: Evaluation

  // // Section: Target -> concepts

  // // Section: Malaria_test -> concepts

  // // Section: TB_evaluation -> concepts

 // //  Page: Observations

  // // Section: Observations -> concepts

 // //  Page: Diagnosis

  // // Section: Diagnosis -> concepts

 // //  Page: Prescription

  // // Section: Prescription -> concepts
// //<-- concepts
// //--> sf
 void init_sf();

 // //  Page: Admission

 // //  Page: Anamnesis at admission

 // //  Page: Physical exam at admission

 // //  Page: Evaluation

 // //  Page: Observations

 // //  Page: Diagnosis

 // //  Page: Prescription
// //<-- sf


}; // end class


_KANS(AMPATH_Forms)

#endif // __H guard
