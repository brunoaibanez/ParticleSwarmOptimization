/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../ParticleSwarmOptimization/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[17];
    char stringdata0[334];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 19), // "changeFunctionLabel"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 11), // "std::string"
QT_MOC_LITERAL(4, 44, 4), // "path"
QT_MOC_LITERAL(5, 49, 22), // "on_startButton_clicked"
QT_MOC_LITERAL(6, 72, 21), // "on_stopButton_clicked"
QT_MOC_LITERAL(7, 94, 24), // "on_restartButton_clicked"
QT_MOC_LITERAL(8, 119, 33), // "on_numberOfParticles_valueCha..."
QT_MOC_LITERAL(9, 153, 4), // "arg1"
QT_MOC_LITERAL(10, 158, 24), // "on_deJongButton1_toggled"
QT_MOC_LITERAL(11, 183, 7), // "checked"
QT_MOC_LITERAL(12, 191, 24), // "on_deJongButton2_toggled"
QT_MOC_LITERAL(13, 216, 27), // "on_RastriginButton6_toggled"
QT_MOC_LITERAL(14, 244, 27), // "on_InerciaBox1_valueChanged"
QT_MOC_LITERAL(15, 272, 27), // "on_InerciaBox2_valueChanged"
QT_MOC_LITERAL(16, 300, 33) // "on_InercialWeightBox_valueCha..."

    },
    "MainWindow\0changeFunctionLabel\0\0"
    "std::string\0path\0on_startButton_clicked\0"
    "on_stopButton_clicked\0on_restartButton_clicked\0"
    "on_numberOfParticles_valueChanged\0"
    "arg1\0on_deJongButton1_toggled\0checked\0"
    "on_deJongButton2_toggled\0"
    "on_RastriginButton6_toggled\0"
    "on_InerciaBox1_valueChanged\0"
    "on_InerciaBox2_valueChanged\0"
    "on_InercialWeightBox_valueChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x08 /* Private */,
       5,    0,   72,    2, 0x08 /* Private */,
       6,    0,   73,    2, 0x08 /* Private */,
       7,    0,   74,    2, 0x08 /* Private */,
       8,    1,   75,    2, 0x08 /* Private */,
      10,    1,   78,    2, 0x08 /* Private */,
      12,    1,   81,    2, 0x08 /* Private */,
      13,    1,   84,    2, 0x08 /* Private */,
      14,    1,   87,    2, 0x08 /* Private */,
      15,    1,   90,    2, 0x08 /* Private */,
      16,    1,   93,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Bool,   11,
    QMetaType::Void, QMetaType::Bool,   11,
    QMetaType::Void, QMetaType::Bool,   11,
    QMetaType::Void, QMetaType::Double,    9,
    QMetaType::Void, QMetaType::Double,    9,
    QMetaType::Void, QMetaType::Double,    9,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->changeFunctionLabel((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 1: _t->on_startButton_clicked(); break;
        case 2: _t->on_stopButton_clicked(); break;
        case 3: _t->on_restartButton_clicked(); break;
        case 4: _t->on_numberOfParticles_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_deJongButton1_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->on_deJongButton2_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->on_RastriginButton6_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->on_InerciaBox1_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 9: _t->on_InerciaBox2_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 10: _t->on_InercialWeightBox_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
