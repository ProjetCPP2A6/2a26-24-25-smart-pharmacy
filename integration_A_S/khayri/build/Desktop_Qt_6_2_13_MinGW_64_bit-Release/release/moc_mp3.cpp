/****************************************************************************
** Meta object code from reading C++ file 'mp3.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.13)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../newProject/interface khayri/mp3.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mp3.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.13. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_mp3_t {
    uint offsetsAndSizes[24];
    char stringdata0[210];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_mp3_t::offsetsAndSizes) + ofs), len 
static const qt_meta_stringdata_mp3_t qt_meta_stringdata_mp3 = {
    {
        QT_MOC_LITERAL(0, 3),  // "mp3"
        QT_MOC_LITERAL(4, 26),  // "on_pushButton_play_clicked"
        QT_MOC_LITERAL(31, 0),  // ""
        QT_MOC_LITERAL(32, 27),  // "on_pushButton_pause_clicked"
        QT_MOC_LITERAL(60, 26),  // "on_pushButton_stop_clicked"
        QT_MOC_LITERAL(87, 26),  // "on_pushButton_load_clicked"
        QT_MOC_LITERAL(114, 32),  // "on_horizontalSlider_valueChanged"
        QT_MOC_LITERAL(147, 5),  // "value"
        QT_MOC_LITERAL(153, 20),  // "updatePositionSlider"
        QT_MOC_LITERAL(174, 8),  // "position"
        QT_MOC_LITERAL(183, 17),  // "updateSliderRange"
        QT_MOC_LITERAL(201, 8)   // "duration"
    },
    "mp3\0on_pushButton_play_clicked\0\0"
    "on_pushButton_pause_clicked\0"
    "on_pushButton_stop_clicked\0"
    "on_pushButton_load_clicked\0"
    "on_horizontalSlider_valueChanged\0value\0"
    "updatePositionSlider\0position\0"
    "updateSliderRange\0duration"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_mp3[] = {

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
       5,    0,   59,    2, 0x08,    4 /* Private */,
       6,    1,   60,    2, 0x08,    5 /* Private */,
       8,    1,   63,    2, 0x08,    7 /* Private */,
      10,    1,   66,    2, 0x08,    9 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::LongLong,    9,
    QMetaType::Void, QMetaType::LongLong,   11,

       0        // eod
};

void mp3::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<mp3 *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_pushButton_play_clicked(); break;
        case 1: _t->on_pushButton_pause_clicked(); break;
        case 2: _t->on_pushButton_stop_clicked(); break;
        case 3: _t->on_pushButton_load_clicked(); break;
        case 4: _t->on_horizontalSlider_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 5: _t->updatePositionSlider((*reinterpret_cast< std::add_pointer_t<qint64>>(_a[1]))); break;
        case 6: _t->updateSliderRange((*reinterpret_cast< std::add_pointer_t<qint64>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject mp3::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_mp3.offsetsAndSizes,
    qt_meta_data_mp3,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_mp3_t
, QtPrivate::TypeAndForceComplete<mp3, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<qint64, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<qint64, std::false_type>


>,
    nullptr
} };


const QMetaObject *mp3::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *mp3::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_mp3.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int mp3::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
