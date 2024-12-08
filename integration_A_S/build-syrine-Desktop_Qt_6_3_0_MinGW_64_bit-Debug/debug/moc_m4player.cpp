/****************************************************************************
** Meta object code from reading C++ file 'm4player.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../khayri/m4player.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'm4player.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_m4player_t {
    const uint offsetsAndSize[20];
    char stringdata0[208];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_m4player_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_m4player_t qt_meta_stringdata_m4player = {
    {
QT_MOC_LITERAL(0, 8), // "m4player"
QT_MOC_LITERAL(9, 26), // "on_pushButton_play_clicked"
QT_MOC_LITERAL(36, 0), // ""
QT_MOC_LITERAL(37, 27), // "on_pushButton_pause_clicked"
QT_MOC_LITERAL(65, 26), // "on_pushButton_stop_clicked"
QT_MOC_LITERAL(92, 39), // "on_horizontalSlider_volume_va..."
QT_MOC_LITERAL(132, 5), // "value"
QT_MOC_LITERAL(138, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(160, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(184, 23) // "on_pushButton_3_clicked"

    },
    "m4player\0on_pushButton_play_clicked\0"
    "\0on_pushButton_pause_clicked\0"
    "on_pushButton_stop_clicked\0"
    "on_horizontalSlider_volume_valueChanged\0"
    "value\0on_pushButton_clicked\0"
    "on_pushButton_2_clicked\0on_pushButton_3_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_m4player[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   56,    2, 0x08,    1 /* Private */,
       3,    0,   57,    2, 0x08,    2 /* Private */,
       4,    0,   58,    2, 0x08,    3 /* Private */,
       5,    1,   59,    2, 0x08,    4 /* Private */,
       7,    0,   62,    2, 0x08,    6 /* Private */,
       8,    0,   63,    2, 0x08,    7 /* Private */,
       9,    0,   64,    2, 0x08,    8 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void m4player::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<m4player *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_pushButton_play_clicked(); break;
        case 1: _t->on_pushButton_pause_clicked(); break;
        case 2: _t->on_pushButton_stop_clicked(); break;
        case 3: _t->on_horizontalSlider_volume_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->on_pushButton_clicked(); break;
        case 5: _t->on_pushButton_2_clicked(); break;
        case 6: _t->on_pushButton_3_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject m4player::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_m4player.offsetsAndSize,
    qt_meta_data_m4player,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_m4player_t
, QtPrivate::TypeAndForceComplete<m4player, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *m4player::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *m4player::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_m4player.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int m4player::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
