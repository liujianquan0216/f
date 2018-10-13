#include <QCoreApplication>
#include <QDebug>
#include <QList>

int main()
{
    QList<QString>l;
    l<<"学号"<<"姓名"<<"课程1"<<"课程2";

    QList<QString>l1;
    l1<<"1403130209"<<"鲁智深"<<"80"<<"72";

    QList<QString>l2;
    l2<<"1403140101"<<"林冲"<<"82"<<"76";

    QList<QString>l3;
    l3<<"1403140102"<<"宋江"<<"76"<<"85";

    QList<QString>l4;
    l4<<"1403140103"<<"武松"<<"88"<<"80";

    QList<QString>s1;
    s1<<"鲁智深"<<"林冲"<<"宋江"<<"武松";

    QList<QString>s2;
    s2<<"80"<<"82"<<"76"<<"88";

    QList<QString>s3;
    s3<<"72"<<"76"<<"85"<<"80";

    std::sort(s1.begin(),s1.end(),std::greater<QString>());
    std::sort(s2.begin(),s2.end(),std::greater<QString>());
    std::sort(s3.begin(),s3.end(),std::greater<QString>());

    qDebug()<<"初始排序:";

    qDebug()<<l1;
    qDebug()<<l2;
    qDebug()<<l3;
    qDebug()<<l4;
    qDebug()<<"";

    int i;

    qDebug()<<"按姓名排序:";

    for(i=0;i<4;i++)
    {
        if(l1.at(1) == s1.at(i))
            qDebug()<<l1;
        if(l2.at(1) == s1.at(i))
            qDebug()<<l2;
        if(l3.at(1) == s1.at(i))
            qDebug()<<l3;
        if(l4.at(1) == s1.at(i))
            qDebug()<<l4;
    }

    qDebug()<<"";

    qDebug()<<"按课程1排序:";

    for(i=0;i<4;i++)
    {
        if(l1.at(2) == s2.at(i))
            qDebug()<<l1;
        if(l2.at(2) == s2.at(i))
            qDebug()<<l2;
        if(l3.at(2) == s2.at(i))
            qDebug()<<l3;
        if(l4.at(2) == s2.at(i))
            qDebug()<<l4;
    }

    qDebug()<<"";

    qDebug()<<"按课程2排序:";

    for(i=0;i<4;i++)
    {
        if(l1.at(3) == s3.at(i))
            qDebug()<<l1;
        if(l2.at(3) == s3.at(i))
            qDebug()<<l2;
        if(l3.at(3) == s3.at(i))
            qDebug()<<l3;
        if(l4.at(3) == s3.at(i))
            qDebug()<<l4;
    }

}
