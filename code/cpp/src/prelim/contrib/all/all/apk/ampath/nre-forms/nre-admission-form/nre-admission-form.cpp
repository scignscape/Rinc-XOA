
//           Copyright Nathaniel Christen 2026.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#include "nre-controls/nre-accordion-list/nre-accordion-list.h"
#include "nre-controls/nre-combo/nre-combo-with-label-bar.h"
#include "nre-controls/nre-button-group-box/nre-radio-button-group-box.h"


#include "nre-admission-form.h"

USING_KANS(AMPATH_Forms)

// //--> ctor
NRE_Admission_Form::NRE_Admission_Form()
{

 pages_tab_widget_ = new QTabWidget(this);
 init_labels();
 setCentralWidget(pages_tab_widget_);
 pages_tab_widget_->show();


 // //  Page: Admission
 F_100_ = new QFrame;
 F_100_vbl_ = new QVBoxLayout;
 F_100_->setLayout(F_100_vbl_);
 S_100_ = new QScrollArea;
 pages_tab_widget_->addTab(S_100_, "Admission");

  // // Section: Admission_data -- ctor
 Admission_data_F100_ = new NRE_Accordion_List(F_100_);
 F_100_vbl_->addWidget(Admission_data_F100_);
 F_100_vbl_->addSpacing(19);
 Admission_data_F100_->set_text("Admission_data");
 Admission_data_F100_->set_enclosing_scroll_area(S_100_);
 caretakersName_ = new QLineEdit(Admission_data_F100_);
 Admission_data_F100_->add_horizontal_item(L_caretakersName_,
   caretakersName_);
 admissionDateAndTime_ = new QDateTimeEdit(Admission_data_F100_);
 Admission_data_F100_->add_horizontal_item(L_admissionDateAndTime_,
   admissionDateAndTime_);
 admissionType_ = new NRE_Radio_Button_Group_Box(Admission_data_F100_);
 Admission_data_F100_->add_vertical_item(L_admissionType_,
   admissionType_);
 spontaneousAdmission_ = new NRE_Radio_Button_Group_Box(Admission_data_F100_);
 Admission_data_F100_->add_vertical_item(L_spontaneousAdmission_,
   spontaneousAdmission_);
 ifReferredByWhomOrFromWhere_ = new NRE_Radio_Button_Group_Box(Admission_data_F100_);
 Admission_data_F100_->add_vertical_item(L_ifReferredByWhomOrFromWhere_,
   ifReferredByWhomOrFromWhere_);
 ifReferredByWhomOrFromWhere_ifOtherSpecify_ = new QLineEdit(Admission_data_F100_);
 Admission_data_F100_->add_horizontal_item(L_ifReferredByWhomOrFromWhere_ifOtherSpecify_,
   ifReferredByWhomOrFromWhere_ifOtherSpecify_);

 // //  Page: Anamnesis at admission
 F_101_ = new QFrame;
 F_101_vbl_ = new QVBoxLayout;
 F_101_->setLayout(F_101_vbl_);
 S_101_ = new QScrollArea;
 pages_tab_widget_->addTab(S_101_, "Anamnesis at admission");

  // // Section: History_of_the_illness -- ctor
 History_of_the_illness_F101_ = new NRE_Accordion_List(F_101_);
 F_101_vbl_->addWidget(History_of_the_illness_F101_);
 F_101_vbl_->addSpacing(19);
 History_of_the_illness_F101_->set_text("History_of_the_illness");
 History_of_the_illness_F101_->set_enclosing_scroll_area(S_101_);
 howLongHasTheChildBeenSick_ = new QLineEdit(History_of_the_illness_F101_);
 howLongHasTheChildBeenSick_->setPlaceholderText(0);
 History_of_the_illness_F101_->add_horizontal_item(L_howLongHasTheChildBeenSick_,
   howLongHasTheChildBeenSick_);
 whatAreTheProblemsReportedByTheCaretaker_ = new QPlainTextEdit(History_of_the_illness_F101_);
 History_of_the_illness_F101_->add_vertical_item(L_whatAreTheProblemsReportedByTheCaretaker_,
   whatAreTheProblemsReportedByTheCaretaker_);
 isThereSomeoneInTheFamilyCoughingForMoreThanOneMonth_ = new NRE_Radio_Button_Group_Box(History_of_the_illness_F101_);
 History_of_the_illness_F101_->add_vertical_item(L_isThereSomeoneInTheFamilyCoughingForMoreThanOneMonth_,
   isThereSomeoneInTheFamilyCoughingForMoreThanOneMonth_);
 isThereSomeoneInTheFamilyCoughingForMoreThanOneMonth_specifyWho_ = new QLineEdit(History_of_the_illness_F101_);
 History_of_the_illness_F101_->add_horizontal_item(L_isThereSomeoneInTheFamilyCoughingForMoreThanOneMonth_specifyWho_,
   isThereSomeoneInTheFamilyCoughingForMoreThanOneMonth_specifyWho_);
 isThereSomeoneTreatedForTbSinceTheBirthOfTheChild_ = new NRE_Radio_Button_Group_Box(History_of_the_illness_F101_);
 History_of_the_illness_F101_->add_vertical_item(L_isThereSomeoneTreatedForTbSinceTheBirthOfTheChild_,
   isThereSomeoneTreatedForTbSinceTheBirthOfTheChild_);
 isThereSomeoneTreatedForTbSinceTheBirthOfTheChild_specifyWho_ = new QLineEdit(History_of_the_illness_F101_);
 History_of_the_illness_F101_->add_horizontal_item(L_isThereSomeoneTreatedForTbSinceTheBirthOfTheChild_specifyWho_,
   isThereSomeoneTreatedForTbSinceTheBirthOfTheChild_specifyWho_);

  // // Section: Feeding_history -- ctor
 Feeding_history_F101_ = new NRE_Accordion_List(F_101_);
 F_101_vbl_->addWidget(Feeding_history_F101_);
 F_101_vbl_->addSpacing(19);
 Feeding_history_F101_->set_text("Feeding_history");
 Feeding_history_F101_->set_enclosing_scroll_area(S_101_);
 hasTheChildEverBeenBreastfed_ = new NRE_Radio_Button_Group_Box(Feeding_history_F101_);
 Feeding_history_F101_->add_vertical_item(L_hasTheChildEverBeenBreastfed_,
   hasTheChildEverBeenBreastfed_);
 isTheChildCurrentlyBeingBreastfed_ = new NRE_Radio_Button_Group_Box(Feeding_history_F101_);
 Feeding_history_F101_->add_vertical_item(L_isTheChildCurrentlyBeingBreastfed_,
   isTheChildCurrentlyBeingBreastfed_);
 atWhatAgeDidYouIntroduceSolidFood_ = new QLineEdit(Feeding_history_F101_);
 Feeding_history_F101_->add_horizontal_item(L_atWhatAgeDidYouIntroduceSolidFood_,
   atWhatAgeDidYouIntroduceSolidFood_);
 typeOfMealsBeforeIllness_ = new QLineEdit(Feeding_history_F101_);
 Feeding_history_F101_->add_horizontal_item(L_typeOfMealsBeforeIllness_,
   typeOfMealsBeforeIllness_);
 numberOfMealsPerDayBeforeIllness_ = new QLineEdit(Feeding_history_F101_);
 numberOfMealsPerDayBeforeIllness_->setPlaceholderText(0);
 Feeding_history_F101_->add_horizontal_item(L_numberOfMealsPerDayBeforeIllness_,
   numberOfMealsPerDayBeforeIllness_);
 numberOfMealsDuringTheLast24Hours_ = new QLineEdit(Feeding_history_F101_);
 numberOfMealsDuringTheLast24Hours_->setPlaceholderText(0);
 Feeding_history_F101_->add_horizontal_item(L_numberOfMealsDuringTheLast24Hours_,
   numberOfMealsDuringTheLast24Hours_);

  // // Section: Family_history -- ctor
 Family_history_F101_ = new NRE_Accordion_List(F_101_);
 F_101_vbl_->addWidget(Family_history_F101_);
 F_101_vbl_->addSpacing(19);
 Family_history_F101_->set_text("Family_history");
 Family_history_F101_->set_enclosing_scroll_area(S_101_);
 whoIsTheHeadOfFamily_ = new NRE_Radio_Button_Group_Box(Family_history_F101_);
 Family_history_F101_->add_vertical_item(L_whoIsTheHeadOfFamily_,
   whoIsTheHeadOfFamily_);
 whoIsTheHeadOfFamily_ifOtherSpecify_ = new QLineEdit(Family_history_F101_);
 Family_history_F101_->add_horizontal_item(L_whoIsTheHeadOfFamily_ifOtherSpecify_,
   whoIsTheHeadOfFamily_ifOtherSpecify_);
 isTheMotherAlive_ = new NRE_Radio_Button_Group_Box(Family_history_F101_);
 Family_history_F101_->add_vertical_item(L_isTheMotherAlive_,
   isTheMotherAlive_);
 whoIsTakingCareOfTheChild_ = new QLineEdit(Family_history_F101_);
 Family_history_F101_->add_horizontal_item(L_whoIsTakingCareOfTheChild_,
   whoIsTakingCareOfTheChild_);
 numberOfBirthsForTheMother_ = new QLineEdit(Family_history_F101_);
 numberOfBirthsForTheMother_->setPlaceholderText(0);
 Family_history_F101_->add_horizontal_item(L_numberOfBirthsForTheMother_,
   numberOfBirthsForTheMother_);
 numberOfMothersChildrenAlive_ = new QLineEdit(Family_history_F101_);
 numberOfMothersChildrenAlive_->setPlaceholderText(0);
 Family_history_F101_->add_horizontal_item(L_numberOfMothersChildrenAlive_,
   numberOfMothersChildrenAlive_);
 rankInTheBirthOrder_ = new QLineEdit(Family_history_F101_);
 rankInTheBirthOrder_->setPlaceholderText(0);
 Family_history_F101_->add_horizontal_item(L_rankInTheBirthOrder_,
   rankInTheBirthOrder_);
 theChildIs_ = new NRE_Combo_With_Label_Bar(Family_history_F101_);
 Family_history_F101_->add_vertical_item(L_theChildIs_,
   theChildIs_);
 nbOfPersonsSharingTheFamilyMeal_ = new QLineEdit(Family_history_F101_);
 nbOfPersonsSharingTheFamilyMeal_->setPlaceholderText(0);
 Family_history_F101_->add_horizontal_item(L_nbOfPersonsSharingTheFamilyMeal_,
   nbOfPersonsSharingTheFamilyMeal_);

 // //  Page: Physical exam at admission
 F_102_ = new QFrame;
 F_102_vbl_ = new QVBoxLayout;
 F_102_->setLayout(F_102_vbl_);
 S_102_ = new QScrollArea;
 pages_tab_widget_->addTab(S_102_, "Physical exam at admission");

  // // Section: Physical_exam -- ctor
 Physical_exam_F102_ = new NRE_Accordion_List(F_102_);
 F_102_vbl_->addWidget(Physical_exam_F102_);
 F_102_vbl_->addSpacing(19);
 Physical_exam_F102_->set_text("Physical_exam");
 Physical_exam_F102_->set_enclosing_scroll_area(S_102_);
 pleaseCheckInvitalsBiometricsFortemperaturerRateweightheightAndmuacAndAddTodaysMeasurements_ = new QPlainTextEdit(Physical_exam_F102_);
 Physical_exam_F102_->add_vertical_item(L_pleaseCheckInvitalsBiometricsFortemperaturerRateweightheightAndmuacAndAddTodaysMeasurements_,
   pleaseCheckInvitalsBiometricsFortemperaturerRateweightheightAndmuacAndAddTodaysMeasurements_);
 capturePatientVitals_ = new NRE_Combo_With_Label_Bar(Physical_exam_F102_);
 capturePatientVitals_->set_max_selectable(1);
 Physical_exam_F102_->add_vertical_item(L_capturePatientVitals_,
   capturePatientVitals_);
 whz_ = new NRE_Radio_Button_Group_Box(Physical_exam_F102_);
 Physical_exam_F102_->add_vertical_item(L_whz_,
   whz_);
 oedema_ = new NRE_Radio_Button_Group_Box(Physical_exam_F102_);
 Physical_exam_F102_->add_vertical_item(L_oedema_,
   oedema_);

 // //  Page: Evaluation
 F_103_ = new QFrame;
 F_103_vbl_ = new QVBoxLayout;
 F_103_->setLayout(F_103_vbl_);
 S_103_ = new QScrollArea;
 pages_tab_widget_->addTab(S_103_, "Evaluation");

  // // Section: Target -- ctor
 Target_F103_ = new NRE_Accordion_List(F_103_);
 F_103_vbl_->addWidget(Target_F103_);
 F_103_vbl_->addSpacing(19);
 Target_F103_->set_text("Target");
 Target_F103_->set_enclosing_scroll_area(S_103_);
 targetWeightOrMuac_ = new QLineEdit(Target_F103_);
 Target_F103_->add_horizontal_item(L_targetWeightOrMuac_,
   targetWeightOrMuac_);

  // // Section: Malaria_test -- ctor
 Malaria_test_F103_ = new NRE_Accordion_List(F_103_);
 F_103_vbl_->addWidget(Malaria_test_F103_);
 F_103_vbl_->addSpacing(19);
 Malaria_test_F103_->set_text("Malaria_test");
 Malaria_test_F103_->set_enclosing_scroll_area(S_103_);
 malariaTestResult_ = new NRE_Radio_Button_Group_Box(Malaria_test_F103_);
 Malaria_test_F103_->add_vertical_item(L_malariaTestResult_,
   malariaTestResult_);

  // // Section: TB_evaluation -- ctor
 TB_evaluation_F103_ = new NRE_Accordion_List(F_103_);
 F_103_vbl_->addWidget(TB_evaluation_F103_);
 F_103_vbl_->addSpacing(19);
 TB_evaluation_F103_->set_text("TB_evaluation");
 TB_evaluation_F103_->set_enclosing_scroll_area(S_103_);
 tbEvaluation_ = new NRE_Radio_Button_Group_Box(TB_evaluation_F103_);
 TB_evaluation_F103_->add_vertical_item(L_tbEvaluation_,
   tbEvaluation_);
 firstResultScore_ = new NRE_Radio_Button_Group_Box(TB_evaluation_F103_);
 TB_evaluation_F103_->add_vertical_item(L_firstResultScore_,
   firstResultScore_);
 firstResultDate_ = new QDateEdit(TB_evaluation_F103_);
 TB_evaluation_F103_->add_horizontal_item(L_firstResultDate_,
   firstResultDate_);
 secondResultScore_ = new NRE_Radio_Button_Group_Box(TB_evaluation_F103_);
 TB_evaluation_F103_->add_vertical_item(L_secondResultScore_,
   secondResultScore_);
 secondResultDate_ = new QDateEdit(TB_evaluation_F103_);
 TB_evaluation_F103_->add_horizontal_item(L_secondResultDate_,
   secondResultDate_);

 // //  Page: Observations
 F_104_ = new QFrame;
 F_104_vbl_ = new QVBoxLayout;
 F_104_->setLayout(F_104_vbl_);
 S_104_ = new QScrollArea;
 pages_tab_widget_->addTab(S_104_, "Observations");

  // // Section: Observations -- ctor
 Observations_F104_ = new NRE_Accordion_List(F_104_);
 F_104_vbl_->addWidget(Observations_F104_);
 F_104_vbl_->addSpacing(19);
 Observations_F104_->set_text("Observations");
 Observations_F104_->set_enclosing_scroll_area(S_104_);
 observations_ = new QPlainTextEdit(Observations_F104_);
 Observations_F104_->add_vertical_item(L_observations_,
   observations_);

 // //  Page: Diagnosis
 F_105_ = new QFrame;
 F_105_vbl_ = new QVBoxLayout;
 F_105_->setLayout(F_105_vbl_);
 S_105_ = new QScrollArea;
 pages_tab_widget_->addTab(S_105_, "Diagnosis");

  // // Section: Diagnosis -- ctor
 Diagnosis_F105_ = new NRE_Accordion_List(F_105_);
 F_105_vbl_->addWidget(Diagnosis_F105_);
 F_105_vbl_->addSpacing(19);
 Diagnosis_F105_->set_text("Diagnosis");
 Diagnosis_F105_->set_enclosing_scroll_area(S_105_);
 mainDiagnosisAtAdmission_ = new NRE_Combo_With_Label_Bar(Diagnosis_F105_);
 mainDiagnosisAtAdmission_->set_max_selectable(1);
 Diagnosis_F105_->add_vertical_item(L_mainDiagnosisAtAdmission_,
   mainDiagnosisAtAdmission_);
 mainDiagnosisAtAdmission_ifOtherSpecify_ = new QLineEdit(Diagnosis_F105_);
 Diagnosis_F105_->add_horizontal_item(L_mainDiagnosisAtAdmission_ifOtherSpecify_,
   mainDiagnosisAtAdmission_ifOtherSpecify_);
 diagnosisAtAdmissionSecondary1_ = new NRE_Combo_With_Label_Bar(Diagnosis_F105_);
 diagnosisAtAdmissionSecondary1_->set_max_selectable(1);
 Diagnosis_F105_->add_vertical_item(L_diagnosisAtAdmissionSecondary1_,
   diagnosisAtAdmissionSecondary1_);
 diagnosisAtAdmissionSecondary1_ifOtherSpecify_ = new QLineEdit(Diagnosis_F105_);
 Diagnosis_F105_->add_horizontal_item(L_diagnosisAtAdmissionSecondary1_ifOtherSpecify_,
   diagnosisAtAdmissionSecondary1_ifOtherSpecify_);
 diagnosisAtAdmissionSecondary2_ = new NRE_Combo_With_Label_Bar(Diagnosis_F105_);
 diagnosisAtAdmissionSecondary2_->set_max_selectable(1);
 Diagnosis_F105_->add_vertical_item(L_diagnosisAtAdmissionSecondary2_,
   diagnosisAtAdmissionSecondary2_);
 diagnosisAtAdmissionSecondary2_ifOtherSpecify_ = new QLineEdit(Diagnosis_F105_);
 Diagnosis_F105_->add_horizontal_item(L_diagnosisAtAdmissionSecondary2_ifOtherSpecify_,
   diagnosisAtAdmissionSecondary2_ifOtherSpecify_);
 diagnosisAtAdmissionSecondary3_ = new NRE_Combo_With_Label_Bar(Diagnosis_F105_);
 diagnosisAtAdmissionSecondary3_->set_max_selectable(1);
 Diagnosis_F105_->add_vertical_item(L_diagnosisAtAdmissionSecondary3_,
   diagnosisAtAdmissionSecondary3_);
 diagnosisAtAdmissionSecondary3_ifOtherSpecify_ = new QLineEdit(Diagnosis_F105_);
 Diagnosis_F105_->add_horizontal_item(L_diagnosisAtAdmissionSecondary3_ifOtherSpecify_,
   diagnosisAtAdmissionSecondary3_ifOtherSpecify_);

 // //  Page: Prescription
 F_106_ = new QFrame;
 F_106_vbl_ = new QVBoxLayout;
 F_106_->setLayout(F_106_vbl_);
 S_106_ = new QScrollArea;
 pages_tab_widget_->addTab(S_106_, "Prescription");

  // // Section: Prescription -- ctor
 Prescription_F106_ = new NRE_Accordion_List(F_106_);
 F_106_vbl_->addWidget(Prescription_F106_);
 F_106_vbl_->addSpacing(19);
 Prescription_F106_->set_text("Prescription");
 Prescription_F106_->set_enclosing_scroll_area(S_106_);
 pleaseStartTheFeedingForm_ = new QPlainTextEdit(Prescription_F106_);
 Prescription_F106_->add_vertical_item(L_pleaseStartTheFeedingForm_,
   pleaseStartTheFeedingForm_);
 pleaseCheckInImmunizations_ = new QPlainTextEdit(Prescription_F106_);
 Prescription_F106_->add_vertical_item(L_pleaseCheckInImmunizations_,
   pleaseCheckInImmunizations_);
 capturePatientImmunizations_ = new NRE_Combo_With_Label_Bar(Prescription_F106_);
 capturePatientImmunizations_->set_max_selectable(1);
 Prescription_F106_->add_vertical_item(L_capturePatientImmunizations_,
   capturePatientImmunizations_);
 pleaseCheckInMedications_ = new QPlainTextEdit(Prescription_F106_);
 Prescription_F106_->add_vertical_item(L_pleaseCheckInMedications_,
   pleaseCheckInMedications_);
 activeMedications_ = new NRE_Combo_With_Label_Bar(Prescription_F106_);
 activeMedications_->set_max_selectable(1);
 Prescription_F106_->add_vertical_item(L_activeMedications_,
   activeMedications_);
 prescribeNewExamsAndMedicationWithTheOrderBasketIfNecessary_ = new QPlainTextEdit(Prescription_F106_);
 Prescription_F106_->add_vertical_item(L_prescribeNewExamsAndMedicationWithTheOrderBasketIfNecessary_,
   prescribeNewExamsAndMedicationWithTheOrderBasketIfNecessary_);
 orderMedications_ = new NRE_Combo_With_Label_Bar(Prescription_F106_);
 orderMedications_->set_max_selectable(1);
 Prescription_F106_->add_vertical_item(L_orderMedications_,
   orderMedications_);

 init();

}// ::NRE_Admission_Form


// //<-- ctor
// //--> init
void NRE_Admission_Form::init()
{


 // //  Page: Admission
 S_100_->setWidget(F_100_);

  // // Section: Admission_data -- init
 Admission_data_F100_->collapse();


 // //  Page: Anamnesis at admission
 S_101_->setWidget(F_101_);

  // // Section: History_of_the_illness -- init
 History_of_the_illness_F101_->collapse();


  // // Section: Feeding_history -- init
 Feeding_history_F101_->collapse();


  // // Section: Family_history -- init
 Family_history_F101_->collapse();


 // //  Page: Physical exam at admission
 S_102_->setWidget(F_102_);

  // // Section: Physical_exam -- init
 Physical_exam_F102_->collapse();


 // //  Page: Evaluation
 S_103_->setWidget(F_103_);

  // // Section: Target -- init
 Target_F103_->collapse();


  // // Section: Malaria_test -- init
 Malaria_test_F103_->collapse();


  // // Section: TB_evaluation -- init
 TB_evaluation_F103_->collapse();


 // //  Page: Observations
 S_104_->setWidget(F_104_);

  // // Section: Observations -- init
 Observations_F104_->collapse();


 // //  Page: Diagnosis
 S_105_->setWidget(F_105_);

  // // Section: Diagnosis -- init
 Diagnosis_F105_->collapse();


 // //  Page: Prescription
 S_106_->setWidget(F_106_);

  // // Section: Prescription -- init
 Prescription_F106_->collapse();

}// ::init


// //<-- init
// //--> methods

 // //  Page: Admission

  // // Section: Admission_data -- methods

 // //  Page: Anamnesis at admission

  // // Section: History_of_the_illness -- methods

  // // Section: Feeding_history -- methods

  // // Section: Family_history -- methods

 // //  Page: Physical exam at admission

  // // Section: Physical_exam -- methods

 // //  Page: Evaluation

  // // Section: Target -- methods

  // // Section: Malaria_test -- methods

  // // Section: TB_evaluation -- methods

 // //  Page: Observations

  // // Section: Observations -- methods

 // //  Page: Diagnosis

  // // Section: Diagnosis -- methods

 // //  Page: Prescription

  // // Section: Prescription -- methods
// //<-- methods
// //--> labels
void NRE_Admission_Form::init_labels()
{


 // //  Page: Admission

  // // Section: Admission_data -- labels
 L_caretakersName_ = "Caretaker's name";
 L_admissionDateAndTime_ = "Admission date and time";
 L_admissionType_ = "Admission type";
 L_spontaneousAdmission_ = "Spontaneous admission";
 L_ifReferredByWhomOrFromWhere_ = "If referred, by whom/from where";
 L_ifReferredByWhomOrFromWhere_ifOtherSpecify_ = "If other, specify";

 // //  Page: Anamnesis at admission

  // // Section: History_of_the_illness -- labels
 L_howLongHasTheChildBeenSick_ = "How long has the child been sick? (in days)";
 L_whatAreTheProblemsReportedByTheCaretaker_ = "What are the problems reported by the caretaker?";
 L_isThereSomeoneInTheFamilyCoughingForMoreThanOneMonth_ = "Is there someone in the family coughing for more than one month?";
 L_isThereSomeoneInTheFamilyCoughingForMoreThanOneMonth_specifyWho_ = "Specify who";
 L_isThereSomeoneTreatedForTbSinceTheBirthOfTheChild_ = "Is there someone treated for TB since the birth of the child?";
 L_isThereSomeoneTreatedForTbSinceTheBirthOfTheChild_specifyWho_ = "Specify who";

  // // Section: Feeding_history -- labels
 L_hasTheChildEverBeenBreastfed_ = "Has the child ever been breastfed?";
 L_isTheChildCurrentlyBeingBreastfed_ = "Is the child currently being breastfed?";
 L_atWhatAgeDidYouIntroduceSolidFood_ = "At what age did you introduce solid food?";
 L_typeOfMealsBeforeIllness_ = "Type of meals before illness (breastfeeding, porridge, vegetables, etc.)";
 L_numberOfMealsPerDayBeforeIllness_ = "Number of meals per day before illness";
 L_numberOfMealsDuringTheLast24Hours_ = "Number of meals during the last 24 hours";

  // // Section: Family_history -- labels
 L_whoIsTheHeadOfFamily_ = "Who is the head of family?";
 L_whoIsTheHeadOfFamily_ifOtherSpecify_ = "If other, specify";
 L_isTheMotherAlive_ = "Is the mother alive?";
 L_whoIsTakingCareOfTheChild_ = "Who is taking care of the child?";
 L_numberOfBirthsForTheMother_ = "Number of births for the mother";
 L_numberOfMothersChildrenAlive_ = "Number of mother's children alive";
 L_rankInTheBirthOrder_ = "Rank in the birth order";
 L_theChildIs_ = "The child is";
 L_nbOfPersonsSharingTheFamilyMeal_ = "Nb of persons sharing the family meal";

 // //  Page: Physical exam at admission

  // // Section: Physical_exam -- labels
 L_pleaseCheckInvitalsBiometricsFortemperaturerRateweightheightAndmuacAndAddTodaysMeasurements_ = "Please check in 'Vitals & Biometrics' for 'Temperature', 'R. rate' 'Weight', 'Height' and 'MUAC' AND add today's measurements";
 L_capturePatientVitals_ = "Capture patient vitals";
 L_whz_ = "WHZ";
 L_oedema_ = "Oedema";

 // //  Page: Evaluation

  // // Section: Target -- labels
 L_targetWeightOrMuac_ = "Target weight / MUAC";

  // // Section: Malaria_test -- labels
 L_malariaTestResult_ = "Malaria test - result";

  // // Section: TB_evaluation -- labels
 L_tbEvaluation_ = "TB evaluation (ex: crofton)";
 L_firstResultScore_ = "First result - score";
 L_firstResultDate_ = "First result - date";
 L_secondResultScore_ = "Second result - score";
 L_secondResultDate_ = "Second result - date";

 // //  Page: Observations

  // // Section: Observations -- labels
 L_observations_ = "Observations";

 // //  Page: Diagnosis

  // // Section: Diagnosis -- labels
 L_mainDiagnosisAtAdmission_ = "Main diagnosis at admission";
 L_mainDiagnosisAtAdmission_ifOtherSpecify_ = "If other, specify";
 L_diagnosisAtAdmissionSecondary1_ = "Diagnosis at admission - Secondary 1";
 L_diagnosisAtAdmissionSecondary1_ifOtherSpecify_ = "If other, specify";
 L_diagnosisAtAdmissionSecondary2_ = "Diagnosis at admission - Secondary 2";
 L_diagnosisAtAdmissionSecondary2_ifOtherSpecify_ = "If other, specify";
 L_diagnosisAtAdmissionSecondary3_ = "Diagnosis at admission - Secondary 3";
 L_diagnosisAtAdmissionSecondary3_ifOtherSpecify_ = "If other, specify";

 // //  Page: Prescription

  // // Section: Prescription -- labels
 L_pleaseStartTheFeedingForm_ = "Please start the 'Feeding form'";
 L_pleaseCheckInImmunizations_ = "Please check in 'Immunizations' (update it if necessary)";
 L_capturePatientImmunizations_ = "Capture patient immunizations";
 L_pleaseCheckInMedications_ = "Please check in 'Medications' (update it if necessary)";
 L_activeMedications_ = "Active medications";
 L_prescribeNewExamsAndMedicationWithTheOrderBasketIfNecessary_ = "Prescribe new exams and medication with the order basket if necessary";
 L_orderMedications_ = "Order medications";
}// ::init_labels


// //<-- labels
// //--> concepts
void NRE_Admission_Form::init_concepts()
{


 // //  Page: Admission

  // // Section: Admission_data -- concepts
 caretakersName_->setProperty("ocl-concept", QVariant("3d039785-f0f6-4a52-bd96-e8362ec6c55f"));
 admissionDateAndTime_->setProperty("ocl-concept", QVariant("7f00c65d-de60-467a-8964-fe80c7a85ef0"));
 admissionType_->setProperty("ocl-concept", QVariant("4dae5b12-070f-4153-b1ca-fbec906106e1"));
 spontaneousAdmission_->setProperty("ocl-concept", QVariant("552ad8cb-35de-4d61-ab8c-5c7b698a573a"));
 ifReferredByWhomOrFromWhere_->setProperty("ocl-concept", QVariant("93eb9716-6866-4d13-9b8f-59c0a7605a11"));
 ifReferredByWhomOrFromWhere_ifOtherSpecify_->setProperty("ocl-concept", QVariant("790b41ce-e1e7-11e8-b02f-0242ac130002"));

 // //  Page: Anamnesis at admission

  // // Section: History_of_the_illness -- concepts
 howLongHasTheChildBeenSick_->setProperty("ocl-concept", QVariant("61f620e5-704f-4674-954e-20b7175240dd"));
 whatAreTheProblemsReportedByTheCaretaker_->setProperty("ocl-concept", QVariant("10cbe6dd-2d3d-40d2-99ea-2e9ea7d0dd7a"));
 isThereSomeoneInTheFamilyCoughingForMoreThanOneMonth_->setProperty("ocl-concept", QVariant("acac8976-3e7f-48eb-9700-e7d41b9e4342"));
 isThereSomeoneInTheFamilyCoughingForMoreThanOneMonth_specifyWho_->setProperty("ocl-concept", QVariant("903fb769-4ea4-4f54-b1b4-aa80bf473b91"));
 isThereSomeoneTreatedForTbSinceTheBirthOfTheChild_->setProperty("ocl-concept", QVariant("465ac93f-2c89-45a9-a83a-140fd1c4ad5c"));
 isThereSomeoneTreatedForTbSinceTheBirthOfTheChild_specifyWho_->setProperty("ocl-concept", QVariant("00e8f84b-0934-45b8-9a91-71c5ab2d1a74"));

  // // Section: Feeding_history -- concepts
 hasTheChildEverBeenBreastfed_->setProperty("ocl-concept", QVariant("53fe57e7-07cc-40e8-b144-c4d69dd878cd"));
 isTheChildCurrentlyBeingBreastfed_->setProperty("ocl-concept", QVariant("2bf8abde-27ee-42ba-8381-5f33fe417081"));
 atWhatAgeDidYouIntroduceSolidFood_->setProperty("ocl-concept", QVariant("0c2209ad-068a-4965-b28b-b42f180ae075"));
 typeOfMealsBeforeIllness_->setProperty("ocl-concept", QVariant("2cdeae3a-911a-4427-85f5-8ed9b9e265ed"));
 numberOfMealsPerDayBeforeIllness_->setProperty("ocl-concept", QVariant("04905c5a-1c7e-4113-a296-70517c6ec27e"));
 numberOfMealsDuringTheLast24Hours_->setProperty("ocl-concept", QVariant("3fdddaa7-1583-4bc2-b81c-de592b4c0e31"));

  // // Section: Family_history -- concepts
 whoIsTheHeadOfFamily_->setProperty("ocl-concept", QVariant("a7160850-5bf6-4d39-a1ff-2a769f716e17"));
 whoIsTheHeadOfFamily_ifOtherSpecify_->setProperty("ocl-concept", QVariant("790b41ce-e1e7-11e8-b02f-0242ac130002"));
 isTheMotherAlive_->setProperty("ocl-concept", QVariant("72a7acea-8d6a-4c5b-8383-9e2150ea93ac"));
 whoIsTakingCareOfTheChild_->setProperty("ocl-concept", QVariant("84bf2d2a-854b-4f3a-b702-3b7b5e65c815"));
 numberOfBirthsForTheMother_->setProperty("ocl-concept", QVariant("76a96d44-00f5-469f-9329-5a53409a87eb"));
 numberOfMothersChildrenAlive_->setProperty("ocl-concept", QVariant("bfaee905-6a8f-4b4d-b66b-fe020d1ca3d8"));
 rankInTheBirthOrder_->setProperty("ocl-concept", QVariant("42503e1b-16f2-471e-a122-c914655f6cca"));
 theChildIs_->setProperty("ocl-concept", QVariant("caed563a-0922-4df5-bb9a-95033e63cb71"));
 nbOfPersonsSharingTheFamilyMeal_->setProperty("ocl-concept", QVariant("8a4c815e-8774-4386-b22f-74c11a10aa19"));

 // //  Page: Physical exam at admission

  // // Section: Physical_exam -- concepts
 pleaseCheckInvitalsBiometricsFortemperaturerRateweightheightAndmuacAndAddTodaysMeasurements_->setProperty("ocl-concept", QVariant(""));
 capturePatientVitals_->setProperty("ocl-concept", QVariant(""));
 whz_->setProperty("ocl-concept", QVariant("2651145f-c10c-4c04-9735-791537a1fa2c"));
 oedema_->setProperty("ocl-concept", QVariant("80469ebc-e769-4edd-a9b6-ecb5c517e2db"));

 // //  Page: Evaluation

  // // Section: Target -- concepts
 targetWeightOrMuac_->setProperty("ocl-concept", QVariant("93c926ef-b9ee-437f-996e-1a5ccfb235db"));

  // // Section: Malaria_test -- concepts
 malariaTestResult_->setProperty("ocl-concept", QVariant("1fc54f92-c324-49c4-aba1-21ade7663ba0"));

  // // Section: TB_evaluation -- concepts
 tbEvaluation_->setProperty("ocl-concept", QVariant("3195e008-7a3f-4888-a2fb-18b569eaa5bc"));
 firstResultScore_->setProperty("ocl-concept", QVariant("bc0a8a73-7fd1-4548-aff0-8f0b7e9fa268"));
 firstResultDate_->setProperty("ocl-concept", QVariant("a1a51d96-87e7-4938-8d64-00701e63896a"));
 secondResultScore_->setProperty("ocl-concept", QVariant("423bfd03-6aec-4a72-ba88-c9f9671e9259"));
 secondResultDate_->setProperty("ocl-concept", QVariant("a3805bea-3355-434b-af0d-56a7181d12eb"));

 // //  Page: Observations

  // // Section: Observations -- concepts
 observations_->setProperty("ocl-concept", QVariant("ef3a4c4f-cdb4-46d1-9e85-bc8a4790a219"));

 // //  Page: Diagnosis

  // // Section: Diagnosis -- concepts
 mainDiagnosisAtAdmission_->setProperty("ocl-concept", QVariant("9da302ed-948f-4030-8f0a-a294dd3dff21"));
 mainDiagnosisAtAdmission_ifOtherSpecify_->setProperty("ocl-concept", QVariant("790b41ce-e1e7-11e8-b02f-0242ac130002"));
 diagnosisAtAdmissionSecondary1_->setProperty("ocl-concept", QVariant("3a03bdb4-4b3f-45c3-966a-97843ec88680"));
 diagnosisAtAdmissionSecondary1_ifOtherSpecify_->setProperty("ocl-concept", QVariant("790b41ce-e1e7-11e8-b02f-0242ac130002"));
 diagnosisAtAdmissionSecondary2_->setProperty("ocl-concept", QVariant("e9ff5084-8d17-48e8-a1b7-890d1b4e14b1"));
 diagnosisAtAdmissionSecondary2_ifOtherSpecify_->setProperty("ocl-concept", QVariant("790b41ce-e1e7-11e8-b02f-0242ac130002"));
 diagnosisAtAdmissionSecondary3_->setProperty("ocl-concept", QVariant("d1e43f55-4432-4a19-bf17-5a1c97b2226f"));
 diagnosisAtAdmissionSecondary3_ifOtherSpecify_->setProperty("ocl-concept", QVariant("790b41ce-e1e7-11e8-b02f-0242ac130002"));

 // //  Page: Prescription

  // // Section: Prescription -- concepts
 pleaseStartTheFeedingForm_->setProperty("ocl-concept", QVariant(""));
 pleaseCheckInImmunizations_->setProperty("ocl-concept", QVariant(""));
 capturePatientImmunizations_->setProperty("ocl-concept", QVariant(""));
 pleaseCheckInMedications_->setProperty("ocl-concept", QVariant(""));
 activeMedications_->setProperty("ocl-concept", QVariant(""));
 prescribeNewExamsAndMedicationWithTheOrderBasketIfNecessary_->setProperty("ocl-concept", QVariant(""));
 orderMedications_->setProperty("ocl-concept", QVariant(""));
}// ::init_concepts


// //<-- concepts
