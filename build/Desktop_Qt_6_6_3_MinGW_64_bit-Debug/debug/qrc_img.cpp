/****************************************************************************
** Resource object code
**
** Created by: The Resource Compiler for Qt version 6.6.3
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

static const unsigned char qt_resource_data[] = {
  // C:/Users/sarra/Documents/interfaceges/interfaceSarra/icone1.jog.png
  0x0,0x0,0x0,0xaf,
  0x89,
  0x50,0x4e,0x47,0xd,0xa,0x1a,0xa,0x0,0x0,0x0,0xd,0x49,0x48,0x44,0x52,0x0,
  0x0,0x0,0x10,0x0,0x0,0x0,0x10,0x8,0x6,0x0,0x0,0x0,0x1f,0xf3,0xff,0x61,
  0x0,0x0,0x0,0x76,0x49,0x44,0x41,0x54,0x78,0x1,0xdd,0xc1,0xb1,0x15,0x82,0x40,
  0x14,0x45,0xc1,0xfb,0xf6,0x50,0x2,0xd8,0x2,0x6,0x86,0x14,0x40,0x1,0x90,0xd9,
  0x85,0x96,0xa3,0x5d,0x90,0x41,0x1,0x16,0x40,0x48,0x20,0x2d,0x8,0x35,0xf0,0xdd,
  0x60,0xf,0xf1,0xf,0xc5,0x19,0x8e,0x4f,0x24,0xed,0x7c,0xca,0x8d,0xed,0x82,0x83,
  0x8,0x53,0x5f,0x7e,0x56,0xa2,0x8c,0x9d,0xd5,0x18,0x77,0x3c,0x64,0xf,0xa0,0xe3,
  0x27,0x88,0xa4,0x79,0x17,0x15,0x58,0x83,0x8b,0x86,0xe1,0xbc,0x8c,0x44,0x81,0xc3,
  0x13,0x49,0x3b,0x17,0x57,0xc3,0x6e,0x38,0x8,0x3d,0xfb,0x72,0xe9,0x88,0x32,0x76,
  0x7a,0xb1,0xd9,0x8a,0x47,0xd0,0xc4,0xff,0xf8,0x2,0xa0,0x99,0x1d,0x79,0x5b,0x8e,
  0xd1,0xa4,0x0,0x0,0x0,0x0,0x49,0x45,0x4e,0x44,0xae,0x42,0x60,0x82,
  
};

static const unsigned char qt_resource_name[] = {
  // res
  0x0,0x3,
  0x0,0x0,0x78,0xc3,
  0x0,0x72,
  0x0,0x65,0x0,0x73,
    // icone1.jog.png
  0x0,0xe,
  0x5,0x93,0x74,0x7,
  0x0,0x69,
  0x0,0x63,0x0,0x6f,0x0,0x6e,0x0,0x65,0x0,0x31,0x0,0x2e,0x0,0x6a,0x0,0x6f,0x0,0x67,0x0,0x2e,0x0,0x70,0x0,0x6e,0x0,0x67,
  
};

static const unsigned char qt_resource_struct[] = {
  // :
  0x0,0x0,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x1,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
  // :/res
  0x0,0x0,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x2,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
  // :/res/icone1.jog.png
  0x0,0x0,0x0,0xc,0x0,0x0,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x0,
0x0,0x0,0x1,0x92,0xf2,0xa9,0x52,0xa0,

};

#ifdef QT_NAMESPACE
#  define QT_RCC_PREPEND_NAMESPACE(name) ::QT_NAMESPACE::name
#  define QT_RCC_MANGLE_NAMESPACE0(x) x
#  define QT_RCC_MANGLE_NAMESPACE1(a, b) a##_##b
#  define QT_RCC_MANGLE_NAMESPACE2(a, b) QT_RCC_MANGLE_NAMESPACE1(a,b)
#  define QT_RCC_MANGLE_NAMESPACE(name) QT_RCC_MANGLE_NAMESPACE2( \
        QT_RCC_MANGLE_NAMESPACE0(name), QT_RCC_MANGLE_NAMESPACE0(QT_NAMESPACE))
#else
#   define QT_RCC_PREPEND_NAMESPACE(name) name
#   define QT_RCC_MANGLE_NAMESPACE(name) name
#endif

#ifdef QT_NAMESPACE
namespace QT_NAMESPACE {
#endif

bool qRegisterResourceData(int, const unsigned char *, const unsigned char *, const unsigned char *);
bool qUnregisterResourceData(int, const unsigned char *, const unsigned char *, const unsigned char *);

#ifdef QT_NAMESPACE
}
#endif

int QT_RCC_MANGLE_NAMESPACE(qInitResources_img)();
int QT_RCC_MANGLE_NAMESPACE(qInitResources_img)()
{
    int version = 3;
    QT_RCC_PREPEND_NAMESPACE(qRegisterResourceData)
        (version, qt_resource_struct, qt_resource_name, qt_resource_data);
    return 1;
}

int QT_RCC_MANGLE_NAMESPACE(qCleanupResources_img)();
int QT_RCC_MANGLE_NAMESPACE(qCleanupResources_img)()
{
    int version = 3;
    QT_RCC_PREPEND_NAMESPACE(qUnregisterResourceData)
       (version, qt_resource_struct, qt_resource_name, qt_resource_data);
    return 1;
}

#ifdef __clang__
#   pragma clang diagnostic push
#   pragma clang diagnostic ignored "-Wexit-time-destructors"
#endif

namespace {
   struct initializer {
       initializer() { QT_RCC_MANGLE_NAMESPACE(qInitResources_img)(); }
       ~initializer() { QT_RCC_MANGLE_NAMESPACE(qCleanupResources_img)(); }
   } dummy;
}

#ifdef __clang__
#   pragma clang diagnostic pop
#endif
