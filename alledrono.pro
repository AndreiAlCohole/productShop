QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Admin.cpp \
    AdminWindow.cpp \
    AppController.cpp \
    Buyer.cpp \
    BuyerWindow.cpp \
    Category.cpp \
    Persistence.cpp \
    Product.cpp \
    Review.cpp \
    Seller.cpp \
    SellerWindow.cpp \
    Store.cpp \
    User.cpp \
    main.cpp \
    mainwindow.cpp \
    registerwindow.cpp

HEADERS += \
    Admin.h \
    AdminWindow.h \
    AppController.h \
    Buyer.h \
    BuyerWindow.h \
    Category.h \
    Persistence.h \
    Product.h \
    RegisterWindow.h \
    Review.h \
    Seller.h \
    SellerWindow.h \
    Store.h \
    User.h \
    mainwindow.h

FORMS += \
    AdminWindow.ui \
    BuyerWindow.ui \
    RegisterWindow.ui \
    SellerWindow.ui \
    mainwindow.ui

TRANSLATIONS += \
    alledrono_pl_PL.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    CMakeLists.txt \
    CMakeLists.txt.user \
    alledrono.pro.user \
    categories.txt \
    products.txt \
    purchase_history.txt \
    reviews.txt \
    users.txt
