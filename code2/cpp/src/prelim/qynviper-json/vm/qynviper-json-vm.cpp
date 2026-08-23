

#include "qynviper-json-vm.h"



#define STATIC_BASIC_SPACE static QChar basic_space = QChar::fromLatin1(' ');
#define STATIC_END_CONTROL static QString end_control = ";.";
#define STATIC_NEWLINE_SPACE static QChar newline_space = QChar::fromLatin1('\n');

u2 _advance_past(QString& basis, QString* skipped, int ix0 = 0)
{
 STATIC_BASIC_SPACE

 int ix1 = basis.indexOf(basic_space, ix0);

 if(ix1 == 0)
  return 0;
 if(ix1 == -1)
  return 0;

 int ix2 = ix1 + 1;

 while(basis[ix2] == basic_space)
  ++ix2;

 if(skipped)
  *skipped = basis.mid(ix0, ix1 - ix0);

 basis = basis.mid(ix2);

 return ix2;
}

u2 _advance_past_end(QString& basis, QString* skipped, int ix0 = 0)
{
 STATIC_BASIC_SPACE
 STATIC_END_CONTROL
 STATIC_NEWLINE_SPACE

 int ix1 = basis.indexOf(end_control, ix0);

 if(ix1 == 0)
  return 0;
 if(ix1 == -1)
  return 0;

 int ix01 = ix1 - 1;

 while(basis[ix01] == basic_space)
  --ix01;

 if(skipped)
  *skipped = basis.mid(ix0, ix1 - ix0);

 int ix2 = ix1 + 2;

 while(basis[ix2] == basic_space)
  ++ix2;

 if(basis[ix2] == newline_space)
  ++ix2;

 basis = basis.mid(ix2);

 return ix2;
}


u2 Qynviper_JSON_VM::advance_past_dispatch(QString& basis, QString* skipped)
{
 STATIC_BASIC_SPACE

 int ix0 = 0;

 while(basis[ix0] == basic_space)
  ++ix0;

 return _advance_past(basis, skipped, ix0);
}

u2 Qynviper_JSON_VM::advance_past_mid_control(QString& basis, QString* skipped)
{
 STATIC_BASIC_SPACE

   if(basis.startsWith(";."))
   return 0;

 return _advance_past(basis, skipped);



}

u2 Qynviper_JSON_VM::advance_past_mid_control(QString& basis, Mid_Control_Kinds& mck, Mid_Control_Coords& mcc)
{
 static QMap<QString, Mid_Control_Kinds> known_mid_controls {
  {"_$", Mid_Control_Kinds::String},
  {"$$", Mid_Control_Kinds::String_List},
  {"1#", Mid_Control_Kinds::U1},
  {"2#", Mid_Control_Kinds::U2},
  {"4#", Mid_Control_Kinds::U4},
  {"8#", Mid_Control_Kinds::U8},
  {"1#", Mid_Control_Kinds::U1},
  {"2#", Mid_Control_Kinds::U2},
  {"4#", Mid_Control_Kinds::U4},
  {"8#", Mid_Control_Kinds::U8},

 };
 QString control;
 u2 result = advance_past_mid_control(basis, &control);

 QString control_key = control.size() == 1? QString("_") + control : control.left(2);

 mck = known_mid_controls.value(control_key, Mid_Control_Kinds::N_A);

 mcc = Mid_Control_Coords::N_A;

 return result;

}


u2 Qynviper_JSON_VM::advance_past_end_control(QString& basis, QString* skipped)
{
 return _advance_past(basis, skipped);
}

u2 Qynviper_JSON_VM::advance_past_end_control(QString& basis, QStringList* skipped)
{

}

u2 Qynviper_JSON_VM::advance_past_end_control(QString& basis, quint64* skipped)
{

}

u2 Qynviper_JSON_VM::advance_past_end_control(QString& basis, qint64* skipped)
{

}

u2 Qynviper_JSON_VM::advance_past_end_control(QString& basis, qreal* skipped)
{

}

u2 Qynviper_JSON_VM::advance_past_end_control(QString& basis, float* skipped)
{

}

