/****************************************************************************
** Meta object code from reading C++ file 'DTreeView.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "DTreeView.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DTreeView.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DTreeView_t {
    QByteArrayData data[8];
    char stringdata0[94];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DTreeView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DTreeView_t qt_meta_stringdata_DTreeView = {
    {
QT_MOC_LITERAL(0, 0, 9), // "DTreeView"
QT_MOC_LITERAL(1, 10, 16), // "slotTemporizador"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 9), // "slotBoton"
QT_MOC_LITERAL(4, 38, 4), // "edit"
QT_MOC_LITERAL(5, 43, 11), // "QModelIndex"
QT_MOC_LITERAL(6, 55, 30), // "QAbstractItemView::EditTrigger"
QT_MOC_LITERAL(7, 86, 7) // "QEvent*"

    },
    "DTreeView\0slotTemporizador\0\0slotBoton\0"
    "edit\0QModelIndex\0QAbstractItemView::EditTrigger\0"
    "QEvent*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DTreeView[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x0a /* Public */,
       3,    0,   30,    2, 0x0a /* Public */,
       4,    3,   31,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool, 0x80000000 | 5, 0x80000000 | 6, 0x80000000 | 7,    2,    2,    2,

       0        // eod
};

void DTreeView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DTreeView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slotTemporizador(); break;
        case 1: _t->slotBoton(); break;
        case 2: { bool _r = _t->edit((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< QAbstractItemView::EditTrigger(*)>(_a[2])),(*reinterpret_cast< QEvent*(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DTreeView::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_DTreeView.data,
    qt_meta_data_DTreeView,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DTreeView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DTreeView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DTreeView.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Ui::DTreeView"))
        return static_cast< Ui::DTreeView*>(this);
    return QDialog::qt_metacast(_clname);
}

int DTreeView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
struct qt_meta_stringdata_ModelTree_t {
    QByteArrayData data[1];
    char stringdata0[10];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ModelTree_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ModelTree_t qt_meta_stringdata_ModelTree = {
    {
QT_MOC_LITERAL(0, 0, 9) // "ModelTree"

    },
    "ModelTree"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ModelTree[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void ModelTree::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject ModelTree::staticMetaObject = { {
    &QAbstractItemModel::staticMetaObject,
    qt_meta_stringdata_ModelTree.data,
    qt_meta_data_ModelTree,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ModelTree::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ModelTree::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ModelTree.stringdata0))
        return static_cast<void*>(this);
    return QAbstractItemModel::qt_metacast(_clname);
}

int ModelTree::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractItemModel::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
