#ifndef EXPERSON_H
#define EXPERSON_H

#include <QObject>

class ExPerson : public QObject
{
    Q_OBJECT

    //类的附加信息：名称————值
    Q_CLASSINFO("author", "touwoyimuli")
    Q_CLASSINFO("version", "1.0.0")
    Q_CLASSINFO("info", "Qt5 Meta Object and Property Example")

    //属性定义
    Q_PROPERTY(int age READ getAge WRITE setAge NOTIFY ageChanged)    //属性age; 方法getAge()和setAge()对其读写; 设置信号ageChanged()
    Q_PROPERTY(QString name MEMBER m_name)     //属性name 与类成员变量m_name关联
    Q_PROPERTY(int score MEMBER m_score)       //属性score与类成员变量m_score关联

public:
    explicit ExPerson(QString name, QObject *parent = nullptr);

public:
    int getAge();                //属性 READ 函数
    void setAge(int value);      //属性 WRITE 函数

    void incAge();               //单独写一个接口，与属性无关

signals:
    void ageChanged(int value);  //属性age发生改变的信号函数

private:
    int m_age = 5;
    QString m_name;
    int m_score = 50;

};

#endif // EXPERSON_H
