#include <QCoreApplication>
#include <QDebug>
#include <QList>
#include <QTextStream>
#include <QFile>
#include <QTextCodec>

namespace SK {
enum SortKind{
    col01    =   0x00000001<<0,         //!< 第1列
    col02    =   0x00000001<<1,         //!< 第2列
    col03    =   0x00000001<<2,         //!< 第3列
    col04    =   0x00000001<<3,         //!< 第4列
    col05    =   0x00000001<<4,         //!< 第5列
    col06    =   0x00000001<<5,         //!< 第6列
    col07    =   0x00000001<<6,         //!< 第7列
    col08    =   0x00000001<<7,         //!< 第8列
    col09    =   0x00000001<<8,         //!< 第9列
    col10    =   0x00000001<<9,         //!< 第10列
    col11    =   0x00000001<<10,        //!< 第11列
    col12    =   0x00000001<<11,        //!< 第12列
    col13    =   0x00000001<<12,        //!< 第13列
    col14    =   0x00000001<<13,        //!< 第14列
    col15    =   0x00000001<<14,        //!< 第15列
    col16    =   0x00000001<<15,        //!< 第16列
    col17    =   0x00000001<<16,        //!< 第17列
    col18    =   0x00000001<<17,        //!< 第18列
    col19    =   0x00000001<<18,        //!< 第19列
    col20    =   0x00000001<<19,        //!< 第20列
    col21    =   0x00000001<<20,        //!< 第21列
    col22    =   0x00000001<<21,        //!< 第22列
    col23    =   0x00000001<<22,        //!< 第23列
    col24    =   0x00000001<<23,        //!< 第24列
    col25    =   0x00000001<<24,        //!< 第25列
    col26    =   0x00000001<<25,        //!< 第26列
    col27    =   0x00000001<<26,        //!< 第27列
    col28    =   0x00000001<<27,        //!< 第28列
    col29    =   0x00000001<<28,        //!< 第29列
    col30    =   0x00000001<<29,        //!< 第30列
    col31    =   0x00000001<<30,        //!< 第31列
    col32    =   0x00000001<<31,        //!< 第32列
};
}


typedef struct{

public:
    QStringList stu;

} studData;

QDebug operator<< (QDebug d, const studData &data) {
    // 运算符重载函数，直接输出studData结构
    for(int i=0;i<data.stu.size();i++)
        {
            d.nospace().noquote()<<QString(data.stu.at(i))<<"  ";
        }
    return d;
}

// 比较类，用于std::sort第三个参数
class myCmp {
public:
    myCmp(int selectedColumn) { this->currentColumn = selectedColumn; }
    bool operator() (const studData& d1,const studData& d2);
private:
    int currentColumn;
};

bool myCmp::operator()(const studData &d1, const studData &d2)
{
    bool resultzero = false;
    quint32 sortedColumn = 0x00000001<<currentColumn;
    switch (sortedColumn) {
    case SK::col01:
        return (d1.stu.at(currentColumn))>(d2.stu.at(currentColumn));break;
    case SK::col02:
        return (d1.stu.at(currentColumn))>(d2.stu.at(currentColumn));break;
    case SK::col03:
        return (d1.stu.at(currentColumn))>(d2.stu.at(currentColumn));break;
    case SK::col04:
        return (d1.stu.at(currentColumn))>(d2.stu.at(currentColumn));break;
    case SK::col05:
        return (d1.stu.at(currentColumn))>(d2.stu.at(currentColumn));break;
    case SK::col06:
        return (d1.stu.at(currentColumn))>(d2.stu.at(currentColumn));break;
    case SK::col07:
        return (d1.stu.at(currentColumn))>(d2.stu.at(currentColumn));break;
    case SK::col08:
        return (d1.stu.at(currentColumn))>(d2.stu.at(currentColumn));break;
    }
    return resultzero;
}



class ScoreSorter
{
private:
    QString textFile;
    QStringList la;
    QList<studData> tl;
public:
    ScoreSorter(QString dataFile);
    void readFile()
    {
        QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));

        QFile file(textFile);

        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
            return;

        QString titile(file.readLine());
        studData sign;
        la=titile.split(" ", QString::SkipEmptyParts);
        while(!file.atEnd())
        {
            QString line(file.readLine());
            sign.stu=line.split(" ",QString::SkipEmptyParts);
            if((sign.stu).last()=="\n")sign.stu.removeLast();
            if((sign.stu.size())==0)continue;
            tl.append(sign);

         }
         file.close();
    }

    void doSort()
    {
        for(int i=0;i<la.count();i++)
            {
                myCmp d(i);
                std::sort(tl.begin(),tl.end(),d);
                qDebug()<<"第"<<i+1<<"列排序，排序后为:";
                qDebug()<<la;
                for(int i=0;i<tl.size();i++)
                    qDebug()<<tl.at(i);
                qDebug()<<"\n";

            }

    }
};




ScoreSorter::ScoreSorter(QString dataFile){
    textFile=dataFile;
}


/*void myMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    QByteArray localMsg = msg.toLocal8Bit();
         switch (type) {
         case QtDebugMsg:
             fprintf(stderr, "Debug: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
             break;
         case QtInfoMsg:
             fprintf(stderr, "Info: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
             break;
         case QtWarningMsg:
             fprintf(stderr, "Warning: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
             break;
         case QtCriticalMsg:
             fprintf(stderr, "Critical: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
             break;
         case QtFatalMsg:
             fprintf(stderr, "Fatal: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
             abort();
         }
}*/

int main()
{
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    //QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    //QTextCodec::setCodecForTr(codec);
    //QTextCodec::setCodecForLocale(codec);
    //QTextCodec::setCodecForCStrings(codec);
    //qInstallMessageHandler(myMessageOutput);//输出调试信息*/
    QString datafile = "D:/data.txt";

    //如果排序后文件已存在，则删除之
    QFile f("sorted_"+datafile);
    if (f.exists()){
        f.remove();
    }

    ScoreSorter s(datafile);
    s.readFile();
    s.doSort();
    return 0;
}
