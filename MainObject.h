#ifndef MAINOBJECT_H
#define MAINOBJECT_H

#include <QObject>

class MainObject : public QObject {
     Q_OBJECT

public:
    explicit MainObject(QObject *parent = nullptr);
    ~MainObject();

private slots:
    void run();

signals:
    void finished();

private:
    int runCommand();

};

#endif // MAINOBJECT_H
