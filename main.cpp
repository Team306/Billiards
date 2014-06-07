#include "glwindow.h"
#include "MyMath.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    /*Vector3 v1(1,2,3);
    Vector3 v2(4,1,2);
    cout<<DistanceBetween(v1,v2)<<endl;
    cout<<DotProduct(v1,v2)<<endl;
    Vector3 v3=GetNormalize(v1);
    cout<<v3[0]<<endl<<v3[1]<<endl<<v3[2]<<endl;
    v1*=3;
    v1.Normalize();
    cout<<v1[0]<<endl<<v1[1]<<endl<<v1[2]<<endl;
    cout<<v1.Length2()<<endl;*/
    GLWindow w;
    w.show();
    return a.exec();
}
