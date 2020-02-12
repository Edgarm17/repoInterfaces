/****************************************************************************
** Meta object code from reading C++ file 'WidgetPRE.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "WidgetPRE.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'WidgetPRE.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_WidgetPRE_t {
    QByteArrayData data[8];
    char stringdata0[89];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WidgetPRE_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WidgetPRE_t qt_meta_stringdata_WidgetPRE = {
    {
QT_MOC_LITERAL(0, 0, 9), // "WidgetPRE"
QT_MOC_LITERAL(1, 10, 11), // "imgSelected"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 5), // "Bola*"
QT_MOC_LITERAL(4, 29, 15), // "slotPonerImagen"
QT_MOC_LITERAL(5, 45, 14), // "slotPonerColor"
QT_MOC_LITERAL(6, 60, 14), // "slotPonerTrama"
QT_MOC_LITERAL(7, 75, 13) // "slotTextoBola"

    },
    "WidgetPRE\0imgSelected\0\0Bola*\0"
    "slotPonerImagen\0slotPonerColor\0"
    "slotPonerTrama\0slotTextoBola"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WidgetPRE[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   42,    2, 0x0a /* Public */,
       5,    0,   43,    2, 0x0a /* Public */,
       6,    0,   44,    2, 0x0a /* Public */,
       7,    1,   45,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,

       0        // eod
};

void WidgetPRE::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<WidgetPRE *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->imgSelected((*reinterpret_cast< Bola*(*)>(_a[1]))); break;
        case 1: _t->slotPonerImagen(); break;
        case 2: _t->slotPonerColor(); break;
        case 3: _t->slotPonerTrama(); break;
        case 4: _t->slotTextoBola((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (WidgetPRE::*)(Bola * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WidgetPRE::imgSelected)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject WidgetPRE::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_WidgetPRE.data,
    qt_meta_data_WidgetPRE,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *WidgetPRE::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WidgetPRE::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_WidgetPRE.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Ui::WidgetPRE"))
        return static_cast< Ui::WidgetPRE*>(this);
    return QWidget::qt_metacast(_clname);
}

int WidgetPRE::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void WidgetPRE::imgSelected(Bola * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
