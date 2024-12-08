/****************************************************************************
** Meta object code from reading C++ file 'employeeui.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../syrine/employeeui.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'employeeui.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_employeeUI_t {
    const uint offsetsAndSize[34];
    char stringdata0[345];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_employeeUI_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_employeeUI_t qt_meta_stringdata_employeeUI = {
    {
QT_MOC_LITERAL(0, 10), // "employeeUI"
QT_MOC_LITERAL(11, 18), // "on_ajouter_clicked"
QT_MOC_LITERAL(30, 0), // ""
QT_MOC_LITERAL(31, 17), // "on_editer_clicked"
QT_MOC_LITERAL(49, 15), // "on_supp_clicked"
QT_MOC_LITERAL(65, 8), // "clrinput"
QT_MOC_LITERAL(74, 33), // "on_lineEdit_recherche_textCha..."
QT_MOC_LITERAL(108, 4), // "arg1"
QT_MOC_LITERAL(113, 35), // "on_comboBox_tri_currentIndexC..."
QT_MOC_LITERAL(149, 24), // "on_Demande_conge_clicked"
QT_MOC_LITERAL(174, 28), // "on_statistiqueButton_clicked"
QT_MOC_LITERAL(203, 17), // "on_retour_clicked"
QT_MOC_LITERAL(221, 19), // "on_stat_btn_clicked"
QT_MOC_LITERAL(241, 28), // "on_ExportationButton_clicked"
QT_MOC_LITERAL(270, 24), // "on_pushButton_22_clicked"
QT_MOC_LITERAL(295, 24), // "on_pushButton_18_clicked"
QT_MOC_LITERAL(320, 24) // "on_pushButton_19_clicked"

    },
    "employeeUI\0on_ajouter_clicked\0\0"
    "on_editer_clicked\0on_supp_clicked\0"
    "clrinput\0on_lineEdit_recherche_textChanged\0"
    "arg1\0on_comboBox_tri_currentIndexChanged\0"
    "on_Demande_conge_clicked\0"
    "on_statistiqueButton_clicked\0"
    "on_retour_clicked\0on_stat_btn_clicked\0"
    "on_ExportationButton_clicked\0"
    "on_pushButton_22_clicked\0"
    "on_pushButton_18_clicked\0"
    "on_pushButton_19_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_employeeUI[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   98,    2, 0x08,    1 /* Private */,
       3,    0,   99,    2, 0x08,    2 /* Private */,
       4,    0,  100,    2, 0x08,    3 /* Private */,
       5,    0,  101,    2, 0x08,    4 /* Private */,
       6,    1,  102,    2, 0x08,    5 /* Private */,
       8,    0,  105,    2, 0x08,    7 /* Private */,
       9,    0,  106,    2, 0x08,    8 /* Private */,
      10,    0,  107,    2, 0x08,    9 /* Private */,
      11,    0,  108,    2, 0x08,   10 /* Private */,
      12,    0,  109,    2, 0x08,   11 /* Private */,
      13,    0,  110,    2, 0x08,   12 /* Private */,
      14,    0,  111,    2, 0x08,   13 /* Private */,
      15,    0,  112,    2, 0x08,   14 /* Private */,
      16,    0,  113,    2, 0x08,   15 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void employeeUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<employeeUI *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_ajouter_clicked(); break;
        case 1: _t->on_editer_clicked(); break;
        case 2: _t->on_supp_clicked(); break;
        case 3: _t->clrinput(); break;
        case 4: _t->on_lineEdit_recherche_textChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 5: _t->on_comboBox_tri_currentIndexChanged(); break;
        case 6: _t->on_Demande_conge_clicked(); break;
        case 7: _t->on_statistiqueButton_clicked(); break;
        case 8: _t->on_retour_clicked(); break;
        case 9: _t->on_stat_btn_clicked(); break;
        case 10: _t->on_ExportationButton_clicked(); break;
        case 11: _t->on_pushButton_22_clicked(); break;
        case 12: _t->on_pushButton_18_clicked(); break;
        case 13: _t->on_pushButton_19_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject employeeUI::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_employeeUI.offsetsAndSize,
    qt_meta_data_employeeUI,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_employeeUI_t
, QtPrivate::TypeAndForceComplete<employeeUI, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *employeeUI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *employeeUI::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_employeeUI.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int employeeUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
